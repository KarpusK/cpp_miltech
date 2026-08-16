#include <rclcpp/rclcpp.hpp>

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <optional>
#include <functional>
#include <string>

#include "underground_world/msg/local_scan.hpp"
#include "underground_world/msg/move_command.hpp"
#include "underground_world/msg/student_status.hpp"
#include "underground_world/srv/payload_trigger.hpp"
#include "underground_world/state_qos.hpp"


struct Position
{
    int x;
    int y;

    bool operator==(const Position &other) const
    {
        return x == other.x && y == other.y;
    }
};


struct PositionHash
{
    std::size_t operator()(const Position &p) const
    {
        return std::hash<int>{}(p.x) ^
               (std::hash<int>{}(p.y) << 1);
    }
};


class MissionExplorer : public rclcpp::Node
{
public:
    MissionExplorer()
        : Node("mission_explorer")
    {
        move_pub_ =
            create_publisher<underground_world::msg::MoveCommand>(
                "/robot/cmd_move",
                10);

        status_pub_ =
            create_publisher<underground_world::msg::StudentStatus>(
                "/student/status",
                10);

        payload_client_ =
            create_client<underground_world::srv::PayloadTrigger>(
                "/payload/trigger");

        scan_sub_ =
            create_subscription<underground_world::msg::LocalScan>(
                "/robot/local_scan",
                underground_world::make_state_qos(),
                std::bind(
                    &MissionExplorer::scan_callback,
                    this,
                    std::placeholders::_1));

        publish_status(
            underground_world::msg::StudentStatus::EXPLORING);

        RCLCPP_INFO(
            get_logger(),
            "Mission explorer started");
    }

private:
    using LocalScan = underground_world::msg::LocalScan;
    using MoveCommand = underground_world::msg::MoveCommand;
    using PayloadTrigger = underground_world::srv::PayloadTrigger;

    std::unordered_map<
        Position,
        std::string,
        PositionHash> known_cells_;

    std::unordered_set<
        Position,
        PositionHash> visited_;

    std::vector<Position> dfs_stack_;

    Position current_position_{0, 0};
    Position start_position_{0, 0};

    bool have_position_ = false;
    bool have_start_position_ = false;
    bool engaging_ = false;
    bool waiting_for_move_ = false;
    bool returning_ = false;
    bool done_ = false;

    std::optional<Position> pending_target_;

    rclcpp::Subscription<LocalScan>::SharedPtr scan_sub_;
    rclcpp::Publisher<MoveCommand>::SharedPtr move_pub_;
    rclcpp::Publisher<
        underground_world::msg::StudentStatus>::SharedPtr status_pub_;
    rclcpp::Client<PayloadTrigger>::SharedPtr payload_client_;


    void scan_callback(
        const LocalScan::SharedPtr scan)
    {
        if (done_)
        {
            return;
        }

        Position new_position{
            scan->robot_x,
            scan->robot_y
        };

        if (!have_start_position_)
        {
            start_position_ = new_position;
            have_start_position_ = true;

            RCLCPP_INFO(
                get_logger(),
                "Start position: (%d, %d)",
                start_position_.x,
                start_position_.y);
        }

        if (waiting_for_move_)
        {
            if (pending_target_.has_value() &&
                new_position == pending_target_.value())
            {
                waiting_for_move_ = false;
                pending_target_.reset();
            }
            else
            {
                return;
            }
        }

        current_position_ = new_position;
        have_position_ = true;

        visited_.insert(current_position_);

        update_map(*scan);

        RCLCPP_INFO(
            get_logger(),
            "Robot position: (%d, %d), known cells: %zu",
            current_position_.x,
            current_position_.y,
            known_cells_.size());

        if (process_visible_contact(*scan))
        {
            return;
        }

        if (engaging_)
        {
            return;
        }

        explore_next();
    }


    void update_map(const LocalScan &scan)
    {
        for (const auto &cell : scan.cells)
        {
            Position p{
                cell.x,
                cell.y
            };

            known_cells_[p] = cell.cell_type;
        }
    }


    bool process_visible_contact(
        const LocalScan &scan)
    {
        if (engaging_)
        {
            return true;
        }

        for (const auto &cell : scan.cells)
        {
            if (cell.cell_type != "C")
            {
                continue;
            }

            RCLCPP_INFO(
                get_logger(),
                "Contact %d visible at (%d, %d)",
                cell.contact_id,
                cell.x,
                cell.y);

            publish_status(
                underground_world::msg::StudentStatus::ENGAGING);

            trigger_payload(
                cell.contact_id,
                cell.x,
                cell.y);

            return true;
        }

        return false;
    }


    void trigger_payload(
        int contact_id,
        int x,
        int y)
    {
        if (!payload_client_->service_is_ready())
        {
            RCLCPP_WARN(
                get_logger(),
                "Payload service is not ready");

            publish_status(
                underground_world::msg::StudentStatus::FAILED);

            return;
        }

        engaging_ = true;

        auto request =
            std::make_shared<PayloadTrigger::Request>();

        request->contact_id = contact_id;
        request->x = x;
        request->y = y;

        payload_client_->async_send_request(
            request,
            [this](
                rclcpp::Client<PayloadTrigger>::SharedFuture future)
            {
                auto response = future.get();

                if (!response->accepted)
                {
                    RCLCPP_ERROR(
                        get_logger(),
                        "Payload rejected: %s",
                        response->reason.c_str());

                    engaging_ = false;

                    publish_status(
                        underground_world::msg::StudentStatus::FAILED);

                    return;
                }

                RCLCPP_INFO(
                    get_logger(),
                    "Payload accepted: %s",
                    response->reason.c_str());

                engaging_ = false;
            });
    }


    bool is_walkable(
        const Position &p) const
    {
        auto it = known_cells_.find(p);

        if (it == known_cells_.end())
        {
            return false;
        }

        const std::string &type = it->second;

        return
            type == "." ||
            type == "S" ||
            type == "x";
    }


    std::vector<Position>
    get_neighbours(
        const Position &p) const
    {
        return {
            {p.x,     p.y - 1},
            {p.x + 1, p.y},
            {p.x,     p.y + 1},
            {p.x - 1, p.y}
        };
    }


    void explore_next()
    {
        if (!have_position_ || done_)
        {
            return;
        }

        publish_status(
            underground_world::msg::StudentStatus::EXPLORING);

        // 1. Шукаємо нового сусіда
        for (const auto &next : get_neighbours(current_position_))
        {
            if (!is_walkable(next))
            {
                continue;
            }

            if (visited_.contains(next))
            {
                continue;
            }

            // Запам'ятовуємо шлях назад
            dfs_stack_.push_back(current_position_);

            move_to(next);
            return;
        }

        // 2. Нових сусідів немає — повертаємося назад
        if (!dfs_stack_.empty())
        {
            Position previous = dfs_stack_.back();
            dfs_stack_.pop_back();

            move_to(previous);
            return;
        }

        // 3. Немає нового сусіда І стек порожній.
        // DFS повністю завершився.
        returning_ = true;

        publish_status(
            underground_world::msg::StudentStatus::RETURNING);

        RCLCPP_INFO(
            get_logger(),
            "Exploration complete. Robot returned to start.");

        // При нормальному DFS тут робот уже повинен бути в S.
        if (current_position_ == start_position_)
        {
            done_ = true;

            publish_status(
                underground_world::msg::StudentStatus::DONE);

            RCLCPP_INFO(
                get_logger(),
                "Mission DONE");

            return;
        }

        publish_status(
            underground_world::msg::StudentStatus::FAILED);
    }


    void move_to(
        const Position &target)
    {
        auto direction =
            direction_to(
                current_position_,
                target);

        if (!direction.has_value())
        {
            RCLCPP_ERROR(
                get_logger(),
                "Invalid target (%d,%d) from (%d,%d)",
                target.x,
                target.y,
                current_position_.x,
                current_position_.y);

            publish_status(
                underground_world::msg::StudentStatus::FAILED);

            return;
        }

        MoveCommand msg;

        msg.direction =
            direction.value();

        waiting_for_move_ = true;
        pending_target_ = target;

        move_pub_->publish(msg);

        RCLCPP_INFO(
            get_logger(),
            "Move: (%d,%d) -> (%d,%d)",
            current_position_.x,
            current_position_.y,
            target.x,
            target.y);
    }


    std::optional<uint8_t>
    direction_to(
        const Position &from,
        const Position &to) const
    {
        int dx = to.x - from.x;
        int dy = to.y - from.y;

        if (dx == 0 && dy == -1)
        {
            return MoveCommand::UP;
        }

        if (dx == 0 && dy == 1)
        {
            return MoveCommand::DOWN;
        }

        if (dx == -1 && dy == 0)
        {
            return MoveCommand::LEFT;
        }

        if (dx == 1 && dy == 0)
        {
            return MoveCommand::RIGHT;
        }

        return std::nullopt;
    }


    void publish_status(
        uint8_t state)
    {
        underground_world::msg::StudentStatus msg;

        msg.state = state;

        status_pub_->publish(msg);
    }
};


int main(
    int argc,
    char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<MissionExplorer>());

    rclcpp::shutdown();

    return 0;
}
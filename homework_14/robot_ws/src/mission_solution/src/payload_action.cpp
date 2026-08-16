#include <rclcpp/rclcpp.hpp>

#include <memory>
#include <functional>

#include "underground_world/msg/enemy_down.hpp"
#include "underground_world/srv/payload_trigger.hpp"


class PayloadAction : public rclcpp::Node
{
public:
    PayloadAction()
        : Node("payload_action")
    {
        enemy_down_pub_ =
            create_publisher<
                underground_world::msg::EnemyDown>(
                "/payload/enemy_down",
                10);

        trigger_service_ =
            create_service<
                underground_world::srv::PayloadTrigger>(
                "/payload/trigger",
                std::bind(
                    &PayloadAction::trigger_callback,
                    this,
                    std::placeholders::_1,
                    std::placeholders::_2));

        RCLCPP_INFO(
            get_logger(),
            "Payload action node started");
    }

private:

    rclcpp::Publisher<
        underground_world::msg::EnemyDown>::SharedPtr
        enemy_down_pub_;

    rclcpp::Service<
        underground_world::srv::PayloadTrigger>::SharedPtr
        trigger_service_;


    void trigger_callback(
        const std::shared_ptr<
            underground_world::srv::PayloadTrigger::Request>
            request,

        std::shared_ptr<
            underground_world::srv::PayloadTrigger::Response>
            response)
    {
        RCLCPP_INFO(
            get_logger(),
            "Payload trigger request: contact=%d position=(%d,%d)",
            request->contact_id,
            request->x,
            request->y);

        // Мінімальна базова перевірка.
        if (request->contact_id <= 0)
        {
            response->accepted = false;
            response->reason =
                "Invalid contact_id";

            return;
        }

        underground_world::msg::EnemyDown msg;

        msg.contact_id =
            request->contact_id;

        msg.x =
            request->x;

        msg.y =
            request->y;

        enemy_down_pub_->publish(msg);

        response->accepted = true;
        response->reason =
            "Payload action published";

        RCLCPP_INFO(
            get_logger(),
            "EnemyDown published for contact %d",
            request->contact_id);
    }
};


int main(
    int argc,
    char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<PayloadAction>());

    rclcpp::shutdown();

    return 0;
}
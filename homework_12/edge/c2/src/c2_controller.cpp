#include "c2_controller.hpp"
#include "fc_link.hpp"     // MAVSDK обгортка, API описано у fc_link.hpp
#include "udp_socket.hpp"  // UDP прийом, API описано у udp_socket.hpp

#include <nlohmann/json.hpp>  // Розбiр JSON з точками маршруту вiд auto_stub

#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <cstdint>

static constexpr uint16_t STUB_PORT = 14560;

namespace {
const char* state_name(C2State s) {
    switch (s) {
        case C2State::DISARMED: return "DISARMED";
        case C2State::ARMED_HOLD: return "ARMED_HOLD";
        case C2State::ARMED_GUIDED: return "ARMED_GUIDED";
        case C2State::ARMED_MANUAL: return "ARMED_MANUAL";
    }
    return "UNKNOWN";
}
}

struct C2Controller::Impl {
    C2State state = C2State::DISARMED;
    std::unique_ptr<FcLink> fc;
    std::unique_ptr<UdpSocket> udp;
    std::ofstream log;
    bool healthy_written = false;
    bool hold_sent = false;

    // TODO: додати FcLink, UdpSocket, лог-файл та прапорцi стану.
    // FcLink потребує fc_port у конструкторi Impl.
    // UdpSocket має слухати STUB_PORT.

    void transition(C2State next) {
        // TODO: якщо next != state, записати "PREV -> NEW" у stdout i лог,
        // потiм оновити state. Якщо стан не змiнився, нiчого не писати.
        if (next == state) {
            return;
        }

        std::cout << "[C2] state: " << state_name(state)
                  << " -> " << state_name(next) << '\n';
        if (log.is_open()) {
            log << "[C2] state: " << state_name(state)
                << " -> " << state_name(next) << '\n';
            log.flush();
        }

        state = next;
        hold_sent = false;
    }
};

C2Controller::C2Controller(uint16_t fc_port)
    : impl_(std::make_unique<Impl>())
{
    // TODO: передати fc_port в Impl та вiдкрити /var/log/c2/c2.log.
        impl_->fc = std::make_unique<FcLink>(fc_port);
    impl_->udp = std::make_unique<UdpSocket>(STUB_PORT);

    impl_->log.open("/var/log/c2/c2.log", std::ios::app);
}

C2Controller::~C2Controller() = default;

void C2Controller::tick() {
    // TODO: healthcheck, оновлення C2State, читання точки маршруту,
    // передавання або блокування команди згiдно з поточним станом.
    if (!impl_->healthy_written && impl_->fc->is_connected()) {
        std::ofstream("/tmp/c2_healthy").close();
        impl_->healthy_written = true;
    }

    C2State next = C2State::DISARMED;
    if (impl_->fc->is_armed()) {
        switch (impl_->fc->flight_mode()) {
            case FcLink::FlightMode::Guided:
                next = C2State::ARMED_GUIDED;
                break;
            case FcLink::FlightMode::Hold:
                next = C2State::ARMED_HOLD;
                break;
            case FcLink::FlightMode::Manual:
                next = C2State::ARMED_MANUAL;
                break;
            default:
                next = impl_->state;
                break;
        }
    }

    impl_->transition(next);

    if (impl_->state == C2State::ARMED_HOLD && !impl_->hold_sent) {
        impl_->fc->hold();
        impl_->hold_sent = true;
    }

    char buf[4096];
    const auto n = impl_->udp->recv(buf, sizeof(buf) - 1);
    if (n <= 0) {
        return;
    }

    buf[n] = '\0';
    const std::string payload(buf, n);

    try {
        const auto j = nlohmann::json::parse(payload);
        if (!j.contains("north_m") || !j.contains("east_m")) {
            return;
        }

        const float north = j.at("north_m").get<float>();
        const float east  = j.at("east_m").get<float>();

        if (impl_->state == C2State::ARMED_GUIDED) {
            impl_->fc->go_to_ned(north, east);
            std::cout << "[C2] fwd: north=" << north << " east=" << east << '\n';
        } else {
            std::cout << "[C2] blocked: waypoint in " << state_name(impl_->state) << '\n';
            if (impl_->log.is_open()) {
                impl_->log << "[C2] blocked: waypoint in " << state_name(impl_->state) << '\n';
                impl_->log.flush();
            }
        }
    } catch (const std::exception&) {
        // ignore malformed JSON
    }
}

C2State C2Controller::current_state() const {
    return impl_->state;
}

#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <tuple>
#include "take_a_brake.h"


double initial_speed_is_zero(){
    MockServiceBus bus{};
    AutoBrake ab{bus};
    return ab.get_speed_mps();
}

double initial_sensitivity_is_5(){
    MockServiceBus bus{};
    AutoBrake ab{bus};
    return ab.get_collision_threshold_s();
}

double speed_is_saved_between_events(double speed){
    MockServiceBus bus{};
    AutoBrake ab{bus};
    bus.speed_update_callback(SpeedUpdate{speed});
    return ab.get_speed_mps();
}

double sensitivity_cannot_be_lt_one(double sensitivity){
    MockServiceBus bus{};
    AutoBrake ab{bus};
    ab.set_collision_threshold_s(sensitivity);
    return ab.get_collision_threshold_s();
}

std::tuple<int, double> alert_when_collision_imminent(){
    MockServiceBus bus{};
    AutoBrake ab{bus};
    ab.set_collision_threshold_s(10L);
    bus.speed_update_callback(SpeedUpdate{100L});
    bus.car_detected_callback(CarDetected{100L, 0L});
    return {bus.commands_published, bus.last_command.time_to_collision_s};
}

int no_alert_when_collision_avoidable(){
    MockServiceBus bus{};
    AutoBrake ab{bus};
    ab.set_collision_threshold_s(2L);
    bus.speed_update_callback(SpeedUpdate{100L});
    bus.car_detected_callback(CarDetected{1000L, 50L});
    return bus.commands_published;
}

TEST_CASE("AutoBrake Test Group"){
    MockServiceBus bus{};
    AutoBrake ab{bus};

    SECTION("Initial speed is zero", "[configuration, speed]"){
        REQUIRE_THAT(initial_speed_is_zero(), Catch::Matchers::WithinAbs(0L, 0.1L));
        
    };

    SECTION("Initial collision threshold is 5", "[configuration, sensitivity]"){
        REQUIRE_THAT(initial_sensitivity_is_5(), Catch::Matchers::WithinAbs(5L, 0.2L));
    };

    SECTION("Speed is persisted internally between SpeedUpdate events", "[configuration, speed]"){
        REQUIRE_THAT(speed_is_saved_between_events(100L), Catch::Matchers::WithinAbs(100L, 0.5L));
        REQUIRE_THAT(speed_is_saved_between_events(50L), Catch::Matchers::WithinAbs(50L, 0.5L));
        REQUIRE_THAT(speed_is_saved_between_events(0L), Catch::Matchers::WithinAbs(0L, 0.5L));
    };

    SECTION("Collision sensitivity cannot be < 1", "[configuration, sensitivity]"){
        REQUIRE_THAT(sensitivity_cannot_be_lt_one(0.5L), Catch::Matchers::WithinAbs(1L, 0.1L));
        REQUIRE_THAT(sensitivity_cannot_be_lt_one(6L), Catch::Matchers::WithinAbs(6L, 0.1L));
    };

    SECTION("Alert generated when collision imminent", "[collision]"){
        auto [commands_published, time_to_collision_s] = alert_when_collision_imminent();
        REQUIRE(commands_published == 1);
        REQUIRE_THAT(time_to_collision_s, Catch::Matchers::WithinAbs(1L, 0.1L));
        // BENCHMARK("test"){
        //     return alert_when_collision_imminent();
        // };
    };

    SECTION("No alert for avoidable collision", "[collision]"){
        REQUIRE(no_alert_when_collision_avoidable() == 0);
    };
};

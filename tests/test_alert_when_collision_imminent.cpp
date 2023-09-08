#include "../take_a_brake.h"

int main(int argc, char const *argv[])
{
    MockServiceBus bus{};
    AutoBrake auto_brake{bus};
    auto_brake.set_collision_threshold_s(10L);
    bus.speed_update_callback(SpeedUpdate{100L});
    bus.car_detected_callback(CarDetected{100L, 0L});

    assert_that(bus.commands_published == 1, "brake command not published");
    assert_that(bus.last_command.time_to_collision_s == 1L, "time to collision not computed correctly");
}
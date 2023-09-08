#include "../take_a_brake.h"

int main(int argc, char const *argv[])
{
    MockServiceBus bus{};
    AutoBrake ab{bus};
    ab.set_collision_threshold_s(2L);
    bus.speed_update_callback(SpeedUpdate{100L});
    bus.car_detected_callback(CarDetected{1000L, 50L});
    assert_that(bus.commands_published == 0, "brake command published");
}
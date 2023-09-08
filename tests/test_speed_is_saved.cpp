#include "../take_a_brake.h"

int main(int argc, char const *argv[])
{
    MockServiceBus bus{};
    AutoBrake ab{bus};
    bus.speed_update_callback(SpeedUpdate{100L});
    assert_that(ab.get_speed_mps() == 100L, "speed not saved!");
    bus.speed_update_callback(SpeedUpdate{50L});
    assert_that(ab.get_speed_mps() == 50L, "speed not saved!");
    bus.speed_update_callback(SpeedUpdate{0L});
    assert_that(ab.get_speed_mps() == 0L, "speed not saved!");
}

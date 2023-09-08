#include "../take_a_brake.h"

int main(int argc, char const *argv[])
{
    MockServiceBus bus{};
    AutoBrake ab{bus};
    assert_that(ab.get_collision_threshold_s() == 5L, "Initial collision threshold not 5!");
}


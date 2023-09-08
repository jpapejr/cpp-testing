#include "../take_a_brake.h"

int main(int argc, char const *argv[])
{
    MockServiceBus bus{};
    AutoBrake ab{bus};
    ab.set_collision_threshold_s(0.5L);
    return 0;
}
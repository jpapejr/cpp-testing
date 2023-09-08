//
//  tests.cpp
//  cpp-test
//
//  Created by John Pape on 8 Sept 23.
//
#include "../take_a_brake.h"

int main(int argc, char const *argv[])
{
    MockServiceBus bus{};
    AutoBrake ab{bus};
    assert_that(ab.get_speed_mps() == 0L, "Initial speed not zero!");
}


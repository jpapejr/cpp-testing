//
//  take_a_brake.h
//  cpp-test
//
//  Created by John Pape on 09/06/23.
//

#ifndef take_a_brake_h
#define take_a_brake_h

#include <stdexcept>
#include <exception>
#include <iostream>

struct SpeedUpdate
{
    double velocity_mps;
};

struct CarDetected
{
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand
{
    double time_to_collision_s;
};

struct ServiceBus
{
    void publish(const BrakeCommand &);
};

template <typename T>
struct AutoBrake
{
    AutoBrake(const T &publish) : speed_mps{0}, collision_threshold_s{5}, publish{publish} {}
    void observe(const SpeedUpdate &x)
    {
        speed_mps = x.velocity_mps;
    }
    void observe(const CarDetected &cd)
    {
        const auto relative_velocity_mps = speed_mps - cd.velocity_mps;
        const auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
        if (time_to_collision_s > 0 &&  time_to_collision_s <= collision_threshold_s)
        {
            publish(BrakeCommand{time_to_collision_s});
        }
    }
    void set_collision_threshold_s(const double x)
    {
        if (x < 1)
            throw std::exception();
        collision_threshold_s = x;
    }
    double get_collision_threshold_s()
    {
        return collision_threshold_s;
    }
    double get_speed_mps()
    {
        return speed_mps;
    }

private:
    const T &publish;
    double collision_threshold_s;
    double speed_mps;
};

constexpr void assert_that(bool statement, const char *message)
{
    if (!statement)
        throw std::runtime_error{message};
}

// tests
void initial_speed_is_zero()
{
    AutoBrake auto_brake{
        [](const BrakeCommand &cmd) {}};
    assert_that(auto_brake.get_speed_mps() == 0L, "Initial speed not zero!");
}

void initial_sensitivity_is_five()
{
    AutoBrake auto_brake{
        [](const BrakeCommand &cmd) {}};
    assert_that(auto_brake.get_collision_threshold_s() == 5L, "Initial collision threshhold not 5!");
}

void sensitivity_less_than_1()
{
    AutoBrake auto_brake{
        [](const BrakeCommand &cmd) {}};
    try
    {
        auto_brake.set_collision_threshold_s(0.5L);
    }
    catch (const std::exception e)
    {
        return;
    }
    assert_that(false, "no exception thrown");
}

void speed_is_saved()
{
    AutoBrake auto_brake{
        [](const BrakeCommand &cmd) {}};
    auto_brake.observe(SpeedUpdate{100L});
    assert_that(auto_brake.get_speed_mps() == 100L, "speed not saved!");
    auto_brake.observe(SpeedUpdate{50L});
    assert_that(auto_brake.get_speed_mps() == 50L, "speed not saved!");
    auto_brake.observe(SpeedUpdate{0L});
    assert_that(auto_brake.get_speed_mps() == 0L, "speed not saved!");
}

void alert_when_collision_imminent()
{
    int brake_commands_published{};
    AutoBrake auto_brake{
        [&brake_commands_published](const BrakeCommand &cmd)
        {
            brake_commands_published++;
        }};
    auto_brake.set_collision_threshold_s(10L);
    auto_brake.observe(SpeedUpdate{100L});
    auto_brake.observe(CarDetected{100L, 0L});
    assert_that(brake_commands_published == 1, "brake command not published");
}

void no_alert_when_no_collision_imminent()
{
    int brake_commands_published{};
    AutoBrake auto_brake{
        [&brake_commands_published](const BrakeCommand &cmd)
        {
            brake_commands_published++;
        }};
    auto_brake.set_collision_threshold_s(2L);
    auto_brake.observe(SpeedUpdate{100L});
    auto_brake.observe(CarDetected{1000L, 50L});
    assert_that(brake_commands_published == 0, "brake command published");
}

// test harness
void run_test(void (*unit_test)(), const char *name)
{
    try
    {
        unit_test();
        std::cout << "[+] Test succcessfull! : " << name << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "[-] Test failed! : " << name << " -> " << e.what() << std::endl;
    }
}
#endif /* take_a_brake_h */
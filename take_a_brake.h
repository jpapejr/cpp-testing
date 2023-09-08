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
#include <functional>

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

struct IServiceBus {
    using SpeedUpdateCallBack = std::function<void(const SpeedUpdate&)>;
    using CarDetectedCallBack = std::function<void(const CarDetected&)>;

    virtual ~IServiceBus() = default;
    virtual void publish(const BrakeCommand&) = 0;
    virtual void subscribe(const SpeedUpdateCallBack) = 0;
    virtual void subscribe(const CarDetectedCallBack) = 0;
};

struct MockServiceBus : IServiceBus {
    BrakeCommand last_command{};
    int commands_published{};
    SpeedUpdateCallBack speed_update_callback{};
    CarDetectedCallBack car_detected_callback{}; 
    void publish(const BrakeCommand& cmd) override {
        commands_published++;
        last_command = cmd;
    }
    void subscribe(const SpeedUpdateCallBack sucb) override {
        speed_update_callback = sucb;
    }
    void subscribe(const CarDetectedCallBack cdcb) override {
        car_detected_callback = cdcb;
    }
};


struct AutoBrake
{
    AutoBrake(IServiceBus& bus) : speed_mps{0}, collision_threshold_s{5}  {
        bus.subscribe([this](const SpeedUpdate& update){
            speed_mps = update.velocity_mps;
        });

        bus.subscribe([this, &bus](const CarDetected& update){
            const auto relative_velocity_mps = speed_mps - update.velocity_mps;
            const auto time_to_collision_s = update.distance_m / relative_velocity_mps;
            if (time_to_collision_s > 0 && time_to_collision_s <= collision_threshold_s){
                bus.publish(BrakeCommand{time_to_collision_s});
            }
        });
    }
    // void observe(const SpeedUpdate &x)
    // {
    //     speed_mps = x.velocity_mps;
    // }
    // void observe(const CarDetected &cd)
    // {
    //     const auto relative_velocity_mps = speed_mps - cd.velocity_mps;
    //     const auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
    //     if (time_to_collision_s > 0 &&  time_to_collision_s <= collision_threshold_s)
    //     {
    //         bus.publish(BrakeCommand{time_to_collision_s});
    //     }
    // }
    void set_collision_threshold_s(const double x)
    {
        if (x < 1)
            collision_threshold_s = 1;
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
    double collision_threshold_s;
    double speed_mps;
};

constexpr void assert_that(bool statement, const char *message)
{
    if (!statement)
        throw std::runtime_error{message};
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
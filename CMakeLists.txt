cmake_minimum_required(VERSION 3.5.0)
project(cpp-testing VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)

include(CTest)
enable_testing()

cmake_policy(SET CMP0110 NEW )

add_executable(test_initial_speed_is_0 tests/test_initial_speed_is_0.cpp)
add_test(NAME "Initial speed is 0" COMMAND test_initial_speed_is_0)

add_executable(test_speed_is_saved tests/test_speed_is_saved.cpp)
add_test(NAME "Speed is saved between SpeedUpdate events" COMMAND test_speed_is_saved)

add_executable(test_initial_sensitivity_is_5 tests/test_initial_sensitivity_is_5.cpp)
add_test(NAME "Initial sensitivity is 5" COMMAND test_initial_sensitivity_is_5)

add_executable(test_sensitivity_cannot_be_lt_one tests/test_sensitivity_cannot_be_lt_one.cpp)
add_test(NAME "Sensitivity cannot be < 1" COMMAND test_sensitivity_cannot_be_lt_one)

add_executable(test_alert_when_collision_imminent tests/test_alert_when_collision_imminent.cpp)
add_test(NAME "Emit alert with collision imminent" COMMAND test_alert_when_collision_imminent)

add_executable(test_no_alert_when_no_collision_imminent tests/test_no_alert_when_no_collision_imminent.cpp)
add_test(NAME "No alert emitted when collision time above theshold" COMMAND test_no_alert_when_no_collision_imminent)



add_executable(cpp-testing main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

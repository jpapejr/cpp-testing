cmake_minimum_required(VERSION 3.5.0)
project(cpp-testing VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)

find_package(Catch2 3 REQUIRED)

include(CTest)
enable_testing()

cmake_policy(SET CMP0110 NEW )

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME "Catch2 Tests" COMMAND tests)


add_executable(cpp-testing main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

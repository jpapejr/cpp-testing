cmake_minimum_required(VERSION 3.5.0)
project(cpp-testing VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(VCPKG_ROOT /home/jtp.linux/vcpkg)
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

set(VCPKG_TARGET_TRIPLET x64-linux)
include_directories(${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/include)
link_directories(${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/lib)


set(Catch2_DIR ${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/share/catch2)
find_package(Catch2 CONFIG REQUIRED)
set(Boost_INCLUDE_DIR ${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}/include)
find_package(Boost REQUIRED)

include(CTest)
enable_testing()


add_executable(Tests tests.cpp)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

add_executable(Tests2 tests2.cpp)
target_link_libraries(Tests2 PRIVATE Catch2::Catch2WithMain)

add_test(NAME "Catch2" COMMAND Tests)
add_test(NAME "Smartpointer" COMMAND Tests2)
add_executable(cpp-testing main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

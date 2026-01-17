cmake_minimum_required(VERSION 3.10.3)

project(SignalHandling LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_executable(SignalHandling
    main.cpp
    signalHandler.cpp
)

target_include_directories(SignalHandling PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# GoogleTest integration
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    test_signalHandler
    tests/test_signalHandler.cpp
    signalHandler.cpp
)
target_include_directories(test_signalHandler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_signalHandler gtest_main)

include(GoogleTest)
gtest_discover_tests(test_signalHandler)
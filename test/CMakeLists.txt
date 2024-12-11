cmake_minimum_required(VERSION 3.26)
project(Tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(TESTS_SOURCE_FILES
        Competitions.cpp
        DefaultStrategies.cpp
        Parser.cpp
)


add_executable(Tests ${TESTS_SOURCE_FILES})

target_link_libraries(Tests Competitions)
target_link_libraries(Tests Strategies)
target_link_libraries(Tests Parser)

target_link_libraries(Tests gtest gtest_main)

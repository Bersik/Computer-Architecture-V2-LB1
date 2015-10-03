cmake_minimum_required(VERSION 3.3)
project(Lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_unit_test_framework")

FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(TestFiles lzw.cpp lzw.h main.cpp)
add_executable(Main ${TestFiles})

set(TestFiles lzw.cpp lzw.h tests.cpp)
add_executable(Tests ${TestFiles})

TARGET_LINK_LIBRARIES(Main ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES(Tests ${Boost_LIBRARIES})


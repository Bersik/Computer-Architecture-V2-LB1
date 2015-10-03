cmake_minimum_required(VERSION 3.3)
project(Lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_unit_test_framework")

FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(SOURCE_FILES main.cpp lzw.cpp lzw.h)
add_executable(Lab1 ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.28)

project(TheSun)

set(SOURCES src/main.cpp src/Objects.cpp)

include_directories(include)

add_executable(TheSun ${SOURCES})



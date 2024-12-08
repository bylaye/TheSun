cmake_minimum_required(VERSION 3.28)

project(TheSun)
find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)
set(SOURCES src/main.cpp src/Objects.cpp src/SystemMap.cpp)

include_directories(include)

add_executable(TheSun ${SOURCES})

target_link_libraries(TheSun sfml-graphics sfml-window sfml-system)

configure_file(assets/arial.ttf COPYONLY)

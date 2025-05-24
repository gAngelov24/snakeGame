cmake_minimum_required(VERSION 3.10)

project(SnakeGameGUI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

file(GLOB SOURCES
    src/*.cpp
    src/gui/*.cpp
)

add_executable(SnakeGameGUI ${SOURCES})

# Link SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(SnakeGameGUI sfml-graphics sfml-window sfml-system)
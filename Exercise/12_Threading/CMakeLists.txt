cmake_minimum_required(VERSION 3.25)
project(Exercise_12)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(Exercise_12 main.cpp)
target_link_libraries(Exercise_12 PRIVATE Threads::Threads)

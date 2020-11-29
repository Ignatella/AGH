cmake_minimum_required(VERSION 3.13)
project(Before_Lab C)

set(CMAKE_C_STANDARD 99)

add_executable(Before_Lab main.c)
add_executable(Ex1 Algorithms/Ex1.c)
add_executable(Ex2 Algorithms/Ex2.c)
add_executable(Ex3 Algorithms/Ex3.c)
add_executable(Ex4 Algorithms/Ex4.c)
add_executable(Ex5 Algorithms/Ex5.c)

target_link_libraries(Ex2 m)

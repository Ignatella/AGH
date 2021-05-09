cmake_minimum_required(VERSION 3.13)
project(Lab8 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab8 main.c)
target_link_libraries(Lab8 m)
add_executable(Ex1 Algorithms/Ex1.c)
add_executable(Ex2 Algorithms/Ex2.c)
target_link_libraries(Ex2 m)
add_executable(Ex3 Algorithms/Ex3.c)
add_executable(Ex4 Algorithms/Ex4.c)
add_executable(Ex5 Algorithms/Ex5.c)
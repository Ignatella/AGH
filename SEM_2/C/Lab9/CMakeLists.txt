cmake_minimum_required(VERSION 3.13)
project(Lab9 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab9 main.c)
add_executable(Ex1 Algorithms/Ex1.c)
target_link_libraries(Ex1 m)
add_executable(Ex2 Algorithms/Ex2.c)
add_executable(Ex3 Algorithms/Ex3.c)
add_executable(Ex5 Algorithms/Ex5.c)
target_link_libraries(Ex5 m)

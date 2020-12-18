cmake_minimum_required(VERSION 3.13)
project(RedBlackTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RedBlackTree main.c SharedLib/shared.h SharedLib/shared.c AddLib/add.h AddLib/add.c HelpersLib/helpers.h HelpersLib/helpers.c)

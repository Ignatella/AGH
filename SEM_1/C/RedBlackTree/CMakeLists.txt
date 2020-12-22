cmake_minimum_required(VERSION 3.13)
project(RedBlackTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RedBlackTree main.c
        SharedLib/shared.h SharedLib/shared.c
        AddLib/add.h AddLib/add.c
        AddLib/HelpersLib/addHelpers.h AddLib/HelpersLib/addHelpers.c
        DeleteLib/delete.h DeleteLib/delete.c
        DeleteLib/HelpersLib/deleteHelpers.h DeleteLib/HelpersLib/deleteHelpers.c)

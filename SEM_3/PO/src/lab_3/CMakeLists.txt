cmake_minimum_required(VERSION 3.13)

project("lab_3" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB sources "src/*.cpp" "include/*.hpp" "include/*.h")
add_executable(${PROJECT_NAME} ${sources})

target_include_directories(${PROJECT_NAME} PRIVATE "include")

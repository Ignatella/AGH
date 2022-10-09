cmake_minimum_required(VERSION 3.1.0)

project("lab__14" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_BUILD_TYPE Debug) #Release


add_definitions(-DEKSTRA=1)
file(GLOB sources "*.cpp" "src/*.cpp" "include/*.h")
add_executable(${PROJECT_NAME} ${sources})

target_include_directories(${PROJECT_NAME} PRIVATE "include")

add_custom_target(run ./${PROJECT_NAME})
add_custom_target(check valgrind ./${PROJECT_NAME})

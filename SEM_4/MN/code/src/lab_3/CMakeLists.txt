cmake_minimum_required(VERSION 3.1.0)

project("lab_3" LANGUAGES C)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_BUILD_TYPE Debug)


file(GLOB sources "*.c" "../helpers/*.h")
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} gsl gslcblas m)


cmake_minimum_required(VERSION 3.15)

project(lab_2 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_BUILD_TYPE "Debug")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)

FetchContent_Declare(
  sfml
  URL  https://github.com/SFML/SFML/archive/2.5.1.tar.gz
)

file(GLOB sources "src/*.cpp" "src/*.c")
add_executable(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE "include")

FetchContent_MakeAvailable(sfml)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-window)

configure_file("assets/TerminusTTF-4.40.1.ttf" ${CMAKE_BINARY_DIR} COPYONLY)
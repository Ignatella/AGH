cmake_minimum_required(VERSION 3.1.0)

project("lab_5_1" LANGUAGES C)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_BUILD_TYPE Debug)
set(ENV{currentProjectOutDir} ${CMAKE_SOURCE_DIR})

file(GLOB sources "*.c")
add_executable(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE "../../helpers")
target_link_libraries(${PROJECT_NAME} gsl gslcblas m)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/assets
                $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)

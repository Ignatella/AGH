# # cmake_minimum_required(VERSION 3.1.0)

# # project("lab_4" LANGUAGES CXX)
# # set(CMAKE_CXX_STANDARD 17)
# # set(CMAKE_CXX_STANDARD_REQUIRED ON)
# # set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
# # set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
# # set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
# # set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
# # set(CMAKE_BUILD_TYPE Debug) #Release

# # # add_definitions(-DBASIC=1)
# # add_definitions(-DADVANCE=1)


# # file(GLOB sources "*.cpp" "src/*.cpp" "include/*.hpp" "include/*.h")
# # add_executable(${PROJECT_NAME} ${sources})

# # target_include_directories(${PROJECT_NAME} PRIVATE "include")

# # add_custom_target(run ./${PROJECT_NAME})
# # add_custom_target(check valgrind ./${PROJECT_NAME})

# cmake_minimum_required(VERSION 3.1.0)
# project (lab_4)

# # prevent for in-source building
# set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
# set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
# if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
#   message(SEND_ERROR "In-source builds are not allowed.")
# endif ()

# #add_definitions(-DBASIC=1) # odkomentuj dla wersji BASIC
# add_definitions(-DADVANCE=1) # odkomentuj dla wersji ADVANCE

# set(CMAKE_BUILD_TYPE Debug) #Release
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
# set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

# set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
# include_directories(${INCLUDES})

# file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# add_library(Map STATIC ${SOURCES})

# add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
# target_link_libraries(${PROJECT_NAME} Map)

# # add_custom_target(run ./${PROJECT_NAME})
# # add_custom_target(check valgrind ./${PROJECT_NAME})

cmake_minimum_required(VERSION 3.24)
project(AccessPrivateMembers)

set(CMAKE_CXX_STANDARD 23)

FILE(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ./include/)

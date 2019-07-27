cmake_minimum_required(VERSION 2.7)

project(p3_g8) # Group 8

set(CMAKE_C_STANDARD 14)

set(CMAKE_C_FLAGS "-Wall -Werror -pedantic -Wextra -std=c++11")

find_package(OPENGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

add_executable(p3 main.cpp Vec.cpp shape.cpp figure.cpp ${SOURCES})
target_link_libraries(p3 ${GLUT_LIBRARY} ${OPENGL_LIBRARY})

add_executable(test test.cpp Vec.cpp)
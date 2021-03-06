cmake_minimum_required(VERSION 2.7)
project(p3_g8)

# Set the C++ Standard (you can use 98, 11, but 14 is recommended now)
set(CMAKE_CXX_STANDARD 14)

# Set the compiling flags (don't modify)
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

# Find the OpenGL library (don't modify)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Find the GLUT library (don't modify)
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

# Build Part 1 of the project (add all of related files)
add_executable(p3_part1 p3_part1.cpp parkingarea.h parkingarea.cpp normalvehicle.h normalvehicle.cpp)

# Build Part 2 of the project (add all of related files)
add_executable(p3 main.cpp Vec.cpp Vec.h Canvas.cpp Canvas.h figure.cpp figure.h shape.cpp shape.h parkinglot.cpp parkinglot.h)

# Link the OpenGL, GLUT and Maths library to your project (don't modify)
target_link_libraries(p3 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)

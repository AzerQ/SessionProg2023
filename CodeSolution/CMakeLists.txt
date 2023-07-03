cmake_minimum_required(VERSION 3.25)
project(CodeSolution)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(CodeSolution
        src/include/Lab1.h
        src/include/Lab2.h
        src/include/Lab3.h
        src/include/Lab4.h
        src/include/Lab5.h
        src/Lab1.cpp
        src/Lab2.cpp
        src/Lab3.cpp
        src/Lab4.cpp
        src/Lab5.cpp
        src/Main.cpp)

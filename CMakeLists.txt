cmake_minimum_required(VERSION 4.1)
project(brnfk)

set(CMAKE_CXX_STANDARD 20)

add_executable(brnfk src/main.cpp
        src/header.cpp
        header/header.h
        src/interpreter.cpp
        header/interpreter.h
        src/preprocessor.cpp
        header/preprocessor.h)

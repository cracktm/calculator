cmake_minimum_required(VERSION 3.0)

project(calculator)

set(SOURCE_EXE src/main.cpp src/ParserMathHandler.cpp)

add_executable(calculator ${SOURCE_EXE})
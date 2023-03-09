cmake_minimum_required(VERSION 3.0)

project("calculator")

add_compile_options(-std=c++17)

add_executable(example "src/main.cpp" "src/parser/parser.cpp" "src/exprHandler.cpp" "src/math.cpp")

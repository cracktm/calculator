cmake_minimum_required (VERSION 3.0)

project ("calculator")

add_compile_options(-std=c++20)

add_executable (example "src/parser.cpp" "src/parser.h" "src/main.cpp")

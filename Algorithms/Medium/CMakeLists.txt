cmake_minimum_required(VERSION 3.5)

project(Medium LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Solution longest_palindromic_substring.cpp
    main.cpp
    longest_substring_without_repeating_characters.cpp
    problems.hpp
    smallest_chair.cpp
    set_matrix_zeros.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra -pedantic")

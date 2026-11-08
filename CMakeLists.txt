cmake_minimum_required(VERSION 3.5)

project(LeetCodeSolutions LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -pedantic")

set(SANITIZER_MODE "UBSAN" CACHE STRING "Choose sanitizer: NONE, UBSAN, MSAN")
if(SANITIZER_MODE STREQUAL "UBSAN")
    message(STATUS "Building with UndefinedBehaviorSanitizer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fno-omit-frame-pointer -g")
    
elseif(SANITIZER_MODE STREQUAL "MSAN")
    message(STATUS "Building with MemorySanitizer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory -fsanitize-memory-track-origins -fno-omit-frame-pointer -g")
endif()

file(GLOB_RECURSE TASK_FILES "*.cpp")
foreach(FILE_PATH ${TASK_FILES})
    # get only file name before . for example "remove-element"
    get_filename_component(TARGET_NAME ${FILE_PATH} NAME_WE)
    add_executable(${TARGET_NAME} ${FILE_PATH})
endforeach()

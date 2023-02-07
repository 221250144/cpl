cmake_minimum_required(VERSION 3.23)
project(untitled4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(hhh hhh.c)
add_executable(xxx xxx.cpp)

add_subdirectory(cpl_homework)

add_subdirectory(leetcode)
add_subdirectory(suanfa)
add_subdirectory(jiji)

add_subdirectory(LuoGu)
add_subdirectory(contest)
add_subdirectory(ECNU)
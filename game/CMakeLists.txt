cmake_minimum_required(VERSION 3.13)
project(game)

set(CMAKE_CXX_STANDARD 11)

add_executable(game main.cpp Matrix.cpp Matrix.h suppplements.cpp supplements.h Player.cpp Player.h)
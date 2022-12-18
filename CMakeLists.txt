cmake_minimum_required(VERSION 3.14)

project(ugit-cpp LANGUAGES CXX)

file(GLOB source_files "*.cpp")

add_library(solution STATIC ${source_files})

cmake_minimum_required(VERSION 3.19)

add_library(twtProcessing
    DataProcessing.hpp
    DataProcessing.cpp
)

target_include_directories(twtProcessing PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
cmake_minimum_required(VERSION 3.19)

add_library(twtProcessing
    DataProcessing.hpp
    DataProcessing.cpp
)

add_subdirectory(twitcurl/libtwitcurl)
target_include_directories(twtProcessing PUBLIC "${PROJECT_SOURCE_DIR}/Src")
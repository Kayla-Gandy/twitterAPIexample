cmake_minimum_required(VERSION 3.19)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(twitter-API-proj DataProcessingTest.cpp)
target_link_libraries(twitter-API-proj PRIVATE twtProcessing)

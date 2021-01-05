cmake_minimum_required(VERSION 3.19)

add_executable(twitter-API-proj DataProcessingTest.cpp)

target_link_libraries(twitter-API-proj PRIVATE twtProcessing)
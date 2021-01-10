cmake_minimum_required(VERSION 3.19)
project(TwitterAPIProj VERSION 1.0)

include_directories(TwitterAPIProj PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/Src")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Src/twitcurl/libtwitcurl)
include_directories(twitCurl PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Src/twitcurl/libtwitcurl")

add_subdirectory(Src/JSONparsing)
include_directories(nlohmann_json PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Src/JSONparsing/single_include")

add_subdirectory(Src)
add_subdirectory(Test)
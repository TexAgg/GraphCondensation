CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)
project(csce221_a6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    221A6/Edge.cpp
    221A6/Edge.h
    221A6/Graph.cpp
    221A6/Graph.h
    221A6/Main.cpp
    221A6/Vertex.cpp
    221A6/Vertex.h)

add_executable(csce221_a6 ${SOURCE_FILES})
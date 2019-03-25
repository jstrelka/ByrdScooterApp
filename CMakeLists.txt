cmake_minimum_required(VERSION 3.13)
project(BirdApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BirdApp
        BinNode.h
        BinTree.h
        Bird.cpp
        Bird.h
        BirdApp.cpp
        DateTime.cpp
        DateTime.h
        Field.cpp
        Field.h
        my_rides.csv)

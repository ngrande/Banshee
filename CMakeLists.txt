cmake_minimum_required(VERSION 3.5.2 FATAL_ERROR)
project(Banshee)

# The version number
SET(Banshee_VERSION_MAJOR 0)
SET(Banshee_VERSION_MINOR_1)

SET(CMAKE_CXX_COMPILER "g++") # or gcc
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -Wall") # -g
# INCLUDE_DIRECTORIES(dir)

SET(SOURCE_FILES main.cpp Memory/MemoryPool.cpp Memory/MemoryPool.h
                      Bus/MessageBus.cpp Bus/MessageBus.h
                      TMP/Helper.hpp)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/Bin/Release")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/Bin/Debug")
ADD_EXECUTABLE(Banshee ${SOURCE_FILES})

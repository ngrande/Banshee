cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(Banshee)

# The version number
SET(Banshee_VERSION_MAJOR 0)
SET(Banshee_VERSION_MINOR_1)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++") # or gcc
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -m64") # -g
# INCLUDE_DIRECTORIES(Memory)
# INCLUDE_DIRECTORIES(Bus)

SET(SOURCE_FILES main.cpp Memory/MemoryPool.cpp Memory/MemoryPool.h
                          Bus/MessageBus.cpp Bus/MessageBus.h)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Bin")
ADD_EXECUTABLE(Banshee ${SOURCE_FILES})

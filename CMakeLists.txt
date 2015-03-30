cmake_minimum_required(VERSION 2.4)

project(Shooter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lSDL -lGL -lGLU")

file(GLOB_RECURSE SOURCE_FILES
	src/*.cpp src/*.h
)

add_executable(Tetris3d ${SOURCE_FILES})

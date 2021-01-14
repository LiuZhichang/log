cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET(CMAKE_CXX_STANDARD 17)

project(main)

SET(TSRC 
	../formatter.cpp
	../event.cpp
	../util.cpp
)

add_executable(${PROJECT_NAME} ./main.cpp ${TSRC})

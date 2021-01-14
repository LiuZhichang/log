cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET(CMAKE_CXX_STANDARD 17)

project(main)

SET(TSRC 
	../util.cpp
	../event.cpp
	../formatter.cpp
	../appender.cpp
	../logger.cpp
)

add_executable(${PROJECT_NAME} ./pares.cpp ${TSRC})

cmake_minimum_required(VERSION 3.2)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build)
SET(CMAKE_CXX_STANDARD 17)


SET(TSRC 
	../util.cpp
	../event.cpp
	../formatter.cpp
	../appender.cpp
	../logger.cpp
)

project(examplelog)
add_executable(${PROJECT_NAME} ./examplelog.cpp ${TSRC})

project(examplelog1)
add_executable(${PROJECT_NAME} ./examplelog1.cpp ${TSRC})
target_link_libraries(${PROJECT_NAME} pthread)

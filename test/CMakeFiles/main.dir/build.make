# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /lzc/my/Log/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /lzc/my/Log/test

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/pares.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/pares.cpp.o: pares.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/pares.cpp.o"
	/usr/local/share/gcc-10.2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/pares.cpp.o -c /lzc/my/Log/test/pares.cpp

CMakeFiles/main.dir/pares.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/pares.cpp.i"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lzc/my/Log/test/pares.cpp > CMakeFiles/main.dir/pares.cpp.i

CMakeFiles/main.dir/pares.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/pares.cpp.s"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lzc/my/Log/test/pares.cpp -o CMakeFiles/main.dir/pares.cpp.s

CMakeFiles/main.dir/lzc/my/Log/util.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lzc/my/Log/util.cpp.o: /lzc/my/Log/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/lzc/my/Log/util.cpp.o"
	/usr/local/share/gcc-10.2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/lzc/my/Log/util.cpp.o -c /lzc/my/Log/util.cpp

CMakeFiles/main.dir/lzc/my/Log/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/lzc/my/Log/util.cpp.i"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lzc/my/Log/util.cpp > CMakeFiles/main.dir/lzc/my/Log/util.cpp.i

CMakeFiles/main.dir/lzc/my/Log/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/lzc/my/Log/util.cpp.s"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lzc/my/Log/util.cpp -o CMakeFiles/main.dir/lzc/my/Log/util.cpp.s

CMakeFiles/main.dir/lzc/my/Log/event.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lzc/my/Log/event.cpp.o: /lzc/my/Log/event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/lzc/my/Log/event.cpp.o"
	/usr/local/share/gcc-10.2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/lzc/my/Log/event.cpp.o -c /lzc/my/Log/event.cpp

CMakeFiles/main.dir/lzc/my/Log/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/lzc/my/Log/event.cpp.i"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lzc/my/Log/event.cpp > CMakeFiles/main.dir/lzc/my/Log/event.cpp.i

CMakeFiles/main.dir/lzc/my/Log/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/lzc/my/Log/event.cpp.s"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lzc/my/Log/event.cpp -o CMakeFiles/main.dir/lzc/my/Log/event.cpp.s

CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.o: /lzc/my/Log/formatter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.o"
	/usr/local/share/gcc-10.2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.o -c /lzc/my/Log/formatter.cpp

CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.i"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lzc/my/Log/formatter.cpp > CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.i

CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.s"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lzc/my/Log/formatter.cpp -o CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.s

CMakeFiles/main.dir/lzc/my/Log/appender.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lzc/my/Log/appender.cpp.o: /lzc/my/Log/appender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/lzc/my/Log/appender.cpp.o"
	/usr/local/share/gcc-10.2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/lzc/my/Log/appender.cpp.o -c /lzc/my/Log/appender.cpp

CMakeFiles/main.dir/lzc/my/Log/appender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/lzc/my/Log/appender.cpp.i"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lzc/my/Log/appender.cpp > CMakeFiles/main.dir/lzc/my/Log/appender.cpp.i

CMakeFiles/main.dir/lzc/my/Log/appender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/lzc/my/Log/appender.cpp.s"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lzc/my/Log/appender.cpp -o CMakeFiles/main.dir/lzc/my/Log/appender.cpp.s

CMakeFiles/main.dir/lzc/my/Log/logger.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lzc/my/Log/logger.cpp.o: /lzc/my/Log/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/lzc/my/Log/logger.cpp.o"
	/usr/local/share/gcc-10.2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/lzc/my/Log/logger.cpp.o -c /lzc/my/Log/logger.cpp

CMakeFiles/main.dir/lzc/my/Log/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/lzc/my/Log/logger.cpp.i"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /lzc/my/Log/logger.cpp > CMakeFiles/main.dir/lzc/my/Log/logger.cpp.i

CMakeFiles/main.dir/lzc/my/Log/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/lzc/my/Log/logger.cpp.s"
	/usr/local/share/gcc-10.2/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /lzc/my/Log/logger.cpp -o CMakeFiles/main.dir/lzc/my/Log/logger.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/pares.cpp.o" \
"CMakeFiles/main.dir/lzc/my/Log/util.cpp.o" \
"CMakeFiles/main.dir/lzc/my/Log/event.cpp.o" \
"CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.o" \
"CMakeFiles/main.dir/lzc/my/Log/appender.cpp.o" \
"CMakeFiles/main.dir/lzc/my/Log/logger.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/pares.cpp.o
main: CMakeFiles/main.dir/lzc/my/Log/util.cpp.o
main: CMakeFiles/main.dir/lzc/my/Log/event.cpp.o
main: CMakeFiles/main.dir/lzc/my/Log/formatter.cpp.o
main: CMakeFiles/main.dir/lzc/my/Log/appender.cpp.o
main: CMakeFiles/main.dir/lzc/my/Log/logger.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/lzc/my/Log/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /lzc/my/Log/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /lzc/my/Log/test /lzc/my/Log/test /lzc/my/Log/test /lzc/my/Log/test /lzc/my/Log/test/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend


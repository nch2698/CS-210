# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danielng/Projects/CS-210/Project5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danielng/Projects/CS-210/Project5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PC_5_6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PC_5_6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PC_5_6.dir/flags.make

CMakeFiles/PC_5_6.dir/pc_5_6.cpp.o: CMakeFiles/PC_5_6.dir/flags.make
CMakeFiles/PC_5_6.dir/pc_5_6.cpp.o: ../pc_5_6.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danielng/Projects/CS-210/Project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PC_5_6.dir/pc_5_6.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PC_5_6.dir/pc_5_6.cpp.o -c /home/danielng/Projects/CS-210/Project5/pc_5_6.cpp

CMakeFiles/PC_5_6.dir/pc_5_6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PC_5_6.dir/pc_5_6.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danielng/Projects/CS-210/Project5/pc_5_6.cpp > CMakeFiles/PC_5_6.dir/pc_5_6.cpp.i

CMakeFiles/PC_5_6.dir/pc_5_6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PC_5_6.dir/pc_5_6.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danielng/Projects/CS-210/Project5/pc_5_6.cpp -o CMakeFiles/PC_5_6.dir/pc_5_6.cpp.s

# Object files for target PC_5_6
PC_5_6_OBJECTS = \
"CMakeFiles/PC_5_6.dir/pc_5_6.cpp.o"

# External object files for target PC_5_6
PC_5_6_EXTERNAL_OBJECTS =

PC_5_6: CMakeFiles/PC_5_6.dir/pc_5_6.cpp.o
PC_5_6: CMakeFiles/PC_5_6.dir/build.make
PC_5_6: CMakeFiles/PC_5_6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danielng/Projects/CS-210/Project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PC_5_6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PC_5_6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PC_5_6.dir/build: PC_5_6

.PHONY : CMakeFiles/PC_5_6.dir/build

CMakeFiles/PC_5_6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PC_5_6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PC_5_6.dir/clean

CMakeFiles/PC_5_6.dir/depend:
	cd /home/danielng/Projects/CS-210/Project5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danielng/Projects/CS-210/Project5 /home/danielng/Projects/CS-210/Project5 /home/danielng/Projects/CS-210/Project5/cmake-build-debug /home/danielng/Projects/CS-210/Project5/cmake-build-debug /home/danielng/Projects/CS-210/Project5/cmake-build-debug/CMakeFiles/PC_5_6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PC_5_6.dir/depend


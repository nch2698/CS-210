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
include CMakeFiles/SQRT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SQRT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SQRT.dir/flags.make

CMakeFiles/SQRT.dir/sqrt.cpp.o: CMakeFiles/SQRT.dir/flags.make
CMakeFiles/SQRT.dir/sqrt.cpp.o: ../sqrt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danielng/Projects/CS-210/Project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SQRT.dir/sqrt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SQRT.dir/sqrt.cpp.o -c /home/danielng/Projects/CS-210/Project5/sqrt.cpp

CMakeFiles/SQRT.dir/sqrt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SQRT.dir/sqrt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danielng/Projects/CS-210/Project5/sqrt.cpp > CMakeFiles/SQRT.dir/sqrt.cpp.i

CMakeFiles/SQRT.dir/sqrt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SQRT.dir/sqrt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danielng/Projects/CS-210/Project5/sqrt.cpp -o CMakeFiles/SQRT.dir/sqrt.cpp.s

# Object files for target SQRT
SQRT_OBJECTS = \
"CMakeFiles/SQRT.dir/sqrt.cpp.o"

# External object files for target SQRT
SQRT_EXTERNAL_OBJECTS =

SQRT: CMakeFiles/SQRT.dir/sqrt.cpp.o
SQRT: CMakeFiles/SQRT.dir/build.make
SQRT: CMakeFiles/SQRT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danielng/Projects/CS-210/Project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SQRT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SQRT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SQRT.dir/build: SQRT

.PHONY : CMakeFiles/SQRT.dir/build

CMakeFiles/SQRT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SQRT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SQRT.dir/clean

CMakeFiles/SQRT.dir/depend:
	cd /home/danielng/Projects/CS-210/Project5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danielng/Projects/CS-210/Project5 /home/danielng/Projects/CS-210/Project5 /home/danielng/Projects/CS-210/Project5/cmake-build-debug /home/danielng/Projects/CS-210/Project5/cmake-build-debug /home/danielng/Projects/CS-210/Project5/cmake-build-debug/CMakeFiles/SQRT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SQRT.dir/depend


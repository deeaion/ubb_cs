# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3"

# Include any dependencies generated for this target.
include CMakeFiles/Server3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Server3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Server3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server3.dir/flags.make

CMakeFiles/Server3.dir/main.c.o: CMakeFiles/Server3.dir/flags.make
CMakeFiles/Server3.dir/main.c.o: ../main.c
CMakeFiles/Server3.dir/main.c.o: CMakeFiles/Server3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Server3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Server3.dir/main.c.o -MF CMakeFiles/Server3.dir/main.c.o.d -o CMakeFiles/Server3.dir/main.c.o -c "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/main.c"

CMakeFiles/Server3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/main.c" > CMakeFiles/Server3.dir/main.c.i

CMakeFiles/Server3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/main.c" -o CMakeFiles/Server3.dir/main.c.s

# Object files for target Server3
Server3_OBJECTS = \
"CMakeFiles/Server3.dir/main.c.o"

# External object files for target Server3
Server3_EXTERNAL_OBJECTS =

Server3: CMakeFiles/Server3.dir/main.c.o
Server3: CMakeFiles/Server3.dir/build.make
Server3: CMakeFiles/Server3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Server3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server3.dir/build: Server3
.PHONY : CMakeFiles/Server3.dir/build

CMakeFiles/Server3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server3.dir/clean

CMakeFiles/Server3.dir/depend:
	cd "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/3/Server3/cmake-build-s3/CMakeFiles/Server3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Server3.dir/depend

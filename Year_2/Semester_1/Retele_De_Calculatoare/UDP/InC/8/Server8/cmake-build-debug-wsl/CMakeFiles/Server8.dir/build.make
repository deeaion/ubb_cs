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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl"

# Include any dependencies generated for this target.
include CMakeFiles/Server8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Server8.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Server8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server8.dir/flags.make

CMakeFiles/Server8.dir/main.c.o: CMakeFiles/Server8.dir/flags.make
CMakeFiles/Server8.dir/main.c.o: ../main.c
CMakeFiles/Server8.dir/main.c.o: CMakeFiles/Server8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Server8.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Server8.dir/main.c.o -MF CMakeFiles/Server8.dir/main.c.o.d -o CMakeFiles/Server8.dir/main.c.o -c "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/main.c"

CMakeFiles/Server8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Server8.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/main.c" > CMakeFiles/Server8.dir/main.c.i

CMakeFiles/Server8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Server8.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/main.c" -o CMakeFiles/Server8.dir/main.c.s

# Object files for target Server8
Server8_OBJECTS = \
"CMakeFiles/Server8.dir/main.c.o"

# External object files for target Server8
Server8_EXTERNAL_OBJECTS =

Server8: CMakeFiles/Server8.dir/main.c.o
Server8: CMakeFiles/Server8.dir/build.make
Server8: CMakeFiles/Server8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Server8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server8.dir/build: Server8
.PHONY : CMakeFiles/Server8.dir/build

CMakeFiles/Server8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server8.dir/clean

CMakeFiles/Server8.dir/depend:
	cd "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl" "/mnt/c/Users/Deea/Desktop/Uni/Second year/Semester 1/Computer networks/Labs/UDP/InC/8/Server8/cmake-build-debug-wsl/CMakeFiles/Server8.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Server8.dir/depend


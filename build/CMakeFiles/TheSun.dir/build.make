# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/aniang/TheSun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aniang/TheSun/build

# Include any dependencies generated for this target.
include CMakeFiles/TheSun.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TheSun.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TheSun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TheSun.dir/flags.make

CMakeFiles/TheSun.dir/src/main.cpp.o: CMakeFiles/TheSun.dir/flags.make
CMakeFiles/TheSun.dir/src/main.cpp.o: /home/aniang/TheSun/src/main.cpp
CMakeFiles/TheSun.dir/src/main.cpp.o: CMakeFiles/TheSun.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aniang/TheSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TheSun.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TheSun.dir/src/main.cpp.o -MF CMakeFiles/TheSun.dir/src/main.cpp.o.d -o CMakeFiles/TheSun.dir/src/main.cpp.o -c /home/aniang/TheSun/src/main.cpp

CMakeFiles/TheSun.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TheSun.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aniang/TheSun/src/main.cpp > CMakeFiles/TheSun.dir/src/main.cpp.i

CMakeFiles/TheSun.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TheSun.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aniang/TheSun/src/main.cpp -o CMakeFiles/TheSun.dir/src/main.cpp.s

CMakeFiles/TheSun.dir/src/Objects.cpp.o: CMakeFiles/TheSun.dir/flags.make
CMakeFiles/TheSun.dir/src/Objects.cpp.o: /home/aniang/TheSun/src/Objects.cpp
CMakeFiles/TheSun.dir/src/Objects.cpp.o: CMakeFiles/TheSun.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aniang/TheSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TheSun.dir/src/Objects.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TheSun.dir/src/Objects.cpp.o -MF CMakeFiles/TheSun.dir/src/Objects.cpp.o.d -o CMakeFiles/TheSun.dir/src/Objects.cpp.o -c /home/aniang/TheSun/src/Objects.cpp

CMakeFiles/TheSun.dir/src/Objects.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TheSun.dir/src/Objects.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aniang/TheSun/src/Objects.cpp > CMakeFiles/TheSun.dir/src/Objects.cpp.i

CMakeFiles/TheSun.dir/src/Objects.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TheSun.dir/src/Objects.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aniang/TheSun/src/Objects.cpp -o CMakeFiles/TheSun.dir/src/Objects.cpp.s

# Object files for target TheSun
TheSun_OBJECTS = \
"CMakeFiles/TheSun.dir/src/main.cpp.o" \
"CMakeFiles/TheSun.dir/src/Objects.cpp.o"

# External object files for target TheSun
TheSun_EXTERNAL_OBJECTS =

TheSun: CMakeFiles/TheSun.dir/src/main.cpp.o
TheSun: CMakeFiles/TheSun.dir/src/Objects.cpp.o
TheSun: CMakeFiles/TheSun.dir/build.make
TheSun: CMakeFiles/TheSun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/aniang/TheSun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TheSun"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TheSun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TheSun.dir/build: TheSun
.PHONY : CMakeFiles/TheSun.dir/build

CMakeFiles/TheSun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TheSun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TheSun.dir/clean

CMakeFiles/TheSun.dir/depend:
	cd /home/aniang/TheSun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aniang/TheSun /home/aniang/TheSun /home/aniang/TheSun/build /home/aniang/TheSun/build /home/aniang/TheSun/build/CMakeFiles/TheSun.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TheSun.dir/depend


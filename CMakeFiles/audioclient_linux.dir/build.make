# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32"

# Include any dependencies generated for this target.
include CMakeFiles/audioclient_linux.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/audioclient_linux.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/audioclient_linux.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/audioclient_linux.dir/flags.make

CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o: CMakeFiles/audioclient_linux.dir/flags.make
CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o: linux/portaudio_impl3_linux.cpp
CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o: CMakeFiles/audioclient_linux.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o -MF CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o.d -o CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o -c "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32/linux/portaudio_impl3_linux.cpp"

CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32/linux/portaudio_impl3_linux.cpp" > CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.i

CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32/linux/portaudio_impl3_linux.cpp" -o CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.s

# Object files for target audioclient_linux
audioclient_linux_OBJECTS = \
"CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o"

# External object files for target audioclient_linux
audioclient_linux_EXTERNAL_OBJECTS =

audioclient_linux: CMakeFiles/audioclient_linux.dir/linux/portaudio_impl3_linux.cpp.o
audioclient_linux: CMakeFiles/audioclient_linux.dir/build.make
audioclient_linux: CMakeFiles/audioclient_linux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable audioclient_linux"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/audioclient_linux.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/audioclient_linux.dir/build: audioclient_linux
.PHONY : CMakeFiles/audioclient_linux.dir/build

CMakeFiles/audioclient_linux.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/audioclient_linux.dir/cmake_clean.cmake
.PHONY : CMakeFiles/audioclient_linux.dir/clean

CMakeFiles/audioclient_linux.dir/depend:
	cd "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32" "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32" "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32" "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32" "/home/diogorroessler/dev/CXX Projects/linux/audioclient_win32/CMakeFiles/audioclient_linux.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/audioclient_linux.dir/depend

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
CMAKE_SOURCE_DIR = /home/jontz/Documents/Git/BWT-Semb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jontz/Documents/Git/BWT-Semb

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/FileManager/file_manager.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/FileManager/file_manager.c.o: FileManager/file_manager.c
CMakeFiles/app.dir/FileManager/file_manager.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jontz/Documents/Git/BWT-Semb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app.dir/FileManager/file_manager.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/FileManager/file_manager.c.o -MF CMakeFiles/app.dir/FileManager/file_manager.c.o.d -o CMakeFiles/app.dir/FileManager/file_manager.c.o -c /home/jontz/Documents/Git/BWT-Semb/FileManager/file_manager.c

CMakeFiles/app.dir/FileManager/file_manager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/FileManager/file_manager.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jontz/Documents/Git/BWT-Semb/FileManager/file_manager.c > CMakeFiles/app.dir/FileManager/file_manager.c.i

CMakeFiles/app.dir/FileManager/file_manager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/FileManager/file_manager.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jontz/Documents/Git/BWT-Semb/FileManager/file_manager.c -o CMakeFiles/app.dir/FileManager/file_manager.c.s

CMakeFiles/app.dir/ApplicationArgs/app_args.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/ApplicationArgs/app_args.c.o: ApplicationArgs/app_args.c
CMakeFiles/app.dir/ApplicationArgs/app_args.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jontz/Documents/Git/BWT-Semb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/app.dir/ApplicationArgs/app_args.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/ApplicationArgs/app_args.c.o -MF CMakeFiles/app.dir/ApplicationArgs/app_args.c.o.d -o CMakeFiles/app.dir/ApplicationArgs/app_args.c.o -c /home/jontz/Documents/Git/BWT-Semb/ApplicationArgs/app_args.c

CMakeFiles/app.dir/ApplicationArgs/app_args.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/ApplicationArgs/app_args.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jontz/Documents/Git/BWT-Semb/ApplicationArgs/app_args.c > CMakeFiles/app.dir/ApplicationArgs/app_args.c.i

CMakeFiles/app.dir/ApplicationArgs/app_args.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/ApplicationArgs/app_args.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jontz/Documents/Git/BWT-Semb/ApplicationArgs/app_args.c -o CMakeFiles/app.dir/ApplicationArgs/app_args.c.s

CMakeFiles/app.dir/main.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/main.c.o: main.c
CMakeFiles/app.dir/main.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jontz/Documents/Git/BWT-Semb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/app.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/main.c.o -MF CMakeFiles/app.dir/main.c.o.d -o CMakeFiles/app.dir/main.c.o -c /home/jontz/Documents/Git/BWT-Semb/main.c

CMakeFiles/app.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jontz/Documents/Git/BWT-Semb/main.c > CMakeFiles/app.dir/main.c.i

CMakeFiles/app.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jontz/Documents/Git/BWT-Semb/main.c -o CMakeFiles/app.dir/main.c.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/FileManager/file_manager.c.o" \
"CMakeFiles/app.dir/ApplicationArgs/app_args.c.o" \
"CMakeFiles/app.dir/main.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/FileManager/file_manager.c.o
app: CMakeFiles/app.dir/ApplicationArgs/app_args.c.o
app: CMakeFiles/app.dir/main.c.o
app: CMakeFiles/app.dir/build.make
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jontz/Documents/Git/BWT-Semb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/jontz/Documents/Git/BWT-Semb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jontz/Documents/Git/BWT-Semb /home/jontz/Documents/Git/BWT-Semb /home/jontz/Documents/Git/BWT-Semb /home/jontz/Documents/Git/BWT-Semb /home/jontz/Documents/Git/BWT-Semb/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend


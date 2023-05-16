# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/castro/BWT-Semb/BWT-Semb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/castro/BWT-Semb/BWT-Semb

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/castro/BWT-Semb/BWT-Semb/CMakeFiles /home/castro/BWT-Semb/BWT-Semb//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/castro/BWT-Semb/BWT-Semb/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named bwt

# Build rule for target.
bwt: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 bwt
.PHONY : bwt

# fast build rule for target.
bwt/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/build
.PHONY : bwt/fast

ApplicationArgs/app_args.o: ApplicationArgs/app_args.c.o
.PHONY : ApplicationArgs/app_args.o

# target to build an object file
ApplicationArgs/app_args.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/ApplicationArgs/app_args.c.o
.PHONY : ApplicationArgs/app_args.c.o

ApplicationArgs/app_args.i: ApplicationArgs/app_args.c.i
.PHONY : ApplicationArgs/app_args.i

# target to preprocess a source file
ApplicationArgs/app_args.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/ApplicationArgs/app_args.c.i
.PHONY : ApplicationArgs/app_args.c.i

ApplicationArgs/app_args.s: ApplicationArgs/app_args.c.s
.PHONY : ApplicationArgs/app_args.s

# target to generate assembly for a file
ApplicationArgs/app_args.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/ApplicationArgs/app_args.c.s
.PHONY : ApplicationArgs/app_args.c.s

FileManager/file_manager.o: FileManager/file_manager.c.o
.PHONY : FileManager/file_manager.o

# target to build an object file
FileManager/file_manager.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/FileManager/file_manager.c.o
.PHONY : FileManager/file_manager.c.o

FileManager/file_manager.i: FileManager/file_manager.c.i
.PHONY : FileManager/file_manager.i

# target to preprocess a source file
FileManager/file_manager.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/FileManager/file_manager.c.i
.PHONY : FileManager/file_manager.c.i

FileManager/file_manager.s: FileManager/file_manager.c.s
.PHONY : FileManager/file_manager.s

# target to generate assembly for a file
FileManager/file_manager.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/FileManager/file_manager.c.s
.PHONY : FileManager/file_manager.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/bwt.dir/build.make CMakeFiles/bwt.dir/main.c.s
.PHONY : main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... bwt"
	@echo "... ApplicationArgs/app_args.o"
	@echo "... ApplicationArgs/app_args.i"
	@echo "... ApplicationArgs/app_args.s"
	@echo "... FileManager/file_manager.o"
	@echo "... FileManager/file_manager.i"
	@echo "... FileManager/file_manager.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


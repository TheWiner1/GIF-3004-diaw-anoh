# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build

# Include any dependencies generated for this target.
include CMakeFiles/SETR_LABO5_SERVEUR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SETR_LABO5_SERVEUR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SETR_LABO5_SERVEUR.dir/flags.make

CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.o: CMakeFiles/SETR_LABO5_SERVEUR.dir/flags.make
CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.o: ../serveur.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.o"
	/home/setr/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/bin/arm-raspbian-linux-gnueabihf-gcc --sysroot=/home/setr/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/arm-raspbian-linux-gnueabihf/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.o   -c /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/serveur.c

CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.i"
	/home/setr/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/bin/arm-raspbian-linux-gnueabihf-gcc --sysroot=/home/setr/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/arm-raspbian-linux-gnueabihf/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/serveur.c > CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.i

CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.s"
	/home/setr/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/bin/arm-raspbian-linux-gnueabihf-gcc --sysroot=/home/setr/arm-cross-comp-env/arm-raspbian-linux-gnueabihf/arm-raspbian-linux-gnueabihf/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/serveur.c -o CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.s

# Object files for target SETR_LABO5_SERVEUR
SETR_LABO5_SERVEUR_OBJECTS = \
"CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.o"

# External object files for target SETR_LABO5_SERVEUR
SETR_LABO5_SERVEUR_EXTERNAL_OBJECTS =

SETR_LABO5_SERVEUR: CMakeFiles/SETR_LABO5_SERVEUR.dir/serveur.c.o
SETR_LABO5_SERVEUR: CMakeFiles/SETR_LABO5_SERVEUR.dir/build.make
SETR_LABO5_SERVEUR: CMakeFiles/SETR_LABO5_SERVEUR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SETR_LABO5_SERVEUR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SETR_LABO5_SERVEUR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SETR_LABO5_SERVEUR.dir/build: SETR_LABO5_SERVEUR

.PHONY : CMakeFiles/SETR_LABO5_SERVEUR.dir/build

CMakeFiles/SETR_LABO5_SERVEUR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SETR_LABO5_SERVEUR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SETR_LABO5_SERVEUR.dir/clean

CMakeFiles/SETR_LABO5_SERVEUR.dir/depend:
	cd /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build /home/setr/projects/GIF-3004-diaw-anoh/laboratoire5/serveur/build/CMakeFiles/SETR_LABO5_SERVEUR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SETR_LABO5_SERVEUR.dir/depend


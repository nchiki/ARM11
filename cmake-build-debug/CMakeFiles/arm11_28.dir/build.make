# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/nb1317/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/nb1317/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nb1317/arm11_28

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nb1317/arm11_28/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/arm11_28.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arm11_28.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arm11_28.dir/flags.make

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o: ../src/emulate_utils/instructions/branch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/instructions/branch.c

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/instructions/branch.c > CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/instructions/branch.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o: ../src/emulate_utils/instructions/DataProcDec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/instructions/DataProcDec.c

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/instructions/DataProcDec.c > CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/instructions/DataProcDec.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o: ../src/emulate_utils/instructions/multiply.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/instructions/multiply.c

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/instructions/multiply.c > CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/instructions/multiply.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o: ../src/emulate_utils/instructions/singleDT.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/instructions/singleDT.c

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/instructions/singleDT.c > CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/instructions/singleDT.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o


CMakeFiles/arm11_28.dir/src/assemble.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/assemble.c.o: ../src/assemble.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/arm11_28.dir/src/assemble.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/assemble.c.o   -c /home/nb1317/arm11_28/src/assemble.c

CMakeFiles/arm11_28.dir/src/assemble.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/assemble.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/assemble.c > CMakeFiles/arm11_28.dir/src/assemble.c.i

CMakeFiles/arm11_28.dir/src/assemble.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/assemble.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/assemble.c -o CMakeFiles/arm11_28.dir/src/assemble.c.s

CMakeFiles/arm11_28.dir/src/assemble.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/assemble.c.o.requires

CMakeFiles/arm11_28.dir/src/assemble.c.o.provides: CMakeFiles/arm11_28.dir/src/assemble.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/assemble.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/assemble.c.o.provides

CMakeFiles/arm11_28.dir/src/assemble.c.o.provides.build: CMakeFiles/arm11_28.dir/src/assemble.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o: ../src/emulate_utils/binaryloader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/binaryloader.c

CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/binaryloader.c > CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/binaryloader.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o: ../src/emulate_utils/decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/decode.c

CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/decode.c > CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/decode.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o


CMakeFiles/arm11_28.dir/src/emulate.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate.c.o: ../src/emulate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/arm11_28.dir/src/emulate.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate.c.o   -c /home/nb1317/arm11_28/src/emulate.c

CMakeFiles/arm11_28.dir/src/emulate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate.c > CMakeFiles/arm11_28.dir/src/emulate.c.i

CMakeFiles/arm11_28.dir/src/emulate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate.c -o CMakeFiles/arm11_28.dir/src/emulate.c.s

CMakeFiles/arm11_28.dir/src/emulate.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o: ../src/emulate_utils/execute.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/execute.c

CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/execute.c > CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/execute.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o


CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o: ../src/emulate_utils/usefulFuncs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o   -c /home/nb1317/arm11_28/src/emulate_utils/usefulFuncs.c

CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/emulate_utils/usefulFuncs.c > CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.i

CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/emulate_utils/usefulFuncs.c -o CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.s

CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.requires

CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.provides: CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.provides

CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.provides.build: CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o


CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o: ../src/assemble_utils/assemblerImplementation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o   -c /home/nb1317/arm11_28/src/assemble_utils/assemblerImplementation.c

CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/assemble_utils/assemblerImplementation.c > CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.i

CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/assemble_utils/assemblerImplementation.c -o CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.s

CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.requires

CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.provides: CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.provides

CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.provides.build: CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o


CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o: ../src/assemble_utils/defs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o   -c /home/nb1317/arm11_28/src/assemble_utils/defs.c

CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/assemble_utils/defs.c > CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.i

CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/assemble_utils/defs.c -o CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.s

CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.requires

CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.provides: CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.provides

CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.provides.build: CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o


CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o: ../src/assemble_utils/instructions/multiply.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o   -c /home/nb1317/arm11_28/src/assemble_utils/instructions/multiply.c

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/assemble_utils/instructions/multiply.c > CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.i

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/assemble_utils/instructions/multiply.c -o CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.s

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.requires

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.provides: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.provides

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.provides.build: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o


CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o: ../src/assemble_utils/instructions/branch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o   -c /home/nb1317/arm11_28/src/assemble_utils/instructions/branch.c

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/assemble_utils/instructions/branch.c > CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.i

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/assemble_utils/instructions/branch.c -o CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.s

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.requires

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.provides: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.provides

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.provides.build: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o


CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o: CMakeFiles/arm11_28.dir/flags.make
CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o: ../src/assemble_utils/instructions/DataProc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o   -c /home/nb1317/arm11_28/src/assemble_utils/instructions/DataProc.c

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nb1317/arm11_28/src/assemble_utils/instructions/DataProc.c > CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.i

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nb1317/arm11_28/src/assemble_utils/instructions/DataProc.c -o CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.s

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.requires:

.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.requires

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.provides: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.requires
	$(MAKE) -f CMakeFiles/arm11_28.dir/build.make CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.provides.build
.PHONY : CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.provides

CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.provides.build: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o


# Object files for target arm11_28
arm11_28_OBJECTS = \
"CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o" \
"CMakeFiles/arm11_28.dir/src/assemble.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o" \
"CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o" \
"CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o" \
"CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o" \
"CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o" \
"CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o" \
"CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o"

# External object files for target arm11_28
arm11_28_EXTERNAL_OBJECTS =

arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/assemble.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o
arm11_28: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o
arm11_28: CMakeFiles/arm11_28.dir/build.make
arm11_28: CMakeFiles/arm11_28.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nb1317/arm11_28/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking C executable arm11_28"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arm11_28.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arm11_28.dir/build: arm11_28

.PHONY : CMakeFiles/arm11_28.dir/build

CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/branch.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/DataProcDec.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/multiply.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/instructions/singleDT.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/assemble.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/binaryloader.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/decode.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/execute.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/emulate_utils/usefulFuncs.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/assemble_utils/assemblerImplementation.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/assemble_utils/defs.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/multiply.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/branch.c.o.requires
CMakeFiles/arm11_28.dir/requires: CMakeFiles/arm11_28.dir/src/assemble_utils/instructions/DataProc.c.o.requires

.PHONY : CMakeFiles/arm11_28.dir/requires

CMakeFiles/arm11_28.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arm11_28.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arm11_28.dir/clean

CMakeFiles/arm11_28.dir/depend:
	cd /home/nb1317/arm11_28/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nb1317/arm11_28 /home/nb1317/arm11_28 /home/nb1317/arm11_28/cmake-build-debug /home/nb1317/arm11_28/cmake-build-debug /home/nb1317/arm11_28/cmake-build-debug/CMakeFiles/arm11_28.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arm11_28.dir/depend


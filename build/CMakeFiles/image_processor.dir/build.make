# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build

# Include any dependencies generated for this target.
include CMakeFiles/image_processor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image_processor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image_processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_processor.dir/flags.make

CMakeFiles/image_processor.dir/files/BMP.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/files/BMP.cpp.o: /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/BMP.cpp
CMakeFiles/image_processor.dir/files/BMP.cpp.o: CMakeFiles/image_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_processor.dir/files/BMP.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_processor.dir/files/BMP.cpp.o -MF CMakeFiles/image_processor.dir/files/BMP.cpp.o.d -o CMakeFiles/image_processor.dir/files/BMP.cpp.o -c /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/BMP.cpp

CMakeFiles/image_processor.dir/files/BMP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/files/BMP.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/BMP.cpp > CMakeFiles/image_processor.dir/files/BMP.cpp.i

CMakeFiles/image_processor.dir/files/BMP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/files/BMP.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/BMP.cpp -o CMakeFiles/image_processor.dir/files/BMP.cpp.s

CMakeFiles/image_processor.dir/files/Filters.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/files/Filters.cpp.o: /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Filters.cpp
CMakeFiles/image_processor.dir/files/Filters.cpp.o: CMakeFiles/image_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_processor.dir/files/Filters.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_processor.dir/files/Filters.cpp.o -MF CMakeFiles/image_processor.dir/files/Filters.cpp.o.d -o CMakeFiles/image_processor.dir/files/Filters.cpp.o -c /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Filters.cpp

CMakeFiles/image_processor.dir/files/Filters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/files/Filters.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Filters.cpp > CMakeFiles/image_processor.dir/files/Filters.cpp.i

CMakeFiles/image_processor.dir/files/Filters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/files/Filters.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Filters.cpp -o CMakeFiles/image_processor.dir/files/Filters.cpp.s

CMakeFiles/image_processor.dir/files/Image.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/files/Image.cpp.o: /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Image.cpp
CMakeFiles/image_processor.dir/files/Image.cpp.o: CMakeFiles/image_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image_processor.dir/files/Image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_processor.dir/files/Image.cpp.o -MF CMakeFiles/image_processor.dir/files/Image.cpp.o.d -o CMakeFiles/image_processor.dir/files/Image.cpp.o -c /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Image.cpp

CMakeFiles/image_processor.dir/files/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/files/Image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Image.cpp > CMakeFiles/image_processor.dir/files/Image.cpp.i

CMakeFiles/image_processor.dir/files/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/files/Image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Image.cpp -o CMakeFiles/image_processor.dir/files/Image.cpp.s

CMakeFiles/image_processor.dir/files/Pixel.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/files/Pixel.cpp.o: /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Pixel.cpp
CMakeFiles/image_processor.dir/files/Pixel.cpp.o: CMakeFiles/image_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/image_processor.dir/files/Pixel.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_processor.dir/files/Pixel.cpp.o -MF CMakeFiles/image_processor.dir/files/Pixel.cpp.o.d -o CMakeFiles/image_processor.dir/files/Pixel.cpp.o -c /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Pixel.cpp

CMakeFiles/image_processor.dir/files/Pixel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/files/Pixel.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Pixel.cpp > CMakeFiles/image_processor.dir/files/Pixel.cpp.i

CMakeFiles/image_processor.dir/files/Pixel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/files/Pixel.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/Pixel.cpp -o CMakeFiles/image_processor.dir/files/Pixel.cpp.s

CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o: /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor_impl.cpp
CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o: CMakeFiles/image_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o -MF CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o.d -o CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o -c /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor_impl.cpp

CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor_impl.cpp > CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.i

CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor_impl.cpp -o CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.s

CMakeFiles/image_processor.dir/files/image_processor.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/files/image_processor.cpp.o: /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor.cpp
CMakeFiles/image_processor.dir/files/image_processor.cpp.o: CMakeFiles/image_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/image_processor.dir/files/image_processor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_processor.dir/files/image_processor.cpp.o -MF CMakeFiles/image_processor.dir/files/image_processor.cpp.o.d -o CMakeFiles/image_processor.dir/files/image_processor.cpp.o -c /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor.cpp

CMakeFiles/image_processor.dir/files/image_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/files/image_processor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor.cpp > CMakeFiles/image_processor.dir/files/image_processor.cpp.i

CMakeFiles/image_processor.dir/files/image_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/files/image_processor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/files/image_processor.cpp -o CMakeFiles/image_processor.dir/files/image_processor.cpp.s

# Object files for target image_processor
image_processor_OBJECTS = \
"CMakeFiles/image_processor.dir/files/BMP.cpp.o" \
"CMakeFiles/image_processor.dir/files/Filters.cpp.o" \
"CMakeFiles/image_processor.dir/files/Image.cpp.o" \
"CMakeFiles/image_processor.dir/files/Pixel.cpp.o" \
"CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o" \
"CMakeFiles/image_processor.dir/files/image_processor.cpp.o"

# External object files for target image_processor
image_processor_EXTERNAL_OBJECTS =

image_processor: CMakeFiles/image_processor.dir/files/BMP.cpp.o
image_processor: CMakeFiles/image_processor.dir/files/Filters.cpp.o
image_processor: CMakeFiles/image_processor.dir/files/Image.cpp.o
image_processor: CMakeFiles/image_processor.dir/files/Pixel.cpp.o
image_processor: CMakeFiles/image_processor.dir/files/image_processor_impl.cpp.o
image_processor: CMakeFiles/image_processor.dir/files/image_processor.cpp.o
image_processor: CMakeFiles/image_processor.dir/build.make
image_processor: CMakeFiles/image_processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable image_processor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_processor.dir/build: image_processor
.PHONY : CMakeFiles/image_processor.dir/build

CMakeFiles/image_processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_processor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_processor.dir/clean

CMakeFiles/image_processor.dir/depend:
	cd /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build /Users/ronsh/code/ami-Pavel-Eliseev-Soyavo/tasks/image_processor/build/CMakeFiles/image_processor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/image_processor.dir/depend


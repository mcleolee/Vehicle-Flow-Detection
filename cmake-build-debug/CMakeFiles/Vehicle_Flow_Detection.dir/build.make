# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/raven/CLionProjects/Vehicle-Flow-Detection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Vehicle_Flow_Detection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vehicle_Flow_Detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vehicle_Flow_Detection.dir/flags.make

CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.o: CMakeFiles/Vehicle_Flow_Detection.dir/flags.make
CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.o -c /Users/raven/CLionProjects/Vehicle-Flow-Detection/main.cpp

CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/raven/CLionProjects/Vehicle-Flow-Detection/main.cpp > CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.i

CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/raven/CLionProjects/Vehicle-Flow-Detection/main.cpp -o CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.s

# Object files for target Vehicle_Flow_Detection
Vehicle_Flow_Detection_OBJECTS = \
"CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.o"

# External object files for target Vehicle_Flow_Detection
Vehicle_Flow_Detection_EXTERNAL_OBJECTS =

Vehicle_Flow_Detection: CMakeFiles/Vehicle_Flow_Detection.dir/main.cpp.o
Vehicle_Flow_Detection: CMakeFiles/Vehicle_Flow_Detection.dir/build.make
Vehicle_Flow_Detection: /usr/local/lib/libopencv_gapi.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_highgui.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_ml.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_objdetect.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_photo.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_stitching.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_video.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_videoio.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_imgcodecs.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_dnn.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_calib3d.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_features2d.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_flann.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_imgproc.4.7.0.dylib
Vehicle_Flow_Detection: /usr/local/lib/libopencv_core.4.7.0.dylib
Vehicle_Flow_Detection: CMakeFiles/Vehicle_Flow_Detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vehicle_Flow_Detection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vehicle_Flow_Detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vehicle_Flow_Detection.dir/build: Vehicle_Flow_Detection

.PHONY : CMakeFiles/Vehicle_Flow_Detection.dir/build

CMakeFiles/Vehicle_Flow_Detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vehicle_Flow_Detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vehicle_Flow_Detection.dir/clean

CMakeFiles/Vehicle_Flow_Detection.dir/depend:
	cd /Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/raven/CLionProjects/Vehicle-Flow-Detection /Users/raven/CLionProjects/Vehicle-Flow-Detection /Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug /Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug /Users/raven/CLionProjects/Vehicle-Flow-Detection/cmake-build-debug/CMakeFiles/Vehicle_Flow_Detection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vehicle_Flow_Detection.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build"

# Include any dependencies generated for this target.
include CMakeFiles/DM_detection.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DM_detection.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DM_detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DM_detection.dir/flags.make

CMakeFiles/DM_detection.dir/DM_detection.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/DM_detection.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/DM_detection.cc
CMakeFiles/DM_detection.dir/DM_detection.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DM_detection.dir/DM_detection.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/DM_detection.cc.o -MF CMakeFiles/DM_detection.dir/DM_detection.cc.o.d -o CMakeFiles/DM_detection.dir/DM_detection.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/DM_detection.cc"

CMakeFiles/DM_detection.dir/DM_detection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/DM_detection.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/DM_detection.cc" > CMakeFiles/DM_detection.dir/DM_detection.cc.i

CMakeFiles/DM_detection.dir/DM_detection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/DM_detection.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/DM_detection.cc" -o CMakeFiles/DM_detection.dir/DM_detection.cc.s

CMakeFiles/DM_detection.dir/src/RunAction.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/RunAction.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/RunAction.cc
CMakeFiles/DM_detection.dir/src/RunAction.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DM_detection.dir/src/RunAction.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/RunAction.cc.o -MF CMakeFiles/DM_detection.dir/src/RunAction.cc.o.d -o CMakeFiles/DM_detection.dir/src/RunAction.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/RunAction.cc"

CMakeFiles/DM_detection.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/RunAction.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/RunAction.cc" > CMakeFiles/DM_detection.dir/src/RunAction.cc.i

CMakeFiles/DM_detection.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/RunAction.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/RunAction.cc" -o CMakeFiles/DM_detection.dir/src/RunAction.cc.s

CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/SteppingAction.cc
CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o -MF CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o.d -o CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/SteppingAction.cc"

CMakeFiles/DM_detection.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/SteppingAction.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/SteppingAction.cc" > CMakeFiles/DM_detection.dir/src/SteppingAction.cc.i

CMakeFiles/DM_detection.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/SteppingAction.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/SteppingAction.cc" -o CMakeFiles/DM_detection.dir/src/SteppingAction.cc.s

CMakeFiles/DM_detection.dir/src/action.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/action.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/action.cc
CMakeFiles/DM_detection.dir/src/action.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DM_detection.dir/src/action.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/action.cc.o -MF CMakeFiles/DM_detection.dir/src/action.cc.o.d -o CMakeFiles/DM_detection.dir/src/action.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/action.cc"

CMakeFiles/DM_detection.dir/src/action.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/action.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/action.cc" > CMakeFiles/DM_detection.dir/src/action.cc.i

CMakeFiles/DM_detection.dir/src/action.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/action.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/action.cc" -o CMakeFiles/DM_detection.dir/src/action.cc.s

CMakeFiles/DM_detection.dir/src/construction.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/construction.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/construction.cc
CMakeFiles/DM_detection.dir/src/construction.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DM_detection.dir/src/construction.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/construction.cc.o -MF CMakeFiles/DM_detection.dir/src/construction.cc.o.d -o CMakeFiles/DM_detection.dir/src/construction.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/construction.cc"

CMakeFiles/DM_detection.dir/src/construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/construction.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/construction.cc" > CMakeFiles/DM_detection.dir/src/construction.cc.i

CMakeFiles/DM_detection.dir/src/construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/construction.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/construction.cc" -o CMakeFiles/DM_detection.dir/src/construction.cc.s

CMakeFiles/DM_detection.dir/src/detector.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/detector.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/detector.cc
CMakeFiles/DM_detection.dir/src/detector.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DM_detection.dir/src/detector.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/detector.cc.o -MF CMakeFiles/DM_detection.dir/src/detector.cc.o.d -o CMakeFiles/DM_detection.dir/src/detector.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/detector.cc"

CMakeFiles/DM_detection.dir/src/detector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/detector.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/detector.cc" > CMakeFiles/DM_detection.dir/src/detector.cc.i

CMakeFiles/DM_detection.dir/src/detector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/detector.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/detector.cc" -o CMakeFiles/DM_detection.dir/src/detector.cc.s

CMakeFiles/DM_detection.dir/src/generator.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/generator.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/generator.cc
CMakeFiles/DM_detection.dir/src/generator.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DM_detection.dir/src/generator.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/generator.cc.o -MF CMakeFiles/DM_detection.dir/src/generator.cc.o.d -o CMakeFiles/DM_detection.dir/src/generator.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/generator.cc"

CMakeFiles/DM_detection.dir/src/generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/generator.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/generator.cc" > CMakeFiles/DM_detection.dir/src/generator.cc.i

CMakeFiles/DM_detection.dir/src/generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/generator.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/generator.cc" -o CMakeFiles/DM_detection.dir/src/generator.cc.s

CMakeFiles/DM_detection.dir/src/physics.cc.o: CMakeFiles/DM_detection.dir/flags.make
CMakeFiles/DM_detection.dir/src/physics.cc.o: /Users/maria/Desktop/Máster/M1/S1/Astroparticle\ space\ misions/DM_signatures/src/physics.cc
CMakeFiles/DM_detection.dir/src/physics.cc.o: CMakeFiles/DM_detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DM_detection.dir/src/physics.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DM_detection.dir/src/physics.cc.o -MF CMakeFiles/DM_detection.dir/src/physics.cc.o.d -o CMakeFiles/DM_detection.dir/src/physics.cc.o -c "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/physics.cc"

CMakeFiles/DM_detection.dir/src/physics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DM_detection.dir/src/physics.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/physics.cc" > CMakeFiles/DM_detection.dir/src/physics.cc.i

CMakeFiles/DM_detection.dir/src/physics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DM_detection.dir/src/physics.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/src/physics.cc" -o CMakeFiles/DM_detection.dir/src/physics.cc.s

# Object files for target DM_detection
DM_detection_OBJECTS = \
"CMakeFiles/DM_detection.dir/DM_detection.cc.o" \
"CMakeFiles/DM_detection.dir/src/RunAction.cc.o" \
"CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o" \
"CMakeFiles/DM_detection.dir/src/action.cc.o" \
"CMakeFiles/DM_detection.dir/src/construction.cc.o" \
"CMakeFiles/DM_detection.dir/src/detector.cc.o" \
"CMakeFiles/DM_detection.dir/src/generator.cc.o" \
"CMakeFiles/DM_detection.dir/src/physics.cc.o"

# External object files for target DM_detection
DM_detection_EXTERNAL_OBJECTS =

DM_detection: CMakeFiles/DM_detection.dir/DM_detection.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/RunAction.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/SteppingAction.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/action.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/construction.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/detector.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/generator.cc.o
DM_detection: CMakeFiles/DM_detection.dir/src/physics.cc.o
DM_detection: CMakeFiles/DM_detection.dir/build.make
DM_detection: /usr/local/lib/libG4Tree.dylib
DM_detection: /usr/local/lib/libG4FR.dylib
DM_detection: /usr/local/lib/libG4GMocren.dylib
DM_detection: /usr/local/lib/libG4visHepRep.dylib
DM_detection: /usr/local/lib/libG4RayTracer.dylib
DM_detection: /usr/local/lib/libG4VRML.dylib
DM_detection: /usr/local/lib/libG4ToolsSG.dylib
DM_detection: /usr/local/lib/libG4OpenGL.dylib
DM_detection: /usr/local/lib/libG4visQt3D.dylib
DM_detection: /usr/local/lib/libG4vis_management.dylib
DM_detection: /usr/local/lib/libG4modeling.dylib
DM_detection: /usr/local/lib/libG4interfaces.dylib
DM_detection: /usr/local/lib/libG4mctruth.dylib
DM_detection: /usr/local/lib/libG4geomtext.dylib
DM_detection: /usr/local/lib/libG4error_propagation.dylib
DM_detection: /usr/local/lib/libG4readout.dylib
DM_detection: /usr/local/lib/libG4physicslists.dylib
DM_detection: /usr/local/lib/libG4run.dylib
DM_detection: /usr/local/lib/libG4event.dylib
DM_detection: /usr/local/lib/libG4tracking.dylib
DM_detection: /usr/local/lib/libG4parmodels.dylib
DM_detection: /usr/local/lib/libG4processes.dylib
DM_detection: /usr/local/lib/libG4digits_hits.dylib
DM_detection: /usr/local/lib/libG4track.dylib
DM_detection: /usr/local/lib/libG4particles.dylib
DM_detection: /usr/local/lib/libG4geometry.dylib
DM_detection: /usr/local/lib/libG4materials.dylib
DM_detection: /usr/local/lib/libG4graphics_reps.dylib
DM_detection: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/System/Library/Frameworks/OpenGL.framework
DM_detection: /opt/homebrew/Cellar/qt@5/5.15.13_1/lib/QtOpenGL.framework/QtOpenGL
DM_detection: /opt/homebrew/Cellar/qt@5/5.15.13_1/lib/QtWidgets.framework/QtWidgets
DM_detection: /opt/homebrew/Cellar/qt@5/5.15.13_1/lib/QtGui.framework/QtGui
DM_detection: /opt/homebrew/Cellar/qt@5/5.15.13_1/lib/QtCore.framework/QtCore
DM_detection: /usr/local/lib/libG4analysis.dylib
DM_detection: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/lib/libexpat.tbd
DM_detection: /usr/local/lib/libG4zlib.dylib
DM_detection: /usr/local/lib/libG4intercoms.dylib
DM_detection: /usr/local/lib/libG4global.dylib
DM_detection: /usr/local/lib/libG4clhep.dylib
DM_detection: /usr/local/lib/libG4ptl.2.3.3.dylib
DM_detection: CMakeFiles/DM_detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable DM_detection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DM_detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DM_detection.dir/build: DM_detection
.PHONY : CMakeFiles/DM_detection.dir/build

CMakeFiles/DM_detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DM_detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DM_detection.dir/clean

CMakeFiles/DM_detection.dir/depend:
	cd "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures" "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures" "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build" "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build" "/Users/maria/Desktop/Máster/M1/S1/Astroparticle space misions/DM_signatures/build/CMakeFiles/DM_detection.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/DM_detection.dir/depend


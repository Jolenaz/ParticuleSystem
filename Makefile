# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/cmake

# The command to remove a file.
RM = /Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jbelless/ParticuleSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jbelless/ParticuleSystem

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/jbelless/ParticuleSystem/CMakeFiles /Users/jbelless/ParticuleSystem/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/jbelless/ParticuleSystem/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ParticuleSystem

# Build rule for target.
ParticuleSystem: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ParticuleSystem
.PHONY : ParticuleSystem

# fast build rule for target.
ParticuleSystem/fast:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/build
.PHONY : ParticuleSystem/fast

Classes/Math/Mat2.class.o: Classes/Math/Mat2.class.cpp.o

.PHONY : Classes/Math/Mat2.class.o

# target to build an object file
Classes/Math/Mat2.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat2.class.cpp.o
.PHONY : Classes/Math/Mat2.class.cpp.o

Classes/Math/Mat2.class.i: Classes/Math/Mat2.class.cpp.i

.PHONY : Classes/Math/Mat2.class.i

# target to preprocess a source file
Classes/Math/Mat2.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat2.class.cpp.i
.PHONY : Classes/Math/Mat2.class.cpp.i

Classes/Math/Mat2.class.s: Classes/Math/Mat2.class.cpp.s

.PHONY : Classes/Math/Mat2.class.s

# target to generate assembly for a file
Classes/Math/Mat2.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat2.class.cpp.s
.PHONY : Classes/Math/Mat2.class.cpp.s

Classes/Math/Mat3.class.o: Classes/Math/Mat3.class.cpp.o

.PHONY : Classes/Math/Mat3.class.o

# target to build an object file
Classes/Math/Mat3.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat3.class.cpp.o
.PHONY : Classes/Math/Mat3.class.cpp.o

Classes/Math/Mat3.class.i: Classes/Math/Mat3.class.cpp.i

.PHONY : Classes/Math/Mat3.class.i

# target to preprocess a source file
Classes/Math/Mat3.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat3.class.cpp.i
.PHONY : Classes/Math/Mat3.class.cpp.i

Classes/Math/Mat3.class.s: Classes/Math/Mat3.class.cpp.s

.PHONY : Classes/Math/Mat3.class.s

# target to generate assembly for a file
Classes/Math/Mat3.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat3.class.cpp.s
.PHONY : Classes/Math/Mat3.class.cpp.s

Classes/Math/Mat4.class.o: Classes/Math/Mat4.class.cpp.o

.PHONY : Classes/Math/Mat4.class.o

# target to build an object file
Classes/Math/Mat4.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat4.class.cpp.o
.PHONY : Classes/Math/Mat4.class.cpp.o

Classes/Math/Mat4.class.i: Classes/Math/Mat4.class.cpp.i

.PHONY : Classes/Math/Mat4.class.i

# target to preprocess a source file
Classes/Math/Mat4.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat4.class.cpp.i
.PHONY : Classes/Math/Mat4.class.cpp.i

Classes/Math/Mat4.class.s: Classes/Math/Mat4.class.cpp.s

.PHONY : Classes/Math/Mat4.class.s

# target to generate assembly for a file
Classes/Math/Mat4.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Mat4.class.cpp.s
.PHONY : Classes/Math/Mat4.class.cpp.s

Classes/Math/Vec2.class.o: Classes/Math/Vec2.class.cpp.o

.PHONY : Classes/Math/Vec2.class.o

# target to build an object file
Classes/Math/Vec2.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec2.class.cpp.o
.PHONY : Classes/Math/Vec2.class.cpp.o

Classes/Math/Vec2.class.i: Classes/Math/Vec2.class.cpp.i

.PHONY : Classes/Math/Vec2.class.i

# target to preprocess a source file
Classes/Math/Vec2.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec2.class.cpp.i
.PHONY : Classes/Math/Vec2.class.cpp.i

Classes/Math/Vec2.class.s: Classes/Math/Vec2.class.cpp.s

.PHONY : Classes/Math/Vec2.class.s

# target to generate assembly for a file
Classes/Math/Vec2.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec2.class.cpp.s
.PHONY : Classes/Math/Vec2.class.cpp.s

Classes/Math/Vec3.class.o: Classes/Math/Vec3.class.cpp.o

.PHONY : Classes/Math/Vec3.class.o

# target to build an object file
Classes/Math/Vec3.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec3.class.cpp.o
.PHONY : Classes/Math/Vec3.class.cpp.o

Classes/Math/Vec3.class.i: Classes/Math/Vec3.class.cpp.i

.PHONY : Classes/Math/Vec3.class.i

# target to preprocess a source file
Classes/Math/Vec3.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec3.class.cpp.i
.PHONY : Classes/Math/Vec3.class.cpp.i

Classes/Math/Vec3.class.s: Classes/Math/Vec3.class.cpp.s

.PHONY : Classes/Math/Vec3.class.s

# target to generate assembly for a file
Classes/Math/Vec3.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec3.class.cpp.s
.PHONY : Classes/Math/Vec3.class.cpp.s

Classes/Math/Vec4.class.o: Classes/Math/Vec4.class.cpp.o

.PHONY : Classes/Math/Vec4.class.o

# target to build an object file
Classes/Math/Vec4.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec4.class.cpp.o
.PHONY : Classes/Math/Vec4.class.cpp.o

Classes/Math/Vec4.class.i: Classes/Math/Vec4.class.cpp.i

.PHONY : Classes/Math/Vec4.class.i

# target to preprocess a source file
Classes/Math/Vec4.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec4.class.cpp.i
.PHONY : Classes/Math/Vec4.class.cpp.i

Classes/Math/Vec4.class.s: Classes/Math/Vec4.class.cpp.s

.PHONY : Classes/Math/Vec4.class.s

# target to generate assembly for a file
Classes/Math/Vec4.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Math/Vec4.class.cpp.s
.PHONY : Classes/Math/Vec4.class.cpp.s

Classes/Render/Camera.class.o: Classes/Render/Camera.class.cpp.o

.PHONY : Classes/Render/Camera.class.o

# target to build an object file
Classes/Render/Camera.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Render/Camera.class.cpp.o
.PHONY : Classes/Render/Camera.class.cpp.o

Classes/Render/Camera.class.i: Classes/Render/Camera.class.cpp.i

.PHONY : Classes/Render/Camera.class.i

# target to preprocess a source file
Classes/Render/Camera.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Render/Camera.class.cpp.i
.PHONY : Classes/Render/Camera.class.cpp.i

Classes/Render/Camera.class.s: Classes/Render/Camera.class.cpp.s

.PHONY : Classes/Render/Camera.class.s

# target to generate assembly for a file
Classes/Render/Camera.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Render/Camera.class.cpp.s
.PHONY : Classes/Render/Camera.class.cpp.s

Classes/Render/RenderManager.class.o: Classes/Render/RenderManager.class.cpp.o

.PHONY : Classes/Render/RenderManager.class.o

# target to build an object file
Classes/Render/RenderManager.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Render/RenderManager.class.cpp.o
.PHONY : Classes/Render/RenderManager.class.cpp.o

Classes/Render/RenderManager.class.i: Classes/Render/RenderManager.class.cpp.i

.PHONY : Classes/Render/RenderManager.class.i

# target to preprocess a source file
Classes/Render/RenderManager.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Render/RenderManager.class.cpp.i
.PHONY : Classes/Render/RenderManager.class.cpp.i

Classes/Render/RenderManager.class.s: Classes/Render/RenderManager.class.cpp.s

.PHONY : Classes/Render/RenderManager.class.s

# target to generate assembly for a file
Classes/Render/RenderManager.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Render/RenderManager.class.cpp.s
.PHONY : Classes/Render/RenderManager.class.cpp.s

Classes/SceneManager.class.o: Classes/SceneManager.class.cpp.o

.PHONY : Classes/SceneManager.class.o

# target to build an object file
Classes/SceneManager.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/SceneManager.class.cpp.o
.PHONY : Classes/SceneManager.class.cpp.o

Classes/SceneManager.class.i: Classes/SceneManager.class.cpp.i

.PHONY : Classes/SceneManager.class.i

# target to preprocess a source file
Classes/SceneManager.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/SceneManager.class.cpp.i
.PHONY : Classes/SceneManager.class.cpp.i

Classes/SceneManager.class.s: Classes/SceneManager.class.cpp.s

.PHONY : Classes/SceneManager.class.s

# target to generate assembly for a file
Classes/SceneManager.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/SceneManager.class.cpp.s
.PHONY : Classes/SceneManager.class.cpp.s

Classes/Transform.class.o: Classes/Transform.class.cpp.o

.PHONY : Classes/Transform.class.o

# target to build an object file
Classes/Transform.class.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Transform.class.cpp.o
.PHONY : Classes/Transform.class.cpp.o

Classes/Transform.class.i: Classes/Transform.class.cpp.i

.PHONY : Classes/Transform.class.i

# target to preprocess a source file
Classes/Transform.class.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Transform.class.cpp.i
.PHONY : Classes/Transform.class.cpp.i

Classes/Transform.class.s: Classes/Transform.class.cpp.s

.PHONY : Classes/Transform.class.s

# target to generate assembly for a file
Classes/Transform.class.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/Classes/Transform.class.cpp.s
.PHONY : Classes/Transform.class.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/ParticuleSystem.dir/build.make CMakeFiles/ParticuleSystem.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... ParticuleSystem"
	@echo "... Classes/Math/Mat2.class.o"
	@echo "... Classes/Math/Mat2.class.i"
	@echo "... Classes/Math/Mat2.class.s"
	@echo "... Classes/Math/Mat3.class.o"
	@echo "... Classes/Math/Mat3.class.i"
	@echo "... Classes/Math/Mat3.class.s"
	@echo "... Classes/Math/Mat4.class.o"
	@echo "... Classes/Math/Mat4.class.i"
	@echo "... Classes/Math/Mat4.class.s"
	@echo "... Classes/Math/Vec2.class.o"
	@echo "... Classes/Math/Vec2.class.i"
	@echo "... Classes/Math/Vec2.class.s"
	@echo "... Classes/Math/Vec3.class.o"
	@echo "... Classes/Math/Vec3.class.i"
	@echo "... Classes/Math/Vec3.class.s"
	@echo "... Classes/Math/Vec4.class.o"
	@echo "... Classes/Math/Vec4.class.i"
	@echo "... Classes/Math/Vec4.class.s"
	@echo "... Classes/Render/Camera.class.o"
	@echo "... Classes/Render/Camera.class.i"
	@echo "... Classes/Render/Camera.class.s"
	@echo "... Classes/Render/RenderManager.class.o"
	@echo "... Classes/Render/RenderManager.class.i"
	@echo "... Classes/Render/RenderManager.class.s"
	@echo "... Classes/SceneManager.class.o"
	@echo "... Classes/SceneManager.class.i"
	@echo "... Classes/SceneManager.class.s"
	@echo "... Classes/Transform.class.o"
	@echo "... Classes/Transform.class.i"
	@echo "... Classes/Transform.class.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


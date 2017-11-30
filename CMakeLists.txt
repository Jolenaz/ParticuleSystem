cmake_minimum_required(VERSION 3.5)
project(ParticuleSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

find_package(OpenGL REQUIRED)
find_package(OpenCL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${OpenCL_INCLUDE_DIR})
include_directories(Classes)
include_directories(Classes/Math)
include_directories(Classes/Render)
include_directories(include)

link_directories(${OpenCL_LIBRARY})
link_directories(${OpenGL_LIBRARY})

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCE_FILES
	src/main.cpp
	Classes/Math/Vec2.class.cpp
	Classes/Math/Vec3.class.cpp
	Classes/Math/Vec4.class.cpp
	Classes/Math/Mat2.class.cpp
	Classes/Math/Mat3.class.cpp
	Classes/Math/Mat4.class.cpp
	Classes/Render/Camera.class.cpp
	Classes/Render/RenderManager.class.cpp
	Classes/Transform.class.cpp
	Classes/SceneManager.class.cpp
	)

add_executable(ParticuleSystem ${SOURCE_FILES})

target_link_libraries(ParticuleSystem ${CMAKE_DL_LIBS})
target_link_libraries(ParticuleSystem ${SDL2_LIBRARIES})
target_link_libraries(ParticuleSystem ${OPENGL_LIBRARIES})
target_link_libraries(ParticuleSystem ${OpenCL_LIBRARIES})

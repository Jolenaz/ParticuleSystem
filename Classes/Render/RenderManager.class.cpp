
#include "RenderManager.class.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

RenderManager::RenderManager(float w, float h){
    cam.ratio = (float)w / (float)h;
    this->_initSDL(w,h);
    this->_initGLCL();
}

RenderManager::~RenderManager(void){}

void RenderManager::_initSDL(int width, int height){
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		this->window = SDL_CreateWindow("HumanGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if (this->window == NULL) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			// SDL_ShowCursor(SDL_DISABLE);
			// SDL_WarpMouseInWindow(this->window, width / 2, height / 2);
			// SDL_SetWindowGrab(this->window, SDL_TRUE);
			// SDL_SetRelativeMouseMode(SDL_TRUE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
			this->glContext = SDL_GL_CreateContext(this->window);
			if(this->glContext == NULL) {
				std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
		}
	}
}

void RenderManager::_initGLCL(){
	
	cl_uint         nb_platform;
	cl_uint         nb_device;
	cl_platform_id  platforms[10];
	cl_device_id    devices[10];

	clGetPlatformIDs(
			10,
			platforms,
			&nb_platform);

	clGetDeviceIDs(
			platforms[0],
			CL_DEVICE_TYPE_GPU,
			10,
			devices,
			&nb_device);

	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
		GL_ARRAY_BUFFER,
		100,
		NULL,
		GL_STATIC_DRAW
	);

	CGLContextObj    gl_ctx        = CGLGetCurrentContext();
	CGLShareGroupObj gl_sharegroup = CGLGetShareGroup(gl_ctx);

	cl_context_properties properties[] = {
			CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE,
			(cl_context_properties) gl_sharegroup,
			0
	};
	
	cl_int err_code;
	this->clContext = clCreateContextFromType(  properties,
									CL_DEVICE_TYPE_GPU, 
									nullptr,
									nullptr,
									&err_code);
	std::cout << "error create cl context : " << err_code << std::endl;
}
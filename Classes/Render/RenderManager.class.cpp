
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

void RenderManager::getClProgram(){
	std::string line;
	std::string source_code;
	cl_int err_code;

	std::fstream progFd("clProgram/clProgram.txt");
	int compilation_return;
	
	if (progFd)
	{
		while (getline(progFd, line))
			source_code += line + "\n";
			progFd.close();
	}
	else
		std::cout << "shader introuvable : " << "clProgram/clProgram.txt" << std::endl;

	const char * ptrSourc = source_code.c_str();

	cl_program prog = clCreateProgramWithSource(this->clContext,
		1,
		&ptrSourc,
		nullptr,
		&err_code);

	std::cout << "error create cl progran : " << err_code  << " for prog : " << prog << std::endl;
	
	cl_int ret = clBuildProgram(prog, 1, &this->clDevice, NULL, NULL, NULL);
	
	std::cout << "error compilation cl program : " << ret << std::endl;

	if (ret != 0){
		size_t len = 0;
		cl_int retour = CL_SUCCESS;
		retour = clGetProgramBuildInfo(prog, this->clDevice, CL_PROGRAM_BUILD_LOG, 0, NULL, &len);
		char buffer[len];
		retour = clGetProgramBuildInfo(prog, this->clDevice, CL_PROGRAM_BUILD_LOG, len, buffer, NULL);
		std::cout << "failed" <<  buffer << std::endl;
	}

	this->clKernel = clCreateKernel(prog, "drawPoints", &ret);
}

void RenderManager::getGlProgram(){
	int ret = glCreateProgram();
	std::vector<t_shader_info> shaders = {
		{ GL_VERTEX_SHADER, "Shaders/general.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/general.frag" }
	};
	
    for( t_shader_info si : shaders)
    {
        std::string line;
        std::string source_code;

        std::fstream shaderfd(si.addr);
        int shader_id = glCreateShader(si.flag);
        int compilation_return;
        
        if (shaderfd)
        {
            while (getline(shaderfd, line))
                source_code += line + "\n";
            shaderfd.close();
        }
        else
            std::cout << "shader introuvable : " << si.addr << std::endl;
        const char *source_char = source_code.c_str();
        glShaderSource(shader_id, 1, &source_char, NULL);
        glCompileShader(shader_id);
        glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_return);
        if (compilation_return == 0)
        {
            GLchar buf[10000];
	        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &compilation_return);
	        glGetShaderInfoLog(shader_id, 10000, &compilation_return, buf);
	        std::cout << buf << std::endl;
        }
        glAttachShader(ret, shader_id);
    }
    glLinkProgram(ret);
    this->glProgramId = ret;
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
	
	this->clDevice = devices[0];

	struct vertex
	{
	  float x, y, z, w; // position
	
	}pos[3];

	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,3*sizeof(vertex),pos,GL_DYNAMIC_DRAW);

	CGLContextObj    gl_ctx        = CGLGetCurrentContext();
	CGLShareGroupObj gl_sharegroup = CGLGetShareGroup(gl_ctx);

	cl_context_properties properties[] = {
			CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE,
			(cl_context_properties) gl_sharegroup,
			0
	};
	
	cl_int err_code;
	this->clContext = clCreateContext(  properties,
									1,
									&this->clDevice, 
									nullptr,
									nullptr,
									&err_code);
	std::cout << "error create cl context : " << err_code  << " for context : " << this->clContext << std::endl;

	this->getClProgram();
	this->getGlProgram();

	cl_int ret;

	cl_command_queue cmd_queue = clCreateCommandQueue(this->clContext, this->clDevice, 0, &ret);

	
	cl_mem vbo_cl = clCreateFromGLBuffer(this->clContext,CL_MEM_READ_WRITE,vbo,NULL);
	
	/* Set OpenCL Kernel Parameters */
	ret = clSetKernelArg(this->clKernel, 0,sizeof(cl_mem), (void *)&vbo_cl); //,
	
	glFlush(); 
	ret = clEnqueueAcquireGLObjects(cmd_queue, 1, &vbo_cl, 0,0,0);
	
	/* Execute OpenCL Kernel */
	ret = clEnqueueNDRangeKernel(cmd_queue, this->clKernel, 1, NULL,NULL, NULL, 0, NULL, NULL);
	
	ret = clEnqueueReleaseGLObjects(cmd_queue, 1, &vbo_cl, 0,0,0);
	clFinish(cmd_queue);
	
	}
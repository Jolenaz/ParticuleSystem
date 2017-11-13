
#include "RenderManager.class.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

void GL_DUMP_ERROR(std::string message){
    int glErrorCode = 0;
    if ((glErrorCode = glGetError()) != GL_NO_ERROR)
        std::cout << message << " (error code: " << glErrorCode << ")\n";
}

RenderManager::RenderManager(float w, float h){
    //cam.ratio = (float)w / (float)h;
    this->_initSDL(w,h);
	this->_initGLCL();
	//this->getGlProgram();
	//this->draw();
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
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
			this->glContext = SDL_GL_CreateContext(this->window);
			if(this->glContext == NULL) {
				std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
			//glEnable(GL_DEBUG_OUTPUT);
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
	GL_DUMP_ERROR("test");
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
		GL_DUMP_ERROR("test");
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
		GL_DUMP_ERROR("test");
		glCompileShader(shader_id);
		GL_DUMP_ERROR("test");
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_return);
		GL_DUMP_ERROR("test");
        if (compilation_return == 0)
        {
            GLchar buf[10000];
	        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &compilation_return);
	        glGetShaderInfoLog(shader_id, 10000, &compilation_return, buf);
	        std::cout << buf << std::endl;
        }
		glAttachShader(ret, shader_id);
		GL_DUMP_ERROR("test");
    }
	glLinkProgram(ret);
	GL_DUMP_ERROR("test");
    this->glProgramId = ret;
}

void RenderManager::draw(GLuint vbo){

	struct vertex
	{
	  float x, y, z, w; // position
	
	}pos[3];

	glUseProgram(this->glProgramId);
	GL_DUMP_ERROR("test");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GL_DUMP_ERROR("test");
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	GL_DUMP_ERROR("test");

	GLuint vao;
	glGenVertexArrays(1, &vao);
	GL_DUMP_ERROR("test");
	glBindVertexArray(vao);
	GL_DUMP_ERROR("test");
	glVertexAttribPointer(0,4, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)(0));
	GL_DUMP_ERROR("test");
	glEnableVertexAttribArray(0);
	GL_DUMP_ERROR("test");
	glDrawArrays(GL_POINTS,0,3);
	GL_DUMP_ERROR("test");
	SDL_GL_SwapWindow(this->window);
	

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
	  float x = 0.0f;
	  float y = 0.0f;
	  float z = 0.0f;
	  float w = 0.0f;
	
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
	std::cout << "create command queue " << ret << std::endl;

	
	cl_mem vbo_cl = clCreateFromGLBuffer(this->clContext,CL_MEM_READ_WRITE,vbo,NULL);
	


	/* Set OpenCL Kernel Parameters */
	ret = clSetKernelArg(this->clKernel, 0,sizeof(cl_mem), (void *)&vbo_cl); //,
	
	std::cout << "set kernel arg " << ret << std::endl;


	glFlush(); 
	ret = clEnqueueAcquireGLObjects(cmd_queue, 1, &vbo_cl, 0,0,0);

	std::cout << "enqueue object " << ret << std::endl;
	
	/* Execute OpenCL Kernel */
	
	const size_t global_item_size = 1;
	const size_t local_item_size = 1;

	ret = clEnqueueNDRangeKernel(cmd_queue, this->clKernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
	
	std::cout << "enqueue kernel " << ret << std::endl;

	ret = clEnqueueReleaseGLObjects(cmd_queue, 1, &vbo_cl, 0,0,0);

	std::cout << "enqueu release " << ret << std::endl;
	clFinish(cmd_queue);

	this->draw(vbo);
	
	}
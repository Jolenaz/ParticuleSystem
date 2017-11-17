
#include "RenderManager.class.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

void GL_DUMP_ERROR(std::string message){
    int glErrorCode = 0;
    if ((glErrorCode = glGetError()) != GL_NO_ERROR)
        std::cout << message << " (error code: " << glErrorCode << ")\n";
}

RenderManager::RenderManager(float w, float h, uint caracSize){
	this->cam.ratio = (float)w / (float)h;
	this->cam.transform.translate(Vec3(0.0,2.0,20.0));
	this->caracSize = caracSize;
	this->fullSize =  caracSize * caracSize * caracSize;
	this->center[0] = 0.0f;
	this->center[1] = 0.0f;
	this->center[2] = 0.0f;
	//this->center[3] = 1.0f;
	this->delta = 1.0f / 60.0f;
	std::cout << this->fullSize << std::endl;
	this->_initSDL(w,h);
	this->_initGLCL();
	this->getClProgram();
	this->getGlProgram();
	this->initParticule();
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
			SDL_GL_SetSwapInterval(0);
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
	if (err_code != 0){std::cout << "error create cl progran : " << err_code  << " for prog : " << prog << std::endl;}
	
	cl_int ret = clBuildProgram(prog, 1, &this->clDevice, "-cl-fast-relaxed-math", NULL, NULL);
	
	if (ret != 0){std::cout << "error compilation cl program : " << ret << std::endl;}

	if (ret != 0){
		size_t len = 0;
		cl_int retour = CL_SUCCESS;
		retour = clGetProgramBuildInfo(prog, this->clDevice, CL_PROGRAM_BUILD_LOG, 0, NULL, &len);
		char buffer[len];
		retour = clGetProgramBuildInfo(prog, this->clDevice, CL_PROGRAM_BUILD_LOG, len, buffer, NULL);
		std::cout << "failed" <<  buffer << std::endl;
	}

	this->initKernel = clCreateKernel(prog, "initPoints", &ret);
	if (ret != 0){std::cout << "error compilation cl program : " << ret << std::endl;}
	this->updateKernel = clCreateKernel(prog, "updatePoints", &ret);
	if (ret != 0){std::cout << "error compilation cl program : " << ret << std::endl;}
}

void RenderManager::getGlProgram(){
	int ret = glCreateProgram();
	GL_DUMP_ERROR("glCreateProgram : ");
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
		GL_DUMP_ERROR("glCreateShader : ");
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
		GL_DUMP_ERROR("glShaderSource : ");
		glCompileShader(shader_id);
		GL_DUMP_ERROR("glCompileShader : ");
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_return);
		GL_DUMP_ERROR("glGetShaderiv : ");
        if (compilation_return == 0)
        {
            GLchar buf[10000];
	        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &compilation_return);
	        glGetShaderInfoLog(shader_id, 10000, &compilation_return, buf);
	        std::cout << buf << std::endl;
        }
		glAttachShader(ret, shader_id);
		GL_DUMP_ERROR("glAttachShader");
    }
	glLinkProgram(ret);
	GL_DUMP_ERROR("glLinkProgram : ");
    this->glProgramId = ret;
}

void RenderManager::draw(){

	glUseProgram(this->glProgramId);
	GL_DUMP_ERROR("glUseProgram : ");
	Mat4 VP =  this->cam.get_projMat() * this->cam.transform.get_localToWorld();
	glUniformMatrix4fv(glGetUniformLocation(this->glProgramId, "VP"), 1, GL_TRUE, (const GLfloat*)&VP.value);
	GL_DUMP_ERROR("glUniformMatrix4fv : ");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GL_DUMP_ERROR("glClear : ");
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	GL_DUMP_ERROR("glBindBuffer : ");

	GLuint vao;
	glGenVertexArrays(1, &vao);
	GL_DUMP_ERROR("glGenVertexArrays : ");
	glBindVertexArray(vao);
	GL_DUMP_ERROR("glBindVertexArray : ");
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(0));
	GL_DUMP_ERROR("glVertexAttribPointer : ");
	glEnableVertexAttribArray(0);
	GL_DUMP_ERROR("glEnableVertexAttribArray : ");
	glDrawArrays(GL_POINTS,0,this->fullSize);
	GL_DUMP_ERROR("glDrawArrays : ");
	SDL_GL_SwapWindow(this->window);
}

void RenderManager::_initGLCL(){
	
	cl_uint         nb_platform;
	cl_uint         nb_device;
	cl_platform_id  platforms[100];
	cl_device_id    devices[100];

	clGetPlatformIDs(
			100,
			platforms,
			&nb_platform);

	clGetDeviceIDs(
			platforms[0],
			CL_DEVICE_TYPE_GPU,
			100,
			devices,
			&nb_device);
	
	this->clDevice = devices[0];

	for (int i = 0; i < 10; i++)
	{
		size_t retSize;
		clGetDeviceInfo(devices[0], CL_DEVICE_NAME, 0, NULL, &retSize);
		if (retSize == 0)
			continue;
		char extensions[retSize];
		clGetDeviceInfo(devices[0], CL_DEVICE_NAME, retSize, extensions, &retSize);
		std::cout << extensions << std::endl;
	}
	cl_uint nb;
	clGetDeviceInfo(this->clDevice, CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, sizeof(cl_uint), &nb, NULL);
	std::cout << "vector width : " << nb << std::endl;
	

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, this->fullSize * sizeof(Vertex),NULL,GL_DYNAMIC_DRAW);

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
	if (err_code != 0) {std::cout << "error create cl context : " << err_code  << " for context : " << this->clContext << std::endl;}

	this->vbo_cl = clCreateFromGLBuffer(this->clContext,CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,this->vbo,&err_code);
	if (err_code != 0){std::cout << "cll mem allocation " << err_code << std::endl;}

}

void RenderManager::initParticule(){

	cl_int err_code;

	glFinish(); 

	this->cmd_queue = clCreateCommandQueue(this->clContext, this->clDevice, 0, &err_code);
	if (err_code != 0){std::cout << "create command queue " << err_code << std::endl;}

	err_code = clEnqueueAcquireGLObjects(this->cmd_queue, 1, &this->vbo_cl, 0,0,0);
	if (err_code != 0){std::cout << "enqueue object " << err_code << std::endl;}


	err_code = clSetKernelArg(this->initKernel, 0, sizeof(cl_mem), (void *)&this->vbo_cl);
	if (err_code != 0){std::cout << "set kernel arg0 init " << err_code << std::endl;}
	err_code = clSetKernelArg(this->initKernel, 1, sizeof(uint), (void *)&this->caracSize);
	if (err_code != 0){std::cout << "set kernel arg1 init " << err_code << std::endl;}

	const size_t global_item_size = this->fullSize;

	err_code = clEnqueueNDRangeKernel(this->cmd_queue, this->initKernel, 1, NULL, &global_item_size, NULL, 0, NULL, NULL);
	if (err_code != 0){std::cout << "enqueue kernel " << err_code << std::endl;}
	
	err_code = clEnqueueReleaseGLObjects(this->cmd_queue, 1, &this->vbo_cl, 0,0,0);
	if (err_code != 0){std::cout << "enqueu release " << err_code << std::endl;}

	clFinish(cmd_queue);

}

void RenderManager::update(){

	cl_int err_code;

	glFinish(); 

	err_code = clSetKernelArg(this->updateKernel, 0, sizeof(cl_mem), (void *)&this->vbo_cl);
	if (err_code != 0){std::cout << "set kernel arg0 update " << err_code << std::endl;}
	err_code = clSetKernelArg(this->updateKernel, 1, sizeof(float), (void *)&this->delta);
	if (err_code != 0){std::cout << "set kernel arg1 update " << err_code << std::endl;}
	err_code = clSetKernelArg(this->updateKernel, 2, sizeof(float[3]), (void *)&this->center);
	if (err_code != 0){std::cout << "set kernel arg1 update " << err_code << std::endl;}
	
	err_code = clEnqueueAcquireGLObjects(this->cmd_queue, 1, &this->vbo_cl, 0,0,0);
	if (err_code != 0){std::cout << "enqueue object in update " << err_code << std::endl;}

	const size_t global_item_size = this->fullSize;
	
	err_code = clEnqueueNDRangeKernel(this->cmd_queue, this->updateKernel, 1, NULL,	&global_item_size, NULL, 0,	0, 0);
	if (err_code != 0){		std::cout << "enqueue kernel in update " << err_code << std::endl;		exit(0);}
	
	err_code = clEnqueueReleaseGLObjects(this->cmd_queue, 1, &this->vbo_cl, 0,0,0);
	if (err_code != 0){std::cout << "enqueu release in update " << err_code << std::endl;}
	
	clFinish(cmd_queue);
}

void RenderManager::showFPS(float FPS, int frameIndex ){
    static float mo = 0;

    if (frameIndex < 29)
    {
        mo += FPS;
        return;
    }

    char str[100];
    sprintf(str, "%.1f fps", mo/30);
    SDL_SetWindowTitle(this->window, str);
    mo = 0;
}

#pragma once
#include "Camera.class.hpp"
#include "struct.hpp"
#include <SDL.h>
#include <fstream>
#include <vector>
#include <OpenGL/gl3.h> 
#include <OpenCL/cl.h>
#include <OpenCL/cl_gl_ext.h>
#include <OpenGL/CGLDevice.h>
#include <OpenGL/CGLCurrent.h>

class RenderManager{

    typedef struct shader_info{
        GLenum	flag;
        std::string addr;
    }   t_shader_info;

        //constructor

    public:
    RenderManager(float, float, uint);
    virtual ~RenderManager(void);

    private:
    RenderManager(void);
    RenderManager(RenderManager const &);
    RenderManager & operator=(RenderManager const &);
    
    
public:
    
    int debug;
    Camera cam;
    void            _initSDL(int width, int height);
    void            _initGLCL();
    void            getClProgram();
    void            getGlProgram();

    void            initParticule();

    void            draw();
    SDL_Window      *window;
    GLuint          vbo;
    cl_mem          vbo_cl;
    cl_command_queue cmd_queue;
    SDL_GLContext   glContext;
    cl_context      clContext;
    cl_device_id    clDevice;
    int             glProgramId;
    cl_kernel       initKernel;
    
    uint            caracSize;
    uint            fullSize;

};
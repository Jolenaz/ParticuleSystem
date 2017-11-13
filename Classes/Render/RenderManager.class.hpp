
#pragma once
#include "Camera.class.hpp"
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
    RenderManager(float, float);
    virtual ~RenderManager(void);

    private:
    RenderManager(void);
    RenderManager(RenderManager const &);
    RenderManager & operator=(RenderManager const &);
    
    public:

    Camera cam;
    void            _initSDL(int width, int height);
    void            _initGLCL();
    void            getClProgram();
    void            getGlProgram();
    void            draw(GLuint);
    SDL_Window      *window;
    SDL_GLContext   glContext;
    cl_context      clContext;
    cl_device_id    clDevice;
    int             glProgramId;
    cl_kernel       clKernel;
    

};

#pragma once
#include "Camera.class.hpp"
#include <SDL.h>
#include <OpenGL/gl3.h> 
#include <OpenCL/cl.h>
#include <OpenCL/cl_gl_ext.h>
#include <OpenGL/CGLDevice.h>
#include <OpenGL/CGLCurrent.h>

class RenderManager{

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
    void _initSDL(int width, int height);
    void _initGLCL();
    SDL_Window      *window;
    SDL_GLContext   glContext;
    cl_context      clContext;
    int             glProgramId;
    

};
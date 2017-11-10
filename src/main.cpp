#include "particule.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

int main_loop(RenderManager & rManager){
        SDL_Event		ev;
        SDL_PumpEvents();

        if (SDL_PollEvent(&ev)){
                if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
                        return (0);
        }
        return (1);
}

int main()
{
        RenderManager rManager(1024,768);
        while(main_loop(rManager))
        {

        }
        return (0);
}
#include "particule.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

#define NB_POINT 1000000


int main()
{
        uint p = floor(pow(NB_POINT, 1.0/3.0)) + 1;
        RenderManager rManager(1024,768,p);
        SceneManager sManager(rManager);

        int     i = 0;
        int     old_time;
        int     tmp;

        while(sManager.main_loop())
        {
                tmp = SDL_GetTicks() - old_time;
                rManager.delta = (double)tmp / 1000.0f ;
                if (sManager.state == fly)
                        sManager.get_mouse(rManager);
                old_time += tmp;
                rManager.timeru += rManager.delta;
                rManager.showFPS(1/rManager.delta, i);
                rManager.draw();
                if (!sManager.pause)
                        rManager.update();
                i = i < 29 ? i + 1 : 0;
        }
        return (0);
}
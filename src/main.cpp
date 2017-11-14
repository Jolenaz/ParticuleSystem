#include "particule.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

#define NB_POINT 1000

int main_loop(RenderManager & rManager){
        SDL_Event		ev;
        SDL_PumpEvents();

        if (SDL_PollEvent(&ev)){
                if (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE || ev.type == SDL_QUIT)
                        return (0);
                if (ev.key.keysym.sym == SDLK_w){
                        rManager.cam.translateCam(Vec3(0,0,-0.1)); 
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_s){
                        rManager.cam.translateCam(Vec3(0,0,0.1));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_a){
                        rManager.cam.translateCam(Vec3(-0.1,0,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_d){
                        rManager.cam.translateCam(Vec3(0.1,0,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_q){
                        rManager.cam.translateCam(Vec3(0,-0.1,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_e){
                        rManager.cam.translateCam(Vec3(0,0.1,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_UP){
                        rManager.cam.transform.rotate(Vec3(1,0,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_DOWN){
                        rManager.cam.transform.rotate(Vec3(-1,0,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_LEFT){
                        rManager.cam.transform.rotate(Vec3(0,1,0));
                        rManager.debug = 1;}
                if (ev.key.keysym.sym == SDLK_RIGHT){
                        rManager.cam.transform.rotate(Vec3(0,-1,0));
                        rManager.debug = 1;}
        }
        return (1);
}

int main()
{
        uint p = floor(pow(NB_POINT, 1.0/3.0)) + 1;
        RenderManager rManager(1024,768,p);
        while(main_loop(rManager))
        {
                rManager.draw();
        }
        return (0);
}
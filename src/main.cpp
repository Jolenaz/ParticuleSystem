#include "particule.hpp"
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

#define NB_POINT 1000000
#define MOVE_SPEED 1.0f

int main_loop(RenderManager & rManager){
        SDL_Event		ev;
        SDL_PumpEvents();

        if (SDL_PollEvent(&ev)){
                if ( ( ev.type == SDL_KEYDOWN && (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE)))
                        return (0);
                if (ev.key.keysym.sym == SDLK_w){
                        rManager.cam.translateCam(Vec3(0,0,-MOVE_SPEED)); 
                        }
                if (ev.key.keysym.sym == SDLK_s){
                        rManager.cam.translateCam(Vec3(0,0,MOVE_SPEED));
                        }
                if (ev.key.keysym.sym == SDLK_a){
                        rManager.cam.translateCam(Vec3(-MOVE_SPEED ,0,0));
                        }
                if (ev.key.keysym.sym == SDLK_d){
                        rManager.cam.translateCam(Vec3(MOVE_SPEED ,0,0));
                        }
                if (ev.key.keysym.sym == SDLK_q){
                        rManager.cam.translateCam(Vec3(0,-MOVE_SPEED ,0));
                        }
                if (ev.key.keysym.sym == SDLK_e){
                        rManager.cam.translateCam(Vec3(0,MOVE_SPEED ,0));
                        }
                if (ev.key.keysym.sym == SDLK_UP){
                        rManager.cam.transform.rotate(Vec3(1,0,0));
                        }
                if (ev.key.keysym.sym == SDLK_DOWN){
                        rManager.cam.transform.rotate(Vec3(-1,0,0));
                        }
                if (ev.key.keysym.sym == SDLK_LEFT){
                        rManager.cam.transform.rotate(Vec3(0,1,0));
                        }
                if (ev.key.keysym.sym == SDLK_RIGHT){
                        rManager.cam.transform.rotate(Vec3(0,-1,0));
                        }
                if (ev.key.keysym.sym == SDLK_1 && ev.type == SDL_KEYDOWN && ev.key.repeat == 0){
                        std::cout << "1 bro" << std::endl;
                        rManager.initParticule();
                        rManager.running = 0;
                        }
                if (ev.key.keysym.sym == SDLK_SPACE && ev.type == SDL_KEYDOWN && ev.key.repeat == 0){
                        rManager.running = !rManager.running;
                        }
                if (ev.key.keysym.sym == SDLK_t){
                     //   rManager.center += Vec4(1.0f, 1.0f, 1.0f, 0.0f);
                      //  std::cout << rManager.center << std::endl;
                        rManager.debug = !rManager.debug;}
        }
        return (1);
}

void get_mouse(RenderManager & rManager){
        
int x;
int y;

SDL_GetMouseState(&x,&y);

Vec4 pos;

pos.x = 2 * float(x) / 768.0 - 4.0 / 3.0;
pos.y = -2 * float(y) / 768.0 + 1.0;
pos.z = -1.0f;
pos.w = 1.0;

Vec3 ray = (rManager.cam.transform.get_position() + (Vec3(rManager.cam.transform.get_worldToLocal() * pos) - rManager.cam.transform.get_position()) * 20.0f) * tanf(rManager.cam.fov / 2.0f * M_PI / 180.0f) * 2.0f;
        
rManager.center[0] = ray.x;
rManager.center[1] = ray.y;
rManager.center[2] = ray.z;

}

int main()
{
        uint p = floor(pow(NB_POINT, 1.0/3.0)) + 1;
        RenderManager rManager(1024,768,p);

        int     i = 0;
        int     old_time;
        int     tmp;

        while(main_loop(rManager))
        {
                tmp = SDL_GetTicks() - old_time;
                rManager.delta = (double)tmp / 1000.0f ;
                get_mouse(rManager);
                old_time += tmp;
                rManager.timeru += rManager.delta;
                rManager.showFPS(1/rManager.delta, i);
                rManager.draw();
                if (rManager.running)
                        rManager.update();
                i = i < 29 ? i + 1 : 0;

        }
        return (0);
}
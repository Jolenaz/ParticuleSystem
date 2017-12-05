#include "SceneManager.class.hpp"
#define MOVE_SPEED 1.0f

int SceneManager::main_loop(){
    SDL_Event		ev;
    SDL_PumpEvents();

    if (SDL_PollEvent(&ev)){
        if ( ( ev.type == SDL_KEYDOWN && (ev.key.keysym.sym == SDLK_c || ev.key.keysym.sym == SDLK_ESCAPE)))
                return (0);
        if (ev.key.keysym.sym == SDLK_SPACE && ev.type == SDL_KEYDOWN && ev.key.repeat == 0){
                SDL_SetRelativeMouseMode(SDL_TRUE);
                this->state = fly;
        }
        if (ev.key.keysym.sym == SDLK_KP_1 && ev.type == SDL_KEYDOWN && ev.key.repeat == 0){
                SDL_SetRelativeMouseMode(SDL_TRUE);
                this->state = fly;
        }
        if (ev.key.keysym.sym == SDLK_KP_2 && ev.type == SDL_KEYDOWN && ev.key.repeat == 0){
                SDL_SetRelativeMouseMode(SDL_FALSE);
                SDL_ShowCursor(SDL_ENABLE);
                this->state = mouseClick;
        }
        if (ev.key.keysym.sym == SDLK_KP_3 && ev.type == SDL_KEYDOWN && ev.key.repeat == 0){
                SDL_SetRelativeMouseMode(SDL_FALSE);
                SDL_ShowCursor(SDL_ENABLE);
                this->state = mouseTrack;
        }
        switch (this->state){
                case mouseClick:
                this->clickMode(ev);
                break;
                case mouseTrack:
                this->trackMode(ev);
                break;                
                case fly:
                this->flyMode(ev);
                break;
                case intro :
                return(1);
        }
        this->inputKeyboard(ev);
        }
    return (1);
}

void SceneManager::clickMode(SDL_Event ev)
{
        if (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT)
        {
                this->get_mouse(this->rManager);
        }
}

void SceneManager::flyMode(SDL_Event ev)
{
        int x = 0;
        int y = 0;
        
        SDL_GetRelativeMouseState(&x,&y);
        this->rManager.cam.transform.rotate(Vec3(-y / 10.0,0,0));
        this->rManager.cam.transform.rotate(Vec3(0,-x / 10.0,0));
        
        SDL_WarpMouseInWindow(this->rManager.window, this->rManager.width / 2, this->rManager.height / 2);

}

void SceneManager::trackMode(SDL_Event ev)
{
        this->get_mouse(this->rManager);
}

void SceneManager::inputKeyboard(SDL_Event ev)
{        if (ev.key.keysym.sym == SDLK_w){
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
        if (ev.key.keysym.sym == SDLK_t){
                //std::cout << rManager.cam.transform.get_worldToLocal() * rManager.cam.transform.get_localToWorld() << std::endl; 
                //   rManager.center += Vec4(1.0f, 1.0f, 1.0f, 0.0f);
                // std::cout << rManager.center << std::endl;
                rManager.debug = !rManager.debug;
        }
}


void SceneManager::get_mouse(RenderManager & rManager){
        
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

SceneManager::SceneManager(RenderManager & reManager) : rManager(reManager) {
    this->state = intro;
}

SceneManager::~SceneManager(){};

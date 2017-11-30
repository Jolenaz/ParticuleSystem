#pragma once
#include "render.hpp"

typedef enum e_state{
        fly,
        normal,
        track
}t_state;

class SceneManager{



public:
    virtual ~SceneManager(void);        
    SceneManager(RenderManager & rManager);
    
    void    get_mouse(RenderManager & rManager);
    int     main_loop(void); 

    t_state state;

private:
    RenderManager  & rManager;
    SceneManager(void);

    void flyMode(SDL_Event ev);
    void normalMode(SDL_Event ev);
    void trackMode(SDL_Event ev);


};
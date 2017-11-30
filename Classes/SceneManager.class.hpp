#pragma once
#include "render.hpp"

typedef enum e_state{
        fly,
        fixed,
}t_state;

class SceneManager{



public:
    virtual ~SceneManager(void);        
    SceneManager(RenderManager & rManager);
    
    void    get_mouse(RenderManager & rManager);
    int     main_loop(void); 

    t_state state;
    bool pause;

private:
    RenderManager  & rManager;
    SceneManager(void);

    void flyMode(SDL_Event ev);
    void fixedMode(SDL_Event ev);


};
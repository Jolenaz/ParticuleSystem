#include "particule.hpp"
#include <vector>
#pragma OPENCL EXTENSION cl_apple_gl_sharing : enable

#define NB_POINT 1000000


uint parse_args(int ac, char **av)
{
        if (ac == 1){return (NB_POINT);}
        
        int bo = std::atoi(av[1]);

        if (bo > 0){
                if (ac == 2){ 
                        char * ptr = av[1];
                        while(*ptr >= '0' && *ptr <= '9')
                        {
                                ptr++;
                        }
                        if (*ptr == 'k' || *ptr == 'K'){
                                return ((bo <= 10000) ? bo * 1000 : 10000000);}
                        else if (*ptr == 'm' || *ptr == 'M'){
                                return ((bo <= 10 ) ? bo * 1000000 : 10000000);}
                        else {
                                return (bo <= 10000000 ? bo : 10000000);
                        }
                }
                std::string mu = std::string(av[2]);
                if (mu == "k" || mu == "K"){
                        return ((bo <= 10000) ? bo * 1000 : 10000000);}
                else if (mu == "m" || mu == "M"){
                        return ((bo <= 10 ) ? bo * 1000000 : 10000000);}
                else{
                        return (bo <= 10000000 ? bo : 10000000);}
        }else{
                return NB_POINT;
        }
}

int main(int ac, char **av)
{
        uint p = floor(pow(parse_args(ac, av), 1.0/3.0)) + 1;
        
        RenderManager rManager(1024,768,p);
        SceneManager sManager(rManager);

        int     i = 0;
        int     old_time;
        int     tmp;



        while(sManager.main_loop())
        {
                tmp = SDL_GetTicks() - old_time;
                rManager.delta = (double)tmp / 1000.0f ;
                old_time += tmp;
                rManager.timeru += rManager.delta;
                if (sManager.state != intro)
                {
                        rManager.showFPS(1/rManager.delta, i);
                        rManager.draw();
                        if (sManager.state != fly)
                                rManager.update();
                }else{
                        rManager.drawIntro();
                }
                i = i < 29 ? i + 1 : 0;
        }
        return (0);
}
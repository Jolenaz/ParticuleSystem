# 42run

Project in C++11 and OpenGL 4.1
No Engine Use, all made by myself (I have pore graphic skills, sory about that)

to install you need SDL2 and SDL_ttf on Mac OSX

./brew install sdl2

./brew install sdl_ttf

on the following commande line change path to find sdl2 and sdl_ttf include

clang++ ./Classes/**/*.cpp src/* -std=c++11 -I ./Classes/Math -I ./include/  -I ./Classes/Render -I ./Classes/GamePlay -I ./Classes -I ~/.brew/Cellar/sdl_ttf/2.0.11_1/include/SDL/ -I ~/.brew/Cellar/sdl2/2.0.9/include/SDL2/  -framework OpenGL -framework OpenCL -lSDL2 -L/Users/jbelless/.brew/lib -o Particle

use args to select the number of particles. 1000000 is de fault value.

./Particle 2m

./Particle 100k

./Particle 10m

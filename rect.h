#pragma once

#include <SDL2/SDL.h>

class Rect{

public:
    Rect();
    ~Rect();

    void setCenter(int x,int y);
    bool isClicked(SDL_Event &event);
    
    int _x=0,_y=0;
};
#pragma once

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "window.h"

class Text{

public:
    Text(const std::string &fontPath,int fontSize,const std::string &text,const SDL_Color &color);
    void display(int x,int y) const;
    static SDL_Texture *loadFont(SDL_Renderer *renderer,const std::string &fontPath,int fontSize,const std::string &text,const SDL_Color &color);

private:
    SDL_Texture *_texture;
    mutable SDL_Rect _rect;

};

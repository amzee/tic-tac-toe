#include "text.h"

Text::Text(const std::string &fontPath,int fontSize,const std::string &text,const SDL_Color &color)
{
    _texture = loadFont(Window::renderer,fontPath,fontSize,text,color);
    SDL_QueryTexture(_texture,nullptr,nullptr,&_rect.w,&_rect.h);
}

void Text::display(int x,int y) const
{
    _rect.x = x;
    _rect.y = y;

    SDL_RenderCopy(Window::renderer,_texture,nullptr,&_rect);
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer,const std::string &fontPath,int fontSize,const std::string &text,const SDL_Color &color)
{
    auto font = TTF_OpenFont(fontPath.c_str(),fontSize);

    if(!font){
        std::cerr << "Failed to load to font." << std::endl;
    }

    auto Surface = TTF_RenderText_Solid(font,text.c_str(),color);

    if(!Surface){
        std::cerr << "Failed to create text surface" << std::endl; 
    } 

    auto texture = SDL_CreateTextureFromSurface(renderer,Surface);

    if(!texture){
        std::cerr << "Failed to create text texture" << std::endl;
    }

    SDL_FreeSurface(Surface);

    return texture;
}
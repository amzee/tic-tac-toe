#include "rect.h"

Rect::Rect()
{

}

Rect::~Rect()
{
    
}

void Rect::setCenter(int x,int y)
{
    _x = x;
    _y = y;
}

bool Rect::isClicked(SDL_Event &event)
{   
    int posX,posY;
    if(event.type == SDL_MOUSEBUTTONDOWN){
        int left=_x-50,right=_x+50,up=_y-50,down=_y+50;
        SDL_GetMouseState(&posX,&posY);
        if(posX > left  && posX < right){
            if(posY > up  && posY < down ){
                return true;
            }
        }
    }

    return false;
}
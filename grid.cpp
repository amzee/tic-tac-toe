#include "grid.h"

Grid::Grid()
{

}

Grid::~Grid()
{

}

void Grid::draw()
{
    SDL_SetRenderDrawColor(Window::renderer,255,255,255,255);

    //horizontal lines
    SDL_RenderDrawLine(Window::renderer,200,100,200,400);
    SDL_RenderDrawLine(Window::renderer,300,100,300,400);

    //vertical lines
    SDL_RenderDrawLine(Window::renderer,100,200,400,200);
    SDL_RenderDrawLine(Window::renderer,100,300,400,300);

}

void Grid::drawElements(std::vector<std::vector<Rect>> boundaries,std::vector<std::vector<state>> gridState)
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(gridState[i][j] == circle){
                drawCircle(boundaries[i][j]._x,boundaries[i][j]._y);
            }

            if(gridState[i][j] == cross){
                drawCross(boundaries[i][j]._x,boundaries[i][j]._y);
            }

        }
    }

    SDL_RenderPresent(Window::renderer);
}

void Grid::drawCircle(int x,int y)
{
    ellipseRGBA(Window::renderer, x, y, 20, 20, 255, 255, 255, 255);
}

void Grid::drawCross(int x,int y)
{
    SDL_RenderDrawLine(Window::renderer,x-20,y-20,x+20,y+20);
    SDL_RenderDrawLine(Window::renderer,x-20,y+20,x+20,y-20);   
}
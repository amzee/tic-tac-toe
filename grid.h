#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "window.h"
#include "rect.h"
#include "state.h"
#include <vector>

class Grid{

public:
    Grid();
    ~Grid();

    void draw();
    void drawElements(std::vector<std::vector<Rect>> boundaries,std::vector<std::vector<state>> gridState);

private:
    void drawCircle(int x,int y);
    void drawCross(int x,int y);

};
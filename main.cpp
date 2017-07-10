#include "window.h"
#include "grid.h"
#include "rect.h"
#include "state.h"
#include "text.h"
#include "ai.h"

#include <vector>
#include <string>
#include <iostream>

int main(){
    Window screen("Tic Tac Toe",500,500);
    Grid grd;
    std::vector<std::vector<Rect>> boundaries(3,std::vector<Rect>(3));

    std::string fontPath = "res/font.ttf";
    SDL_Color white{255,255,255,255};
    int fontSize = 30;
    std::string displayText = "Lets Begin";

    bool draw = false;
    int moveCount = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int x = 150+(100*i);
            int y = 150+(100*j);
            boundaries[i][j].setCenter(x,y);
        }
    }

    std::vector<std::vector<state>> gridState(3,std::vector<state>(3,empty));   

    bool player = true;
    bool gameOver = false;

    while(!screen.isClosed()){

        Text label(fontPath,fontSize,displayText,white);
        screen.clear();
        grd.draw();
        label.display();
        grd.drawElements(boundaries,gridState);
        SDL_Event event;

        if(SDL_PollEvent(&event)){

            screen.pollEvents(event);

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(boundaries[i][j].isClicked(event) && gridState[i][j] == empty){
                        moveCount++;
                        if(player){
                            gridState[i][j] = circle;
                            gameOver = checkifWon(gridState,i,j,circle,moveCount,&draw);
                            displayText = "Player 2's turn";
                        }else{
                            gridState[i][j] = cross;
                            gameOver = checkifWon(gridState,i,j,cross,moveCount,&draw);
                            displayText = "Player 1's turn";
                        }
                        player = !player;
                        //std::cout << moveCount << std::endl; 
                    }
                }
            }

        }

        if(gameOver && !draw){
            if(player){
                displayText = "Player 2 Won";
            }else{
                displayText = "Player 1 Won";
            }
        }

        if(draw){
            displayText = "Its a draw";
        }

    }
    return 0;
}
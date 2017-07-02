#include "window.h"
#include "grid.h"
#include "rect.h"
#include "state.h"
#include "text.h"

#include <vector>

bool draw = false;
int moveCount = 0;

bool checkifWon(const std::vector<std::vector<state>> &gridState,int x,int y,state s){

    for(int i=0;i<3;i++){
        if(gridState[x][i] != s){
            break;
        }
        if(i==2){
            return true;
        } 
    }

    for(int i=0;i<3;i++){
        if(gridState[i][y] != s){
            break;
        }
        if(i==2){
            return true;
        }
    }

    if(x==y){
        for(int i=0;i<3;i++){
            if(gridState[i][i] != s){
                break;
            }

            if(i==2){
                return true;
            }
        }
    }

    if(x+y == 2){
        for(int i=0;i<3;i++){
            if(gridState[i][2-i] != s){
                break;
            }

            if(i==2){
                return true;
            }
        }
    }

    if(moveCount == 9){
        draw = true;
    }
    return false;
}

int main(){
    Window screen("Tic Tac Toe",500,500);
    Grid grd;
    std::vector<std::vector<Rect>> boundaries(3,std::vector<Rect>(3));

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

    while(!screen.isClosed() && !gameOver){

        screen.clear();
        grd.draw();
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
                            gameOver = checkifWon(gridState,i,j,circle);
                        }else{
                            gridState[i][j] = cross;
                            gameOver = checkifWon(gridState,i,j,cross);
                        }
                        player = !player;
                        std::cout << moveCount << std::endl; 
                    }
                }
            }

        }

        if(gameOver && !draw){
            if(player){
                std::cout << "Player 2 Won" << std::endl;
            }else{
                std::cout << "Player 1 Won" << std::endl;
            }
        }

        if(draw){
            std::cout << "Game Drawn" << std::endl;
            break;
        }

    }
    return 0;
}
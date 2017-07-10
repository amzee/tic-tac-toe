#include "ai.h"

bool checkifWon(const std::vector<std::vector<state>> &gridState,int x,int y,state s,int moveCount,bool *draw){

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
        *draw = true;
    }
    return false;
}


int dfs(std::vector<std::vector<state>> gridState,bool circle){
    int score = INT_MIN;
    int x=0,y=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(gridState[i][j] == empty){
                if(circle){
                    gridState[i][j] = circle;
                    //if(checkifWon(gridState,i,j,circle,))
                    dfs(gridState,false);
                }else{
                    gridState[i][j] = cross;
                    dfs(gridState,false);
                }
            }
        }
    }
}
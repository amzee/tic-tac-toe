#pragma once

#include "state.h"
#include <vector>

void chooseMove(std::vector<std::vector>> &gridState);

int dfs(std::vector<std::vector<state>> gridState);

bool checkifWon(const std::vector<std::vector<state>> &gridState,int x,int y,state s,int moveCount,bool *draw);
#pragma once

#include "state.h"
#include <vector>

int dfs(std::vector<std::vector<state>> gridState);
bool checkifWon(const std::vector<std::vector<state>> &gridState,int x,int y,state s,int moveCount,bool *draw);
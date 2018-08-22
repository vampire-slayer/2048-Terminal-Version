#include "Game.h"

void Game::insertIntoRandomCell() {
    if (!moved) {
        return;
    }
    auto emptyCells = getEmptyCells();
    vector<int> valueToInsert = {2, 4};

    if (!emptyCells.empty()) {
        auto randomCell = emptyCells[rand() % emptyCells.size()];
        grid[randomCell.first][randomCell.second] = valueToInsert[rand() % valueToInsert.size()];
    }
}
    
vector<pair<int, int> > Game::getEmptyCells() {
    vector<pair<int, int> > emptyCells;
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (!grid[i][j]) {
                emptyCells.push_back({i, j});
            }
        }
    }
    return emptyCells;
}
    

Game::Game(int size, int power) {
    srand((unsigned) time(0));
    moved = true;
    maxScore = (1LL << power);
    curScore = 0;
    grid.resize(size, vector<long long>(size, 0));
    insertIntoRandomCell();
}
    
void Game::moveUp() {
    moved = false;
    
    for (int i = 0; i < grid.size(); i++) {
        int idx = 0;
        bool combine = true;
        
        for (int j = 0; j < grid.size(); j++) {
            if (grid[j][i]) {
                if (combine && idx - 1 >= 0 && grid[idx - 1][i] == grid[j][i]) {
                    grid[idx - 1][i] += grid[j][i];
                    curScore = max(curScore, grid[idx - 1][i]);
                    combine = false;
                } else {
                    grid[idx++][i] = grid[j][i];
                    combine = true;
                }
            }
        }
        
        for (int j = idx; j < grid.size(); j++) {
            if (grid[j][i]) {
                moved = true;
            }
            grid[j][i] = 0;
        }
    }
    
    if (moved) {
        insertIntoRandomCell();
    }
}
    
void Game::moveDown() {
    moved = false;
    
    for (int i = 0; i < grid.size(); i++) {
        int lastIndex = (int) grid.size() - 1;
        int idx = lastIndex;
        bool combine = true;
        
        for (int j = lastIndex; j >= 0; j--) {
            if (grid[j][i]) {
                if (combine && idx + 1 <= lastIndex && grid[idx + 1][i] == grid[j][i]) {
                    grid[idx + 1][i] += grid[j][i];
                    curScore = max(curScore, grid[idx + 1][i]);
                    combine = false;
                } else {
                    grid[idx--][i] = grid[j][i];
                    combine = true;
                }
            }
        }
        
        for (int j = idx; j >= 0; j--) {
            if (grid[j][i]) {
                moved = true;
            }
            grid[j][i] = 0;
        }
    }
    
    if (moved) {
        insertIntoRandomCell();
    }
}
    
void Game::moveLeft() {
    moved = false;
    
    for (int i = 0; i < grid.size(); i++) {
        int idx = 0;
        bool combine = true;
        
        for (int j = 0; j < grid.size(); j++) {
            if (grid[i][j]) {
                if (combine && idx - 1 >= 0 && grid[i][idx - 1] == grid[i][j]) {
                    grid[i][idx - 1] += grid[i][j];
                    curScore = max(curScore, grid[i][idx - 1]);
                    combine = false;
                } else {
                    grid[i][idx++] = grid[i][j];
                    combine = true;
                }
            }
        }
        
        for (int j = idx; j < grid.size(); j++) {
            if (grid[i][j]) {
                moved = true;
            }
            grid[i][j] = 0;
        }
    }
    
    if (moved) {
        insertIntoRandomCell();
    }
}
    
void Game::moveRight() {
    moved = false;
    
    for (int i = 0; i < grid.size(); i++) {
        int lastIndex = (int) grid.size() - 1;
        int idx = lastIndex;
        bool combine = true;
        
        for (int j = lastIndex; j >= 0; j--) {
            if (grid[i][j]) {
                if (combine && idx + 1 <= lastIndex && grid[i][idx + 1] == grid[i][j]) {
                    grid[i][idx + 1] += grid[i][j];
                    curScore = max(curScore, grid[i][idx + 1]);
                    combine = false;
                } else {
                    grid[i][idx--] = grid[i][j];
                    combine = true;
                }
            }
        }
        
        for (int j = idx; j >= 0; j--) {
            if (grid[i][j]) {
                moved = true;
            }
            grid[i][j] = 0;
        }
    }

    if (moved) {
        insertIntoRandomCell();
    }
}
    
vector<vector<long long> > Game::getGameState() {
    return grid;
}
    
bool Game::checkIfWon() {
    return curScore == maxScore;
}
    
bool Game::checkIfLost() {
    if (getEmptyCells().empty()) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (i - 1 >= 0 && grid[i - 1][j] == grid[i][j]) {
                    return false;
                }
                if (i + 1 < grid.size() && grid[i + 1][j] == grid[i][j]) {
                    return false;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == grid[i][j]) {
                    return false;
                }
                if (j + 1 < grid.size() && grid[i][j + 1] == grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
    
void Game::increaseLevel() {
    if (checkIfWon()) {
        maxScore <<= 1;
    }
}


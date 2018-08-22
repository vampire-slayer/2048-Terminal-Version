#include "GameHandler.h"

void GameHandler::initializeColors() {
    start_color();
    
    int color = 2;
    
    for (int power = 1; power <= 62; power++) {
        if (color == COLOR_BLUE) {
            color++;
        }
        
        numToPowerMap[1LL << power] = power;
        init_pair(power, COLOR_BLUE, color);
        color++;
        
        if (color == 8) {
            color = 1;
        }
    }
}

void GameHandler::turnOnColorProperties(long long num) {
    attron(COLOR_PAIR(numToPowerMap[num]));
}

void GameHandler::turnOffColorProperties(long long num) {
    attroff(COLOR_PAIR(numToPowerMap[num]));
}

void GameHandler::displayGameState() {
    clear();
    
    auto grid = game->getGameState();
    int rowIndex = 2;
    int stepSize = 10;
    
    for (int i = 0; i < grid.size(); i++) {
        int colIndex = 2;
        for (int j = 0; j < grid[i].size(); j++) {
            move(rowIndex, colIndex);
            
            if (grid[i][j]) {
                turnOnColorProperties(grid[i][j]);
                printw(" %d ", grid[i][j]);
                turnOffColorProperties(grid[i][j]);
            } else {
                printw(" . ");
            }
            
            colIndex += stepSize;
        }
        rowIndex += 2;
    }
    
    refresh();
}

void GameHandler::destroy() {
    delete game;
    endwin();
}

GameHandler::GameHandler(int size, int power) {
    this->size = size;
    this->power = power;
    initscr();
    game = new Game(size, power);
    curs_set(0);
    initializeColors();
    displayGameState();
}

GameHandler::~GameHandler() {
    destroy();
}

void GameHandler::actionOnKey(int key) {
    switch (key) {
        case KEY_UP:
            game->moveUp();
            break;
        case KEY_DOWN:
            game->moveDown();
            break;
        case KEY_LEFT:
            game->moveLeft();
            break;
        case KEY_RIGHT:
            game->moveRight();
            break;
    }
    displayGameState();
}

bool GameHandler::checkIfWon() {
    return game->checkIfWon();
}

bool GameHandler::checkIfLost() {
    return game->checkIfLost();
}

void GameHandler::increaseLevel() {
    game->increaseLevel();
}


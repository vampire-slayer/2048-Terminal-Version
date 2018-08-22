#ifndef _GameHandler_h
#define _GameHandler_h

#include <unordered_map>
#include <ncurses.h>
#include "Game.h"

class GameHandler {
    Game *game;
    int size;
    int power;
    unordered_map<long long, int> numToPowerMap;
    
    void initializeColors();
    void turnOnColorProperties(long long num);
    void turnOffColorProperties(long long num);
    void displayGameState();
    void destroy();
    
public:
    GameHandler(int size, int power);
    ~GameHandler();
    
    void actionOnKey(int key);
    bool checkIfWon();
    bool checkIfLost();
    void increaseLevel();
};

#endif


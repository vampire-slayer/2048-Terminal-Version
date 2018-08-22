#ifndef _Game_h
#define _Game_h

#include <vector>

using namespace std;

class Game {
    bool moved;
    long long maxScore;
    long long curScore;
    vector<vector<long long> > grid;

    void insertIntoRandomCell();
    vector<pair<int, int> > getEmptyCells();
    
public:
    Game(int size, int power);
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    vector<vector<long long> > getGameState();
    bool checkIfWon();
    bool checkIfLost();
    void increaseLevel();
};

#endif


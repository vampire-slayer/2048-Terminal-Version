#include "GameUtil.h"

void startGame() {
    int size = 4; // The size of the grid is 4x4 by default
    int power = 11; // The target score is 2^11, i.e. 2048 by default

    GameHandler gameHandler(size, power);
    keypad(stdscr, TRUE);
    
    while (true) {
        printw("\n\nMESSAGE: Welcome to the console version of 2048. Cheers! Press the 'q' key to quit.");
        
        if (gameHandler.checkIfWon()) {
            printw("\n\nMESSAGE: Congrats, you've won! Press 'q' to quit, any other key to try the next level.");
            refresh();
            
            int key = getch();
            if (key != 'q') {
                printw("\n\nMESSAGE: Level increased successfully! Continue playing.");
                refresh();
                gameHandler.increaseLevel();
            } else {
                break;
            }
        }
        
        if (gameHandler.checkIfLost()) {
            printw("\n\nSorry, you've lost! Press any key to quit.");
            refresh();
            getch();
            break;
        }
        
        int key = getch();
        switch (key) {
            case 'q':
                return;
            default:
                gameHandler.actionOnKey(key);
                break;
        }
    }
}

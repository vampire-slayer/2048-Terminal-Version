# 2048-Terminal-Version

This is a terminal-based version of the popular 2048 game (http://gabrielecirulli.github.io/2048/) built using C++ and the ncurses library.

## How to build the game from the source files?

Navigate to the project directory and run the following command on terminal:

`g++ -std=c++11 -lncurses main.cpp src/Game.cpp src/GameHandler.cpp src/GameUtil.cpp -o 2048`

## How to run the game?

Run the generated file `2048` in order to play the game. This can be done using the following command:

`./2048`

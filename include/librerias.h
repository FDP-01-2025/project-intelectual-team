#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int TRACK_LENGTH = 10;
const int PLAYER_COUNT = 2;
const int OBSTACLE_COUNT = 2;

struct Player {
    string name;
    int position;
    int score;
};

void initializePlayers(Player players[]);
void showTrack(Player players[], int obstacles[]);
void movePlayer(Player &player);
void generateObstacles(int obstacles[]);
void loadGame();

#endif


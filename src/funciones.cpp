#include "../include/librerias.h"

void initializePlayers(Player players[]) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> players[i].name;
        players[i].position = 0;
        players[i].score = 0;
    }
}

void showTrack(Player players[], int obstacles[]) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        cout << players[i].name << " (" << players[i].score << "): ";
        for (int j = 0; j < TRACK_LENGTH; j++) {
            if (j == players[i].position)
                cout << "|-o-|";
            else if (obstacles[j])
                cout << "|X|";
            else
                cout << "|__|";
        }
        cout << endl;
    }
    cout << endl;
}


void movePlayer(Player &player) {
    int step = rand() % 3 + 1;
    player.position += step;
    player.score += step;
    if (player.position >= TRACK_LENGTH) {
        player.position = TRACK_LENGTH - 1;
    }
}

void generateObstacles(int obstacles[]) {
    for (int i = 0; i < TRACK_LENGTH; i++) {
        obstacles[i] = 0;
    }
    for (int i = 0; i < OBSTACLE_COUNT; i++) {
        int pos = rand() % (TRACK_LENGTH - 1) + 1;
        obstacles[pos] = 1;
    }
}



#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TRACK_LENGTH = 20;

struct Player {
    string name;
    int position;
    int score;
};

void startNewGame(Player players[2]) {
    for (int i = 0; i < 2; i++) {
        cout << "Nombre del jugador " << (i + 1) << ": ";
        cin >> players[i].name;
        players[i].position = 0;
        players[i].score = 0;
    }
}

void saveGame(Player players[2]) {
    ofstream file("partida.txt");
    for (int i = 0; i < 2; i++) {
        file << players[i].name << " " << players[i].position << " " << players[i].score << "\n";
    }
    file.close();
    cout << "Partida guardada.\n";
}

void viewSavedGame() {
    Player players[2];
    ifstream file("partida.txt");
    if (file.is_open()) {
        for (int i = 0; i < 2; i++) {
            file >> players[i].name >> players[i].position >> players[i].score;
        }
        file.close();
        cout << "\n--- PARTIDA GUARDADA ---\n";
        for (int i = 0; i < 2; i++) {
            cout << players[i].name << ": " << players[i].score << " puntos (posicion " << players[i].position << ")\n";
        }
    } else {
        cout << "No se encontro una partida guardada.\n";
    }

    cout << "\nPresiona ENTER para volver al menu...";
    cin.ignore();
    cin.get();
}

void displayTrack(Player players[2], bool obstacles[TRACK_LENGTH]) {
    cout << "\n=== CARRERA ===\n";

    for (int i = 0; i < 2; i++) {
        cout << players[i].name << " |";

        for (int j = 0; j < TRACK_LENGTH; j++) {
            if (players[i].position == j) {
                cout << (i == 0 ? 'A' : 'B');
            } else if (j == TRACK_LENGTH - 1) {
                cout << "|";
            } else if (obstacles[j]) {
                cout << "X";
            } else {
                cout << "-";
            }
        }

        cout << "| Puntos: " << players[i].score << "\n";
    }

    cout << "===============\n";
}

void movePlayers(Player players[2], bool obstacles[TRACK_LENGTH]) {
    for (int i = 0; i < 2; i++) {
        cout << players[i].name << ", presiona ENTER para avanzar...";
        cin.ignore();
        cin.get();

        int move = 1 + rand() % 3;
        players[i].position += move;

        if (players[i].position >= TRACK_LENGTH) {
            players[i].position = TRACK_LENGTH - 1;
            players[i].score += 10;
            cout << players[i].name << " ha llegado a la meta!\n";
        } else if (obstacles[players[i].position]) {
            cout << "Obstaculo encontrado! Retrocedes una casilla.\n";
            players[i].position--;
            if (players[i].position < 0)
                players[i].position = 0;
            obstacles[players[i].position + 1] = false;
            players[i].score -= 1;
        } else {
            players[i].score += move;
        }
    }
}

void showScores(Player players[2]) {
    cout << "\n--- PUNTUACIONES ---\n";
    for (int i = 0; i < 2; i++) {
        cout << players[i].name << ": " << players[i].score << " puntos\n";
    }
}

#endif
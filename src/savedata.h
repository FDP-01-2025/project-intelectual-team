#ifndef SAVEDATA_H
#define SAVEDATA_H

#include <iostream>
#include <fstream>
#include "player.h"
using namespace std;

// Guardar y mostrar partida de carreras 
void saveRaceGame(Player players[2]) {
    ofstream file("race_save.txt");
    for (int i = 0; i < 2; i++) {
        file << players[i].name << " " << players[i].position << " " << players[i].score << "\n";
    }
    file.close();
    cout << "Partida de carrera guardada.\n";
}

void viewRaceSavedGame() {
    Player players[2];
    ifstream file("race_save.txt");
    if (file.is_open()) {
        for (int i = 0; i < 2; i++) {
            file >> players[i].name >> players[i].position >> players[i].score;
        }
        file.close();
        cout << "\n--- PARTIDA GUARDADA (CARRERAS) ---\n";
        for (int i = 0; i < 2; i++) {
            cout << players[i].name << ": " << players[i].score << " puntos (posición " << players[i].position << ")\n";
        }
    } else {
        cout << "No se encontró una partida guardada de carreras.\n";
    }

    cout << "\nPresiona ENTER para volver al menú...";
    cin.ignore();
    cin.get();
}

// Guardar y mostrar partida de penales
void savePenaltyGame(Player p1, Player p2, int round) {
    ofstream file("penalty_save.txt");
    file << p1.name << " " << p1.goals << "\n";
    file << p2.name << " " << p2.goals << "\n";
    file << round << "\n";
    file.close();
    cout << "Partida de penales guardada.\n";
}

void viewPenaltySavedGame() {
    ifstream file("penalty_save.txt");
    if (file.is_open()) {
        string name1, name2;
        int goals1, goals2, round;
        file >> name1 >> goals1;
        file >> name2 >> goals2;
        file >> round;
        file.close();
        cout << "\n--- PARTIDA GUARDADA (PENALES) ---\n";
        cout << name1 << ": " << goals1 << " goles\n";
        cout << name2 << ": " << goals2 << " goles\n";
        cout << "Ronda actual: " << round << "\n";
    } else {
        cout << "No se encontro una partida guardada de penales.\n";
    }

    cout << "\nPresiona ENTER para volver al menu";
    cin.ignore();
    cin.get();
}

#endif
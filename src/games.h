#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "utils.h"
#include "deco.h"
#include "savedata.h"

using namespace std;

void takePenalty(Player &player, int difficulty) {
    int chosenNumber, keeperNumber;

    clearScreen();
    drawShooter();
    cout << "\n" << player.name << ", elige un numero del 1 al " << difficulty << " para disparar: ";
    cin >> chosenNumber;

    while (chosenNumber < 1 || chosenNumber > difficulty) {
        cout << "Ese numero no es valido. Intenta de nuevo: ";
        cin >> chosenNumber;
    }

    keeperNumber = rand() % difficulty + 1;

    clearScreen();
    cout << "\n" << player.name << " toma carrera...\n";
    pause(1);
    shootBallAnimation();
    drawGoalkeeper();

    cout << "\nTu numero: " << chosenNumber << " | Portero eligio: " << keeperNumber << "\n";

    if (chosenNumber == keeperNumber) {
        cout << "¡Atajadon del portero! .... El publico se vuelve loco.\n";
    } else {
        cout << "¡GOOOOOOL de " << player.name << "... ! El estadio ruge de emocion.\n";
        player.goals++;
    }

    pause(2);
}

void startPenaltyGame() {
    srand(time(nullptr));
    Player p1, p2;
    p1.goals = 0;
    p2.goals = 0;

    clearScreen();
    printDivider();
    cout << "BIENVENIDO AL TORNEO DE PENALES\n";
    printDivider();
    cout << "Jugador 1, ingresa tu nombre: ";
    cin >> p1.name;
    cout << "Jugador 2, ingresa tu nombre: ";
    cin >> p2.name;

    const int MAX_ROUNDS = 5;
    int round = 1;

    while (round <= MAX_ROUNDS) {
        int difficulty = 10 + round * 2;
        clearScreen();
        printDivider();
        cout << " Ronda " << round << " | Dificultad: 1-" << difficulty << "\n";
        printDivider();
        takePenalty(p1, difficulty);
        takePenalty(p2, difficulty);

        // Guardar partida tras cada ronda
        savePenaltyGame(p1, p2, round);

        round++;
    }

    while (p1.goals == p2.goals) {
        clearScreen();
        printDivider();
        cout << " EMPATE... ¡Muerte subita!\n";
        printDivider();
        takePenalty(p1, 20);
        takePenalty(p2, 20);

        // Guardar partida tras cada muerte súbita
        savePenaltyGame(p1, p2, round);
    }

    clearScreen();
    printDivider();
    cout << "RESULTADO FINAL:\n";
    cout << p1.name << ": " << p1.goals << " goles\n";
    cout << p2.name << ": " << p2.goals << " goles\n";
    printDivider();

    if (p1.goals > p2.goals)
        cout << "¡" << p1.name << " se lleva la victoria!\n";
    else
        cout << "¡" << p2.name << " se lleva la victoria!\n";

    pause(3);
}

// Juego de carreras

const int TRACK_LENGTH = 20;

void startRaceGame() {
    Player players[2];
    bool obstacles[TRACK_LENGTH] = {false};

    for (int i = 5; i < TRACK_LENGTH - 1; i += 5) {
        obstacles[i] = true;
    }

    for (int i = 0; i < 2; i++) {
        cout << "Nombre del jugador " << (i + 1) << ": ";
        cin >> players[i].name;
        players[i].position = 0;
        players[i].score = 0;
    }

    bool gameRunning = true;
    while (gameRunning) {
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
                cout << "¡Obstaculo encontrado! Retrocedes una casilla.\n";
                players[i].position--;
                if (players[i].position < 0)
                    players[i].position = 0;
                obstacles[players[i].position + 1] = false;
                players[i].score -= 1;
            } else {
                players[i].score += move;
            }
        }

        if (players[0].position >= TRACK_LENGTH - 1 || players[1].position >= TRACK_LENGTH - 1) {
            gameRunning = false;

            cout << "\n--- PUNTUACIONES ---\n";
            for (int i = 0; i < 2; i++) {
                cout << players[i].name << ": " << players[i].score << " puntos\n";
            }

            saveRaceGame(players);
        }
    }

    pause(3);
}

#endif


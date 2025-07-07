#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "utils.h"
#include "deco.h"
//LLamado a las librerias ".h" que complementan el juego
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
//Generar un numero aleatorio
    clearScreen();
    cout << "\n" << player.name << " toma carrera...\n";
    pause(1);
    shootBallAnimation();
    drawGoalkeeper();

    cout << "\nTu numero: " << chosenNumber << " | Portero eligio: " << keeperNumber << "\n";

    
    if (chosenNumber == keeperNumber) {
        cout << "¡Atajadon del portero! El publico se vuelve loco.\n";
    } else {
        cout << "¡GOOOOOOL de " << player.name << "! El estadio ruge de emocion.\n";
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
//Funcion para que las rondas maximas sean 5
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
        round++;
    }
// Empate: muerte súbita
    while (p1.goals == p2.goals) {
        clearScreen();
        printDivider();
        cout << " EMPATE... ¡Muerte subita!\n";
        printDivider();
        takePenalty(p1, 20);
        takePenalty(p2, 20);
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
        cout << " ¡" << p2.name << " se lleva la victoria!\n";

    pause(3);
}

#endif


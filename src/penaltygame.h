#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "utils.h"
#include "deco.h"
using namespace std;
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
        round++;
    }}
    
    void takePenalty(Player &player, int difficulty) {
    int chosenNumber, keeperNumber;
//Declarar variables
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

    cout << "\nTu numero: " << chosenNumber << " | Portero elige: " << keeperNumber << "\n";

    if (chosenNumber == keeperNumber) {
        cout << "X ¡Atajadon del portero! El publico se vuelve loco.\n";
    } else {
        cout << "¡GOOOOOOL de " << player.name << "! El estadio ruge de emocion.\n";
        player.goals++;
    }}
#endif
#ifndef DECO_H
#define DECO_H

#include <iostream>
using namespace std;

// Decoración para el portero en penales
void drawGoalkeeper() {
    cout << "    |=========|\n";
    cout << "    |   \\o/   |\n";
    cout << "    |    |    |\n";
    cout << "    |   / \\   |\n";
    cout << "    |_________|\n";
}

// Decoración para el tirador en penales
void drawShooter() {
    cout << "     o\n";
    cout << "    /|\\\n";
    cout << "    / \\\n";
    cout << "Jugador se prepara...\n";
}

// Animación simple de balón disparándose
void shootBallAnimation() {
    for (int i = 0; i < 5; i++) {
        cout << "\n\n\n\t\tBalon -> ";
        for (int j = 0; j < i; j++) cout << " ";
        cout << "O\n";
    }
}

// Línea divisoria para mejorar lectura
void printDivider() {
    cout << "========================================\n";
}

#endif

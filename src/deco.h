#ifndef DECO_H
#define DECO_H

#include <iostream>
using namespace std;

void drawGoalkeeper() {
    cout << "    |=========|\n";
    cout << "    |   \\o/   |\n";
    cout << "    |    |    |\n";
    cout << "    |   / \\   |\n";
    cout << "    |_________|\n";
}

void drawShooter() {
    cout << "     o\n";
    cout << "    /|\\\n";
    cout << "    / \\\n";
    cout << "Jugador se prepara...\n";
}

void shootBallAnimation() {
    for (int i = 0; i < 5; i++) {
        cout << "\n\n\n\t\tBalón -> ";
        for (int j = 0; j < i; j++) cout << " ";
        cout << "O\n";
    }
}

void printDivider() {
    cout << "========================================\n";
}

#endif

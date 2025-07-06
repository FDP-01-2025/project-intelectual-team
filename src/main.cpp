#include "../include/librerias.h"
#include <ctime>

int main() {
    srand(time(0));
    Player players[PLAYER_COUNT];
    int obstacles[TRACK_LENGTH];
    int option;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Iniciar partida \n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option) {
    case 1: {
        initializePlayers(players);
        generateObstacles(obstacles);
        bool finished = false;
        cin.ignore();

        do {
            showTrack(players, obstacles);

            for (int i = 0; i < PLAYER_COUNT; i++) {
                cout << players[i].name << " presiona ENTER para avanzar...";
                cin.get();

                if (obstacles[players[i].position]) {
                    cout << "Obstaculo! Retrocedes una casilla.\n";
                    players[i].position -= 1;
                    if (players[i].position < 0) players[i].position = 0;
                    players[i].score -= 1;
                    if (players[i].score < 0) players[i].score = 0;

                    obstacles[players[i].position + 1] = 0;
                }

                movePlayer(players[i]);

                if (players[i].position >= TRACK_LENGTH - 1) {
                    players[i].position = TRACK_LENGTH - 1;
                    cout << "\n " << players[i].name << " ha ganado, FELICIDADES!\n";
                    finished = true;
                    break;
                }
            }

        } while (!finished);

        break;
    }

    case 2:
        cout << "Saliendo del juego...\n";
        break;

    default:
        cout << "Opcion invalida. Intente de nuevo por favor.\n";
        break;
}

    } while (option != 2);

    return 0;
}


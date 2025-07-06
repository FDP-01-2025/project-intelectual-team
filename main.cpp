#include "src/game.h"

int main() {
    srand(time(0));

    Player players[2];
    bool obstacles[TRACK_LENGTH] = { false };

    for (int i = 5; i < TRACK_LENGTH - 1; i += 5) {
        obstacles[i] = true;
    }

    int option;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Iniciar nueva partida\n";
        cout << "2. Ver partida guardada\n";
        cout << "3. Salir del juego\n";
        cout << "Elije una opcion: ";
        cin >> option;

        switch (option) {
            case 1:
                startNewGame(players);
                {
                    bool gameRunning = true;
                    while (gameRunning) {
                        displayTrack(players, obstacles);
                        movePlayers(players, obstacles);

                        if (players[0].position >= TRACK_LENGTH - 1 || players[1].position >= TRACK_LENGTH - 1) {
                            gameRunning = false;
                            showScores(players);
                            saveGame(players);
                        }
                    }
                }
                break;
            case 2:
                cin.ignore();
                viewSavedGame();
                break;
            case 3:
                cout << "Saliendo del juego...\n";
                return 0;
            default:
                cout << "Opcion no valida.\n";
        }

    } while (true);

    return 0;
}

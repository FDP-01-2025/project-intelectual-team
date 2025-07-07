#include <iostream>
#include <cstdlib>
#include <ctime>
#include "src/games.h"
#include "src/savedata.h"

using namespace std;

int main() {
    srand(time(nullptr));
    int option;

    do {
        cout << "\n--- MENu PRINCIPAL ---\n";
        cout << "1. Jugar Penales\n";
        cout << "2. Jugar Carreras\n";
        cout << "3. Ver partidas guardadas\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> option;

        switch(option) {
            case 1:
                startPenaltyGame();
                break;
            case 2:
                startRaceGame();
                break;
            case 3: {
                int gameChoice;
                cout << "¿De que juego quieres ver la partida guardada?\n";
                cout << "1. Penales\n2. Carreras\nElige: ";
                cin >> gameChoice;
                cin.ignore();

                if (gameChoice == 1)
                    viewPenaltySavedGame();
                else if (gameChoice == 2)
                    viewRaceSavedGame();
                else
                    cout << "Opción invalida.\n";

                break;
            }
            case 4:
                cout << "Gracias por jugar. ¡Hasta luego!\n";
                return 0;
            default:
                cout << "Opcion no valida. Intenta de nuevo.\n";
        }
    } while(true);

    return 0;
}


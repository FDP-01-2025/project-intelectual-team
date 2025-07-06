#include <iostream>
#include "src/game.h"

using namespace std;

int main() {
    int option;
    do {
        cout << "\n=====================\n";
        cout << "🚗  RACING GAME MENU 🚗\n";
        cout << "=====================\n";
        cout << "1. Start New Race\n";
        cout << "2. View Records\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case 1:
                startRace();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                cout << "\n👋 Thank you for playing! Goodbye.\n";
                break;
            default:
                cout << "\n❗ Invalid option. Please try again.\n";
        }
    } while(option != 3);

    return 0;
}

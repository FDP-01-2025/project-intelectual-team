#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

struct Player {
    string name;
    int goals;     // Para penales
    int position;  // Para carreras
    int score;     // Para carreras
};

#endif

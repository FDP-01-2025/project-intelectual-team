#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <ctime>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause(float seconds) {
    time_t start = time(nullptr);
    while (time(nullptr) - start < seconds) {}
}

#endif

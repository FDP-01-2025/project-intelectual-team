#ifndef LIBRERIAS_H
#define LIBRERIAS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int LONGITUD_CARRERA = 20;
const int NUM_JUGADORES = 2;
const int NUM_OBSTACULOS = 5;

struct Jugador {
    string nombre;
    int posicion;
    int puntuacion;
};

void iniciarJugadores(Jugador jugadores[]);
void mostrarPista(Jugador jugadores[], int obstaculos[]);
void moverJugador(Jugador &jugador);
void generarObstaculos(int obstaculos[]);
void guardarPartida(Jugador jugadores[]);
void cargarPartida(Jugador jugadores[]);

#endif

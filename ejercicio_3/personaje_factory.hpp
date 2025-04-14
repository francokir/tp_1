#pragma once
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../ejercicio_2/personajes.hpp"

using namespace std;

class PersonajeFactory {
public:
    static void inicializarRandom();
    static int numeroAleatorio(int min, int max);
    static unique_ptr<Arma> crearArmaAleatoria();
    static unique_ptr<Arma> crearArma(const string&);
    static unique_ptr<Mago> crearMago();
    static unique_ptr<Mago> crearMago(const string&); 
    static unique_ptr<Guerrero> crearGuerrero();
    static unique_ptr<Guerrero> crearGuerrero(const string&);
    static vector<unique_ptr<Personaje>> crearPersonajesArmados();
};
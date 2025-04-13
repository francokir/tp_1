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
    static shared_ptr<Arma> crearArmaAleatoria();
    static shared_ptr<Arma> crearArma(const string&);
    static shared_ptr<Mago> crearMago();
    static shared_ptr<Mago> crearMago(const string&); 
    static shared_ptr<Guerrero> crearGuerrero();
    static shared_ptr<Guerrero> crearGuerrero(const string&);
    static vector<shared_ptr<Personaje>> crearPersonajesArmados();
};
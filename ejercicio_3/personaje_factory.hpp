#pragma once
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../ejercicio_2/armas.hpp"
#include "../ejercicio_2/personajes.hpp"

using namespace std;

class PersonajeFactory {
public:
    static void inicializarRandom() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    static int numeroAleatorio(int min, int max) {
        return min + rand() % (max - min + 1);
    }

    static shared_ptr<Arma> crearArmaAleatoria() {
        int tipo = numeroAleatorio(0, 9);

        switch (tipo) {
            case 0:
                return make_shared<Espada>("Espada Legendaria", 50, 3.5f, "Acero", 100);
            case 1:
                return make_shared<HachaSimple>("Hacha Rústica", 40, 5.0f, "Hierro", 80);
            case 2:
                return make_shared<HachaDoble>("Hacha Doble de Guerra", 60, 6.5f, "Acero", 90);
            case 3:
                return make_shared<Lanza>("Lanza de Caza", 35, 2.5f, "Madera y Acero", 70);
            case 4:
                return make_shared<Garrote>("Garrote con Púas", 45, 4.0f, "Hierro oxidado", 85);
            case 5:
                return make_shared<Baston>("Bastón Elemental", 30, 2, "Fuego", "Regeneración");
            case 6:
                return make_shared<LibroHechizos>("Libro de Furia", 40, 3, "Oscuridad", "Invocación");
            case 7:
                return make_shared<Pocion>("Poción Tóxica", 25, 1, "Veneno", "Daño progresivo");
            case 8:
                return make_shared<Amuleto>("Amuleto de Suerte", 20, 5, "Luz", "Inmortalidad");
            case 9:
                return make_shared<Baston>("Bastón de Hielo", 35, 2, "Hielo", "Congelación");
            default:
                return make_shared<Espada>("Espada común", 20, 2.5f, "Hierro", 50);
        }
    }


    static shared_ptr<Mago> crearMago() {
        int tipoMago = numeroAleatorio(0, 4);
        
        switch (tipoMago) {
            case 0:
                return make_shared<Hechicero>("Hechicero", 1, 100, "Fuego", 50);
            case 1:
                return make_shared<Conjurador>("Conjurador", 1, 100, "Eter", 50);
            case 2:
                return make_shared<Brujo>("Brujo", 1, 100, "Oscuridad", 50);
            case 3:
                return make_shared<Nigromante>("Nigromante", 1, 100, "Muerte", 50);
        }
    }

    static shared_ptr<Guerrero> crearGuerrero() {
        int tipoGuerrero = numeroAleatorio(0, 5);
        
        switch (tipoGuerrero) {
            case 0:
                return make_shared<Barbaro>("Barbaro", 1, 100, 70, 40);
            case 1:
                return make_shared<Paladin>("Paladin", 1, 100, 70, 10);
            case 2:
                return make_shared<Caballero>("Caballero", 1, 100, 70, 20);
            case 3:
                return make_shared<Mercenario>("Mercenario", 1, 100, 70, 30);
            case 4:
                return make_shared<Gladiador>("Gladiador", 1, 100, 70, 30);
        }
    }

    static vector<shared_ptr<Personaje>> crearPersonajesArmados() {
        vector<shared_ptr<Personaje>> personajes;
    
        int cantidadMagos = numeroAleatorio(3, 7);
        int cantidadGuerreros = numeroAleatorio(3, 7);
    
        for (int i = 0; i < cantidadMagos; ++i) {
            auto mago = crearMago();
            int cantidadArmas = numeroAleatorio(0, 2);
            for (int j = 0; j < cantidadArmas; ++j) {
                mago->agregarArma(crearArmaAleatoria());
            }
            personajes.push_back(mago);
        }
    
        for (int i = 0; i < cantidadGuerreros; ++i) {
            auto guerrero = crearGuerrero();
            int cantidadArmas = numeroAleatorio(0, 2);
            for (int j = 0; j < cantidadArmas; ++j) {
                guerrero->agregarArma(crearArmaAleatoria());
            }
            personajes.push_back(guerrero);
        }
    
        return personajes;
    }
};
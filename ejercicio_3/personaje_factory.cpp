#include "personaje_factory.hpp"

void PersonajeFactory::inicializarRandom() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

int PersonajeFactory::numeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

shared_ptr<Arma> PersonajeFactory::crearArmaAleatoria() {
    int tipo = numeroAleatorio(0, 8);

    switch (tipo) {
        case 0:
            return make_shared<Espada>("Espada medieval", 50, 3.5f, "Acero", 100);
        case 1:
            return make_shared<HachaSimple>("Hacha letal", 40, 5.0f, "Hierro", 80);
        case 2:
            return make_shared<HachaDoble>("Hacha Doble de filosa", 60, 6.5f, "Acero", 90);
        case 3:
            return make_shared<Lanza>("Lanza rustica", 35, 2.5f, "Madera y Acero", 70);
        case 4:
            return make_shared<Garrote>("Garrote con Púas", 45, 4.0f, "Hierro oxidado", 85);
        case 5:
            return make_shared<Baston>("Bastón magico", 30, 2, "Fuego", "Regeneración");
        case 6:
            return make_shared<LibroHechizos>("Libro imposible", 40, 3, "Oscuridad", "Invocación");
        case 7:
            return make_shared<Pocion>("Poción Tóxica", 25, 1, "Veneno", "Daño progresivo");
        case 8:
            return make_shared<Amuleto>("Amuleto de Suerte", 20, 5, "Luz", "Inmortalidad");
    }
    throw runtime_error("Error con el 'tipo'");
}

shared_ptr<Arma> PersonajeFactory::crearArma(const string& tipo) {
    if (tipo == "Espada")
        return make_shared<Espada>("Espada medieval", 50, 3.5f, "Acero", 100);
    else if (tipo == "HachaSimple")
        return make_shared<HachaSimple>("Hacha letal", 40, 5.0f, "Hierro", 80);
    else if (tipo == "HachaDoble")
        return make_shared<HachaDoble>("Hacha Doble filosa", 60, 6.5f, "Acero", 90);
    else if (tipo == "Lanza")
        return make_shared<Lanza>("Lanza rustica", 35, 2.5f, "Madera y Acero", 70);
    else if (tipo == "Garrote")
        return make_shared<Garrote>("Garrote con Púas", 45, 4.0f, "Hierro oxidado", 85);
    else if (tipo == "Baston")
        return make_shared<Baston>("Bastón magico", 30, 2, "Fuego", "Regeneración");
    else if (tipo == "LibroHechizos")
        return make_shared<LibroHechizos>("Libro imposible", 40, 3, "Oscuridad", "Invocación");
    else if (tipo == "Pocion")
        return make_shared<Pocion>("Poción Tóxica", 25, 1, "Veneno", "Daño progresivo");
    else if (tipo == "Amuleto")
        return make_shared<Amuleto>("Amuleto de Suerte", 20, 5, "Luz", "Inmortalidad");
    else
        throw invalid_argument("El Arma "+ tipo +" no esta en el videojuego.");
}

shared_ptr<Mago> PersonajeFactory::crearMago() {
    int tipoMago = numeroAleatorio(0, 3);
    
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
    throw runtime_error("error con 'tipomago'");
}

shared_ptr<Mago> PersonajeFactory::crearMago(const string& subtipo) {
    if (subtipo == "Hechicero")
        return make_shared<Hechicero>("Hechicero", 1, 100, "Fuego", 50);
    else if (subtipo == "Conjurador")
        return make_shared<Conjurador>("Conjurador", 1, 100, "Eter", 50);
    else if (subtipo == "Brujo")
        return make_shared<Brujo>("Brujo", 1, 100, "Oscuridad", 50);
    else if (subtipo == "Nigromante")
        return make_shared<Nigromante>("Nigromante", 1, 100, "Muerte", 50);
    else
        throw invalid_argument("Subtipo de mago desconocido: " + subtipo);
}

shared_ptr<Guerrero> PersonajeFactory::crearGuerrero() {
    int tipoGuerrero = numeroAleatorio(0, 4);
    
    switch (tipoGuerrero) {
        case 0:
            return make_shared<Barbaro>("Barbaro", 1, 100, 100, 40);
        case 1:
            return make_shared<Paladin>("Paladin", 1, 100, 100, 10);
        case 2:
            return make_shared<Caballero>("Caballero", 1, 100, 100, 20);
        case 3:
            return make_shared<Mercenario>("Mercenario", 1, 100, 100, 30);
        case 4:
            return make_shared<Gladiador>("Gladiador", 1, 100, 100, 30);
    }
    throw runtime_error("error con 'tipoguerrero'");
}

shared_ptr<Guerrero> PersonajeFactory::crearGuerrero(const string& subtipo) {
    if (subtipo == "Barbaro")
        return make_shared<Barbaro>("Barbaro", 1, 100, 70, 40);
    else if (subtipo == "Paladin")
        return make_shared<Paladin>("Paladin", 1, 100, 70, 10);
    else if (subtipo == "Caballero")
        return make_shared<Caballero>("Caballero", 1, 100, 70, 20);
    else if (subtipo == "Mercenario")
        return make_shared<Mercenario>("Mercenario", 1, 100, 70, 30);
    else if (subtipo == "Gladiador")
        return make_shared<Gladiador>("Gladiador", 1, 100, 70, 30);
    else
        throw invalid_argument("Subtipo de guerrero desconocido: " + subtipo);
}

vector<shared_ptr<Personaje>> PersonajeFactory::crearPersonajesArmados() {
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

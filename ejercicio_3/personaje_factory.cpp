#include "personaje_factory.hpp"

void PersonajeFactory::inicializarRandom() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

int PersonajeFactory::numeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

unique_ptr<Arma> PersonajeFactory::crearArmaAleatoria() {
    int tipo = numeroAleatorio(0, 8);

    switch (tipo) {
        case 0:
            return make_unique<Espada>("Espada medieval", 50, 3.5f, "Acero", 100);
        case 1:
            return make_unique<HachaSimple>("Hacha letal", 40, 5.0f, "Hierro", 80);
        case 2:
            return make_unique<HachaDoble>("Hacha Doble de filosa", 60, 6.5f, "Acero", 90);
        case 3:
            return make_unique<Lanza>("Lanza rustica", 35, 2.5f, "Madera y Acero", 70);
        case 4:
            return make_unique<Garrote>("Garrote con Púas", 45, 4.0f, "Hierro oxidado", 85);
        case 5:
            return make_unique<Baston>("Bastón magico", 30, 2, "Fuego", "Regeneración");
        case 6:
            return make_unique<LibroHechizos>("Libro imposible", 40, 3, "Oscuridad", "Invocación");
        case 7:
            return make_unique<Pocion>("Poción Tóxica", 25, 1, "Veneno", "Daño progresivo");
        case 8:
            return make_unique<Amuleto>("Amuleto de Suerte", 20, 5, "Luz", "Inmortalidad");
    }
    throw runtime_error("Error con el 'tipo'");
}

unique_ptr<Arma> PersonajeFactory::crearArma(const string& tipo) {
    if (tipo == "Espada")
        return make_unique<Espada>("Espada medieval", 50, 3.5f, "Acero", 100);
    else if (tipo == "HachaSimple")
        return make_unique<HachaSimple>("Hacha letal", 40, 5.0f, "Hierro", 80);
    else if (tipo == "HachaDoble")
        return make_unique<HachaDoble>("Hacha Doble filosa", 60, 6.5f, "Acero", 90);
    else if (tipo == "Lanza")
        return make_unique<Lanza>("Lanza rustica", 35, 2.5f, "Madera y Acero", 70);
    else if (tipo == "Garrote")
        return make_unique<Garrote>("Garrote con Púas", 45, 4.0f, "Hierro oxidado", 85);
    else if (tipo == "Baston")
        return make_unique<Baston>("Bastón magico", 30, 2, "Fuego", "Regeneración");
    else if (tipo == "LibroHechizos")
        return make_unique<LibroHechizos>("Libro imposible", 40, 3, "Oscuridad", "Invocación");
    else if (tipo == "Pocion")
        return make_unique<Pocion>("Poción Tóxica", 25, 1, "Veneno", "Daño progresivo");
    else if (tipo == "Amuleto")
        return make_unique<Amuleto>("Amuleto de Suerte", 20, 5, "Luz", "Inmortalidad");
    else
        throw invalid_argument("El Arma "+ tipo +" no esta en el videojuego.");
}

unique_ptr<Mago> PersonajeFactory::crearMago() {
    int tipoMago = numeroAleatorio(0, 3);
    
    switch (tipoMago) {
        case 0:
            return make_unique<Hechicero>("Hechicero", 1, 100, "Fuego", 50);
        case 1:
            return make_unique<Conjurador>("Conjurador", 1, 100, "Eter", 50);
        case 2:
            return make_unique<Brujo>("Brujo", 1, 100, "Oscuridad", 50);
        case 3:
            return make_unique<Nigromante>("Nigromante", 1, 100, "Muerte", 50);
    }
    throw runtime_error("error con 'tipomago'");
}

unique_ptr<Mago> PersonajeFactory::crearMago(const string& subtipo) {
    if (subtipo == "Hechicero")
        return make_unique<Hechicero>("Hechicero", 1, 100, "Fuego", 50);
    else if (subtipo == "Conjurador")
        return make_unique<Conjurador>("Conjurador", 1, 100, "Eter", 50);
    else if (subtipo == "Brujo")
        return make_unique<Brujo>("Brujo", 1, 100, "Oscuridad", 50);
    else if (subtipo == "Nigromante")
        return make_unique<Nigromante>("Nigromante", 1, 100, "Muerte", 50);
    else
        throw invalid_argument("Subtipo de mago desconocido: " + subtipo);
}

unique_ptr<Guerrero> PersonajeFactory::crearGuerrero() {
    int tipoGuerrero = numeroAleatorio(0, 4);
    
    switch (tipoGuerrero) {
        case 0:
            return make_unique<Barbaro>("Barbaro", 1, 100, 100, 40);
        case 1:
            return make_unique<Paladin>("Paladin", 1, 100, 100, 10);
        case 2:
            return make_unique<Caballero>("Caballero", 1, 100, 100, 20);
        case 3:
            return make_unique<Mercenario>("Mercenario", 1, 100, 100, 30);
        case 4:
            return make_unique<Gladiador>("Gladiador", 1, 100, 100, 30);
    }
    throw runtime_error("error con 'tipoguerrero'");
}

unique_ptr<Guerrero> PersonajeFactory::crearGuerrero(const string& subtipo) {
    if (subtipo == "Barbaro")
        return make_unique<Barbaro>("Barbaro", 1, 80, 100, 40);
    else if (subtipo == "Paladin")
        return make_unique<Paladin>("Paladin", 1, 50, 100, 10);
    else if (subtipo == "Caballero")
        return make_unique<Caballero>("Caballero", 1, 70, 100, 20);
    else if (subtipo == "Mercenario")
        return make_unique<Mercenario>("Mercenario", 1, 75, 100, 30);
    else if (subtipo == "Gladiador")
        return make_unique<Gladiador>("Gladiador", 1, 85, 100, 30);
    else
        throw invalid_argument("Subtipo de guerrero desconocido: " + subtipo);
}

vector<unique_ptr<Personaje>> PersonajeFactory::crearPersonajesArmados() {
    vector<unique_ptr<Personaje>> personajes;

    int cantidadMagos = numeroAleatorio(3, 7);
    int cantidadGuerreros = numeroAleatorio(3, 7);

    for (int i = 0; i < cantidadMagos; ++i) {
        auto mago = crearMago();
        int cantidadArmas = numeroAleatorio(0, 2);
        for (int j = 0; j < cantidadArmas; ++j) {
            mago->agregarArma(crearArmaAleatoria());
        }
        personajes.push_back(move(mago));
    }

    for (int i = 0; i < cantidadGuerreros; ++i) {
        auto guerrero = crearGuerrero();
        int cantidadArmas = numeroAleatorio(0, 2);
        for (int j = 0; j < cantidadArmas; ++j) {
            guerrero->agregarArma(crearArmaAleatoria());
        }
        personajes.push_back(move(guerrero));
    }

    return personajes;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "../ejercicio_3/personaje_factory.hpp"

enum OpcionAtaque {
    GOLPE_FUERTE = 1,
    GOLPE_RAPIDO,
    DEFENSA_Y_GOLPE
};

using namespace std;

void mostrarMenu(int hp1, int hp2) {
    cout << "Jugador 1 tiene " << hp1 << " HP y Jugador 2 tiene " << hp2 << " HP." << endl;
    cout << "Elija su opción de ataque: " << endl;
    cout << "(1) Golpe Fuerte" << endl;
    cout << "(2) Golpe Rápido" << endl;
    cout << "(3) Defensa y Golpe" << endl;
}

OpcionAtaque obtenerOpcionJugador1() {
    int opcion;
    cout << "Opción: ";
    cin >> opcion;
    return static_cast<OpcionAtaque>(opcion);
}

OpcionAtaque obtenerOpcionJugador2() {
    return static_cast<OpcionAtaque>(rand() % 3 + 1);
}

enum ResultadoCombate {
    EMPATE,
    GANA_JUGADOR,
    GANA_ENEMIGO
};

ResultadoCombate resolverCombate(OpcionAtaque jugador, OpcionAtaque enemigo) {
    if ((jugador == GOLPE_FUERTE && enemigo == GOLPE_RAPIDO) ||
        (jugador == GOLPE_RAPIDO && enemigo == DEFENSA_Y_GOLPE) ||
        (jugador == DEFENSA_Y_GOLPE && enemigo == GOLPE_FUERTE)) {
        return GANA_JUGADOR;
    }
    if ((enemigo == GOLPE_FUERTE && jugador == GOLPE_RAPIDO) ||
        (enemigo == GOLPE_RAPIDO && jugador == DEFENSA_Y_GOLPE) ||
        (enemigo == DEFENSA_Y_GOLPE && jugador == GOLPE_FUERTE)) {
        return GANA_ENEMIGO;
    }
    return EMPATE;
}

int calcularDano(Arma* arma) {
    int dano = 10;
    if (arma) {
        dano += arma->obtenerdano();
    }
    return dano;
}

unique_ptr<Personaje> elegirPersonajeJugador1() {
    int clase;
    cout << "Elige tu clase de personaje:" << endl;
    cout << "1. Guerrero" << endl;
    cout << "2. Mago" << endl;
    cin >> clase;

    if (clase == 1) {
        vector<string> subtiposGuerrero = { "Barbaro", "Paladin", "Caballero", "Mercenario", "Gladiador" };
        cout << "Elige tu subtipo de Guerrero:" << endl;
        for (size_t i = 0; i < subtiposGuerrero.size(); ++i) {
            cout << i + 1 << ". " << subtiposGuerrero[i] << endl;
        }

        int opcion;
        cin >> opcion;
        return PersonajeFactory::crearGuerrero(subtiposGuerrero[opcion - 1]);
    } else {
        vector<string> subtiposMago = { "Hechicero", "Conjurador", "Brujo", "Nigromante" };
        cout << "Elige tu subtipo de Mago:" << endl;
        for (size_t i = 0; i < subtiposMago.size(); ++i) {
            cout << i + 1 << ". " << subtiposMago[i] << endl;
        }

        int opcion;
        cin >> opcion;
        return PersonajeFactory::crearMago(subtiposMago[opcion - 1]);
    }
}

unique_ptr<Arma> elegirArmaJugador1() {
    cout << "Elige tu arma:" << endl;
    cout << "1. Espada medieval" << endl;
    cout << "2. Hacha letal" << endl;
    cout << "3. Hacha Doble filosa" << endl;
    cout << "4. Lanza rústica" << endl;
    cout << "5. Garrote con púas" << endl;
    cout << "6. Bastón mágico" << endl;
    cout << "7. Libro de hechizos" << endl;
    cout << "8. Poción tóxica" << endl;
    cout << "9. Amuleto de suerte" << endl;

    int opcion;
    cin >> opcion;

    string tipoArma;
    switch (opcion) {
        case 1: tipoArma = "Espada"; break;
        case 2: tipoArma = "HachaSimple"; break;
        case 3: tipoArma = "HachaDoble"; break;
        case 4: tipoArma = "Lanza"; break;
        case 5: tipoArma = "Garrote"; break;
        case 6: tipoArma = "Baston"; break;
        case 7: tipoArma = "LibroHechizos"; break;
        case 8: tipoArma = "Pocion"; break;
        case 9: tipoArma = "Amuleto"; break;
        default:
            cout << "Opción inválida. Se seleccionará arma por defecto (Espada)." << endl;
            tipoArma = "Espada";
            break;
    }

    return PersonajeFactory::crearArma(tipoArma);
}

void pelea() {
    PersonajeFactory::inicializarRandom();
    srand(static_cast<unsigned int>(time(0)));

    auto jugador1 = elegirPersonajeJugador1();
    jugador1->agregarArma(move(elegirArmaJugador1()));

    unique_ptr<Personaje> jugador2;
    if (rand() % 2 == 0) jugador2 = PersonajeFactory::crearGuerrero();
    else jugador2 = PersonajeFactory::crearMago();

    int cantidadArmas = PersonajeFactory::numeroAleatorio(1, 2);
    for (int i = 0; i < cantidadArmas; ++i) {
        jugador2->agregarArma(PersonajeFactory::crearArmaAleatoria());
    }

    Arma* armaJugador1 = nullptr;
    if (!jugador1->obtenerArmas().empty()) {
        armaJugador1 = jugador1->obtenerArmas().front().get();
        }

    Arma* armaJugador2 = nullptr;
    if (!jugador2->obtenerArmas().empty()) {
    armaJugador2 = jugador2->obtenerArmas().front().get();
    }

    int hp1 = jugador1->obtenervida();
    int hp2 = jugador2->obtenervida();

    while (hp1 > 0 && hp2 > 0) {
        mostrarMenu(hp1, hp2);

        OpcionAtaque opcionJugador1 = obtenerOpcionJugador1();
        OpcionAtaque opcionJugador2 = obtenerOpcionJugador2();

        ResultadoCombate resultado = resolverCombate(opcionJugador1, opcionJugador2);

        if (resultado == GANA_JUGADOR) {
            int dano = calcularDano(armaJugador1);
            hp2 -= dano;
            if (hp2 < 0) hp2 = 0;
        } else if (resultado == GANA_ENEMIGO) {
            int dano = calcularDano(armaJugador2);
            hp1 -= dano;
            if (hp1 < 0) hp1 = 0;
        }
        cout << "\n== RESULTADOS DEL TURNO ==" << endl;
        
        if (resultado == GANA_JUGADOR) {
            cout << "El ganador de la ronda es el Jugador 1" << endl;
        } else if (resultado == GANA_ENEMIGO) {
            cout << "El ganador de la ronda es el Jugador 2" << endl;
        } else if (resultado == EMPATE){
            cout << "Hay un empate esta ronda y nadie hara daño" << endl;
        }


        if (resultado == GANA_JUGADOR) {
            int dano = calcularDano(armaJugador1);
            cout << "Jugador 1 (" << jugador1->obtenerNombre() << ") elige " << opcionJugador1
                 << " y ataca con " << armaJugador1->obtenerNombre()
                 << " haciendo " << dano << " puntos de daño." << endl;
        
            cout << "Jugador 2 (" << jugador2->obtenerNombre() << ") elige " << opcionJugador2
                 << " y no hace daño esta ronda." << endl;
        
        } else if (resultado == GANA_ENEMIGO) {
            int dano = calcularDano(armaJugador2);
            cout << "Jugador 2 (" << jugador2->obtenerNombre() << ") elige " << opcionJugador2
                 << " y ataca con " << armaJugador2->obtenerNombre()
                 << " haciendo " << dano << " puntos de daño." << endl;
        
            cout << "Jugador 1 (" << jugador1->obtenerNombre() << ") elige " << opcionJugador1
                 << " y no hace daño esta ronda." << endl;
        
        } else { 
            cout << "Jugador 1 (" << jugador1->obtenerNombre() << ") elige " << opcionJugador1 << endl;
            cout << "Jugador 2 (" << jugador2->obtenerNombre() << ") elige " << opcionJugador2 << endl;
            cout << "Empate. Nadie hace daño esta ronda (0 puntos de daño)." << endl;
        }

        cout << "HP actual: Jugador 1 = " << hp1 << ", Jugador 2 = " << hp2 << "\n" << endl;

        if (hp1 <= 0) {
            cout << "¡El Jugador 1 ha sido derrotado!" << endl;
            break;
        }
        if (hp2 <= 0) {
            cout << "¡El Jugador 2 ha sido derrotado!" << endl;
            break;
        }

        cout << "Presione ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    }
}

int main() {
    pelea();
    return 0;
}
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

int calcularDano(OpcionAtaque ataqueJugador, OpcionAtaque ataqueEnemigo, Arma* armaJugador) {
    bool ganaJugador = false;
    bool ganaEnemigo = false;

    if ((ataqueJugador == GOLPE_FUERTE && ataqueEnemigo == GOLPE_RAPIDO) ||
        (ataqueJugador == GOLPE_RAPIDO && ataqueEnemigo == DEFENSA_Y_GOLPE) ||
        (ataqueJugador == DEFENSA_Y_GOLPE && ataqueEnemigo == GOLPE_FUERTE)) {
        ganaJugador = true;
    }
    else if ((ataqueEnemigo == GOLPE_FUERTE && ataqueJugador == GOLPE_RAPIDO) ||
             (ataqueEnemigo == GOLPE_RAPIDO && ataqueJugador == DEFENSA_Y_GOLPE) ||
             (ataqueEnemigo == DEFENSA_Y_GOLPE && ataqueJugador == GOLPE_FUERTE)) {
        ganaEnemigo = true;
    }

    int dano = 0;
    if (ganaJugador) {
        dano = 10;
        if (armaJugador) {
            dano += armaJugador->obtenerdano();
        }
    } 
    else if (ganaEnemigo) {
        dano = 10;
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

    int cantidadArmas = PersonajeFactory::numeroAleatorio(0, 2);
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

        int dano1 = calcularDano(opcionJugador1, opcionJugador2, armaJugador1);
        int dano2 = calcularDano(opcionJugador2, opcionJugador1, armaJugador2);

        hp1 -= dano2;
        hp2 -= dano1;

        cout << "\n== RESULTADOS DEL TURNO ==" << endl;
        cout << "Jugador 1 (" << jugador1->obtenerNombre() << ") ataca con " << armaJugador1->obtenerNombre()
             << " y hace " << dano1 << " puntos de daño." << endl;

        if (armaJugador2)
            cout << "Jugador 2 (" << jugador2->obtenerNombre() << ") ataca con " << armaJugador2->obtenerNombre()
                 << " y hace " << dano2 << " puntos de daño." << endl;
        else
            cout << "Jugador 2 (" << jugador2->obtenerNombre() << ") ataca sin arma y hace " << dano2 << " puntos de daño." << endl;

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
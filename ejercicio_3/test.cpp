#include <iostream>
#include <memory>
#include <vector>
#include "personaje_factory.hpp"

using namespace std;

int main() {
    PersonajeFactory factory;
    factory.inicializarRandom();

    vector<unique_ptr<Personaje>> personajes = factory.crearPersonajesArmados();

    cout << "Se han creado " << personajes.size() << " personajes:\n\n";

    for (const auto& personaje : personajes) {
        cout << "Personaje: " << personaje->obtenerNombre()
             << " Nivel: " << personaje->obtenernivel()
             << ", Vida: " << personaje->obtenervida() << ")\n";

        const vector<unique_ptr<Arma>>& armas = personaje->obtenerArmas();
        if (armas.empty()) {
            cout << " No tiene armas\n";
        } else {
            for (const auto& arma : armas) {
                cout << " Arma: " << arma->obtenerNombre()
                     << " Daño: " << arma->obtenerdano();
            }
        }
    }

    return 0;
}
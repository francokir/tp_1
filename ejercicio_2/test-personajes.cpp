#include "personajes.hpp"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    cout << "--- MAGOS ---" << endl;
    Hechicero hech("Mario", 10, 100, "Luz", 80);
    hech.mostrarEstado();
    hech.atacar();
    hech.defender();
    hech.recibirDano(30);
    hech.enjaular();
    hech.mostrarEstado();
    cout << "Vida actual: " << hech.obtenervida() << endl;

    Conjurador conj("Alan", 12, 90, "Fuego", 85);
    conj.mostrarEstado();
    conj.invocar_criaturas();

    Brujo bru("Franco", 8, 70, "Oscuridad", 60);
    bru.mostrarEstado();
    bru.manipular_sombras();

    Nigromante nigro("Mariano", 11, 80, "Tinieblas", 75);
    nigro.mostrarEstado();
    nigro.manipular_cadaveres();

    cout << "\n--- GUERREROS ---" << endl;
    Barbaro barb("Ciro", 9, 100, 120, 30);
    barb.mostrarEstado();
    barb.atacar();
    barb.defender();
    barb.recibirDano(40);
    barb.atacar_enfurecido();
    barb.mostrarEstado();

    Paladin pala("Luis", 7, 85, 110, 25);
    pala.mostrarEstado();
    pala.proteger_aliados();
    pala.defender();

    Caballero cab("Roberto", 10, 95, 100, 35);
    cab.mostrarEstado();
    cab.ataque_a_caballo();
    cab.atacar();

    Mercenario merc("Carlos", 6, 70, 90, 40);
    merc.mostrarEstado();
    merc.lanzar_humo();
    merc.defender();

    Gladiador glad("Lionel", 8, 90, 105, 28);
    glad.mostrarEstado();
    glad.revolear_escudo();
    glad.recibirDano(50);
}
#include "personajes.hpp"
#include <iostream>
using namespace std;

// Constructores base
Mago::Mago(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : nombre(nombre), nivel(nivel), energia(energia), afinidad(afinidad), poderMagico(poderMagico) {}

Guerrero::Guerrero(string nombre, int nivel, int fuerza, int resistencia, string arma)
    : nombre(nombre), nivel(nivel), fuerza(fuerza), resistencia(resistencia), arma(arma) {}

// Hechicero
Hechicero::Hechicero(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Hechicero::atacar() { cout << nombre << " lanza un hechizo poderoso.\n"; }
void Hechicero::defender() { cout << nombre << " se protege con un escudo mágico.\n"; }
void Hechicero::recibirDano(int cantidad) { energia -= cantidad / 2; }
void Hechicero::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Energía: " << energia << endl; }

// Conjurador
Conjurador::Conjurador(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Conjurador::atacar() { cout << nombre << " invoca criaturas mágicas.\n"; }
void Conjurador::defender() { cout << nombre << " crea un muro de energía.\n"; }
void Conjurador::recibirDano(int cantidad) { energia -= cantidad / 3; }
void Conjurador::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Energía: " << energia << endl; }

// Brujo
Brujo::Brujo(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Brujo::atacar() { cout << nombre << " usa magia oscura.\n"; }
void Brujo::defender() { cout << nombre << " esquiva con agilidad.\n"; }
void Brujo::recibirDano(int cantidad) { energia -= cantidad; }
void Brujo::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Energía: " << energia << endl; }

// Nigromante
Nigromante::Nigromante(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Nigromante::atacar() { cout << nombre << " levanta a los muertos.\n"; }
void Nigromante::defender() { cout << nombre << " se cubre con un aura oscura.\n"; }
void Nigromante::recibirDano(int cantidad) { energia -= cantidad / 4; }
void Nigromante::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Energía: " << energia << endl; }

// Barbaro
Barbaro::Barbaro(string nombre, int nivel, int fuerza, int resistencia, string arma)
    : Guerrero(nombre, nivel, fuerza, resistencia, arma) {}

void Barbaro::atacar() { cout << nombre << " ataca con su hacha.\n"; }
void Barbaro::defender() { cout << nombre << " se cubre con su fuerza bruta.\n"; }
void Barbaro::recibirDano(int cantidad) { resistencia -= cantidad / 2; }
void Barbaro::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Resistencia: " << resistencia << endl; }

// Paladin
Paladin::Paladin(string nombre, int nivel, int fuerza, int resistencia, string arma)
    : Guerrero(nombre, nivel, fuerza, resistencia, arma) {}

void Paladin::atacar() { cout << nombre << " golpea con su maza sagrada.\n"; }
void Paladin::defender() { cout << nombre << " invoca un escudo divino.\n"; }
void Paladin::recibirDano(int cantidad) { resistencia -= cantidad / 3; }
void Paladin::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Resistencia: " << resistencia << endl; }

// Caballero
Caballero::Caballero(string nombre, int nivel, int fuerza, int resistencia, string arma)
    : Guerrero(nombre, nivel, fuerza, resistencia, arma) {}

void Caballero::atacar() { cout << nombre << " embiste con su lanza.\n"; }
void Caballero::defender() { cout << nombre << " levanta su escudo.\n"; }
void Caballero::recibirDano(int cantidad) { resistencia -= cantidad / 4; }
void Caballero::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Resistencia: " << resistencia << endl; }

// Mercenario
Mercenario::Mercenario(string nombre, int nivel, int fuerza, int resistencia, string arma)
    : Guerrero(nombre, nivel, fuerza, resistencia, arma) {}

void Mercenario::atacar() { cout << nombre << " ataca por oro.\n"; }
void Mercenario::defender() { cout << nombre << " esquiva con rapidez.\n"; }
void Mercenario::recibirDano(int cantidad) { resistencia -= cantidad; }
void Mercenario::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Resistencia: " << resistencia << endl; }

// Gladiador
Gladiador::Gladiador(string nombre, int nivel, int fuerza, int resistencia, string arma)
    : Guerrero(nombre, nivel, fuerza, resistencia, arma) {}

void Gladiador::atacar() { cout << nombre << " lucha por la gloria.\n"; }
void Gladiador::defender() { cout << nombre << " bloquea con su escudo.\n"; }
void Gladiador::recibirDano(int cantidad) { resistencia -= cantidad / 2; }
void Gladiador::mostrarEstado() { cout << nombre << " - Nivel: " << nivel << " - Resistencia: " << resistencia << endl; }
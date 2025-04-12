#include "personajes.hpp"
#include <iostream>
using namespace std;


void Personaje::agregarArma(shared_ptr<Arma> arma) {
    armas.push_back(arma);
}

const vector<shared_ptr<Arma>>& Personaje::obtenerArmas() {
    return armas;
};

Mago::Mago(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : nombre(nombre), nivel(nivel), energia(energia), afinidad(afinidad), poderMagico(poderMagico) {}

void Mago::atacar() {
    cout << nombre << " lanza un hechizo con poder " << poderMagico <<"."<< endl;
    energia -= 10;
}

void Mago::defender() {
    cout << nombre << " Se defiende con magia del ataque enemigo." << endl;
    energia -= 5;
}

void Mago::recibirDano(int cantidad) {
    cout << nombre << " recibe " << cantidad << " puntos de daño." << endl;
    energia -= cantidad / 2;
}

void Mago::mostrarEstado() {
    cout << "Mago: " << nombre << " | Nivel: " << nivel << " | Energia: " << energia
         << " | Afinidad: " << afinidad << " | Poder Mágico: " << poderMagico << endl;
}


Guerrero::Guerrero(string nombre, int nivel, int fuerza, int resistencia, int velocidad)
    : nombre(nombre), nivel(nivel), fuerza(fuerza), resistencia(resistencia), velocidad(velocidad) {}

void Guerrero::atacar() {
    cout <<"El guerrero "<< nombre << " ataca con fuerza " << fuerza << "." << endl;
}

void Guerrero::defender() {
    cout <<"El guerrero "<< nombre << " se cubre con su armadura. Su resistencia es: " << resistencia << endl;
}

void Guerrero::recibirDano(int cantidad) {
    int danoReducido = cantidad - resistencia;
    if (danoReducido < 0) danoReducido = 0;
    cout <<"El guerrero "<< nombre << " recibe " << danoReducido << " puntos de daño físico." << endl;
}

void Guerrero::mostrarEstado() {
    cout << "Guerrero: " << nombre << " | Nivel: " << nivel << " | Fuerza: " << fuerza
         << " | Resistencia: " << resistencia << " | Velocidad: " << velocidad << endl;
}

Hechicero::Hechicero(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Hechicero::enjaular() {
    cout <<"El hechicero "<< nombre << " enjaula al enemigo en una prision temporal dejandolo vulnerable para atacarlo." << endl;
}

Conjurador::Conjurador(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Conjurador::invocar_criaturas() {
    cout <<"El conjurador "<< nombre << " invoca criaturas de fuego que atacan al enemigo." << endl;
}

Brujo::Brujo(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Brujo::manipular_sombras() {
    cout <<"El Brujo "<< nombre << " manipula las sombras confundiendo al enemigo." << endl;
}

Nigromante::Nigromante(string nombre, int nivel, int energia, string afinidad, int poderMagico)
    : Mago(nombre, nivel, energia, afinidad, poderMagico) {}

void Nigromante::manipular_cadaveres() {
    cout <<"El nigromante "<< nombre << " revive cadaveres que atacan al enemigo." << endl;
}


Barbaro::Barbaro(string nombre, int nivel, int fuerza, int resistencia, int velocidad)
    : Guerrero(nombre, nivel, fuerza, resistencia, velocidad) {}

void Barbaro::atacar_enfurecido() {
    Barbaro::fuerza+=10;
    Barbaro::nivel+=1;
    cout <<"El barbaro "<< nombre << " entra en un estado de furia y destroza al enemigo." << endl;
}

Paladin::Paladin(string nombre, int nivel, int fuerza, int resistencia, int velocidad)
    : Guerrero(nombre, nivel, fuerza, resistencia, velocidad) {}

void Paladin::proteger_aliados() {
    Paladin::nivel--;
    cout <<"El paladin "<< nombre << " protege a sus aliados del ataque enemigo recibiendo todo el." << endl;
}

Caballero::Caballero(string nombre, int nivel, int fuerza, int resistencia, int velocidad)
    : Guerrero(nombre, nivel, fuerza, resistencia, velocidad) {}

void Caballero::ataque_a_caballo() {
    Caballero::fuerza+=10;
    cout <<"El caballero "<< nombre << " monta a un caballo y carga contra el enemigo a mucha velocidad." << endl;
}

Mercenario::Mercenario(string nombre, int nivel, int fuerza, int resistencia, int velocidad)
    : Guerrero(nombre, nivel, fuerza, resistencia, velocidad) {}

void Mercenario::lanzar_humo() {
    cout <<"El mercenario "<< nombre << " Lanza un humo que imposibilita al enemigo localizarlo y asi lo ataca por las espaldas." << endl;
}

Gladiador::Gladiador(string nombre, int nivel, int fuerza, int resistencia, int velocidad)
    : Guerrero(nombre, nivel, fuerza, resistencia, velocidad) {}

void Gladiador::revolear_escudo() {
    cout <<"El gladiador "<< nombre << " revolea su escudo a maxima potencia hacia el enemigo." << endl;
}
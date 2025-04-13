#include "personajes.hpp"
#include <iostream>
using namespace std;


void Mago::agregarArma(shared_ptr<Arma> arma) {
    armas.push_back(arma);
}

const vector<shared_ptr<Arma>>& Mago::obtenerArmas() {
    return armas;
};

int Mago::obtenervida(){
    return vida;
}

int Mago::obtenernivel(){
    return nivel;
}

Mago::Mago(string nombre, int nivel, int vida, string afinidad, int poderMagico)
    : nombre(nombre), nivel(nivel), vida(vida), afinidad(afinidad), poderMagico(poderMagico) {}

void Mago::atacar() {
    cout << nombre << " lanza un hechizo con poder " << poderMagico <<"."<< endl;
    vida -= 10;
}

void Mago::defender() {
    cout << nombre << " Se defiende con magia del ataque enemigo." << endl;
    vida -= 5;
}

void Mago::recibirDano(int cantidad) {
    cout << nombre << " recibe " << cantidad << " puntos de daño." << endl;
    vida -= cantidad / 2;
}

void Mago::mostrarEstado() {
    cout << "Mago: " << nombre << " | Nivel: " << nivel << " | vida: " << vida
         << " | Afinidad: " << afinidad << " | Poder Mágico: " << poderMagico << endl;
}

string Mago::obtenerNombre(){
    return nombre;
}

Guerrero::Guerrero(string nombre, int nivel, int fuerza, int vida, int velocidad)
    : nombre(nombre), nivel(nivel), fuerza(fuerza), vida(vida), velocidad(velocidad) {}

    void Guerrero::agregarArma(shared_ptr<Arma> arma) {
        armas.push_back(arma);
    }
    
    const vector<shared_ptr<Arma>>& Guerrero::obtenerArmas() {
        return armas;
    };
    
    int Guerrero::obtenervida(){
        return vida;
    }
    
    int Guerrero::obtenernivel(){
        return nivel;
    }

void Guerrero::atacar() {
    cout <<"El guerrero "<< nombre << " ataca con fuerza " << fuerza << "." << endl;
}

void Guerrero::defender() {
    cout <<"El guerrero "<< nombre << " se cubre con su armadura. Su vida es: " << vida << endl;
}

void Guerrero::recibirDano(int cantidad) {
    int danoReducido = cantidad - vida;
    if (danoReducido < 0) danoReducido = 0;
    cout <<"El guerrero "<< nombre << " recibe " << danoReducido << " puntos de daño físico." << endl;
}

void Guerrero::mostrarEstado() {
    cout << "Guerrero: " << nombre << " | Nivel: " << nivel << " | Fuerza: " << fuerza
         << " | vida: " << vida << " | Velocidad: " << velocidad << endl;
}

string Guerrero::obtenerNombre(){
    return nombre;
}

Hechicero::Hechicero(string nombre, int nivel, int vida, string afinidad, int poderMagico)
    : Mago(nombre, nivel, vida, afinidad, poderMagico) {}

void Hechicero::enjaular() {
    cout <<"El hechicero "<< nombre << " enjaula al enemigo en una prision temporal dejandolo vulnerable para atacarlo." << endl;
}

Conjurador::Conjurador(string nombre, int nivel, int vida, string afinidad, int poderMagico)
    : Mago(nombre, nivel, vida, afinidad, poderMagico) {}

void Conjurador::invocar_criaturas() {
    cout <<"El conjurador "<< nombre << " invoca criaturas de fuego que atacan al enemigo." << endl;
}

Brujo::Brujo(string nombre, int nivel, int vida, string afinidad, int poderMagico)
    : Mago(nombre, nivel, vida, afinidad, poderMagico) {}

void Brujo::manipular_sombras() {
    cout <<"El Brujo "<< nombre << " manipula las sombras confundiendo al enemigo." << endl;
}

Nigromante::Nigromante(string nombre, int nivel, int vida, string afinidad, int poderMagico)
    : Mago(nombre, nivel, vida, afinidad, poderMagico) {}

void Nigromante::manipular_cadaveres() {
    cout <<"El nigromante "<< nombre << " revive cadaveres que atacan al enemigo." << endl;
}


Barbaro::Barbaro(string nombre, int nivel, int fuerza, int vida, int velocidad)
    : Guerrero(nombre, nivel, fuerza, vida, velocidad) {}

void Barbaro::atacar_enfurecido() {
    Barbaro::fuerza+=10;
    Barbaro::nivel+=1;
    cout <<"El barbaro "<< nombre << " entra en un estado de furia y destroza al enemigo." << endl;
}

Paladin::Paladin(string nombre, int nivel, int fuerza, int vida, int velocidad)
    : Guerrero(nombre, nivel, fuerza, vida, velocidad) {}

void Paladin::proteger_aliados() {
    Paladin::nivel--;
    cout <<"El paladin "<< nombre << " protege a sus aliados del ataque enemigo recibiendo todo el." << endl;
}

Caballero::Caballero(string nombre, int nivel, int fuerza, int vida, int velocidad)
    : Guerrero(nombre, nivel, fuerza, vida, velocidad) {}

void Caballero::ataque_a_caballo() {
    Caballero::fuerza+=10;
    cout <<"El caballero "<< nombre << " monta a un caballo y carga contra el enemigo a mucha velocidad." << endl;
}

Mercenario::Mercenario(string nombre, int nivel, int fuerza, int vida, int velocidad)
    : Guerrero(nombre, nivel, fuerza, vida, velocidad) {}

void Mercenario::lanzar_humo() {
    cout <<"El mercenario "<< nombre << " Lanza un humo que imposibilita al enemigo localizarlo y asi lo ataca por las espaldas." << endl;
}

Gladiador::Gladiador(string nombre, int nivel, int fuerza, int vida, int velocidad)
    : Guerrero(nombre, nivel, fuerza, vida, velocidad) {}

void Gladiador::revolear_escudo() {
    cout <<"El gladiador "<< nombre << " revolea su escudo a maxima potencia hacia el enemigo." << endl;
}
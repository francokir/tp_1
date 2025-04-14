#pragma once
#include "armas.hpp"
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Personaje {
public:
    virtual void atacar() = 0;
    virtual void defender() = 0;
    virtual void recibirDano(int cantidad) = 0;
    virtual void mostrarEstado() = 0;
    virtual string obtenerNombre() = 0;
    virtual int obtenervida() = 0;
    virtual int obtenernivel() = 0;
    virtual void agregarArma(unique_ptr<Arma>) = 0;
    virtual const vector<unique_ptr<Arma>>& obtenerArmas() = 0;
};

class Mago : public Personaje {
protected:
    string nombre;
    int nivel;
    int vida;
    string afinidad;
    int poderMagico;
    vector<unique_ptr<Arma>> armas;
public:
    Mago(string nombre, int nivel, int vida, string afinidad, int poderMagico);

    void atacar();
    void defender();
    void recibirDano(int cantidad);
    void mostrarEstado();
    string obtenerNombre();
    int obtenervida();
    int obtenernivel();
    void agregarArma(unique_ptr<Arma>);
    const vector<unique_ptr<Arma>>& obtenerArmas();
};

class Guerrero : public Personaje {
protected:
    string nombre;
    int nivel;
    int fuerza;
    int vida;
    int velocidad;
    vector<unique_ptr<Arma>> armas;
public:
    Guerrero(string nombre, int nivel, int fuerza, int vida, int velocidad);

    void atacar();
    void defender();
    void recibirDano(int cantidad);
    void mostrarEstado();
    string obtenerNombre();
    int obtenervida();
    int obtenernivel();
    void agregarArma(unique_ptr<Arma>);
    const vector<unique_ptr<Arma>>& obtenerArmas();
};


class Hechicero : public Mago {
public:
    Hechicero(string nombre, int nivel, int vida, string afinidad, int poderMagico);
    void enjaular();

};

class Conjurador : public Mago {
public:
    Conjurador(string nombre, int nivel, int vida, string afinidad, int poderMagico);
    void invocar_criaturas();
};

class Brujo : public Mago {
public:
    Brujo(string nombre, int nivel, int vida, string afinidad, int poderMagico);
    void manipular_sombras();

};

class Nigromante : public Mago {
public:
    Nigromante(string nombre, int nivel, int vida, string afinidad, int poderMagico);
    void manipular_cadaveres();
};

class Barbaro : public Guerrero {
public:
    Barbaro(string nombre, int nivel, int fuerza, int vida, int velocidad);
    void atacar_enfurecido();
};

class Paladin : public Guerrero {
public:
    Paladin(string nombre, int nivel, int fuerza, int vida, int velocidad);
    void proteger_aliados();
};

class Caballero : public Guerrero {
public:
    Caballero(string nombre, int nivel, int fuerza, int vida, int velocidad);
    void ataque_a_caballo();
};

class Mercenario : public Guerrero {
public:
    Mercenario(string nombre, int nivel, int fuerza, int vida, int velocidad);
    void lanzar_humo();
};

class Gladiador : public Guerrero {
public:
    Gladiador(string nombre, int nivel, int fuerza, int vida, int velocidad);
    void revolear_escudo();
};


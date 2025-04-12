#pragma once
#include "armas.hpp"
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Personaje {
protected:
    vector<shared_ptr<Arma>> armas;
public:
    virtual void atacar() = 0;
    virtual void defender() = 0;
    virtual void recibirDano(int cantidad) = 0;
    virtual void mostrarEstado() = 0;
    virtual string obtenerNombre() = 0;
    virtual ~Personaje() = default;

    void agregarArma(shared_ptr<Arma>);

    const vector<shared_ptr<Arma>>& obtenerArmas();
};

class Mago : public Personaje {
protected:
    string nombre;
    int nivel;
    int energia;
    string afinidad;
    int poderMagico;

public:
    Mago(string nombre, int nivel, int energia, string afinidad, int poderMagico);

    void atacar() override = 0;
    void defender() override = 0;
    void recibirDano(int cantidad) override = 0;
    void mostrarEstado() override = 0;
    string obtenerNombre() override { return nombre; }
};

class Guerrero : public Personaje {
protected:
    string nombre;
    int nivel;
    int fuerza;
    int resistencia;
    int velocidad;

public:
    Guerrero(string nombre, int nivel, int fuerza, int resistencia, int velocidad);

    void atacar() override = 0;
    void defender() override = 0;
    void recibirDano(int cantidad) override = 0;
    void mostrarEstado() override = 0;
    string obtenerNombre() override { return nombre; }
};


class Hechicero : public Mago {
public:
    Hechicero(string nombre, int nivel, int energia, string afinidad, int poderMagico);
    void enjaular();

};

class Conjurador : public Mago {
public:
    Conjurador(string nombre, int nivel, int energia, string afinidad, int poderMagico);
    void invocar_criaturas();
};

class Brujo : public Mago {
public:
    Brujo(string nombre, int nivel, int energia, string afinidad, int poderMagico);
    void manipular_sombras();

};

class Nigromante : public Mago {
public:
    Nigromante(string nombre, int nivel, int energia, string afinidad, int poderMagico);
    void manipular_cadaveres();
};

class Barbaro : public Guerrero {
public:
    Barbaro(string nombre, int nivel, int fuerza, int resistencia, int velocidad);
    void atacar_enfurecido();
};

class Paladin : public Guerrero {
public:
    Paladin(string nombre, int nivel, int fuerza, int resistencia, int velocidad);
    void proteger_aliados();
};

class Caballero : public Guerrero {
public:
    Caballero(string nombre, int nivel, int fuerza, int resistencia, int velocidad);
    void ataque_a_caballo();
};

class Mercenario : public Guerrero {
public:
    Mercenario(string nombre, int nivel, int fuerza, int resistencia, int velocidad);
    void lanzar_humo();
};

class Gladiador : public Guerrero {
public:
    Gladiador(string nombre, int nivel, int fuerza, int resistencia, int velocidad);
    void revolear_escudo();
};


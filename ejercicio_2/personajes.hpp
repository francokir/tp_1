#pragma once

#include <string>
using namespace std;

class Personaje {
public:
    virtual void atacar() = 0;
    virtual void defender() = 0;
    virtual void recibirDano(int cantidad) = 0;
    virtual void mostrarEstado() = 0;
    virtual string obtenerNombre() = 0;
    virtual ~Personaje() {}
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
    string arma;

public:
    Guerrero(string nombre, int nivel, int fuerza, int resistencia, string arma);

    void atacar() override = 0;
    void defender() override = 0;
    void recibirDano(int cantidad) override = 0;
    void mostrarEstado() override = 0;
    string obtenerNombre() override { return nombre; }
};

// Clases derivadas (magos)
class Hechicero : public Mago {
public:
    Hechicero(string nombre, int nivel, int energia, string afinidad, int poderMagico);
};

class Conjurador : public Mago {
public:
    Conjurador(string nombre, int nivel, int energia, string afinidad, int poderMagico);
};

class Brujo : public Mago {
public:
    Brujo(string nombre, int nivel, int energia, string afinidad, int poderMagico);
};

class Nigromante : public Mago {
public:
    Nigromante(string nombre, int nivel, int energia, string afinidad, int poderMagico);
};

// Clases derivadas (guerreros)
class Barbaro : public Guerrero {
public:
    Barbaro(string nombre, int nivel, int fuerza, int resistencia, string arma);
};

class Paladin : public Guerrero {
public:
    Paladin(string nombre, int nivel, int fuerza, int resistencia, string arma);
};

class Caballero : public Guerrero {
public:
    Caballero(string nombre, int nivel, int fuerza, int resistencia, string arma);
};

class Mercenario : public Guerrero {
public:
    Mercenario(string nombre, int nivel, int fuerza, int resistencia, string arma);
};

class Gladiador : public Guerrero {
public:
    Gladiador(string nombre, int nivel, int fuerza, int resistencia, string arma);
};


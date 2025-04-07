#pragma once
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Empleado {
    protected:
        int antiguedad;
        float salario;
    public:
        Empleado(string nombre, string puesto, int antiguedad, float salario);
        string nombre;
        string puesto;
        int getAntiguedad();
        bool updateSalario(float);
        float getSalario();

};

class Manager : public Empleado {
    protected:
        float bono;
        string level;
    public:
        Manager(string nombre, string puesto, int antiguedad, float salario, float bono, string level);
        bool updateBono(float);
        float getBono();
        bool setLevel(string);
};

class GerenteBajo : public Manager{
    public:
        using Manager::Manager;
};

class GerenteMedio : public Manager{
    public:
        using Manager::Manager;
};

class GerenteAlto : public Manager{
    public:
        using Manager::Manager;
};

class LiderEquipo : public Manager{
    public:
        using Manager::Manager;
};
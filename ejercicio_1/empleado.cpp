#include "empleado.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

Empleado::Empleado(string nombre, string puesto, int antiguedad, float salario){
    this->nombre = nombre;
    this->puesto = puesto;
    this->antiguedad = antiguedad;
    this->salario = salario;
}

int Empleado::getAntiguedad(){
    return antiguedad;
}

bool Empleado::updateSalario(float nuevoSalario){
    
    if (nuevoSalario > 0){
        this->salario = nuevoSalario;
        return true;
    }
    return false;
}

float Empleado::getSalario(){
    return salario;
}

Manager::Manager(string nombre, string puesto, int antiguedad, float salario, float bono, string level)
    : Empleado(nombre, puesto, antiguedad, salario), bono(bono), level(level) {
}

bool Manager::updateBono(float NuevoBono){
    if(NuevoBono > 0) {
        this->bono = NuevoBono;
        return true;
    }
    return false;
}

float Manager::getBono(){
    return this->bono;
}

bool Manager::setLevel(string Level){
    this->level = Level;
    return true;
}
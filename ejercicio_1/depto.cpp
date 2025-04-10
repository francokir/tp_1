#include "depto.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

Departamento::Departamento(string nombre, string ubicacion) {
    this->nombre = nombre;
    this->ubicacion = ubicacion;
    this->cantEmpleadosDepts = 0;
}

int Departamento::contarEmpleados(){
    return cantEmpleadosDepts;
}

vector<shared_ptr<Empleado>> Departamento::getEmployees(){
    return Empleados;
}

bool Departamento::contratarEmpleado(shared_ptr<Empleado> NuevoEmpleado){
    cantEmpleadosDepts++;
    Empleados.push_back(NuevoEmpleado);
    return true;
}
        

bool Departamento::despedirEmpleado(shared_ptr<Empleado> empleadoDespido) {
    for (size_t i = 0; i < Empleados.size(); ++i) {
        if (Empleados[i]->nombre == empleadoDespido->nombre) {
            Empleados.erase(Empleados.begin() + i);
            cantEmpleadosDepts--;
            return true;
        }
    }
    return false;
}

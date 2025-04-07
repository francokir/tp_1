#include "depto.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "empleado.cpp"
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
        

bool Departamento::despedirEmpleado(shared_ptr<Empleado> empleadoDespido ){
    for (auto it = Empleados.begin(); it != Empleados.end(); ++it) {
        if ((*it)->nombre == empleadoDespido->nombre) {
            Empleados.erase(it);
            cantEmpleadosDepts--;
            return true;
        }
    }
    return false;
}

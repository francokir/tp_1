#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "empleado.hpp"
using namespace std;

class Departamento{
    private:
        vector<shared_ptr<Empleado>> Empleados; 
        int cantEmpleadosDepts;
    public:
        Departamento(string nombre, string ubicacion);
        string nombre;
        string ubicacion;
        int contarEmpleados();
        vector<shared_ptr<Empleado>> getEmployees();
        bool contratarEmpleado(shared_ptr<Empleado>);
        bool despedirEmpleado(shared_ptr<Empleado>);
};
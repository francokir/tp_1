#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "depto.hpp"
using namespace std;

class EntidadOrganizativa{
    protected:
        vector<EntidadOrganizativa*>subentidades;
    public:
        string nombre;
        void agregarSubentidad(EntidadOrganizativa*);
        int contarSubentidades();
};

class Empresa : public EntidadOrganizativa{
    private:
        vector<shared_ptr<Departamento>> Departamentos;
    public:
        string direccion;
        Departamento getDepByName(string);
        vector<string> getDepNames();
};

class CentralRegional : public EntidadOrganizativa{
    private:
        int cantEmpleados;
        vector<shared_ptr<GerenteAlto>> gerentesAlto;
        vector<shared_ptr<GerenteMedio>> gerentesMedio;
        vector<shared_ptr<Empresa>> Empresas;
    public:
        int getCantEmpleados();
        vector<shared_ptr<string>> getEmpNames();
        vector<shared_ptr<GerenteAlto>> getGerentesAlto();
        vector<shared_ptr<GerenteMedio>> getGerentesMedio();

};
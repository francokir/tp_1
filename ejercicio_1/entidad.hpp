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
        EntidadOrganizativa(vector<EntidadOrganizativa*>subentidades,string nombre);
        string nombre;
        void agregarSubentidad(EntidadOrganizativa*);
        int contarSubentidades();
};

class Empresa : public EntidadOrganizativa{
    private:
        vector<shared_ptr<Departamento>> Departamentos;
    public:
        Empresa(vector<EntidadOrganizativa*>subentidades,string nombre,vector<shared_ptr<Departamento>> Departamentos,string direccion);
        string direccion;
        shared_ptr<Departamento> getDepByName(string nombreDep);
        vector<string> getDepNames();
};

class CentralRegional : public EntidadOrganizativa{
    private:
        int cantEmpleados;
        vector<shared_ptr<GerenteAlto>> gerentesAlto;
        vector<shared_ptr<GerenteMedio>> gerentesMedio;
        vector<shared_ptr<Empresa>> Empresas;
    public:
        CentralRegional(int cantEmpleados, vector<shared_ptr<GerenteAlto>> gerentesAlto,vector<shared_ptr<GerenteMedio>> gerentesMedio,vector<shared_ptr<Empresa>> Empresas,vector<EntidadOrganizativa*>subentidades,string nombre);
        int getCantEmpleados();
        vector<shared_ptr<string>> getEmpNames();
        vector<shared_ptr<GerenteAlto>> getGerentesAlto();
        vector<shared_ptr<GerenteMedio>> getGerentesMedio();
        bool agregarGerenteAlto(shared_ptr<GerenteAlto> g);
        bool agregarGerenteMedio(shared_ptr<GerenteMedio> g);
};
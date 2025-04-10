#include <iostream>
#include <vector>
#include <memory>
#include "entidad.hpp"
using namespace std;

EntidadOrganizativa::EntidadOrganizativa(vector<EntidadOrganizativa*>subentidades,string nombre){
    this->subentidades = subentidades;
    this->nombre = nombre;
}

void EntidadOrganizativa::agregarSubentidad(EntidadOrganizativa* subentidad){
    this->subentidades.push_back(subentidad);
}

int EntidadOrganizativa::contarSubentidades(){
    return subentidades.size();
}

Empresa::Empresa(vector<EntidadOrganizativa*>subentidades,string nombre,vector<shared_ptr<Departamento>> Departamentos,string direccion) : EntidadOrganizativa(subentidades, nombre), Departamentos(Departamentos), direccion(direccion) {};

shared_ptr<Departamento> Empresa::getDepByName(string nombreDep) {
    for (auto& depto : Departamentos) {
        if (depto->nombre == nombreDep) {
            return depto;
        }
    }
    throw runtime_error("Departamento " + nombreDep + " no fue encontrado");
}

vector<string> Empresa::getDepNames() {
    vector<string> nombres;
    for (auto& depto : Departamentos) {
        nombres.push_back(depto->nombre);
    }
    return nombres;
}

CentralRegional::CentralRegional(int cantEmpleados, vector<shared_ptr<GerenteAlto>> gerentesAlto, vector<shared_ptr<GerenteMedio>> gerentesMedio, vector<shared_ptr<Empresa>> Empresas, vector<EntidadOrganizativa*> subentidades, string nombre) : EntidadOrganizativa(subentidades, nombre), cantEmpleados(cantEmpleados), gerentesAlto(gerentesAlto), gerentesMedio(gerentesMedio), Empresas(Empresas) {};

int CentralRegional::getCantEmpleados(){
    return cantEmpleados;
}

vector<shared_ptr<string>> CentralRegional::getEmpNames() {
    vector<shared_ptr<string>> nombres;
    for (auto& empresa : Empresas) {
        nombres.push_back(make_shared<string>(empresa->nombre));
    }
    return nombres;
}

bool CentralRegional::agregarGerenteAlto(shared_ptr<GerenteAlto> g) {
    if (gerentesAlto.size() >= 5) return false;
    gerentesAlto.push_back(g);
    return true;
}

bool CentralRegional::agregarGerenteMedio(shared_ptr<GerenteMedio> g) {
    if (gerentesMedio.size() >= 20) return false;
    gerentesMedio.push_back(g);
    return true;
}

vector<shared_ptr<GerenteAlto>> CentralRegional::getGerentesAlto(){
    return gerentesAlto;
}

vector<shared_ptr<GerenteMedio>> CentralRegional::getGerentesMedio(){
    return gerentesMedio;
}
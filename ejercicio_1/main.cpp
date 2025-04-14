#include <iostream>
#include <memory>
#include "entidad.hpp"

using namespace std;

int main() {
    auto e1 = make_shared<Empleado>("Carlos", "Desarrollador", 3, 80000);
    auto e2 = make_shared<Empleado>("Lucía", "Diseñadora", 2, 75000);
    auto m1 = make_shared<GerenteAlto>("María", "Gerente General", 10, 150000, 25000, "Senior");

    auto depto1 = make_shared<Departamento>("IT", "Piso 3");
    depto1->contratarEmpleado(e1);
    depto1->contratarEmpleado(e2);
    depto1->contratarEmpleado(m1);

    cout << "Empleados en IT: " << depto1->contarEmpleados() << endl;

    vector<shared_ptr<Departamento>> deps = { depto1 };
    auto empresa1 = make_shared<Empresa>(vector<EntidadOrganizativa*>(), "TechCorp", deps, "Av. Siempre Viva 123");

    vector<shared_ptr<Empresa>> empresas = { empresa1 };
    vector<shared_ptr<GerenteAlto>> altos = { m1 };
    vector<shared_ptr<GerenteMedio>> medios = { make_shared<GerenteMedio>("Pedro", "Jefe de Proyecto", 6, 100000, 15000, "Intermedio") };

    CentralRegional central(3, altos, medios, empresas, vector<EntidadOrganizativa*>(), "Centro Buenos Aires");

    cout << "Empresas bajo la central regional: " << endl;
    for (const auto& nombre : central.getEmpNames()) {
        cout << "- " << *nombre << endl;
    }

    auto itDep = empresa1->getDepByName("IT");
    cout << "Empleados en departamento IT:" << endl;
    for (auto& emp : itDep->getEmployees()) {
        cout << emp->nombre << " - " << emp->puesto << endl;
    }

    return 0;
}
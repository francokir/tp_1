#include <iostream>
#include <memory>
#include "entidad.hpp"

using namespace std;

int main() {
    // 1. Crear Empleados y Managers
    auto e1 = make_shared<Empleado>("Carlos", "Desarrollador", 3, 80000);
    auto e2 = make_shared<Empleado>("Lucía", "Diseñadora", 2, 75000);
    auto m1 = make_shared<GerenteAlto>("María", "Gerente General", 10, 150000, 25000, "Senior");

    // 2. Crear Departamento y contratar empleados
    auto depto1 = make_shared<Departamento>("IT", "Piso 3");
    depto1->contratarEmpleado(e1);
    depto1->contratarEmpleado(e2);
    depto1->contratarEmpleado(m1);  // También puede haber managers en el depto

    cout << "Empleados en IT: " << depto1->contarEmpleados() << endl;

    // 3. Crear Empresa y agregar el departamento
    vector<shared_ptr<Departamento>> deps = { depto1 };
    auto empresa1 = make_shared<Empresa>(vector<EntidadOrganizativa*>(), "TechCorp", deps, "Av. Siempre Viva 123");

    // 4. Crear CentralRegional
    vector<shared_ptr<Empresa>> empresas = { empresa1 };
    vector<shared_ptr<GerenteAlto>> altos = { m1 };
    vector<shared_ptr<GerenteMedio>> medios = { make_shared<GerenteMedio>("Pedro", "Jefe de Proyecto", 6, 100000, 15000, "Intermedio") };

    CentralRegional central(3, altos, medios, empresas, vector<EntidadOrganizativa*>(), "Centro Buenos Aires");

    // 5. Mostrar nombres de empresas de la central
    cout << "Empresas bajo la central regional: " << endl;
    for (const auto& nombre : central.getEmpNames()) {
        cout << "- " << *nombre << endl;
    }

    // 6. Acceder a empleados desde la empresa
    auto itDep = empresa1->getDepByName("IT");
    cout << "Empleados en departamento IT:" << endl;
    for (auto& emp : itDep->getEmployees()) {
        cout << emp->nombre << " - " << emp->puesto << endl;
    }

    return 0;
}
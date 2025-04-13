#include <iostream>
#include <memory>
#include "armas.hpp"
using namespace std;

int main() {
    Baston baston("Bastón de Sabiduría", 20, 2, "Luz", "Regeneración");
    baston.usar();
    baston.mejorar();
    baston.regenerar_alrededores();
    cout << baston.obtenerDescripcion() << endl << endl;

    LibroHechizos libro("Necronomicón", 30, 3, "Oscuridad", "Furia infernal");
    libro.usar();
    libro.invocar_furia();
    cout << libro.obtenerDescripcion() << endl << endl;

    Pocion pocion("Poción Venenosa", 10, 2, "Veneno", "Envenenamiento");
    pocion.usar();
    pocion.veneno_arrojadizo();
    pocion.mejorar();
    cout << pocion.obtenerDescripcion() << endl << endl;

    Amuleto amuleto("Amuleto de la Vida", 15, 4, "Tierra", "Inmortalidad");
    amuleto.usar();
    amuleto.activar_inmortalidad();
    cout << amuleto.obtenerDescripcion() << endl << endl;

    HachaSimple hacha1("Hacha de leñador", 40, 5.0, "Hierro", 10);
    hacha1.usar();
    hacha1.mejorar();
    hacha1.arrojar_hacha();
    cout << hacha1.obtenerDescripcion() << endl << endl;

    HachaDoble hacha2("Hacha de batalla doble", 50, 7.0, "Acero", 8);
    hacha2.usar();
    hacha2.cubrirse();
    cout << hacha2.obtenerDescripcion() << endl << endl;

    Espada espada("Espada del destino", 45, 4.5, "Acero encantado", 12);
    espada.usar();
    espada.atravesar_enemigo();
    espada.mejorar();
    cout << espada.obtenerDescripcion() << endl << endl;

    Lanza lanza("Lanza del dragón", 35, 3.8, "Hueso de dragón", 9);
    lanza.usar();
    lanza.arrojar_cabeza();
    cout << lanza.obtenerDescripcion() << endl << endl;

    Garrote garrote("Garrote brutal", 55, 6.0, "Madera negra", 7);
    garrote.usar();
    garrote.activar_puas();
    garrote.mejorar();
    cout << garrote.obtenerDescripcion() << endl << endl;

    return 0;
}
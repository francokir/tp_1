#include "armas.hpp"


ItemMagico::ItemMagico(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto)
    : nombre(nombre), puntos_magia(puntos_magia), multiplicador_por_rareza(tipo_rareza),
      elemento(elemento), efecto(efecto) {}

string ItemMagico::obtenerNombre() const {
    return nombre;
}

int ItemMagico::obtenerPoder() const {
    return puntos_magia * multiplicador_por_rareza;
}

void ItemMagico::usar() {
    cout << "Usando el objeto mágico: " << nombre << ", con efecto: " << efecto << endl;
}

string ItemMagico::obtenerDescripcion() const {
    return "Objeto mágico de elemento " + elemento + " que provoca: " + efecto;
}

void ItemMagico::mejorar() {
    multiplicador_por_rareza++;
    puntos_magia += 10;
    cout << nombre << " ha sido mejorado. Poder actual: " << obtenerPoder() << endl;
}


ArmaCombate::ArmaCombate(string nombre, int dano, float peso, string material, int durabilidad)
    : nombre(nombre), dano(dano), peso(peso), material(material), durabilidad(durabilidad) {}

string ArmaCombate::obtenerNombre() const {
    return nombre;
}

int ArmaCombate::obtenerdano() const {
    return dano;
}

void ArmaCombate::usar() {
    if (durabilidad > 0) {
        durabilidad--;
        cout << nombre << " ha sido usada. Durabilidad restante: " << durabilidad << endl;
    } else {
        cout << nombre << " está rota y no se puede usar." << endl;
    }
}

string ArmaCombate::obtenerDescripcion() const {
    return "Arma de " + material + ", peso: " + to_string(peso) + ", daño: " + to_string(dano);
}

void ArmaCombate::mejorar() {
    dano += 5;
    durabilidad += 10;
    cout << nombre << " ha sido mejorada. Daño actual: " << dano << ", durabilidad: " << durabilidad << endl;
}

Baston::Baston(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto)
    : ItemMagico(nombre, puntos_magia, tipo_rareza, elemento, efecto), vida_alrededores(50) {}

void Baston::regenerar_alrededores() {
    cout << nombre << " regenera " << vida_alrededores << " puntos de vida a su alrededor." << endl;
}



LibroHechizos::LibroHechizos(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto)
    : ItemMagico(nombre, puntos_magia, tipo_rareza, elemento, efecto) {}

void LibroHechizos::invocar_furia() {
    cout << nombre << " Invoca una furia que enrabia a todos los alrededores." << endl;
}


Pocion::Pocion(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto)
    : ItemMagico(nombre, puntos_magia, tipo_rareza, elemento, efecto) {}

int Pocion::veneno_arrojadizo() {
    int dano = puntos_magia * multiplicador_por_rareza;
    cout << nombre << " ha sido arrojada como veneno. Daño causado: " << dano << endl;
    return dano;
}


Amuleto::Amuleto(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto)
    : ItemMagico(nombre, puntos_magia, tipo_rareza, elemento, efecto), inmortalidad(false) {}

void Amuleto::activar_inmortalidad() {
    inmortalidad = true;
    cout << nombre << " activa la inmortalidad temporalmente. Eres invulnerable." << endl;
}



HachaSimple::HachaSimple(string nombre, int dano, float peso, string material, int durabilidad)
    : ArmaCombate(nombre, dano, peso, material, durabilidad) {}

void HachaSimple::arrojar_hacha() {
    cout << nombre << " ha sido arrojada al enemigo y saco " << dano << " puntos de vida."<< endl;
}

HachaDoble::HachaDoble(string nombre, int dano, float peso, string material, int durabilidad)
    : ArmaCombate(nombre, dano, peso, material, durabilidad) {}

void HachaDoble::cubrirse() {
    cout << nombre << " cubren del ataque enemigo al que las posee." << endl;
}



Espada::Espada(string nombre, int dano, float peso, string material, int durabilidad)
    : ArmaCombate(nombre, dano, peso, material, durabilidad) {}

void Espada::atravesar_enemigo() {
    cout << nombre << " atraviesa al enemigo causando " << dano << " de daño y dejando sus organos colgando." << endl;
}



Lanza::Lanza(string nombre, int dano, float peso, string material, int durabilidad)
    : ArmaCombate(nombre, dano, peso, material, durabilidad) {}

void Lanza::arrojar_cabeza() {
    cout << nombre << " ha sido lanzada con precisión a la cabeza del enemigo." << endl;
}



Garrote::Garrote(string nombre, int dano, float peso, string material, int durabilidad)
    : ArmaCombate(nombre, dano, peso, material, durabilidad), alambre_puas(false) {}

void Garrote::activar_puas() {
    alambre_puas = true;
    cout <<"Se le coloca alambre de puas a "<< nombre << ", aumentando el daño." << endl;
}
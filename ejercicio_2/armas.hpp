#pragma once
#include <iostream>
using namespace std;
#include <string>

class Arma {
    public:
        virtual ~Arma() = default;
        virtual string obtenerNombre() const = 0;
        virtual int obtenerdano() const = 0;
        virtual void usar() = 0;
        virtual string obtenerDescripcion() const = 0;
        virtual void mejorar() = 0;
};

class ItemMagico : public Arma {
    protected:
        string nombre;
        int puntos_magia;
        int multiplicador_por_rareza;
        string elemento;
        string efecto;
    public: 
        ItemMagico(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto);
        string obtenerNombre() const override;
        int obtenerdano() const override;
        void usar() override;
        string obtenerDescripcion() const override;
        void mejorar() override;
    };  

class ArmaCombate : public Arma {
    protected:
        string nombre;
        int dano;
        float peso;
        string material;
        int durabilidad;
    public:
        ArmaCombate(string nombre, int dano, float peso, string material, int durabilidad);
        string obtenerNombre() const override;
        int obtenerdano() const override;
        void usar() override;
        string obtenerDescripcion() const override;
        void mejorar() override;
};


class Baston : public ItemMagico {
    private:
        int vida_alrededores;
    public:
        Baston(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto);
        void regenerar_alrededores();

};

class LibroHechizos : public ItemMagico {
    public:
        LibroHechizos(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto);
        void invocar_furia();
       
};

class Pocion : public ItemMagico {
    public:
        Pocion(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto);
        int veneno_arrojadizo();
       
};

class Amuleto : public ItemMagico {
    private:
        bool inmortalidad;
    public:
        Amuleto(string nombre, int puntos_magia, int tipo_rareza, string elemento, string efecto);
        void activar_inmortalidad();
};

class HachaSimple : public ArmaCombate {
    public:
        HachaSimple(string nombre, int dano, float peso, string material, int durabilidad);
        void arrojar_hacha();
    };

class HachaDoble : public ArmaCombate {
    public:
        HachaDoble(string nombre, int dano, float peso, string material, int durabilidad);
        void cubrirse();
};

class Espada : public ArmaCombate {
    public:
        Espada(string nombre, int dano, float peso, string material, int durabilidad);
        void atravesar_enemigo();
};

class Lanza : public ArmaCombate {
    public:
        Lanza(string nombre, int dano, float peso, string material, int durabilidad);
        void arrojar_cabeza();
    };

class Garrote : public ArmaCombate {
    private:
        bool alambre_puas;
    public:
        Garrote(string nombre, int dano, float peso, string material, int durabilidad);
        void activar_puas();
    };

 
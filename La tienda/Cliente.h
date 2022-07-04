#pragma once
#include <string.H>
#include <iostream>
#include "Persona.h"
#include "Producto.h"
#include "ListaProductos.h"
#include <vector>

using namespace std;

class Cliente: public Persona, public ListaProductos{
    public:
        string contraseña;
        string ID;
        int visa;
        vector <Producto> VecCompras;
        Producto nvProducto;

        Cliente(string, string, string, string, string, string, string, int);

        void imprime();

        void agregar(ListaProductos &o);

        void eliminar();

        void comprar(ListaProductos &o);
        
        string getID();

        string getcontraseña();
};
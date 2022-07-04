#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
#include <vector>

using namespace std;

class ListaProductos{
    public:
    vector <Producto> VecProductos;
    string nnombre;
    string marca;
    string nSerie;
    int Precio;
    int Cantidad;
    string Categoria;
    Producto nProducto;
    ListaProductos();

    void imprime();

    void agregar2(Producto);

    void agregar(string,string,string,int,int,string);

    void eliminar(int);

    void modificar();

    void filtro();

    void extraer();
    
};
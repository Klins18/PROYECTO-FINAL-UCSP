#pragma once
#include <iostream>
#include <string.H>

using namespace std;

class Producto
{
	public:
		string nombre;
        string marca;
        string nSerie;
        int precio;
        int cantidad;
        string categoria;

        Producto();

        Producto(string, string, string, int, int, string);

        void imprime();

        void setnombre(string);

        void setmarca(string);

        void setnSerie(string);

        void setprecio(int);

        void setcantidad(int);

        void setcategoria(string);
        
        void cantidadcomprada();

        int getprecio();

        string getcategoria();

};
#include "Producto.h"

Producto::Producto(){
    nombre = "";
}
Producto::Producto(string _nombre, string _marca, string _nSerie, int _precio, int _cantidad, string _categoria){
    nombre = _nombre;
    marca = _marca;
    nSerie = _nSerie;
    precio = _precio;
    cantidad = _cantidad;
    categoria = _categoria;
}
void Producto::imprime(){
    cout << "Nombre: " << nombre << endl;
    cout << "Marca: " << marca << endl;
    cout << "nº de Serie: " << nSerie << endl;
    cout << "Precio: " << precio << endl;
    cout << "Categoria: " << categoria << endl;
}

void Producto::setnombre(string nnombre){
    nombre = nnombre;
}

void Producto::setmarca(string nmarca){
    marca = nmarca;
}

void Producto::setnSerie(string nnSerie){
    nSerie = nnSerie;
}

void Producto::setprecio(int nprecio){
    precio = nprecio;
}

void Producto::setcantidad(int ncantidad){
    cantidad = ncantidad;
}

void Producto::setcategoria(string ncategoria){
    categoria = ncategoria;
}

void Producto::cantidadcomprada(){
    cantidad--;
}

int Producto::getprecio(){
    return precio;
}

string Producto::getcategoria(){
    return categoria;
}
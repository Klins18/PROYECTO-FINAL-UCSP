#include <string.H>
#include <iostream>
#include "Cliente.h"
#include "ListaProductos.h"

using namespace std;

Cliente::Cliente(string nombre, string DNI, string correo, string direccion, string telefono, string _contraseña, string _ID,int _visa):Persona(nombre,DNI,correo,direccion,telefono){
    contraseña = _contraseña;
    ID = _ID;
    visa = _visa;
}

void Cliente::imprime(){
    cout << "Bienvenido " << nombre << endl;
    cout << "ID: " << ID << endl;
    cout << "Correo: " << correo << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Carrito de compras: " << endl;
    for (int i = 0; i < VecCompras.size(); i++){
        VecCompras.at(i).imprime();
    }
}

void Cliente::agregar(ListaProductos &o){
    cout << "Que producto desea agregar? " << endl;
    cout << "Introduzca el indice " << endl;
    int r;
    cin >> r;
    for (int i = 0; i < o.VecProductos.size(); i++){
        if (i == r){
            if (o.VecProductos.at(i).cantidad != 0){
                Producto nProducto = o.VecProductos.at(i);
                VecCompras.push_back(nProducto);
                o.VecProductos.at(i).cantidadcomprada();
                cout << o.VecProductos.at(i).nombre << " agregado con exito " << endl;
            }
            else{
                cout << "El producto esta agotado, pruebe con uno diferente" << endl;
            }
        }
        
    }
}

void Cliente::eliminar(){
    cout << "Que producto desea eliminar? " << endl;
    cout << " Introduzca el indice " << endl;
    int r;
    cin >> r;
    for (int i = 0; i < VecCompras.size(); i++){
        if (i == r){
            VecCompras.erase(VecCompras.begin()+i);
            cout << "Producto borrado con exito" << endl;
        }
    }
}

void Cliente::comprar(){
    cout << "Esta seguro de querer comprar los siguientes objetos? " << endl;
    for (int i = 0; i < VecCompras.size(); i++){
        int re = 0;
        cout << VecCompras.at(i).nombre << "Precio: " << VecCompras.at(i).getprecio() << endl;
        re = re + VecCompras.at(i).getprecio();
    cout << "La suma sale: " << re << "$ " << endl;
    cout << "Esta seguro de querer comprar? " << endl;
    string r;
    cin >> r;
    if (r == "si"){
        if (visa < re){
            cout << "Error, no tiene el suficiente dinero" << endl;
            }
        else{
            visa = visa - re;
            cout << re << "Han sido deducidos de su cuenta" << endl;
            cout << "Compra realizada con exito " << endl;
            VecCompras.clear();
        }
        }
    }
}

string Cliente::getcontraseña(){
    return contraseña;
}

string Cliente::getID(){
    return ID;
}

#include <string.H>
#include "Administrador.h"

using namespace std;

Admin::Admin(string nombre, string DNI, string correo, string direccion, string telefono, string _contraseña, string _ID):Persona(nombre,DNI,correo,direccion,telefono){
    contraseña = _contraseña;
    ID = _ID;
}

void Admin::imprime(){
    cout << "Admin: " << nombre << endl;
    cout << "Correo: " << correo << endl;
    cout << "Telefono: " << telefono << endl;
}

string Admin::getcontraseña(){
    return contraseña;
}

string Admin::getID(){
    return ID;
}

/*void Admin::agregar(){

}*/
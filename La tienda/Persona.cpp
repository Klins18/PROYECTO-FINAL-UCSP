
#include <string.H>
#include "Persona.h"

using namespace std;


Persona::Persona(){
    string nombre = "";
    }

Persona::Persona(string _nombre, string _DNI, string _correo, string _direccion, string _telefono){
    nombre = _nombre;
    DNI = _DNI;
    correo = _correo;
    direccion = _direccion;
    telefono = _telefono;
    }
void Persona::imprime(){
    cout << "Nombre: " << nombre << endl;
    cout << "Correo: " << correo << endl;
    cout << "Telefono: " << telefono << endl;
    }

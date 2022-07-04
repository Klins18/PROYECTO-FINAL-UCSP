#pragma once
#include <string.H>
#include <iostream>

using namespace std;

class Persona{
	public:
		string nombre;
		string DNI;
		string correo;
		string direccion;
		string telefono;

        Persona();

        Persona(string , string , string , string , string);
        void imprime();
};
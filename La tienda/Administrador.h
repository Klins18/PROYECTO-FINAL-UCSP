#pragma once
#include <string.H>
#include <iostream>
#include "Persona.h"

using namespace std;

class Admin :public Persona{
	public:
		string contraseña;
        string ID;

        Admin(string, string, string, string, string, string, string);

        void imprime();

        void agregar();

        string getID();

        string getcontraseña();

};
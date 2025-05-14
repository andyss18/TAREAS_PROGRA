#pragma once

#include <iostream>
using namespace std;
class Persona {
protected:
	string nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0;
	int id_tiposangre=0;


	Persona() {}
	Persona(string nom, string ape, string dir, int tel, string fn, int id_ts) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		id_tiposangre = id_ts;
	}

};


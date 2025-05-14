// Vista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ConexionBD.h"
#include "Estudiante.h"
using namespace std;
int main() {
	//	Estudiante est = Estudiante();
	//	est.leer();
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tiposangre = 0, id_estudiante = 0;
	cout << "Ingrese Codigo:";
	cin >> codigo;
	cin.ignore();
	cout << "Ingres Nombres: ";
	getline(cin, nombres);
	cout << "Ingres Apellidos:";
	getline(cin, apellidos);
	cout << "Ingres Direccion: ";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese Fecha Nacimiento:";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese Tipo Sangre:";
	cin >> id_tiposangre;




	Estudiante e = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tiposangre, codigo, id_estudiante);
	e.crear();
	e.leer();

	//Actualizacion
	cout << "Ingrese el ID a modificar" << endl;
	cin >> id_estudiante;
	cout << "Ingrese Codigo:";
	cin >> codigo;
	cin.ignore();
	cout << "Ingres Nombres: ";
	getline(cin, nombres);
	cout << "Ingres Apellidos:";
	getline(cin, apellidos);
	cout << "Ingres Direccion: ";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese Fecha Nacimiento:";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese Tipo Sangre:";
	cin >> id_tiposangre;

};


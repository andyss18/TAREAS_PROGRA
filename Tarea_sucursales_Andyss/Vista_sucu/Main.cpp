#include <iostream>
#include "ConexionBD.h"
#include "Sucursal.h"
using namespace std;
int main()
{
	string ubicacion, nom, fecha_inaug;
	int id_sucu=0, cant_trabajadores=0, activo=0;
	
	cout << "Ingrese nombre:";
	getline(cin, nom);
	cout << "Ingres ubicacion: ";
	getline(cin, ubicacion);
	cout << "Ingrese cantidad de chambeadores:";
	cin>>cant_trabajadores;
	cin.ignore();
	cout << "Ingres fecha de inauguracion: ";
	getline(cin, fecha_inaug);
	cout << "Ingrese estado 1=activo 0=inactivo:";
	cin >> activo;
	cin.ignore();
	
	Sucursal sucu= Sucursal(nom,ubicacion,fecha_inaug,id_sucu,cant_trabajadores,activo);
	sucu.crear();
	sucu.leer();
}
#pragma once
#include "ConexionBD.h"
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
class Sucursal{

public:
	string ubicacionn, nomm, fecha_inaugg;
	int id_sucuu = 0, cant_trabajadoress = 0, activoo = 0;

	Sucursal(){}
	Sucursal(string nom,string ubicacion,string fecha_inaug,int id_sucu,int cant_trabajadores,int activo){
		ubicacionn = ubicacion;
		nomm = nom;
		fecha_inaugg = fecha_inaug;
		cant_trabajadoress = cant_trabajadores;
		activoo = activo;
		id_sucuu = id_sucu;
	}
	void crear() {
		int estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string cant_tb = to_string(cant_trabajadoress);
			string activ = to_string(activoo);
			string query = "INSERT INTO `sucursales`.`sucursales` (`nombre`, `ubicacion`, `cantidad_trabajadores`, `fecha_inauguracion`, `activo`) VALUES ('"+nomm+"', '" + ubicacionn + "', '"+cant_tb+"', '"+fecha_inaugg+"', "+activ+");";
			const char* q = query.c_str();
			estado = mysql_query(cn.getConector(), q);
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int estado = 0;
		// instanciar la clase
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConector()) {
			string query = "SELECT * FROM sucursales.sucursales;";
			const char* q = query.c_str();
			estado = mysql_query(cn.getConector(), q);
			if (!estado) {
				resultado = mysql_store_result(cn.getConector());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << endl;
				}
			}
			else {
				cout << "Fallo consulta" << endl;
			}
		}
		else {
			cout << "fallo la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string idd = to_string(id_sucuu);

			string query = "DELETE FROM `sucursales`.`sucursales` WHERE (`id_sucursal` = '"+idd+"');";
			const char* q = query.c_str();
			estado = mysql_query(cn.getConector(), q);
			if (!estado) {
				cout << "ingreso de datos correcto..." << endl;
			}
			else {
				cout << "Fallo consulta" << endl;
			}
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string idd = to_string(id_sucuu);
			string cant_tb = to_string(cant_trabajadoress);
			string activ = to_string(activoo);
			string query = "update sucursales set nombre = '" + nomm + "',ubicacion = '" + ubicacionn + "',cantidad_trabajadores='" + cant_tb + "',fecha_inauguracion= '" + fecha_inaugg + "',activo= '" + activ + " where id_sucu=" + idd + "";
			const char* q = query.c_str();
			estado = mysql_query(cn.getConector(), q);
			if (!estado) {
				cout << "modificacion de datos correcto..." << endl;
			}
			else {
				cout << "Fallo consulta" << endl;
			}
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cn.cerrar_conexion();
	}


	
};
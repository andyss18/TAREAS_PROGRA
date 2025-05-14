#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
class Estudiante : Persona {

private:
	string codigo;
	int id_estudiante = 0;
public:

	Estudiante() {}
	Estudiante(string nom, string ape, string dir, int tel, string fn, int id_ts, string cod, int id_es) : Persona(nom, ape, dir, tel, fn, id_ts) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		id_tiposangre = id_ts;
		codigo = cod;
		id_estudiante = id_es;
	}
	void crear() {
		int estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string t = to_string(telefono);
			string idts = to_string(id_tiposangre);
			string query = "INSERT INTO `db_escuela`.`estudiantes` (`codigo`, `nombres`, `apellidos`, `direccion`, `telefono`, `fecha_nacimiento`, `id_tipo_sangre`) VALUES ('" + codigo + "','" + nombres + "', '" + apellidos + "', '" + direccion + "', '" + t + "', '" + apellidos + "', '" + fecha_nacimiento + "', '" + idts + "')";
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
			string query = "SELECT * FROM db_escuela.estudiantes;";
			const char* q = query.c_str();
			estado = mysql_query(cn.getConector(), q);
			if (!estado) {
				resultado = mysql_store_result(cn.getConector());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] <<endl;
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

	void actualizar() {
		int estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string t = to_string(telefono);
			string idts = to_string(id_tiposangre);
			string ides = to_string(id_estudiante);
			string query = "update estudiantes set codigo = '" + codigo + "',nombres = '" + nombres + "',apellidos = '" + apellidos + "',direccion= '" + direccion + "',telefono='" + t + "',fecha_nacimiento= '" + fecha_nacimiento + "',id_tipo_sangre= '" + idts + " where id_estudiante="+ides+"";
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


	void borrar() {
		int estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string t = to_string(telefono);
			string idts = to_string(id_tiposangre);
			string ides = to_string(id_estudiante);
			string query = "DELETE FROM `db_escuela`.`estudiantes` WHERE (`id_estudiantes` = '"+ides+"')";
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

};
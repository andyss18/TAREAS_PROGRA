#include <iostream>
using namespace std;


struct Estudiante{
	int *codigo;
	string *nombre;
	int **notas;
};

main(){
	
	Estudiante estudiante;
	
	int filas=0, c_notas=0;
	cout<<"cuantos alumnos desea agregar?"<<endl;
	cin>>filas;
	cout<<"cuantas notas les vas a agregar master?"<<endl;
	cin>>c_notas;
	
	
	estudiante.codigo = new int[filas];
	estudiante.nombre = new string[filas];
	estudiante.notas = new int *[filas];
	for (int i=0;i<filas; i++){
		estudiante.notas[i] = new int[c_notas];
	}
	
	cout<<"_____________ Ingreso de Notas _____________"<<endl;
	for (int i=0;i<filas;i++){
		cout<<"Codigo["<<i<<"]:";
		cin>>estudiante.codigo[i];
		cin.ignore();
		cout<<"Nombre Completo["<<i<<"]:";
		getline(cin, estudiante.nombre [i]);
		for (int ii=0;ii<c_notas;ii++){
			cout<<"Ingrese Nota["<<ii<<"] :";
			cin>>estudiante.notas[i][ii];
		}
		cout<<endl;
	}

	cout<<"_____________________________________ "<<endl;
		
		
		cout<<"______________Mostrar datos_____________"<<endl;
	for (int i=0;i<filas;i++){
		cout<<"Codigo["<<i<<"]:"<<estudiante.codigo[i]<<endl;
		cout<<"Nombre Completo["<<i<<"]:"<<estudiante.nombre[i]<<endl;
		for (int ii=0;ii<c_notas; ii++){
			cout<<"Nota["<<ii<<"] :"<<estudiante.notas[i][ii]<<endl;
		}
		cout<<"___________________________________"<<endl;
	}
	system("pause");	
};

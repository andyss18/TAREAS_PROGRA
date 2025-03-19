#include <iostream>
using namespace std;  // inge yo hice el codigo mas completo pq usted hizo como 7 codigos en su video de 1h >:(
main() {
	int tam=0, suma=0,promedio=0;
	int notas[tam];
	char res;
	
	do{
		tam++; 	
		cout<<"Ingrese nota " <<tam<<": ";
		cin>>notas[tam-1];
		cout<<"Desea ingresar otra nota(s/n): ";
		cin>>res;
	}while(res == 's' ||res == 'S');
	
	for (int i=0;i<tam;i++){
		cout<<notas[i]<<endl;
		promedio += notas[i];  // aca utilice la misma variable pq así no definiamos tanta variable jaja
	}
	
	promedio = promedio/tam;
	cout<<"promedio: "<<promedio;

};


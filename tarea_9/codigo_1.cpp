#include <iostream>
using namespace std;
main(){
    
	int n;
	cout<<"cuantos alumnos desea agregar?"<<endl;
	cin>>n;
	
	int id[n];
	string nombres[n];
	string apellidos[n];
    float nota1[n], nota2[n], nota3[n], nota4[n];
    float promedio[n];
    string resultado[n];

	for (int i=0;i<n;i++){
		cout<<"Estudiante #"<<i+1<<endl;
		cout<<"id: ";
		cin>>id[i];
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nombres[i]);
        cout << "Apellidos: ";
        getline(cin, apellidos[i]);
        
        cout << "Nota 1: ";
        cin >> nota1[i];
        cout << "Nota 2: ";
        cin >> nota2[i];
        cout << "Nota 3: ";
        cin >> nota3[i];
        cout << "Nota 4: ";
        cin >> nota4[i];
        if (promedio[i] >= 60) {
            resultado[i] = "Aprobado";
        } else {
            resultado[i] = "Reprobado";
        }
    }

    // Mostrar resultados
    cout << "\n========= RESULTADOS =========\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "ID: " << id[i] << endl;
        cout << "Nombre: " << nombres[i] << " " << apellidos[i] << endl;
        cout << "Promedio: " << promedio[i] << endl;
        cout << "Resultado: " << resultado[i] << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Definir estructura básica
struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float nota1, nota2, nota3, nota4;
    float promedio;
};

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante estudiantes[n];

    Estudiante* ptr = estudiantes; 

    // Ingresar datos
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "ID: ";
        cin >> (ptr + i)->id;
        cout << "Nombres: ";
        cin.ignore();
        cin.getline((ptr + i)->nombres, 50);
        cout << "Apellidos: ";
        cin.getline((ptr + i)->apellidos, 50);
        cout << "Nota 1: ";
        cin >> (ptr + i)->nota1;
        cout << "Nota 2: ";
        cin >> (ptr + i)->nota2;
        cout << "Nota 3: ";
        cin >> (ptr + i)->nota3;
        cout << "Nota 4: ";
        cin >> (ptr + i)->nota4;

        // Calcular promedio
        (ptr + i)->promedio = ((ptr + i)->nota1 + (ptr + i)->nota2 + (ptr + i)->nota3 + (ptr + i)->nota4) / 4;
    }

    // Mostrar resultados
    cout << "\n========= RESULTADOS =========\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "ID: " << (ptr + i)->id << endl;
        cout << "Nombre: " << (ptr + i)->nombres << " " << (ptr + i)->apellidos << endl;
        cout << "Promedio: " << (ptr + i)->promedio << endl;
        if ((ptr + i)->promedio >= 60)
            cout << "Resultado: Aprobado" << endl;
        else
            cout << "Resultado: Reprobado" << endl;
    }

    return 0;
}


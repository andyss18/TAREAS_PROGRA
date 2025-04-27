#include <iostream>
#include <fstream>
using namespace std;

// Estructura para guardar datos de un estudiante
struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float nota1, nota2, nota3, nota4;
    float promedio;
    int resultado; // 1 aprobado, 0 reprobado
};

// Función para calcular el promedio y si aprueba o no
void calcularPromedio(Estudiante &e) {
    e.promedio = (e.nota1 + e.nota2 + e.nota3 + e.nota4) / 4;
    if (e.promedio >= 60) {
        e.resultado = 1;
    } else {
        e.resultado = 0;
    }
}

// Función para crear estudiantes y guardarlos en archivo
void crearEstudiantes() {
    ofstream archivo("notas.dat", ios::binary | ios::app);
    int n;
    cout << "¿Cuántos estudiantes desea agregar? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Estudiante e;
        cout << "\nID: ";
        cin >> e.id;
        cout << "Nombres: ";
        cin.ignore();
        cin.getline(e.nombres, 50);
        cout << "Apellidos: ";
        cin.getline(e.apellidos, 50);
        cout << "Nota 1: ";
        cin >> e.nota1;
        cout << "Nota 2: ";
        cin >> e.nota2;
        cout << "Nota 3: ";
        cin >> e.nota3;
        cout << "Nota 4: ";
        cin >> e.nota4;

        calcularPromedio(e);
        archivo.write((char*)&e, sizeof(e));
    }
    archivo.close();
}

// Función para mostrar todos los estudiantes
void verEstudiantes() {
    ifstream archivo("notas.dat", ios::binary);
    Estudiante e;
    cout << "\nLista de Estudiantes:\n";
    while (archivo.read((char*)&e, sizeof(e))) {
        cout << "\nID: " << e.id << endl;
        cout << "Nombres: " << e.nombres << " " << e.apellidos << endl;
        cout << "Notas: " << e.nota1 << ", " << e.nota2 << ", " << e.nota3 << ", " << e.nota4 << endl;
        cout << "Promedio: " << e.promedio << endl;
        if (e.resultado == 1)
            cout << "Resultado: Aprobado\n";
        else
            cout << "Resultado: Reprobado\n";
    }
    archivo.close();
}

// Función para actualizar notas de un estudiante
void actualizarEstudiante() {
    fstream archivo("notas.dat", ios::binary | ios::in | ios::out);
    int id;
    cout << "Ingrese el ID del estudiante a actualizar: ";
    cin >> id;
    Estudiante e;
    while (archivo.read((char*)&e, sizeof(e))) {
        if (e.id == id) {
            cout << "Nuevas notas:\n";
            cout << "Nota 1: ";
            cin >> e.nota1;
            cout << "Nota 2: ";
            cin >> e.nota2;
            cout << "Nota 3: ";
            cin >> e.nota3;
            cout << "Nota 4: ";
            cin >> e.nota4;

            calcularPromedio(e);
            archivo.seekp(-sizeof(e), ios::cur);
            archivo.write((char*)&e, sizeof(e));
            cout << "Estudiante actualizado.\n";
            break;
        }
    }
    archivo.close();
}

// Función para eliminar un estudiante
void eliminarEstudiante() {
    ifstream archivo("notas.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    int id;
    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> id;
    Estudiante e;
    while (archivo.read((char*)&e, sizeof(e))) {
        if (e.id != id) {
            temp.write((char*)&e, sizeof(e));
        }
    }
    archivo.close();
    temp.close();
    remove("notas.dat");
    rename("temp.dat", "notas.dat");
    cout << "Estudiante eliminado.\n";
}

// Programa principal
int main() {
    int opcion;
    do {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Crear estudiantes\n";
        cout << "2. Ver estudiantes\n";
        cout << "3. Actualizar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearEstudiantes(); break;
            case 2: verEstudiantes(); break;
            case 3: actualizarEstudiante(); break;
            case 4: eliminarEstudiante(); break;
            case 5: cout << "Saliendo del programa.\n"; break;
            default: cout << "Opción no válida.\n"; break;
        }
    } while (opcion != 5);

    return 0;
}


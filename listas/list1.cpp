#include <iostream>
#include <list>
#include <string>

using namespace std;

class Persona {
public:
    Persona(const string& nombre, int edad) : nombre(nombre), edad(edad) {}

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

private:
    string nombre;
    int edad;
};

int main() {
    list<Persona> listaPersonas;

    // Agregar personas a la lista
    listaPersonas.push_back(Persona("Juan", 25));
    listaPersonas.push_back(Persona("María", 30));
    listaPersonas.push_back(Persona("Pedro", 28));

    // Mostrar los datos de todas las personas en la lista
    cout << "Datos de las personas en la lista:" << endl;
    for (const auto& persona : listaPersonas) {
        persona.mostrarDatos();
    }

    return 0;
}

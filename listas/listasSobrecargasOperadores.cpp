#include <iostream>
#include <list>
#include <algorithm> // Para usar find_if
#include <iterator>  // Para usar distance

using namespace std;

class Persona {
public:
    Persona(const string& nombre, int edad) : nombre(nombre), edad(edad) {}

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    const string& getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    // Sobrecarga del operador < para facilitar la comparación en algoritmos STL
    bool operator<(const Persona& otra) const {
        return edad < otra.edad;
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

    // Ordenar la lista por edad utilizando el operador < sobrecargado
    listaPersonas.sort();

    // Mostrar los datos después de la ordenación
    cout << "\nDatos de las personas después de la ordenación por edad:" << endl;
    for (const auto& persona : listaPersonas) {
        persona.mostrarDatos();
    }

    // Encontrar la persona más joven
    auto personaMasJoven = min_element(listaPersonas.begin(), listaPersonas.end());
    cout << "\nPersona más joven:" << endl;
    personaMasJoven->mostrarDatos();

    // Eliminar la persona con cierto nombre (si existe)
    string nombreEliminar = "María";
    auto itEliminar = find_if(listaPersonas.begin(), listaPersonas.end(),
                                   [nombreEliminar](const Persona& p) { return p.getNombre() == nombreEliminar; });

    if (itEliminar != listaPersonas.end()) {
        listaPersonas.erase(itEliminar);
        cout << "\nPersona con nombre '" << nombreEliminar << "' eliminada." << endl;
    } else {
        cout << "\nPersona con nombre '" << nombreEliminar << "' no encontrada." << endl;
    }

    // Mostrar los datos después de la eliminación
    cout << "\nDatos de las personas después de la eliminación:" << endl;
    for (const auto& persona : listaPersonas) {
        persona.mostrarDatos();
    }

    return 0;
}

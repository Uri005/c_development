#include <iostream>

int main() {
    // Variable constante
    const int numero_constante = 5;
    // Intentar cambiar el valor genera un error de compilación
    // numero_constante = 10; // Error!

    // Variable no constante
    int cantidad = 10;
    // Cambiar el valor es permitido
    cantidad = 20;

    std::cout << "Número constante: " << numero_constante << std::endl;
    std::cout << "Cantidad: " << cantidad << std::endl;

    return 0;
}
// Puntero básico a función

#include <iostream>
using namespace std;

// Definición de la función
void printMessage(const char* message) {
    cout << message << endl;
}

int main() {
    // Puntero a función que acepta const char* y devuelve void
    void (*funcPtr)(const char*) = printMessage;

    // Llamada a la función a través del puntero
    funcPtr("Hello, esta es una funcion  puntero con cadenas!");
    
    return 0;
}


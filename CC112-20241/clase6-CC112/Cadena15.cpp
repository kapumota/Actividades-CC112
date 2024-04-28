// Acceso a caracteres en una cadena

#include <iostream>
using namespace std;

int main() {
    char greeting[] = "Hello, world!";
    char* p = greeting;  // p apunta al primer carácter de greeting

    cout << "Original: " << p << endl;

    // Modificar caracteres usando aritmética de punteros
    *(p + 5) = ',';  // Coloca una coma en la posición 6

    // Acceder a un carácter específico
    cout << "Character at position 7: " << *(p + 7) << endl;

    // Imprimir la cadena modificada
    cout << "Modificado: " << p << endl;

    return 0;
}


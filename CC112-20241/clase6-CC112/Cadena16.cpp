// Recorrer una cadena

#include <iostream>
using namespace std;

int main() {
    char text[] = "Hello";
    char* ptr = text;

    // Imprimir la cadena carácter por carácter
    while (*ptr != '\0') {  // Mientras no se llegue al final de la cadena
        cout << *ptr << " ";
        ptr++;  // Mover el puntero al siguiente carácter
    }

    cout << endl;

    // Convertir la cadena a mayúsculas
    ptr = text;  // Resetear el puntero al inicio de la cadena
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr -= 32;  // Convertir a mayúsculas
        }
        ptr++;
    }

    cout << "Uppercase: " << text << endl;

    return 0;
}


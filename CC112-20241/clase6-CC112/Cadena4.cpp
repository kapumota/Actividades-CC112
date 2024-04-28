//Ejemplo de entrada de datos:

#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Introduce una cadena: ";
    cin.getline(str, 100);  // Lee una línea completa incluyendo espacios
    cout << "Cadena introducida: " << str << endl;
    return 0;
}


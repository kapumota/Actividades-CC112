// Ejemplo de apuntador a cadena de caracteres:
#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello";
    char* ptr = str;  // Apuntador al primer carácter de str
    cout << "Cadena apuntada: " << ptr << endl;  // Imprime la cadena completa
    return 0;
}


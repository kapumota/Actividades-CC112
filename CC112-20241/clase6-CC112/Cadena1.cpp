//Ejemplo de aritmética de caracteres:

#include <iostream>
using namespace std;

int main() {
    char c = 'a';
    cout << "ASCII de 'a': " << int(c) << endl;  // Convierte char a int para mostrar el valor ASCII
    c = c + 3;  // Aritmética de caracteres: mover tres posiciones en la tabla ASCII
    cout << "Nuevo carácter después de añadir 3: " << c << endl;  // Debería imprimir 'd'
    return 0;
}


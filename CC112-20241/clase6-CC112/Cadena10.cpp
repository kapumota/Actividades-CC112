// Modificación de cadenas en un Aarreglo usando punteros a punteros
#include <iostream>
#include <cstring>  // Para usar strcpy y otros
using namespace std;

int main() {
    // Reserva de memoria para cuatro punteros a char
    char** strs = new char*[4];

    // Asignar memoria para cada cadena y inicializar
    strs[0] = new char[5]; strcpy(strs[0], "Hola");
    strs[1] = new char[6]; strcpy(strs[1], "Mundo");
    strs[2] = new char[3]; strcpy(strs[2], "en");
    strs[3] = new char[4]; strcpy(strs[3], "C++");

    // Modificar una cadena
    strcpy(strs[2], "con");

    // Imprimir las cadenas
    for (int i = 0; i < 4; i++) {
        cout << strs[i] << endl;
    }

    // Liberar la memoria
    for (int i = 0; i < 4; i++) {
        delete[] strs[i];
    }
    delete[] strs;

    return 0;
}


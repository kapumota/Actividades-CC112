#include <iostream>
using namespace std;

int main() {
    // Array de cadenas almacenado como array de punteros a char
    char* strs[] = {"Hola", "Mundo", "en", "C++"};

    // Puntero a puntero apuntando al array de punteros
    char** ptr = strs;

    // Accediendo a los elementos
    for (int i = 0; i < 4; i++) {
        cout << ptr[i] << endl;  // Imprime cada string del array
    }

    return 0;
}


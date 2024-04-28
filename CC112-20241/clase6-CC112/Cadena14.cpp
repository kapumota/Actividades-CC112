//Arreglo bidimensional de cadenas como array de punteros

#include <iostream>
using namespace std;

int main() {
    // Arreglo de punteros a char
    const char* facts[2][3] = {
        {"Jupiter", "Largest planet", "Gas giant"},
        {"Earth", "Our planet", "Has life"}
    };

    // Imprimir cada elemento en el arreglo bidimensional
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << facts[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// Array de punteros a funciones

#include <iostream>
using namespace std;

void greetEnglish() {
    cout << "Hello!" << endl;
}

void greetSpanish() {
    cout << "¡Hola!" << endl;
}

void greetFrench() {
    cout << "Bonjour!" << endl;
}

int main() {
    // Array de punteros a funciones que no toman parámetros y devuelven void
    void (*greetings[3])() = {greetEnglish, greetSpanish, greetFrench};

    // Ejecutar cada función en el array
    for (int i = 0; i < 3; i++) {
        greetings[i]();
    }
    
    return 0;
}


// puntero a función que devuelve cadenas

#include <iostream>
using namespace std;

const char* getEnglishGreeting() {
    return "Hello!";
}

const char* getSpanishGreeting() {
    return "¡Hola!";
}

const char* getFrenchGreeting() {
    return "Bonjour!";
}

int main() {
    // Puntero a función que devuelve const char*
    const char* (*getGreeting)(void);

    // Asignar y usar punteros a función
    getGreeting = getEnglishGreeting;
    cout << getGreeting() << endl;

    getGreeting = getSpanishGreeting;
    cout << getGreeting() << endl;

    getGreeting = getFrenchGreeting;
    cout << getGreeting() << endl;
    
    return 0;
}


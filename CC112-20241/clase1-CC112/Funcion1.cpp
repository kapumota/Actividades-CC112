//Ejemplo simple de una funcion sobrecargada

#include <iostream>
using namespace std;

// Función para sumar dos números enteros
int sumar(int a, int b) {
    return a + b;
}

// Función sobrecargada para sumar tres números enteros
int sumar(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "La suma de 5 y 3 es " << sumar(5, 3) << endl;
    cout << "La suma de 5, 3 y 8 es " << sumar(5, 3, 8) << endl;
    return 0;
}

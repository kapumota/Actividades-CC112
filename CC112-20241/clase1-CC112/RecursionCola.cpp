#include <iostream>
using namespace std;

int factorialDeCola(int n, int acumulador = 1) {
    if (n <= 1) return acumulador;
    else return factorialDeCola(n - 1, n * acumulador);
}

int main() {
    int n = 5;
    cout << "Factorial de " << n << " es " << factorialDeCola(n) << endl;
    return 0;
}

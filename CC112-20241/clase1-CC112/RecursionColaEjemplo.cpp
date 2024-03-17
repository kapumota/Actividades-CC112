#include <iostream>
using namespace std;

int fibonacciTailAux(int n, int a, int b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fibonacciTailAux(n - 1, b, a + b); // Llamada de cola
}

int fibonacciTail(int n) {
    return fibonacciTailAux(n, 0, 1);
}

int main() {
    int n = 10;
    cout << "Fibonacci de " << n << " es " << fibonacciTail(n) << endl;
    return 0;
}

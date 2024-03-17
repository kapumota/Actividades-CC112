/* 
Recursion simple

int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

Recursion de cola

int factorialDeCola(int n, int acumulador = 1) {
    if (n <= 1) return acumulador;
    else return factorialDeCola(n - 1, n * acumulador);
}
Recursion multiple

int fibonacci(int n) {
    if (n <= 1) return n;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

Recursion anidada
int funcionAnidada(int n) {
    if (n <= 10) return n;
    return funcionAnidada(funcionAnidada(n / 2));
}

Recursion mutua o indirecta
void funcionA(int n);
void funcionB(int n);

void funcionA(int n) {
    if (n > 0) {
        cout << "A " << n << endl;
        funcionB(n - 1);
    }
}

void funcionB(int n) {
    if (n > 0) {
        cout << "B " << n << endl;
        funcionA(n / 2);
    }
}

*/

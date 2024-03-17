/*
Funcion iterativa
int factorialIterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
Funcion recursiva
int factorialRecursivo(int n) {
    if (n == 0) return 1; // Caso base
    return n * factorialRecursivo(n - 1); // Caso recursivo
}


Funcion iterativa
int fibonacciIterativo(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
Funcion recursiva

int fibonacciRecursivo(int n) {
    if (n <= 1) return n;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

*/
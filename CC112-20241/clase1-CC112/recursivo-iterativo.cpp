/*

int factorialRecursivo(int n) {
    if (n <= 1) return 1; // Caso base
    return n * factorialRecursivo(n - 1); 
}


int factorialIterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
Tarea: Convertir la función recursiva que encuentra el máximo común divisor (MCD) de dos 
números utilizando el algoritmo de Euclides a una versión iterativa.

Recursivo:
int mcdRecursivo(int a, int b) {
    if (b == 0) return a;
    return mcdRecursivo(b, a % b);
}

Sugerencia:Usa un bucle while para replicar las llamadas recursivas. La condición del bucle 
debe continuar mientras b no sea 0, y en cada iteración, debes  actualizar a y b con los
valores de b y a % b, respectivamente.


*/
/*
int sumaIterativa(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

int sumaRecursiva(int n) {
    if (n == 1) return 1; // Caso base
    return n + sumaRecursiva(n - 1); 
}

Tarea: Dada la función iterativa para calcular la suma de los primeros n números cuadrados, 
convertirla a una versión recursiva.
int sumaCuadradosIterativo(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i * i;
    }
    return suma;
}

Sugerencia: Identifica el caso base. Piensa en cómo puedes representar la suma de los primeros 
n cuadrados con una llamada recursiva que suma n*n al resultado de la suma de los cuadrados 
hasta n-1.
*/
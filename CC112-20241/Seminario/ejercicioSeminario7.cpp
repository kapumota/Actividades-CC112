#include <iostream>  // Incluye la biblioteca estándar de entrada y salida
#include <cstring>   // Para usar strlen
#include <cstdlib>   // Biblioteca estándar de propósitos generales, no se usa en este ejemplo

// Función para encontrar el mínimo de tres valores
int min(int x, int y, int z) {
    return (x < y) ? (x < z ? x : z) : (y < z ? y : z);
}

// Función que calcula la distancia de edición entre dos cadenas str1 y str2
int editDistDP(char* str1, char* str2) {
    int m = strlen(str1);  // Longitud de la primera cadena
    int n = strlen(str2);  // Longitud de la segunda cadena
    int **dp = new int*[m+1];  // Crea un puntero a un arreglo de punteros

    // Inicializa la matriz dp y calcula la distancia de edición dinámicamente
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n+1];  // Asigna memoria para cada fila de la matriz
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;  // Caso base: transformar cadena vacía en str2
            else if (j == 0)
                dp[i][j] = i;  // Caso base: transformar str1 en cadena vacía
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];  // Los caracteres son iguales, no se incrementa el costo
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insertar
                                   dp[i-1][j],  // Eliminar
                                   dp[i-1][j-1]); // Sustituir
        }
    }

    int result = dp[m][n];  // Resultado final: distancia de edición entre str1 y str2
    for (int i = 0; i <= m; i++) {
        delete[] dp[i];  // Libera la memoria de cada fila
    }
    delete[] dp;  // Libera el puntero al arreglo de punteros

    return result;
}

int main() {
    char str1[] = "sunday";
    char str2[] = "saturday";
    printf("Distancia de edicion: %d\n", editDistDP(str1, str2));  // Imprime la distancia de edición
    return 0;
}


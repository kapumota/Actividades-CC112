#include <iostream>
#include <cstring>

// Función para construir el arreglo LPS (Longest Prefix Suffix)
// que nos ayudará a optimizar la búsqueda del patrón en el texto
void computeLPSArray(const char* pattern, int M, int* lps) {
    int length = 0; // Longitud del prefijo que es igual al sufijo actual
    lps[0] = 0; // Inicializamos el primer valor del arreglo LPS en 0
    int i = 1;
    while (i < M) { // Recorremos el patrón
        if (pattern[i] == pattern[length]) { // Si los caracteres son iguales
            length++; // Incrementamos la longitud del prefijo
            lps[i] = length; // Almacenamos la longitud en el arreglo LPS
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // Retrocedemos en el patrón para buscar un nuevo prefijo que sea igual al sufijo
            } else {
                lps[i] = 0; // No hay un sufijo que coincida con ningún prefijo, así que asignamos 0
                i++;
            }
        }
    }
}

// Función principal para la búsqueda de patrones utilizando el algoritmo KMP
void KMPSearch(const char* pattern, const char* text) {
    int M = strlen(pattern); // Longitud del patrón
    int N = strlen(text); // Longitud del texto
    int lps[M]; // Arreglo LPS para el patrón

    computeLPSArray(pattern, M, lps); // Construimos el arreglo LPS

    int i = 0; // Índice para recorrer el texto
    int j = 0; // Índice para recorrer el patrón
    while (i < N) { // Recorremos el texto
        if (pattern[j] == text[i]) { // Si los caracteres coinciden
            j++; // Movemos al siguiente carácter en el patrón
            i++; // Movemos al siguiente carácter en el texto
        }

        if (j == M) { // Si hemos alcanzado el final del patrón
            printf("Se encuentra el patrón en el índice %d\n", i - j); // Imprimimos la posición donde se encontró el patrón
            j = lps[j - 1]; // Retrocedemos al último prefijo-sufijo conocido
        } else if (i < N && pattern[j] != text[i]) { // Si los caracteres no coinciden
            if (j != 0) {
                j = lps[j - 1]; // Retrocedemos en el patrón usando el arreglo LPS
            } else {
                i = i + 1; // Movemos al siguiente carácter en el texto
            }
        }
    }
}

int main() {
    const char* text = "ABABDABACDABABCABAB"; // Texto en el que vamos a buscar el patrón
    const char* pattern = "ABABCABAB"; // Patrón que queremos encontrar en el texto
    KMPSearch(pattern, text); // Llamada a la función de búsqueda KMP
    return 0;
}


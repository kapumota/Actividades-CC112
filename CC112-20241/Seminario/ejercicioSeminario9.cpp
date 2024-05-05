#include <iostream>
#include <cstring>

#define NUM_CHARS 256  // Número de caracteres ASCII, para cubrir todo el conjunto ASCII extendido

// Función para construir la tabla de malos caracteres para la heurística del mal carácter
void computeBadCharTable(char* str, int size, int badchar[NUM_CHARS]) {
    // Inicializa todos los valores de la tabla a -1
    for (int i = 0; i < NUM_CHARS; i++)
        badchar[i] = -1;

    // Llena la tabla con la última posición de cada carácter en el patrón
    for (int i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

// Función principal para buscar el patrón `pattern` en el texto `text` usando el algoritmo de Boyer-Moore
void boyerMoore(char* text, char* pattern) {
    int m = strlen(pattern);  // Longitud del patrón
    int n = strlen(text);     // Longitud del texto
    int badchar[NUM_CHARS];   // Array para la tabla de malos caracteres

    // Construye la tabla de malos caracteres para el patrón
    computeBadCharTable(pattern, m, badchar);

    int s = 0;  // s es el desplazamiento del patrón con respecto al texto
    while (s <= (n - m)) {
        int j = m - 1;  // Comienza a comparar desde el final del patrón

        // Reduce j mientras los caracteres del patrón coinciden con los del texto en la posición actual
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        // Si el patrón ha sido encontrado
        if (j < 0) {
            printf("El patron ocurre en el indice  %d\n", s);
            // Mueve el patrón para que el siguiente carácter en el texto se alinee con el último ocurrencia
            // del carácter en el patrón, o mueve el patrón una posición si no hay más ocurrencias
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } else {
            // Mueve el patrón de modo que el mal carácter en el texto se alinee con la última ocurrencia del
            // carácter en el patrón, o mueve el patrón por al menos una posición
            s += std::max(1, j - badchar[text[s + j]]);
        }
    }
}

int main() {
    char text[] = "ABAAABCD";   // Texto donde buscar
    char pattern[] = "ABC";     // Patrón a buscar
    boyerMoore(text, pattern);  // Ejecuta el algoritmo de Boyer-Moore
    return 0;
}


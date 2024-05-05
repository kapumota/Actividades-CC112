#include <iostream>
#include <cstring>
#include <cmath>

// Función que encuentra la subcadena palindrómica más larga en una cadena de texto.
void findLongestPalindrome(const char *text) {
    int n = strlen(text);
    if (n == 0) return; // Si la cadena está vacía, no hay nada que hacer.

    // Crear un array temporal para almacenar la cadena con separadores '#'
    char T[2 * n + 3];  // Ajusta el tamaño para incorporar separadores y caracteres de control.
    T[0] = '^';  // Carácter inicial que nunca aparecerá en la cadena para evitar problemas de índice.
    int ti = 1;
    for (int i = 0; i < n; i++) {
        T[ti++] = '#'; // Agrega un separador.
        T[ti++] = text[i]; // Agrega el carácter actual de la cadena.
    }
    T[ti++] = '#'; // Agrega un separador después del último carácter.
    T[ti++] = '$'; // Carácter final que nunca aparecerá en la cadena.

    int P[2 * n + 3] = {0};  // Array que almacenará la longitud del radio del palíndromo en cada posición.
    int C = 0, R = 0, iMirror;  // Variables para manejar el centro y el radio derecho del palíndromo actual.
    int maxLen = 0, centerIndex = 0;  // Variables para rastrear el palíndromo más largo encontrado.

    // Proceso el array T para encontrar todos los palíndromos posibles.
    for (int i = 1; i < ti - 1; i++) {
        iMirror = 2 * C - i;  // Encuentra la posición espejo de i respecto al centro C.

        // Si i está dentro del palíndromo actual, usa el valor del espejo para minimizar el trabajo.
        if (i < R) {
            P[i] = std::min(R - i, P[iMirror]);
        }

        // Intenta expandir el palíndromo centrado en i.
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }

        // Si el palíndromo expandido se extiende más allá del radio R, ajusta el centro y el radio.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // Actualiza el palíndromo más largo si es necesario.
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Calcula el índice de inicio del palíndromo más largo en la cadena original.
    int start = (centerIndex - maxLen) / 2;
    printf("Subcadena polindromica mas grande: ");
    // Imprime el palíndromo más largo encontrado.
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", text[i]);
    }
    printf("\n");
}

int main() {
    const char text[] = "forgeeksskeegfor";
    findLongestPalindrome(text);  // Encuentra y muestra el palíndromo más largo en la cadena dada.
    return 0;
}


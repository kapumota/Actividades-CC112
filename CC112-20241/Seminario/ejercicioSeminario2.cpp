#include <iostream>
#include <cstring> // Incluir la biblioteca para manipulación de cadenas C-style
using namespace std;

// Función para computar el arreglo LPS que será utilizado por el algoritmo KMP
void computeLPSArray(const char* pat, int M, int* lps) {
    int length = 0; // Longitud del prefijo y sufijo más largo actualmente conocido
    lps[0] = 0; // El primer elemento del arreglo LPS siempre es 0
    int i = 1; // Iniciar desde el segundo carácter del patrón
    while (i < M) {
        if (*(pat + i) == *(pat + length)) { // Si los caracteres coinciden
            length++;
            lps[i] = length;
            i++;
        } else { // Si no coinciden
            if (length != 0) {
                length = lps[length - 1]; // Usar el valor previo del arreglo LPS
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Función para realizar la búsqueda del patrón 'pat' dentro del texto 'txt' usando KMP
void KMPSearch(const char* pat, const char* txt) {
    int M = strlen(pat); // Longitud del patrón
    int N = strlen(txt); // Longitud del texto
    int lps[M]; // Arreglo LPS de tamaño M

    computeLPSArray(pat, M, lps); // Computar el arreglo LPS para el patrón

    int i = 0; // Índice para el texto
    int j = 0; // Índice para el patrón
    while (i < N) { // Mientras haya caracteres por verificar en el texto
        if (*(pat + j) == *(txt + i)) { // Si hay una coincidencia
            j++;
            i++;
        }

        if (j == M) { // Si se ha encontrado todo el patrón
            cout << "Patron encontrado en el indice 10 " << i - j << endl;
            j = lps[j - 1]; // Continuar la búsqueda desde el último prefijo conocido
        } else if (i < N && *(pat + j) != *(txt + i)) { // Si no coincide
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    const char* txt = "ABABDABACDABABCABAB"; // Texto
    const char* pat = "ABABCABAB"; // Patrón a buscar
    KMPSearch(pat, txt); // Llamar a la función de búsqueda KMP
    return 0;
}


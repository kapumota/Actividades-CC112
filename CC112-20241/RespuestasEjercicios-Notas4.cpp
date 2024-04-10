/*Pregunta 1 */

#include <iostream>

int bubbleSort(int A[], int n) {
    int count = 0;
    bool swapped = true;
    
    while (swapped) {
        swapped = false;
        count++;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i + 1]) {
                std::swap(A[i], A[i + 1]);
                swapped = true;
            }
        }
    }
    
    return count;
}

int main() {
    int N;
    std::cin >> N;
    
    int A[100]; // Asumiendo que no tendremos más de 100 elementos
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    int result = bubbleSort(A, N);
    std::cout << result << std::endl;
    
    return 0;
}

/* Pregunta 2*/

/* Pregunta 3*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1000; // Define un tamaño máximo para el arreglo

int main() {
    int N;
    cin >> N; // Leer el número de strings

    string A[MAX_N]; // Array de strings
    for(int i = 0; i < N; ++i) {
        cin >> A[i]; // Leer cada string
    }

    int niceness[MAX_N] = {0}; // Array para almacenar los valores de niceness, inicializado a 0

    // Comenzar desde el segundo elemento ya que el primer elemento no tiene elementos anteriores
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < i; ++j) {
            // Comparar A[i] con todos los elementos anteriores
            if(A[j] < A[i]) {
                // Incrementar el valor de niceness si el elemento anterior es menor
                niceness[i]++;
            }
        }
    }

    // Imprimir los valores de niceness
    for(int i = 0; i < N; ++i) {
        cout << niceness[i] << endl;
    }

    return 0;
}




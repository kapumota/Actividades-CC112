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

/* Pregunta 4*/
#include <iostream>
#include <string>
using namespace std;

int solve(int N, string S) {
    int firstHalfSum = 0, secondHalfSum = 0;

    // Calcular las sumas de ambas mitades
    for(int i = 0; i < N; ++i) {
        firstHalfSum += S[i] - '0'; // Convertir caracter a entero
    }
    for(int i = N; i < 2*N; ++i) {
        secondHalfSum += S[i] - '0'; // Convertir caracter a entero
    }

    // Calcular la diferencia entre las sumas y asegurar que sea positiva
    int diff = firstHalfSum - secondHalfSum;
    if (diff < 0) {
        diff = -diff; // Hacer la diferencia positiva si es negativa
    }

    // Determinar el número mínimo de movimientos requeridos
    int moves = 0;
    while (diff > 0) {
        int change = diff > 9 ? 9 : diff; // El máximo cambio posible en un movimiento
        diff -= change;
        ++moves;
    }

    return moves;
}

int main() {
    int T;
    cin >> T; // Número de casos de prueba

    while(T--) {
        int N;
        string S;
        cin >> N >> S; // Leer N y S para cada caso de prueba

        cout << solve(N, S) << endl; // Imprimir el resultado
    }

    return 0;
}


/*Pregunta 5*/


/*Pregunta 6*/


/*Pregunta 7*/

/*Pregunta 8*/


/*Pregunta 9*/

/*Pregunta 10*/

#include <iostream>
using namespace std;

const int MAX_N = 1e5; // Asumiendo un máximo según las restricciones del problema.
int arr[MAX_N];

// Función para encontrar el MEX de un prefijo del arreglo
int findMEX(int arr[], int end) {
    int mex = 0;
    while (true) {
        // Buscar si mex está en el prefijo del arreglo [0, end]
        bool found = false;
        for (int i = 0; i <= end; ++i) {
            if (arr[i] == mex) {
                found = true;
                break;
            }
        }
        // Si no se encontró, mex es el MEX del prefijo
        if (!found) return mex;
        // De lo contrario, prueba con el siguiente número mayor
        ++mex;
    }
}

int main() {
    int N;
    cin >> N; // Leer el tamaño del arreglo

    for (int i = 0; i < N; ++i) {
        cin >> arr[i]; // Leer los elementos del arreglo
    }

    // Calcular y mostrar el MEX para cada prefijo del arreglo
    for (int i = 0; i < N; ++i) {
        cout << findMEX(arr, i) << " ";
    }
    cout << endl;

    return 0;
}






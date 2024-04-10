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
#include <iostream>

// Función para ordenar un array en orden descendente usando el ordenamiento por selección
void sortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        // Intercambiar el elemento máximo encontrado con el primer elemento
        int temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

int calculateKeystrokes(int frequencies[], int N, int keySizes[], int K) {
    sortDesc(frequencies, N);
    sortDesc(keySizes, K);

    int totalKeystrokes = 0;
    int keyPosition = 1;  // Pulsaciones necesarias para la letra actual en la tecla
    int freqIndex = 0;  // Índice para las frecuencias ordenadas

    for (int i = 0; i < K && freqIndex < N; ++i) {
        for (int j = 0; j < keySizes[i] && freqIndex < N; ++j, ++freqIndex) {
            totalKeystrokes += keyPosition * frequencies[freqIndex];
        }
        keyPosition++;
    }

    // Verificamos si todas las letras fueron asignadas a una tecla
    if (freqIndex < N) {
        return -1;  // No hay suficiente espacio en las teclas para todas las letras
    }

    return totalKeystrokes;
}

int main() {
    int N;
    std::cin >> N;
    int frequencies[50];  // Asumiendo un máximo de 50 letras

    for (int i = 0; i < N; ++i) {
        std::cin >> frequencies[i];
    }

    int K;
    std::cin >> K;
    int keySizes[50];  // Asumiendo un máximo de 50 teclas

    for (int i = 0; i < K; ++i) {
        std::cin >> keySizes[i];
    }

    int result = calculateKeystrokes(frequencies, N, keySizes, K);
    std::cout << result << std::endl;

    return 0;
}


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
#include <iostream>
using namespace std;

const int MAX_N = 1e5; // Asumiendo un máximo según las restricciones del problema.
pair<int, int> girls[MAX_N]; // Array para almacenar los valores de favor y anger de cada chica.

// Función para realizar el ordenamiento por el primer elemento del par (favor) en orden descendente.
void sortGirls(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (girls[j].first < girls[j + 1].first) {
                // Intercambiar elementos
                pair<int, int> temp = girls[j];
                girls[j] = girls[j + 1];
                girls[j + 1] = temp;
            }
        }
    }
}

long long calculateHappiness(int n) {
    long long totalAnger = 0;
    for (int i = 0; i < n; i++) {
        totalAnger += girls[i].second; // Sumar todo el `anger`
    }
    
    // Ordenar por `favour` de mayor a menor
    sortGirls(n);
    
    // La felicidad máxima es sumando el `favour` de las dos primeras chicas (las de mayor `favour`)
    // y restando el `anger` total, excluyendo el `anger` de las dos seleccionadas.
    return girls[0].first + girls[1].first - (totalAnger - girls[0].second - girls[1].second);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> girls[i].first >> girls[i].second;
        }
        
        cout << calculateHappiness(n) << endl;
    }
    return 0;
}

/* Pregunta 6 */
#include <iostream>

const int MAX_N = 1e5; // Asumiendo un máximo según las restricciones del problema.
int arr[MAX_N];
int temp[MAX_N]; // Para usar en merge sort

// Función recursiva para calcular la suma de dígitos hasta obtener un solo dígito
int sumOfDigits(int n) {
    if (n < 10) return n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sumOfDigits(sum);
}

// Funciones merge y mergeSort implementan el algoritmo de ordenamiento Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Procesa las consultas para sumar los K mayores o menores valores
int processQuery(int arr[], int N, int queryType, int K) {
    int sum = 0;
    if (queryType == 1) {
        // Sumar los K mayores valores
        for (int i = N - K; i < N; ++i) { // Corrección aquí para incluir correctamente los K mayores
            sum += arr[i];
        }
    } else {
        // Sumar los K menores valores
        for (int i = 0; i < K; ++i) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
        arr[i] = sumOfDigits(arr[i]); // Precalcular "Digit-Value"
    }

    mergeSort(arr, 0, N - 1); // Ordenar las "Digit-Values"

    while (Q--) {
        int queryType, K;
        std::cin >> queryType >> K;
        std::cout << processQuery(arr, N, queryType, K) << std::endl;
    }

    return 0;
}


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






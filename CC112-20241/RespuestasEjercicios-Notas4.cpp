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
#include <iostream>
using namespace std;

// Modificación de la función para intercambiar dos elementos usando referencias
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Esta función toma el último elemento como pivote, lo coloca en su posición correcta
// en el arreglo ordenado, y coloca todos menores a su izquierda y los mayores a su derecha
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivote
    int i = (low - 1);  // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor que el pivote
        if (arr[j] < pivot) {
            i++;    // incrementa el índice del elemento más pequeño
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// La función principal que implementa QuickSort
// arr[] --> Arreglo a ser ordenado,
// low  --> Índice inicial,
// high  --> Índice final
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi es el índice de partición, arr[pi] está ahora en el lugar correcto
        int pi = partition(arr, low, high);

        // Ordenar separadamente los elementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para verificar si cada chico puede conseguir una chica
bool canFindPartner(int boys[], int girls[], int M, int N) {
    // Si hay menos chicas que chicos, no es posible encontrar una pareja para cada chico
    if (N < M) return false;

    // Ordenar las alturas de los chicos y las chicas
    quickSort(boys, 0, M - 1);
    quickSort(girls, 0, N - 1);

    // Verificar para cada chico si hay una chica más baja que él
    for (int i = 0; i < M; i++) {
        if (boys[i] <= girls[i]) return false; // No encontró una chica más baja
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        int boys[M], girls[N];

        for (int i = 0; i < M; i++) cin >> boys[i];
        for (int i = 0; i < N; i++) cin >> girls[i];

        if (canFindPartner(boys, girls, M, N)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}



/*Pregunta 9*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000001;
int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + N); // Ordenamos el arreglo

    long long beautifulCount = 0;
    for (int i = 0; i < N; ++i) {
        // Para cada elemento, cuenta cuántos elementos más grandes hay
        beautifulCount += N - i - 1;
    }

    cout << beautifulCount << "\n";

    return 0;
}



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
/* Pregunta 11 */

#include <iostream>
#include <cmath>
using namespace std;

// Función para determinar si ax^x tiene exactamente n dígitos en base b.
bool check(int a, long long x, int n, int b) {
    // Utilizamos logaritmos para calcular el número de dígitos.
    double numDigits = log10(a) + x*log10(x) / log10(b);
    return floor(numDigits) + 1 == n;
}

int main() {
    int a, n, b;

    while (cin >> a >> n >> b) {
        int count = 0;
        for (long long x = 1; x <= 1e9; x++) {
            if (check(a, x, n, b)) {
                // Incrementamos el contador si x satisface la condición.
                count++;
            } else if (count > 0) {
                // Si ya encontramos un x que satisface la condición y el siguiente no,
                // significa que hemos pasado el rango de x válidos.
                break;
            }
        }
        cout << count << endl;
    }

    return 0;
}

/*por corregir esta solución*/

#include <iostream>
#include <cmath>
using namespace std;

// Función para determinar si ax^x tiene n o más dígitos en base b.
bool hasNDigitsOrMore(int a, long long x, int n, int b) {
    double numDigits = log10(a) + x * log10(x) / log10(b);
    return floor(numDigits) + 1 >= n;
}

// Búsqueda binaria para encontrar el límite inferior del rango de x.
long long findLowerBound(int a, int n, int b) {
    long long left = 1, right = 1e9, ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (hasNDigitsOrMore(a, mid, n, b)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Búsqueda binaria para encontrar el límite superior del rango de x.
long long findUpperBound(int a, int n, int b) {
    long long left = 1, right = 1e9, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (!hasNDigitsOrMore(a, mid, n + 1, b)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int a, n, b;

    while (cin >> a >> n >> b) {
        long long lowerBound = findLowerBound(a, n, b);
        long long upperBound = findUpperBound(a, n, b);

        // Calculamos la cantidad de x que satisfacen la condición.
        int count = (upperBound >= lowerBound) ? upperBound - lowerBound + 1 : 0;
        cout << count << endl;
    }

    return 0;
}





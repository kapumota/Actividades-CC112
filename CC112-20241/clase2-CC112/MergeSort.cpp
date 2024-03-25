#include <cstdio>
#define N 101
// Complejidad O(nlogn)
using namespace std;

int X[N], C[N];
int n;

void mergeSort(int, int);
void merge(int, int, int);

int main() {
    scanf("%d", &n);

    // Lee los numeros a ser ordenados
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    // Aplicamos merge sort
    mergeSort(0, n - 1);

    // Imprimimos el arreglo ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(int i, int j) {
 if (i != j) {
    int m = (i + j) / 2;
     mergeSort(i, m);
     mergeSort(m + 1, j);
     merge(i, m, j);
    }
}

void merge(int i, int m, int j) {
    // p y q son los indices que se moverán a través 
    // de cada mitad respectivamente.
    int p = i;
    int q = m + 1;
    int r = i;
    // Sigue comparando los valores de X[p] y X[q] 
    // hasta llegar al final de una de las mitades

    while (p <= m && q <= j) {
        if (X[p] <= X[q]) {
          C[r++] = X[p++];
        } else {
          C[r++] = X[q++];
        }
    }
    
    //Agregamos los elementos restantes de la primera mitad.
    while (p <= m) {
        C[r++] = X[p++];
    }

    //Agregamos los elementos restantes de la segunda mitad.
    while (q <= j) {
        C[r++] = X[q++];
    }

    // Actualizamos el arreglo original
    for (r = i; r <= j; r++) {
      X[r] = C[r];
    }
}


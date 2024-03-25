#include <cstdio>
using namespace std;

int X[20];
int n;

void Swap1(int a, int b) {
    int temp = X[a];
    X[a] = X[b];
    X[b] = temp;
}

void quicksort(int a, int b);
int getPivot(int a, int b);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    quicksort(0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}

// Algoritmo de quicksort

void quicksort(int a, int b) {
    if (a < b) {
        int p = getPivot(a, b);
        quicksort(a, p - 1);
        quicksort(p + 1, b);
    }
}

// Pivote de quicksort

int getPivot(int a, int b) {
    int i = a;
    int j = b - 1;
    int p = b;

    while (i <= j) {
        if (X[i] < X[p]) {
            i++;
        } else if (X[j] >= X[p]) {
            j--;
        } else if (X[i] >= X[p] && X[j] < X[p]) {
            Swap1(i, j);
            i++;
            j--;
        }
    }
    Swap1(i, p);
    return i;
}

/*
#include <algorithm>
#include <cstdio>
//Complejidad: O(n^2)


int X[20];
int n;

void quicksort(int, int);
int getPivot(int, int);

int main() {
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
    scanf("%d", &X[i]);
    }
    
    quicksort(0, n - 1);

    for (int i = 0; i < n; i++) {
      printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}

// Algoritmo de quicksort

void quicksort(int a, int b) {
    if (a < b) {
        int p = getPivot(a, b);
        quicksort(a, p - 1);
        quicksort(p + 1, b);
    }
}

// Pivote de quicksort

int getPivot(int a, int b) {
    int i = a;
    int j = b - 1;
    int p = b;
    
   // Tu codigo

}
*/

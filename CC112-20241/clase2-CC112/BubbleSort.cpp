#include <cstdio>
#define N 101

int X[N];
int n;

void Swap1(int a, int b) {
    int temp = X[a];
    X[a] = X[b];
    X[b] = temp;
}

void bubbleSort();
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }
    bubbleSort();

    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }

    printf("\n");
    return 0;
}

void bubbleSort() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (X[j] > X[j + 1]) {
                Swap1(j, j + 1);
            }
        }
    }
}


/*
#include <algorithm>
#include <cstdio>
#define N 101
//Complejidad O(n^2)
int X[N];

int n;

void bubbleSort();
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    bubbleSort();

    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }

    printf("\n");
    return 0;
}
void bubbleSort() {
   // Tu codigo
}

*/

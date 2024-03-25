#include <cstdio>
#define N 101
//Complejidas O(n^2)
// Utiliza std::cout y std::cin
int X[N];
int n;
int main() {
    int j, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        j = i;
        while (j > 0 && num < X[j - 1]) {
            X[j] = X[j - 1];
            j--;
        }
        X[j] = num;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");
    return 0;
}   

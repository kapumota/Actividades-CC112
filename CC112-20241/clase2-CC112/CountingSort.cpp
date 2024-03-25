#include <cstdio>
#define N 10

// Version elemental
// Complejidad O(n)
// Utiliza std::cout y std::cin
int C[N];
int n;

int main() {
    int num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        C[num]++;
}

for (int i = 0; i < N; i++) {
    for (int j = 0; j < C[i]; j++) {
        printf("%d ", i);
    }
}
printf("\n");

return 0;

}

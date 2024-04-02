#include <algorithm>
#include <cstdio>
#define N 101
using namespace std;

int X[N];
int n;

void selectionSort();

int main() {
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
     scanf("%d", &X[i]);
     }
     selectionSort();
     for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
     }
     printf("\n");
    
     return 0;
 } 

void selectionSort() {
    for (int i = 0; i < n - 1; i++) {
       int pos = i;
       for (int j = i + 1; j < n; j++) {
         if (X[j] < X[pos]) {
            pos = j;
        }
    }  
    swap(X[i], X[pos]);
  }
}

#include <iostream>
#include <vector>
using namespace std;

int fibonacciMemoAux(int n, vector<int>& memo) {
    // Completar
}

int fibonacciMemo(int n) {
    vector<int> memo(n+1, -1); // Inicializa el vector de memoización con -1
    return fibonacciMemoAux(n, memo);
}

int main() {
    int n = 10;
    cout << "Fibonacci de " << n << " es " << fibonacciMemo(n) << endl;
    return 0;
}

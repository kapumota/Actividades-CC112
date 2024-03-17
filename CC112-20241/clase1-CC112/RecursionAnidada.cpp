#include <iostream>
using namespace std;

int funcionAnidada(int n) {
    if (n <= 10) return n;
    return funcionAnidada(funcionAnidada(n / 2));
}

int main() {
    int n = 100;
    cout << "Resultado: " << funcionAnidada(n) << endl;
    return 0;
}

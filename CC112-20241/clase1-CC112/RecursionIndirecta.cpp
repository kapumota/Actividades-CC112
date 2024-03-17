#include <iostream>
using namespace std;

void funcionA(int n);
void funcionB(int n);

void funcionA(int n) {
    if (n > 0) {
        cout << "A " << n << endl;
        funcionB(n - 1);
    }
}

void funcionB(int n) {
    if (n > 0) {
        cout << "B " << n << endl;
        funcionA(n / 2);
    }
}

int main() {
    funcionA(20);

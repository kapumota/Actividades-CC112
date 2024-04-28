// Comparar cadenas con punteros

#include <iostream>
using namespace std;

bool areEqual(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return false;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;  // Ambas cadenas deben terminar al mismo tiempo
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    const char* str3 = "World";

    cout << "str1 y str2 son " << (areEqual(str1, str2) ? "iguales" : "no iguales") << endl;
    cout << "str1 y str3 son " << (areEqual(str1, str3) ? "iguales" : "no iguales") << endl;

    return 0;
}



#include <iostream>
// Complejidad O(n^3)
int main() {
    int n;
    std::cin >> n;
    int arreglo[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arreglo[i];
    }

    int mejor = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int suma = 0;
            for (int k = a; k <= b; k++) {
                suma += arreglo[k];
            }
            mejor = std::max(mejor, suma);
        }
    }
    
    std::cout << mejor << "\n";

    return 0;
}

/*
#include <iostream>
// Comlejidad O(n^2)


int main() {
    int n;
    std::cin >> n;

    int arreglo[n]; 

    for (int i = 0; i < n; i++) {
        std::cin >> arreglo[i];
    }

    // Tu codigo

    std::cout << mejor << "\n";

    return 0;
}
*/

/*
#include <iostream>
Complejidad: O(n)

int main() {
    int n;
    tsd::cin >> n;

    int arreglo[n]; 

    for (int i = 0; i < n; i++) {
        std::cin >> arreglo[i];
    }

    // Tu codigo
    std::cout << mejor << "\n";
    return 0;
}
*/

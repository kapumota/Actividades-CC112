/*
La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada, dividiendo repetidamente a la mitad el rango de búsqueda hasta 
encontrar el elemento.

#include <iostream>
#include <vector>
using namespace std;

int busquedaBinariaIterativa(const vector<int>& arr, int x) {
    int izq = 0, der = arr.size() - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (arr[mid] == x) return mid;      // Elemento encontrado
        else if (arr[mid] < x) izq = mid + 1; // Buscar en la mitad derecha
        else der = mid - 1;                 // Buscar en la mitad izquierda
    }
    return -1; // Elemento no encontrado
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int resultado = busquedaBinariaIterativa(arr, x);
    (resultado == -1) ? cout << "El elemento no está presente en el arreglo"
                      : cout << "El elemento está presente en el índice " << resultado;
    return 0;
}
Tarea: convierte esta version iterativa en recursiva
**/


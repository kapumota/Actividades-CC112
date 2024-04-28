// Ejemplo avanzado con cadenas de texto

#include <iostream>
using namespace std;

void reverseString(char* str) {
    char* start = str;
    char* end = str;
    while (*end) {  // Mover 'end' al final de la cadena
        end++;
    }
    end--;  // Retroceder para no apuntar al carácter nulo

    // Intercambiar caracteres desde el principio y el final hasta que se crucen
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hola Mundo";
    reverseString(str);
    cout << "Cadena invertida: " << str << endl;  // Imprime "odnuM aloH"

    return 0;
}


// Funciones de manejo de cadenas

#include <iostream>
#include <cstring>  // Para funciones de manejo de cadenas
using namespace std;

int main() {
    char str1[20] = "Hola";
    char str2[20] = " Mundo";
    
    cout << "Longitud de str1: " << strlen(str1) << endl;  // Muestra la longitud de str1
    strcat(str1, str2);  // Concatena str2 a str1
    cout << "Cadena concatenada: " << str1 << endl;
    return 0;
}

-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[] = "Hola Mundo";
    cout << "Longitud de la cadena: " << strlen(str) << endl;
    return 0;
}

-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char src[] = "Hola Mundo";
    char dest[20];
    strcpy(dest, src);
    cout << "Cadena copiada: " << dest << endl;
    return 0;
}

-------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[20] = "Hola";
    char str2[] = " Mundo";
    strcat(str1, str2);
    cout << "Cadenas concatenadas: " << str1 << endl;
    return 0;
}

-------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[] = "Hola";
    char str2[] = "Hola";
    char str3[] = "Mundo";
    cout << "Comparando str1 y str2: " << strcmp(str1, str2) << endl;
    cout << "Comparando str1 y str3: " << strcmp(str1, str3) << endl;
    return 0;
}

-------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char src[] = "Hola Mundo";
    char dest[5];  // Nota: para uso seguro, debes asegurar el espacio para el carácter nulo
    strncpy(dest, src, 4);
    dest[4] = '\0';  // Asegura terminación nula
    cout << "Cadena copiada con strncpy: " << dest << endl; // Debería imprimir "Hola"
    return 0;
}



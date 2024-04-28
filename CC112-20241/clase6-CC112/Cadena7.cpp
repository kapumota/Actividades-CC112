//Funciones de caracteres: 
// C++ incluye funciones en la biblioteca <cctype> como isalpha, isdigit, islower, toupper, etc., para trabajar con caracteres individuales.

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c = 'a';
    if (isalpha(c)) {
        cout << c << " es un alfabeto." << endl;
    }
    cout << "Convertido a mayúsculas: " << char(toupper(c)) << endl;
    return 0;
}

-------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "100";
    int num = stoi(s);  // Convierte string a integer
    cout << "Número convertido: " << num << endl;
    return 0;
}



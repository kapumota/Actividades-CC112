#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;  // Variable privada para almacenar el texto.

public:
    // Método para insertar una cadena en una posición dada.
    void insert(const string& str, size_t position) {
        if (position <= text.size()) {  // Verifica que la posición sea válida.
            text.insert(position, str);  // Inserta la cadena en la posición especificada.
        }
    }

    // Método para borrar una parte del texto desde una posición dada, con cierta longitud.
    void deleteText(size_t position, size_t length) {
        if (position < text.size()) {  // Verifica que la posición sea válida.
            text.erase(position, length);  // Borra la longitud especificada del texto comenzando en la posición dada.
        }
    }

    // Método para buscar una subcadena dentro del texto.
    size_t find(const string& str) {
        return text.find(str);  // Retorna la posición de la primera ocurrencia de la subcadena o string::npos si no se encuentra.
    }

    // Método para mostrar el contenido actual del texto.
    void display() {
        cout << text << endl;  // Imprime el texto almacenado.
    }
};

int main() {
    TextEditor editor;  // Crea una instancia de TextEditor.
    editor.insert("Hello world", 0);  // Inserta "Hello world" al inicio del texto.
    editor.display();  // Muestra "Hello world".

    editor.insert(" C++", 11);  // Inserta " C++" al final de "Hello world".
    editor.display();  // Muestra "Hello world C++".

    editor.deleteText(5, 6);  // Borra 6 caracteres comenzando desde la posición 5 (" world").
    editor.display();  // Muestra "HelloC++".

    cout << "Encuentra 'C++': " << editor.find("C++") << endl;  // Busca la subcadena "C++" y muestra su posición.

    return 0;
    
}


/*

#include <iostream>
#include <cstring>
using namespace std;

// Variables globales para el texto y su capacidad
char* text;
size_t capacity = 256; // Capacidad inicial arbitraria

// Función para inicializar el texto
void initializeText() {
    text = new char[capacity];
    text[0] = '\0'; // Inicializar con cadena vacía
}

// Función para asegurar la capacidad de memoria del texto
void ensureCapacity(size_t requiredCapacity) {
    if (requiredCapacity > capacity) {
        // Expandir capacidad
        capacity = requiredCapacity * 2; // Aumentar la capacidad para evitar reallocations frecuentes
        char* newText = new char[capacity];
        strcpy(newText, text); // Copiar el texto existente al nuevo buffer
        delete[] text;
        text = newText;
    }
}

// Función para insertar una cadena en una posición dada
void insertText(const char* str, size_t position) {
    size_t len = strlen(str);
    size_t currentLength = strlen(text);
    if (position > currentLength) return; // Posición no válida

    size_t newLength = currentLength + len;
    ensureCapacity(newLength + 1); // Asegurar capacidad suficiente

    // Mover la parte original del texto para hacer espacio al nuevo
    memmove(text + position + len, text + position, currentLength - position + 1);
    // Copiar la nueva cadena en la posición
    memcpy(text + position, str, len);
}

// Función para borrar texto desde una posición dada, con cierta longitud
void deleteText(size_t position, size_t length) {
    size_t currentLength = strlen(text);
    if (position >= currentLength) return; // Posición no válida

    // Ajustar la longitud si excede el tamaño del texto
    if (position + length > currentLength) {
        length = currentLength - position;
    }

    // Mover el texto para eliminar la parte deseada
    memmove(text + position, text + position + length, currentLength - position - length + 1);
}

// Función para buscar una subcadena dentro del texto
size_t findText(const char* str) {
    char* pos = strstr(text, str);
    if (pos) {
        return pos - text; // Retorna la posición de la subcadena
    }
    return string::npos; // Retorna npos si no se encuentra
}

// Función para mostrar el contenido actual del texto
void displayText() {
    cout << text << endl;
}

// Función principal
int main() {
    initializeText(); // Inicializa el texto
    insertText("Hello world", 0); // Inserta "Hello world" al inicio
    displayText(); // Muestra "Hello world"

    insertText(" C++", 11); // Inserta " C++" al final de "Hello world"
    displayText(); // Muestra "Hello world C++"

    deleteText(5, 6); // Borra 6 caracteres empezando desde la posición 5 (" world")
    displayText(); // Muestra "HelloC++"

    cout << "Encuentra 'C++': " << findText("C++") << endl; // Busca la subcadena "C++" y muestra su posición

    delete[] text; // Liberar la memoria al final
    return 0;
}

*/

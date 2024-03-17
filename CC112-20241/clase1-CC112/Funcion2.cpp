// Ejemplo simple de sobrescritura

#include <iostream>
using namespace std;

class Base {
public:
    virtual void mostrar() {
        cout << "Mostrar base" << endl;
    }
};

class Derivada : public Base {
public:
    // Sobreescritura de la función en la clase derivada
    void mostrar() override {
        cout << "Mostrar derivada" << endl;
    }
};

int main() {
    Base* b = new Derivada();
    b->mostrar();  // Esto llamará a mostrar() en Derivada
    delete b;
    return 0;
}

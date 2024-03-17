#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
    vector<int> v;

    Vector() {}

    // Constructor que acepta una lista inicializadora
    Vector(initializer_list<int> l) : v(l) {}

    // Sobrecarga del operador + para sumar dos vectores
    Vector operator+(const Vector& other) const {
        Vector result;
        for (size_t i = 0; i < v.size(); ++i) {
            result.v.push_back(this->v[i] + other.v[i]);
        }
        return result;
    }

    // Función sobrecargada para mostrar el vector
    void mostrar(const string& mensaje = "Vector: ") const {
        cout << mensaje;
        for (auto& elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector v1 = {1, 2, 3};
    Vector v2 = {4, 5, 6};

    Vector v3 = v1 + v2;  // Usando la sobrecarga del operador +
    v3.mostrar();  // Mostrar resultado de la suma

    v1.mostrar("v1: ");
    v2.mostrar("v2: ");
    return 0;
}

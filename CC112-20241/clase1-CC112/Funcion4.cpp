#include <iostream>
#include <memory>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() const {
        cout << "Algun sonido" << endl;
    }

    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "Guau" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Miau" << endl;
    }
};

void emitirSonido(const Animal& animal) {
    animal.hacerSonido();
}

int main() {
    Perro perro;
    Gato gato;

    emitirSonido(perro);
    emitirSonido(gato);

    // Uso de punteros inteligentes con polimorfismo
    unique_ptr<Animal> animalPolimorfico = make_unique<Perro>();
    animalPolimorfico->hacerSonido();

    animalPolimorfico = make_unique<Gato>();
    animalPolimorfico->hacerSonido();

    return 0;
}

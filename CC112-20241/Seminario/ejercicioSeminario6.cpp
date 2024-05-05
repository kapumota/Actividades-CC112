#include <iostream>
#include <cstring>

// Definición del tipo de puntero a función para los métodos de votación
typedef void (*VotingMethod)();

// Funciones para diferentes métodos de votación
void electronicVoting() {
    std::cout << "Procesando voto electrónico..." << std::endl;
}

void paperVoting() {
    std::cout << "Procesando voto en papel..." << std::endl;
}

int main() {
    // Número máximo de regiones y cabinas por región
    const int MAX_REGIONS = 5;
    const int MAX_CABINAS = 3;

    // Array de punteros a funciones para métodos de votación
    VotingMethod methods[2] = {electronicVoting, paperVoting};

    // Array de punteros a punteros para administrar cabinas de votación en varias regiones
    VotingMethod** votingBooths = new VotingMethod*[MAX_REGIONS];

    // Inicialización de las cabinas de votación por región
    for (int i = 0; i < MAX_REGIONS; i++) {
        votingBooths[i] = new VotingMethod[MAX_CABINAS];
        for (int j = 0; j < MAX_CABINAS; j++) {
            // Alternar métodos de votación para demostración
            votingBooths[i][j] = methods[(i + j) % 2];
        }
    }

    // Simulación de la votación en las cabinas de una región específica
    int selectedRegion = 2;  // Por ejemplo, seleccionar la región 3
    std::cout << "Votación en la región " << selectedRegion + 1 << std::endl;
    for (int i = 0; i < MAX_CABINAS; i++) {
        std::cout << "Cabina " << i + 1 << ": ";
        votingBooths[selectedRegion][i]();  // Llamada al método de votación
    }

    // Limpieza de memoria
    for (int i = 0; i < MAX_REGIONS; i++) {
        delete[] votingBooths[i];
    }
    delete[] votingBooths;

    return 0;
}


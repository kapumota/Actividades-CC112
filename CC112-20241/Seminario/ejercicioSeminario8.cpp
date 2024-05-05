#include <iostream>
#include <cstdlib>
#include <cstring>

const int PAGE_SIZE = 4096; // Tamaño fijo de página de 4KB
const int NUM_PAGES = 256;  // Número total de páginas en el sistema

// Simula la memoria física
char **physicalMemory;

// Tabla de páginas, mapea páginas virtuales a páginas físicas
int *pageTable;

// Inicialización de la memoria y la tabla de páginas
void initializeMemorySystem() {
    physicalMemory = new char*[NUM_PAGES]; // Reserva memoria para el arreglo de punteros
    pageTable = new int[NUM_PAGES]; // Reserva memoria para la tabla de páginas
    for (int i = 0; i < NUM_PAGES; i++) {
        physicalMemory[i] = nullptr; // Inicializa todas las páginas como no asignadas
        pageTable[i] = -1; // -1 indica que la página no está asignada en la tabla de páginas
    }
}

// Asigna una página en la memoria
int allocatePage() {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (physicalMemory[i] == nullptr) { // Busca una página no asignada
            physicalMemory[i] = new char[PAGE_SIZE]; // Reserva memoria para la página
            memset(physicalMemory[i], 0, PAGE_SIZE); // Inicializa la página con ceros
            return i; // Devuelve el índice de la página asignada
        }
    }
    return -1; // No hay páginas disponibles
}

// Libera una página de memoria
void freePage(int pageNumber) {
    if (pageNumber >= 0 && pageNumber < NUM_PAGES && physicalMemory[pageNumber] != nullptr) {
        delete[] physicalMemory[pageNumber]; // Libera la memoria de la página
        physicalMemory[pageNumber] = nullptr; // Marca la página como no asignada
        pageTable[pageNumber] = -1; // Actualiza la tabla de páginas
    }
}

// Simula el acceso a una dirección virtual
char accessMemory(int virtualAddress) {
    int pageNum = virtualAddress / PAGE_SIZE; // Calcula el número de página
    int offset = virtualAddress % PAGE_SIZE; // Calcula el desplazamiento dentro de la página
    
    if (pageNum < NUM_PAGES && pageTable[pageNum] != -1) {
        return physicalMemory[pageTable[pageNum]][offset]; // Devuelve el valor de la dirección virtual
    }
    std::cout << "Acceso a página no asignada." << std::endl; // Muestra un mensaje de error si la página no está asignada
    return -1;  // Página no asignada
}

// Limpieza de la memoria al final
void cleanupMemorySystem() {
    for (int i = 0; i < NUM_PAGES; i++) {
        if (physicalMemory[i] != nullptr) {
            delete[] physicalMemory[i]; // Libera la memoria de las páginas asignadas
        }
    }
    delete[] physicalMemory; // Libera la memoria del arreglo de punteros
    delete[] pageTable; // Libera la memoria de la tabla de páginas
}

int main() {
    initializeMemorySystem(); // Inicializa el sistema de memoria
    
    // Simulación de asignación y acceso
    int page = allocatePage(); // Asigna una página
    if (page != -1) {
        pageTable[0] = page; // Mapea una dirección virtual a la página física
        physicalMemory[page][0] = 'A'; // Escribe en la memoria
        std::cout << "Valor almacenado: " << accessMemory(0) << std::endl; // Accede a la misma dirección
    }
    
    cleanupMemorySystem(); // Limpia la memoria antes de finalizar el programa
    return 0;
}


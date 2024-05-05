#include <iostream>
#include <limits.h>

#define V 5  // Número de vértices en el grafo

// Función para encontrar el vértice con la distancia mínima, de los que no han sido incluidos en el camino más corto aún
int minDistance(int* dist, bool* sptSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Función para imprimir la matriz de distancias
void printSolution(int* dist) {
    std::cout << "Vertice \t Distancia desde la fuente\n";
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

// Implementación del algoritmo de Dijkstra utilizando punteros
void dijkstra(int** graph, int src) {
    int* dist = new int[V];  // La matriz de salida. dist[i] contendrá la distancia más corta desde src hasta i
    bool* sptSet = new bool[V];  // sptSet[i] será verdadero si el vértice i está incluido en el camino más corto

    // Inicializar todas las distancias como INFINITO y sptSet[] como falso
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // La distancia del vértice origen a sí mismo es siempre 0
    dist[src] = 0;

    // Encontrar el camino más corto para todos los vértices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Imprimir la matriz de distancias
    printSolution(dist);

    // Liberar memoria
    delete[] dist;
    delete[] sptSet;
}

int main() {
    // Representación del grafo como una matriz de adyacencia
    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++) {
            std::cin >> graph[i][j]; // Entrada del usuario o definición previa
        }
    }

    dijkstra(graph, 0); // 0 es el vértice origen

    // Liberación de memoria del grafo
    for (int i = 0; i < V; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}


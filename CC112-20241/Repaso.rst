Memoria dinámica, new y delete

Ejemplo

.. code:: c++

    #include <iostream>
    
    int main() {
        int *ptr = new int(42); // asignación dinámica de memoria
        std::cout << "Value: " << *ptr << std::endl;
        delete ptr; // liberación de memoria
    
        int *arr = new int[5]; // asignación dinámica de un arreglo
        for (int i = 0; i < 5; ++i) {
            arr[i] = i * 10;
        }
    
        std::cout << "Array values: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    
        delete[] arr; // liberación de memoria del arreglo
    
        return 0;
    }


Ejercicio

-  Escribe una función que reciba un tamaño y devuelva un puntero a un
   arreglo de enteros inicializado con valores aleatorios. Luego, libera
   la memoria del arreglo fuera de la función.
-  Implementa un programa que use new y delete para gestionar memoria de
   estructuras dinámicamente.

.. code:: c++

    ## Tu respuesta

Ordenar la matriz de estructuras por precio

Escribe un programa que:

-  Define una estructura Producto con los campos nombre, precio y
   cantidad.
-  Implementa una función para ordenar una matriz bidimensional de
   Producto por precio en orden ascendente.
-  Usa la memoria dinámica para crear y llenar la matriz.
-  Imprime la matriz ordenada

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Producto {
        char nombre[50];
        float precio;
        int cantidad;
    };
    
    Producto** crearMatriz(int filas, int columnas) {
        Producto** matriz = new Producto*[filas];
        for (int i = 0; i < filas; ++i) {
            matriz[i] = new Producto[columnas];
        }
        return matriz;
    }
    
    void liberarMatriz(Producto** matriz, int filas) {
        for (int i = 0; i < filas; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
    
    void llenarMatriz(Producto** matriz, int filas, int columnas) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << "Ingrese el nombre del producto en [" << i << "][" << j << "]: ";
                std::cin.ignore();
                std::cin.getline(matriz[i][j].nombre, 50);
                std::cout << "Ingrese el precio del producto en [" << i << "][" << j << "]: ";
                std::cin >> matriz[i][j].precio;
                std::cout << "Ingrese la cantidad del producto en [" << i << "][" << j << "]: ";
                std::cin >> matriz[i][j].cantidad;
            }
        }
    }
    
    void imprimirMatriz(Producto** matriz, int filas, int columnas) {
        std::cout << "Matriz de productos:\n";
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << "Producto en [" << i << "][" << j << "]: ";
                std::cout << "Nombre: " << matriz[i][j].nombre << ", Precio: " << matriz[i][j].precio << ", Cantidad: " << matriz[i][j].cantidad << std::endl;
            }
        }
    }
    
    void ordenarMatrizPorPrecio(Producto** matriz, int filas, int columnas) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas - 1; ++j) {
                for (int k = j + 1; k < columnas; ++k) {
                    if (matriz[i][j].precio > matriz[i][k].precio) {
                        std::swap(matriz[i][j], matriz[i][k]);
                    }
                }
            }
        }
    }
    
    int main() {
        int filas, columnas;
        std::cout << "Ingrese el número de filas: ";
        std::cin >> filas;
        std::cout << "Ingrese el número de columnas: ";
        std::cin >> columnas;
    
        Producto** matriz = crearMatriz(filas, columnas);
    
        llenarMatriz(matriz, filas, columnas);
    
        std::cout << "Antes de ordenar por precio:\n";
        imprimirMatriz(matriz, filas, columnas);
    
        ordenarMatrizPorPrecio(matriz, filas, columnas);
    
        std::cout << "Después de ordenar por precio:\n";
        imprimirMatriz(matriz, filas, columnas);
    
        liberarMatriz(matriz, filas);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Matriz de estructuras y memoria dinámica

Escribe un programa que:

-  Define una estructura Producto con los campos nombre, precio y
   cantidad.
-  Implementa una función para crear una matriz bidimensional de
   Producto usando memoria dinámica.
-  Implementa una función para liberar la memoria de la matriz
   bidimensional.
-  Implementa una función para llenar la matriz con datos proporcionados
   por el usuario.
-  Implementa una función para imprimir la matriz de productos.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Producto {
        char nombre[50];
        float precio;
        int cantidad;
    };
    
    Producto** crearMatriz(int filas, int columnas) {
        Producto** matriz = new Producto*[filas];
        for (int i = 0; i < filas; ++i) {
            matriz[i] = new Producto[columnas];
        }
        return matriz;
    }
    
    void liberarMatriz(Producto** matriz, int filas) {
        for (int i = 0; i < filas; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
    
    void llenarMatriz(Producto** matriz, int filas, int columnas) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << "Ingrese el nombre del producto en [" << i << "][" << j << "]: ";
                std::cin.ignore();
                std::cin.getline(matriz[i][j].nombre, 50);
                std::cout << "Ingrese el precio del producto en [" << i << "][" << j << "]: ";
                std::cin >> matriz[i][j].precio;
                std::cout << "Ingrese la cantidad del producto en [" << i << "][" << j << "]: ";
                std::cin >> matriz[i][j].cantidad;
            }
        }
    }
    
    void imprimirMatriz(Producto** matriz, int filas, int columnas) {
        std::cout << "Matriz de productos:\n";
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << "Producto en [" << i << "][" << j << "]: ";
                std::cout << "Nombre: " << matriz[i][j].nombre << ", Precio: " << matriz[i][j].precio << ", Cantidad: " << matriz[i][j].cantidad << std::endl;
            }
        }
    }
    
    int main() {
        int filas, columnas;
        std::cout << "Ingrese el número de filas: ";
        std::cin >> filas;
        std::cout << "Ingrese el número de columnas: ";
        std::cin >> columnas;
    
        Producto** matriz = crearMatriz(filas, columnas);
    
        llenarMatriz(matriz, filas, columnas);
        imprimirMatriz(matriz, filas, columnas);
    
        liberarMatriz(matriz, filas);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Ordena arreglo de estructuras

Escribe un programa que:

-  Define una estructura Estudiante con los campos nombre, nota y edad.
-  Implementa una función para llenar un arreglo de Estudiante con datos
   proporcionados por el usuario.
-  Implementa una función para ordenar el arreglo de Estudiante por nota
   de manera ascendente utilizando el algoritmo de selección.
-  Implementa una función para imprimir el arreglo de Estudiante.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Estudiante {
        char nombre[50];
        float nota;
        int edad;
    };
    
    void llenarEstudiantes(Estudiante* estudiantes, int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
            std::cin.ignore();
            std::cin.getline(estudiantes[i].nombre, 50);
            std::cout << "Ingrese la nota del estudiante " << i + 1 << ": ";
            std::cin >> estudiantes[i].nota;
            std::cout << "Ingrese la edad del estudiante " << i + 1 << ": ";
            std::cin >> estudiantes[i].edad;
        }
    }
    
    void imprimirEstudiantes(Estudiante* estudiantes, int n) {
        std::cout << "Lista de estudiantes:\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "Nombre: " << estudiantes[i].nombre << ", Nota: " << estudiantes[i].nota << ", Edad: " << estudiantes[i].edad << std::endl;
        }
    }
    
    void ordenarPorNota(Estudiante* estudiantes, int n) {
        for (int i = 0; i < n - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (estudiantes[j].nota < estudiantes[min_idx].nota) {
                    min_idx = j;
                }
            }
            std::swap(estudiantes[i], estudiantes[min_idx]);
        }
    }
    
    int main() {
        int n;
        std::cout << "Ingrese el número de estudiantes: ";
        std::cin >> n;
    
        Estudiante* estudiantes = new Estudiante[n];
    
        llenarEstudiantes(estudiantes, n);
    
        std::cout << "Antes de ordenar:\n";
        imprimirEstudiantes(estudiantes, n);
    
        ordenarPorNota(estudiantes, n);
    
        std::cout << "Después de ordenar por nota:\n";
        imprimirEstudiantes(estudiantes, n);
    
        delete[] estudiantes;
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Puntero a estructura y paso de estructura como parámetro

Escribe un programa que:

-  Define una estructura Persona con los campos nombre, edad y altura.
-  Implementa una función que tome un puntero a Persona y llene los
   campos con datos proporcionados por el usuario.
-  Implementa una función que tome una Persona por valor y la imprima.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Persona {
        char nombre[50];
        int edad;
        float altura;
    };
    
    void llenarPersona(Persona* p) {
        std::cout << "Ingrese el nombre: ";
        std::cin.ignore();
        std::cin.getline(p->nombre, 50);
        std::cout << "Ingrese la edad: ";
        std::cin >> p->edad;
        std::cout << "Ingrese la altura (en metros): ";
        std::cin >> p->altura;
    }
    
    void imprimirPersona(Persona p) {
        std::cout << "Nombre: " << p.nombre << std::endl;
        std::cout << "Edad: " << p.edad << std::endl;
        std::cout << "Altura: " << p.altura << " m" << std::endl;
    }
    
    int main() {
        Persona persona;
        llenarPersona(&persona);
        imprimirPersona(persona);
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Lista enlazada dinámica

Escribe un programa que:

-  Define una estructura Node para una lista enlazada, con un campo data
   y un puntero next.
-  Implementa funciones para agregar un nodo al final de la lista,
   imprimir la lista, y liberar la memoria de la lista.
-  Pide al usuario agregar nodos a la lista y luego imprima la lista.
-  Libera la memoria de la lista.

.. code:: c++

    #include <iostream>
    
    struct Node {
        int data;
        Node* next;
    };
    
    void addNode(Node*& head, int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
    
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    
    void freeList(Node*& head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int main() {
        Node* head = nullptr;
        int n, value;
    
        std::cout << "Ingrese el número de nodos: ";
        std::cin >> n;
    
        for (int i = 0; i < n; ++i) {
            std::cout << "Ingrese el valor del nodo " << i + 1 << ": ";
            std::cin >> value;
            addNode(head, value);
        }
    
        std::cout << "La lista enlazada es: ";
        printList(head);
    
        freeList(head);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Producto de matrices

Escribe un programa que:

-  Define una función para multiplicar dos matrices bidimensionales de
   enteros.
-  Usa memoria dinámica para crear y almacenar el resultado de la
   multiplicación.
-  Pide al usuario el número de filas y columnas de las matrices.
-  Llena las matrices con valores ingresados por el usuario.
-  Imprime la matriz resultante.
-  Libera la memoria de las matrices.

.. code:: c++

    #include <iostream>
    
    int** createMatrix(int rows, int cols) {
        int** matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
        return matrix;
    }
    
    void freeMatrix(int** matrix, int rows) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    void fillMatrix(int** matrix, int rows, int cols) {
        std::cout << "Ingrese los elementos de la matriz:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }
    
    void printMatrix(int** matrix, int rows, int cols) {
        std::cout << "La matriz es:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
        int** result = createMatrix(rows1, cols2);
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < cols1; ++k) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }
    
    int main() {
        int rows1, cols1, rows2, cols2;
        std::cout << "Ingrese el número de filas de la primera matriz: ";
        std::cin >> rows1;
        std::cout << "Ingrese el número de columnas de la primera matriz: ";
        std::cin >> cols1;
        std::cout << "Ingrese el número de filas de la segunda matriz: ";
        std::cin >> rows2;
        std::cout << "Ingrese el número de columnas de la segunda matriz: ";
        std::cin >> cols2;
    
        if (cols1 != rows2) {
            std::cout << "Las matrices no se pueden multiplicar." << std::endl;
            return -1;
        }
    
        int** matrix1 = createMatrix(rows1, cols1);
        int** matrix2 = createMatrix(rows2, cols2);
    
        std::cout << "Llenar la primera matriz:\n";
        fillMatrix(matrix1, rows1, cols1);
        std::cout << "Llenar la segunda matriz:\n";
        fillMatrix(matrix2, rows2, cols2);
    
        int** result = multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);
    
        std::cout << "La matriz resultante de la multiplicación es:\n";
        printMatrix(result, rows1, cols2);
    
        freeMatrix(matrix1, rows1);
        freeMatrix(matrix2, rows2);
        freeMatrix(result, rows1);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Transponer matriz

Escribe un programa que:

-  Define una función para transponer una matriz bidimensional de
   enteros.
-  Use memoria dinámica para crear y almacenar la matriz transpuesta.
-  PidE al usuario el número de filas y columnas.
-  Llena la matriz con valores ingresados por el usuario.
-  Imprime la matriz transpuesta.
-  Libera la memoria de las matrices.

.. code:: c++

    #include <iostream>
    
    int** createMatrix(int rows, int cols) {
        int** matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
        return matrix;
    }
    
    void freeMatrix(int** matrix, int rows) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    void fillMatrix(int** matrix, int rows, int cols) {
        std::cout << "Ingrese los elementos de la matriz:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }
    
    void printMatrix(int** matrix, int rows, int cols) {
        std::cout << "La matriz es:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    int** transposeMatrix(int** matrix, int rows, int cols) {
        int** transposed = createMatrix(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
    
    int main() {
        int rows, cols;
        std::cout << "Ingrese el número de filas: ";
        std::cin >> rows;
        std::cout << "Ingrese el número de columnas: ";
        std::cin >> cols;
    
        int** matrix = createMatrix(rows, cols);
    
        fillMatrix(matrix, rows, cols);
    
        int** transposed = transposeMatrix(matrix, rows, cols);
    
        std::cout << "La matriz transpuesta es:\n";
        printMatrix(transposed, cols, rows);
    
        freeMatrix(matrix, rows);
        freeMatrix(transposed, cols);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crear y liberar una matriz bidimensional

Escribe un programa que:

-  Define una función para crear una matriz bidimensional de enteros
   usando memoria dinámica.
-  Define una función para liberar la memoria de la matriz
   bidimensional.
-  Pide al usuario el número de filas y columnas.
-  Llena la matriz con valores ingresados por el usuario.
-  Imprime la matriz.
-  Libera la memoria de la matriz.

.. code:: c++

    #include <iostream>
    
    int** createMatrix(int rows, int cols) {
        int** matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
        return matrix;
    }
    
    void freeMatrix(int** matrix, int rows) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    void fillMatrix(int** matrix, int rows, int cols) {
        std::cout << "Ingrese los elementos de la matriz:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }
    
    void printMatrix(int** matrix, int rows, int cols) {
        std::cout << "La matriz es:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    int main() {
        int rows, cols;
        std::cout << "Ingrese el número de filas: ";
        std::cin >> rows;
        std::cout << "Ingrese el número de columnas: ";
        std::cin >> cols;
    
        int** matrix = createMatrix(rows, cols);
    
        fillMatrix(matrix, rows, cols);
        printMatrix(matrix, rows, cols);
    
        freeMatrix(matrix, rows);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Redimensionamiento de un arreglo dinámico

Escribe un programa que:

-  Pida al usuario el tamaño inicial del arreglo.
-  Usa new para asignar un arreglo de enteros dinámicamente.
-  Solicita al usuario que ingrese los valores del arreglo.
-  Pide al usuario el nuevo tamaño del arreglo.
-  Usa new para crear un nuevo arreglo con el nuevo tamaño y copie los
   elementos del arreglo antiguo al nuevo.
-  Libera la memoria del arreglo antiguo y reasigne el puntero al nuevo
   arreglo.
-  Imprime el nuevo arreglo.
-  Libera la memoria del nuevo arreglo.

.. code:: c++

    #include <iostream>
    
    int main() {
        int oldSize;
        std::cout << "Ingrese el tamaño inicial del arreglo: ";
        std::cin >> oldSize;
    
        int* arr = new int[oldSize];
        std::cout << "Ingrese los elementos del arreglo:\n";
        for (int i = 0; i < oldSize; ++i) {
            std::cin >> arr[i];
        }
    
        int newSize;
        std::cout << "Ingrese el nuevo tamaño del arreglo: ";
        std::cin >> newSize;
    
        int* newArr = new int[newSize];
        for (int i = 0; i < oldSize && i < newSize; ++i) {
            newArr[i] = arr[i];
        }
    
        delete[] arr;
        arr = newArr;
    
        std::cout << "El nuevo arreglo es:\n";
        for (int i = 0; i < newSize; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    
        delete[] arr;
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crea un sistema de gestión de estudiantes que maneje una lista dinámica
de estudiantes utilizando punteros y funciones a punteros.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Estudiante {
        char nombre[50];
        int edad;
        float nota;
        Estudiante* siguiente;
    };
    
    void agregarEstudiante(Estudiante*& ptr, const char* nombre, int edad, float nota) {
        Estudiante* nuevoEstudiante = new Estudiante;
        std::strcpy(nuevoEstudiante->nombre, nombre);
        nuevoEstudiante->edad = edad;
        nuevoEstudiante->nota = nota;
        nuevoEstudiante->siguiente = nullptr;
    
        if (ptr == nullptr) {
            ptr = nuevoEstudiante;
        } else {
            Estudiante* temp = ptr;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoEstudiante;
        }
    }
    
    void imprimirEstudiantes(const Estudiante* ptr) {
        const Estudiante* temp = ptr;
        while (temp != nullptr) {
            std::cout << "Nombre: " << temp->nombre << ", Edad: " << temp->edad << ", Nota: " << temp->nota << std::endl;
            temp = temp->siguiente;
        }
    }
    
    void eliminarEstudiante(Estudiante*& ptr, const char* nombre) {
        Estudiante* temp = ptr;
        Estudiante* anterior = nullptr;
    
        while (temp != nullptr && std::strcmp(temp->nombre, nombre) != 0) {
            anterior = temp;
            temp = temp->siguiente;
        }
    
        if (temp == nullptr) {
            std::cout << "Estudiante no encontrado." << std::endl;
            return;
        }
    
        if (anterior == nullptr) {
            ptr = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
    
        delete temp;
    }
    
    void liberarMemoria(Estudiante*& ptr) {
        while (ptr != nullptr) {
            Estudiante* temp = ptr;
            ptr = ptr->siguiente;
            delete temp;
        }
    }
    
    int main() {
        Estudiante* listaEstudiantes = nullptr;
        agregarEstudiante(listaEstudiantes, "Juan", 20, 85.5);
        agregarEstudiante(listaEstudiantes, "Maria", 22, 90.0);
        agregarEstudiante(listaEstudiantes, "Luis", 21, 88.0);
    
        std::cout << "Lista de estudiantes:" << std::endl;
        imprimirEstudiantes(listaEstudiantes);
    
        std::cout << "\nEliminando a Maria..." << std::endl;
        eliminarEstudiante(listaEstudiantes, "Maria");
    
        std::cout << "Lista de estudiantes después de eliminar a Maria:" << std::endl;
        imprimirEstudiantes(listaEstudiantes);
    
        liberarMemoria(listaEstudiantes);
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crea un sistema de gestión de libros en una biblioteca, utilizando
estructuras con punteros y funciones a punteros.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Libro {
        char titulo[100];
        char autor[50];
        int anio;
        Libro* siguiente;
    };
    
    void agregarLibro(Libro*& cabeza, const char* titulo, const char* autor, int anio) {
        Libro* nuevoLibro = new Libro;
        std::strcpy(nuevoLibro->titulo, titulo);
        std::strcpy(nuevoLibro->autor, autor);
        nuevoLibro->anio = anio;
        nuevoLibro->siguiente = nullptr;
    
        if (cabeza == nullptr) {
            cabeza = nuevoLibro;
        } else {
            Libro* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoLibro;
        }
    }
    
    void imprimirLibros(const Libro* cabeza) {
        const Libro* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "Titulo: " << temp->titulo << ", Autor: " << temp->autor << ", Año: " << temp->anio << std::endl;
            temp = temp->siguiente;
        }
    }
    
    void buscarLibroPorAutor(const Libro* cabeza, const char* autor) {
        const Libro* temp = cabeza;
        bool encontrado = false;
        while (temp != nullptr) {
            if (std::strcmp(temp->autor, autor) == 0) {
                std::cout << "Titulo: " << temp->titulo << ", Autor: " << temp->autor << ", Año: " << temp->anio << std::endl;
                encontrado = true;
            }
            temp = temp->siguiente;
        }
        if (!encontrado) {
            std::cout << "No se encontraron libros del autor: " << autor << std::endl;
        }
    }
    
    void eliminarLibro(Libro*& cabeza, const char* titulo) {
        Libro* temp = cabeza;
        Libro* anterior = nullptr;
    
        while (temp != nullptr && std::strcmp(temp->titulo, titulo) != 0) {
            anterior = temp;
            temp = temp->siguiente;
        }
    
        if (temp == nullptr) {
            std::cout << "Libro no encontrado." << std::endl;
            return;
        }
    
        if (anterior == nullptr) {
            cabeza = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
    
        delete temp;
    }
    
    void liberarMemoria(Libro*& cabeza) {
        while (cabeza != nullptr) {
            Libro* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    
    int main() {
        Libro* listaLibros = nullptr;
        agregarLibro(listaLibros, "El Quijote", "Miguel de Cervantes", 1605);
        agregarLibro(listaLibros, "Cien años de soledad", "Gabriel García Márquez", 1967);
        agregarLibro(listaLibros, "Don Juan Tenorio", "José Zorrilla", 1844);
    
        std::cout << "Lista de libros en la biblioteca:" << std::endl;
        imprimirLibros(listaLibros);
    
        std::cout << "\nBuscando libros de Gabriel García Márquez..." << std::endl;
        buscarLibroPorAutor(listaLibros, "Gabriel García Márquez");
    
        std::cout << "\nEliminando 'Don Juan Tenorio'..." << std::endl;
        eliminarLibro(listaLibros, "Don Juan Tenorio");
    
        std::cout << "Lista de libros después de eliminar 'Don Juan Tenorio':" << std::endl;
        imprimirLibros(listaLibros);
    
        liberarMemoria(listaLibros);
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crea un sistema de gestión de cursos y estudiantes, utilizando
estructuras anidadas y memoria dinámica.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Estudiante {
        char nombre[50];
        int edad;
        float nota;
        Estudiante* siguiente;
    };
    
    struct Curso {
        char nombreCurso[50];
        Estudiante* listaEstudiantes;
        Curso* siguiente;
    };
    
    void agregarEstudiante(Curso*& curso, const char* nombre, int edad, float nota) {
        Estudiante* nuevoEstudiante = new Estudiante;
        std::strcpy(nuevoEstudiante->nombre, nombre);
        nuevoEstudiante->edad = edad;
        nuevoEstudiante->nota = nota;
        nuevoEstudiante->siguiente = curso->listaEstudiantes;
        curso->listaEstudiantes = nuevoEstudiante;
    }
    
    void imprimirEstudiantes(const Estudiante* cabeza) {
        const Estudiante* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "Nombre: " << temp->nombre << ", Edad: " << temp->edad << ", Nota: " << temp->nota << std::endl;
            temp = temp->siguiente;
        }
    }
    
    void agregarCurso(Curso*& cabeza, const char* nombreCurso) {
        Curso* nuevoCurso = new Curso;
        std::strcpy(nuevoCurso->nombreCurso, nombreCurso);
        nuevoCurso->listaEstudiantes = nullptr;
        nuevoCurso->siguiente = cabeza;
        cabeza = nuevoCurso;
    }
    
    void imprimirCursos(const Curso* cabeza) {
        const Curso* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "Curso: " << temp->nombreCurso << std::endl;
            imprimirEstudiantes(temp->listaEstudiantes);
            temp = temp->siguiente;
        }
    }
    
    void eliminarEstudiante(Estudiante*& cabeza, const char* nombre) {
        Estudiante* temp = cabeza;
        Estudiante* anterior = nullptr;
    
        while (temp != nullptr && std::strcmp(temp->nombre, nombre) != 0) {
            anterior = temp;
            temp = temp->siguiente;
        }
    
        if (temp == nullptr) {
            std::cout << "Estudiante no encontrado." << std::endl;
            return;
        }
    
        if (anterior == nullptr) {
            cabeza = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
    
        delete temp;
    }
    
    void eliminarCurso(Curso*& cabeza, const char* nombreCurso) {
        Curso* temp = cabeza;
        Curso* anterior = nullptr;
    
        while (temp != nullptr && std::strcmp(temp->nombreCurso, nombreCurso) != 0) {
            anterior = temp;
            temp = temp->siguiente;
        }
    
        if (temp == nullptr) {
            std::cout << "Curso no encontrado." << std::endl;
            return;
        }
    
        if (anterior == nullptr) {
            cabeza = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
    
        Estudiante* estudianteTemp = temp->listaEstudiantes;
        while (estudianteTemp != nullptr) {
            Estudiante* estudianteAEliminar = estudianteTemp;
            estudianteTemp = estudianteTemp->siguiente;
            delete estudianteAEliminar;
        }
    
        delete temp;
    }
    
    void liberarMemoria(Curso*& cabeza) {
        while (cabeza != nullptr) {
            Curso* temp = cabeza;
            cabeza = cabeza->siguiente;
    
            Estudiante* estudianteTemp = temp->listaEstudiantes;
            while (estudianteTemp != nullptr) {
                Estudiante* estudianteAEliminar = estudianteTemp;
                estudianteTemp = estudianteTemp->siguiente;
                delete estudianteAEliminar;
            }
    
            delete temp;
        }
    }
    
    int main() {
        Curso* listaCursos = nullptr;
    
        agregarCurso(listaCursos, "Matemáticas");
        agregarCurso(listaCursos, "Física");
    
        agregarEstudiante(listaCursos, "Juan", 20, 85.5);
        agregarEstudiante(listaCursos, "Maria", 22, 90.0);
    
        agregarEstudiante(listaCursos->siguiente, "Luis", 21, 88.0);
        agregarEstudiante(listaCursos->siguiente, "Ana", 23, 92.0);
    
        std::cout << "Lista de cursos y estudiantes:" << std::endl;
        imprimirCursos(listaCursos);
    
        std::cout << "\nEliminando a Juan del curso de Matemáticas..." << std::endl;
        eliminarEstudiante(listaCursos->listaEstudiantes, "Juan");
    
        std::cout << "Lista de cursos y estudiantes después de eliminar a Juan:" << std::endl;
        imprimirCursos(listaCursos);
    
        std::cout << "\nEliminando el curso de Física..." << std::endl;
        eliminarCurso(listaCursos, "Física");
    
        std::cout << "Lista de cursos después de eliminar el curso de Física:" << std::endl;
        imprimirCursos(listaCursos);
    
        liberarMemoria(listaCursos);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crea un sistema de gestión de empleados y proyectos, utilizando
estructuras anidadas y memoria dinámica.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Proyecto {
        char nombreProyecto[50];
        int duracionMeses;
        Proyecto* siguiente;
    };
    
    struct Empleado {
        char nombre[50];
        int edad;
        Proyecto* listaProyectos;
        Empleado* siguiente;
    };
    
    void agregarProyecto(Empleado*& empleado, const char* nombreProyecto, int duracionMeses) {
        Proyecto* nuevoProyecto = new Proyecto;
        std::strcpy(nuevoProyecto->nombreProyecto, nombreProyecto);
        nuevoProyecto->duracionMeses = duracionMeses;
        nuevoProyecto->siguiente = empleado->listaProyectos;
        empleado->listaProyectos = nuevoProyecto;
    }
    
    void imprimirProyectos(const Proyecto* cabeza) {
        const Proyecto* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "Proyecto: " << temp->nombreProyecto << ", Duración: " << temp->duracionMeses << " meses" << std::endl;
            temp = temp->siguiente;
        }
    }
    
    void agregarEmpleado(Empleado*& cabeza, const char* nombre, int edad) {
        Empleado* nuevoEmpleado = new Empleado;
        std::strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->edad = edad;
        nuevoEmpleado->listaProyectos = nullptr;
        nuevoEmpleado->siguiente = cabeza;
        cabeza = nuevoEmpleado;
    }
    
    void imprimirEmpleados(const Empleado* cabeza) {
        const Empleado* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "Empleado: " << temp->nombre << ", Edad: " << temp->edad << std::endl;
            imprimirProyectos(temp->listaProyectos);
            temp = temp->siguiente;
        }
    }
    
    void eliminarProyecto(Proyecto*& cabeza, const char* nombreProyecto) {
        Proyecto* temp = cabeza;
        Proyecto* anterior = nullptr;
    
        while (temp != nullptr && std::strcmp(temp->nombreProyecto, nombreProyecto) != 0) {
            anterior = temp;
            temp = temp->siguiente;
        }
    
        if (temp == nullptr) {
            std::cout << "Proyecto no encontrado." << std::endl;
            return;
        }
    
        if (anterior == nullptr) {
            cabeza = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
    
        delete temp;
    }
    
    void eliminarEmpleado(Empleado*& cabeza, const char* nombre) {
        Empleado* temp = cabeza;
        Empleado* anterior = nullptr;
    
        while (temp != nullptr && std::strcmp(temp->nombre, nombre) != 0) {
            anterior = temp;
            temp = temp->siguiente;
        }
    
        if (temp == nullptr) {
            std::cout << "Empleado no encontrado." << std::endl;
            return;
        }
    
        if (anterior == nullptr) {
            cabeza = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
    
        Proyecto* proyectoTemp = temp->listaProyectos;
        while (proyectoTemp != nullptr) {
            Proyecto* proyectoAEliminar = proyectoTemp;
            proyectoTemp = proyectoTemp->siguiente;
            delete proyectoAEliminar;
        }
    
        delete temp;
    }
    
    void liberarMemoria(Empleado*& cabeza) {
        while (cabeza != nullptr) {
            Empleado* temp = cabeza;
            cabeza = cabeza->siguiente;
    
            Proyecto* proyectoTemp = temp->listaProyectos;
            while (proyectoTemp != nullptr) {
                Proyecto* proyectoAEliminar = proyectoTemp;
                proyectoTemp = proyectoTemp->siguiente;
                delete proyectoAEliminar;
            }
    
            delete temp;
        }
    }
    
    int main() {
        Empleado* listaEmpleados = nullptr;
    
        agregarEmpleado(listaEmpleados, "Carlos", 35);
        agregarEmpleado(listaEmpleados, "Elena", 30);
    
        agregarProyecto(listaEmpleados, "Proyecto Alpha", 12);
        agregarProyecto(listaEmpleados, "Proyecto Beta", 6);
    
        agregarProyecto(listaEmpleados->siguiente, "Proyecto Gamma", 8);
        agregarProyecto(listaEmpleados->siguiente, "Proyecto Delta", 10);
    
        std::cout << "Lista de empleados y proyectos:" << std::endl;
        imprimirEmpleados(listaEmpleados);
    
        std::cout << "\nEliminando 'Proyecto Alpha' de Carlos..." << std::endl;
        eliminarProyecto(listaEmpleados->listaProyectos, "Proyecto Alpha");
    
        std::cout << "Lista de empleados y proyectos después de eliminar 'Proyecto Alpha':" << std::endl;
        imprimirEmpleados(listaEmpleados);
    
        std::cout << "\nEliminando a Elena..." << std::endl;
        eliminarEmpleado(listaEmpleados, "Elena");
    
        std::cout << "Lista de empleados después de eliminar a Elena:" << std::endl;
        imprimirEmpleados(listaEmpleados);
    
        liberarMemoria(listaEmpleados);
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Implementa un árbol binario de búsqueda con operaciones de inserción,
búsqueda y eliminación.

.. code:: c++

    #include <iostream>
    
    struct Nodo {
        int valor;
        Nodo* izquierdo;
        Nodo* derecho;
    
        Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
    };
    
    class BST {
    private:
        Nodo* raiz;
    
        void insertar(Nodo*& nodo, int valor) {
            if (nodo == nullptr) {
                nodo = new Nodo(valor);
            } else if (valor < nodo->valor) {
                insertar(nodo->izquierdo, valor);
            } else {
                insertar(nodo->derecho, valor);
            }
        }
    
        bool buscar(Nodo* nodo, int valor) const {
            if (nodo == nullptr) {
                return false;
            } else if (nodo->valor == valor) {
                return true;
            } else if (valor < nodo->valor) {
                return buscar(nodo->izquierdo, valor);
            } else {
                return buscar(nodo->derecho, valor);
            }
        }
    
        void eliminar(Nodo*& nodo, int valor) {
            if (nodo == nullptr) {
                return;
            }
    
            if (valor < nodo->valor) {
                eliminar(nodo->izquierdo, valor);
            } else if (valor > nodo->valor) {
                eliminar(nodo->derecho, valor);
            } else {
                // Nodo encontrado
                if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                    delete nodo;
                    nodo = nullptr;
                } else if (nodo->izquierdo == nullptr) {
                    Nodo* temp = nodo;
                    nodo = nodo->derecho;
                    delete temp;
                } else if (nodo->derecho == nullptr) {
                    Nodo* temp = nodo;
                    nodo = nodo->izquierdo;
                    delete temp;
                } else {
                    Nodo* temp = encontrarMinimo(nodo->derecho);
                    nodo->valor = temp->valor;
                    eliminar(nodo->derecho, temp->valor);
                }
            }
        }
    
        Nodo* encontrarMinimo(Nodo* nodo) const {
            while (nodo->izquierdo != nullptr) {
                nodo = nodo->izquierdo;
            }
            return nodo;
        }
    
        void imprimirEnOrden(Nodo* nodo) const {
            if (nodo == nullptr) {
                return;
            }
            imprimirEnOrden(nodo->izquierdo);
            std::cout << nodo->valor << " ";
            imprimirEnOrden(nodo->derecho);
        }
    
        void liberarMemoria(Nodo* nodo) {
            if (nodo == nullptr) {
                return;
            }
            liberarMemoria(nodo->izquierdo);
            liberarMemoria(nodo->derecho);
            delete nodo;
        }
    
    public:
        BST() : raiz(nullptr) {}
    
        ~BST() {
            liberarMemoria(raiz);
        }
    
        void insertar(int valor) {
            insertar(raiz, valor);
        }
    
        bool buscar(int valor) const {
            return buscar(raiz, valor);
        }
    
        void eliminar(int valor) {
            eliminar(raiz, valor);
        }
    
        void imprimirEnOrden() const {
            imprimirEnOrden(raiz);
            std::cout << std::endl;
        }
    };
    
    int main() {
        BST arbol;
        arbol.insertar(10);
        arbol.insertar(5);
        arbol.insertar(15);
        arbol.insertar(3);
        arbol.insertar(7);
    
        std::cout << "Árbol en orden: ";
        arbol.imprimirEnOrden();
    
        std::cout << "Buscando 7: " << (arbol.buscar(7) ? "Encontrado" : "No encontrado") << std::endl;
    
        std::cout << "Eliminando 7..." << std::endl;
        arbol.eliminar(7);
    
        std::cout << "Árbol en orden después de eliminar 7: ";
        arbol.imprimirEnOrden();
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Implementa una lista enlazada simple con operaciones de inserción,
búsqueda y eliminación.

.. code:: c++

    #include <iostream>
    
    struct Nodo {
        int valor;
        Nodo* siguiente;
    
        Nodo(int v) : valor(v), siguiente(nullptr) {}
    };
    
    class ListaEnlazada {
    private:
        Nodo* cabeza;
    
        void liberarMemoria() {
            while (cabeza != nullptr) {
                Nodo* temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp;
            }
        }
    
    public:
        ListaEnlazada() : cabeza(nullptr) {}
    
        ~ListaEnlazada() {
            liberarMemoria();
        }
    
        void insertar(int valor) {
            Nodo* nuevo = new Nodo(valor);
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
        }
    
        bool buscar(int valor) const {
            Nodo* actual = cabeza;
            while (actual != nullptr) {
                if (actual->valor == valor) {
                    return true;
                }
                actual = actual->siguiente;
            }
            return false;
        }
    
        void eliminar(int valor) {
            Nodo* actual = cabeza;
            Nodo* anterior = nullptr;
    
            while (actual != nullptr && actual->valor != valor) {
                anterior = actual;
                actual = actual->siguiente;
            }
    
            if (actual == nullptr) {
                return; // Valor no encontrado
            }
    
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
        }
    
        void imprimir() const {
            Nodo* actual = cabeza;
            while (actual != nullptr) {
                std::cout << actual->valor << " -> ";
                actual = actual->siguiente;
            }
            std::cout << "nullptr" << std::endl;
        }
    };
    
    int main() {
        ListaEnlazada lista;
        lista.insertar(10);
        lista.insertar(20);
        lista.insertar(30);
    
        std::cout << "Lista enlazada: ";
        lista.imprimir();
    
        std::cout << "Buscando 20: " << (lista.buscar(20) ? "Encontrado" : "No encontrado") << std::endl;
    
        std::cout << "Eliminando 20..." << std::endl;
        lista.eliminar(20);
    
        std::cout << "Lista enlazada después de eliminar 20: ";
        lista.imprimir();
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Implementa una tabla hash con operaciones de inserción, búsqueda y
eliminación utilizando listas enlazadas para manejar colisiones.

.. code:: c++

    #include <iostream>
    #include <cstring>
    
    struct Nodo {
        std::string clave;
        int valor;
        Nodo* siguiente;
    
        Nodo(const std::string& clave, int valor) : clave(clave), valor(valor), siguiente(nullptr) {}
    };
    
    class TablaHash {
    private:
        Nodo** tabla;
        int capacidad;
    
        int hash(const std::string& clave) const {
            int hashValue = 0;
            for (char c : clave) {
                hashValue = (hashValue * 31 + c) % capacidad;
            }
            return hashValue;
        }
    
    public:
        TablaHash(int cap) : capacidad(cap) {
            tabla = new Nodo*[capacidad];
            for (int i = 0; i < capacidad; ++i) {
                tabla[i] = nullptr;
            }
        }
    
        ~TablaHash() {
            for (int i = 0; i < capacidad; ++i) {
                Nodo* nodo = tabla[i];
                while (nodo != nullptr) {
                    Nodo* temp = nodo;
                    nodo = nodo->siguiente;
                    delete temp;
                }
            }
            delete[] tabla;
        }
    
        void insertar(const std::string& clave, int valor) {
            int index = hash(clave);
            Nodo* nuevoNodo = new Nodo(clave, valor);
    
            if (tabla[index] == nullptr) {
                tabla[index] = nuevoNodo;
            } else {
                Nodo* nodo = tabla[index];
                while (nodo->siguiente != nullptr) {
                    if (nodo->clave == clave) {
                        nodo->valor = valor;
                        delete nuevoNodo;
                        return;
                    }
                    nodo = nodo->siguiente;
                }
                if (nodo->clave == clave) {
                    nodo->valor = valor;
                    delete nuevoNodo;
                    return;
                }
                nodo->siguiente = nuevoNodo;
            }
        }
    
        bool buscar(const std::string& clave, int& valor) const {
            int index = hash(clave);
            Nodo* nodo = tabla[index];
            while (nodo != nullptr) {
                if (nodo->clave == clave) {
                    valor = nodo->valor;
                    return true;
                }
                nodo = nodo->siguiente;
            }
            return false;
        }
    
        void eliminar(const std::string& clave) {
            int index = hash(clave);
            Nodo* nodo = tabla[index];
            Nodo* anterior = nullptr;
    
            while (nodo != nullptr && nodo->clave != clave) {
                anterior = nodo;
                nodo = nodo->siguiente;
            }
    
            if (nodo == nullptr) {
                return; // Clave no encontrada
            }
    
            if (anterior == nullptr) {
                tabla[index] = nodo->siguiente;
            } else {
                anterior->siguiente = nodo->siguiente;
            }
    
            delete nodo;
        }
    
        void imprimir() const {
            for (int i = 0; i < capacidad; ++i) {
                std::cout << "Índice " << i << ": ";
                Nodo* nodo = tabla[i];
                while (nodo != nullptr) {
                    std::cout << "(" << nodo->clave << ", " << nodo->valor << ") ";
                    nodo = nodo->siguiente;
                }
                std::cout << std::endl;
            }
        }
    };
    
    int main() {
        TablaHash tabla(10);
        tabla.insertar("uno", 1);
        tabla.insertar("dos", 2);
        tabla.insertar("tres", 3);
        tabla.insertar("cuatro", 4);
    
        std::cout << "Tabla hash:" << std::endl;
        tabla.imprimir();
    
        int valor;
        if (tabla.buscar("tres", valor)) {
            std::cout << "Valor asociado a 'tres': " << valor << std::endl;
        } else {
            std::cout << "'tres' no encontrado." << std::endl;
        }
    
        std::cout << "Eliminando 'dos'..." << std::endl;
        tabla.eliminar("dos");
    
        std::cout << "Tabla hash después de eliminar 'dos':" << std::endl;
        tabla.imprimir();
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crea un sistema de gestión de contactos utilizando un árbol binario de
búsqueda. El sistema debe permitir agregar, buscar, eliminar y listar
contactos.

.. code:: c++

    #include <iostream>
    #include <string>
    
    struct Contacto {
        std::string nombre;
        std::string telefono;
        std::string email;
        Contacto* izquierdo;
        Contacto* derecho;
    
        Contacto(std::string n, std::string t, std::string e) 
            : nombre(n), telefono(t), email(e), izquierdo(nullptr), derecho(nullptr) {}
    };
    
    class Agenda {
    private:
        Contacto* raiz;
    
        void insertar(Contacto*& nodo, std::string nombre, std::string telefono, std::string email) {
            if (nodo == nullptr) {
                nodo = new Contacto(nombre, telefono, email);
            } else if (nombre < nodo->nombre) {
                insertar(nodo->izquierdo, nombre, telefono, email);
            } else {
                insertar(nodo->derecho, nombre, telefono, email);
            }
        }
    
        Contacto* buscar(Contacto* nodo, std::string nombre) const {
            if (nodo == nullptr || nodo->nombre == nombre) {
                return nodo;
            } else if (nombre < nodo->nombre) {
                return buscar(nodo->izquierdo, nombre);
            } else {
                return buscar(nodo->derecho, nombre);
            }
        }
    
        void eliminar(Contacto*& nodo, std::string nombre) {
            if (nodo == nullptr) {
                return;
            }
            if (nombre < nodo->nombre) {
                eliminar(nodo->izquierdo, nombre);
            } else if (nombre > nodo->nombre) {
                eliminar(nodo->derecho, nombre);
            } else {
                if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                    delete nodo;
                    nodo = nullptr;
                } else if (nodo->izquierdo == nullptr) {
                    Contacto* temp = nodo;
                    nodo = nodo->derecho;
                    delete temp;
                } else if (nodo->derecho == nullptr) {
                    Contacto* temp = nodo;
                    nodo = nodo->izquierdo;
                    delete temp;
                } else {
                    Contacto* temp = encontrarMinimo(nodo->derecho);
                    nodo->nombre = temp->nombre;
                    nodo->telefono = temp->telefono;
                    nodo->email = temp->email;
                    eliminar(nodo->derecho, temp->nombre);
                }
            }
        }
    
        Contacto* encontrarMinimo(Contacto* nodo) const {
            while (nodo->izquierdo != nullptr) {
                nodo = nodo->izquierdo;
            }
            return nodo;
        }
    
        void imprimirEnOrden(Contacto* nodo) const {
            if (nodo == nullptr) {
                return;
            }
            imprimirEnOrden(nodo->izquierdo);
            std::cout << "Nombre: " << nodo->nombre << ", Teléfono: " << nodo->telefono << ", Email: " << nodo->email << std::endl;
            imprimirEnOrden(nodo->derecho);
        }
    
        void liberarMemoria(Contacto* nodo) {
            if (nodo == nullptr) {
                return;
            }
            liberarMemoria(nodo->izquierdo);
            liberarMemoria(nodo->derecho);
            delete nodo;
        }
    
    public:
        Agenda() : raiz(nullptr) {}
    
        ~Agenda() {
            liberarMemoria(raiz);
        }
    
        void agregarContacto(std::string nombre, std::string telefono, std::string email) {
            insertar(raiz, nombre, telefono, email);
        }
    
        void buscarContacto(std::string nombre) const {
            Contacto* contacto = buscar(raiz, nombre);
            if (contacto != nullptr) {
                std::cout << "Contacto encontrado: " << std::endl;
                std::cout << "Nombre: " << contacto->nombre << ", Teléfono: " << contacto->telefono << ", Email: " << contacto->email << std::endl;
            } else {
                std::cout << "Contacto no encontrado." << std::endl;
            }
        }
    
        void eliminarContacto(std::string nombre) {
            eliminar(raiz, nombre);
        }
    
        void listarContactos() const {
            imprimirEnOrden(raiz);
        }
    };
    
    int main() {
        Agenda agenda;
        agenda.agregarContacto("Juan Perez", "123456789", "juan@example.com");
        agenda.agregarContacto("Maria Lopez", "987654321", "maria@example.com");
        agenda.agregarContacto("Luis Garcia", "456789123", "luis@example.com");
    
        std::cout << "Lista de contactos:" << std::endl;
        agenda.listarContactos();
    
        std::cout << "\nBuscando contacto 'Maria Lopez':" << std::endl;
        agenda.buscarContacto("Maria Lopez");
    
        std::cout << "\nEliminando contacto 'Juan Perez'..." << std::endl;
        agenda.eliminarContacto("Juan Perez");
    
        std::cout << "Lista de contactos después de eliminar 'Juan Perez':" << std::endl;
        agenda.listarContactos();
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

Crea un sistema de gestión de inventario utilizando una tabla hash. El
sistema debe permitir agregar, buscar, eliminar y listar productos.

.. code:: c++

    #include <iostream>
    #include <string>
    
    struct Producto {
        std::string codigo;
        std::string nombre;
        int cantidad;
        float precio;
        Producto* siguiente;
    
        Producto(const std::string& c, const std::string& n, int cant, float p) 
            : codigo(c), nombre(n), cantidad(cant), precio(p), siguiente(nullptr) {}
    };
    
    class Inventario {
    private:
        Producto** tabla;
        int capacidad;
    
        int hash(const std::string& clave) const {
            int hashValue = 0;
            for (char c : clave) {
                hashValue = (hashValue * 31 + c) % capacidad;
            }
            return hashValue;
        }
    
    public:
        Inventario(int cap) : capacidad(cap) {
            tabla = new Producto*[capacidad];
            for (int i = 0; i < capacidad; ++i) {
                tabla[i] = nullptr;
            }
        }
    
        ~Inventario() {
            for (int i = 0; i < capacidad; ++i) {
                Producto* producto = tabla[i];
                while (producto != nullptr) {
                    Producto* temp = producto;
                    producto = producto->siguiente;
                    delete temp;
                }
            }
            delete[] tabla;
        }
    
        void agregarProducto(const std::string& codigo, const std::string& nombre, int cantidad, float precio) {
            int index = hash(codigo);
            Producto* nuevoProducto = new Producto(codigo, nombre, cantidad, precio);
    
            if (tabla[index] == nullptr) {
                tabla[index] = nuevoProducto;
            } else {
                Producto* producto = tabla[index];
                while (producto->siguiente != nullptr) {
                    if (producto->codigo == codigo) {
                        producto->nombre = nombre;
                        producto->cantidad = cantidad;
                        producto->precio = precio;
                        delete nuevoProducto;
                        return;
                    }
                    producto = producto->siguiente;
                }
                if (producto->codigo == codigo) {
                    producto->nombre = nombre;
                    producto->cantidad = cantidad;
                    producto->precio = precio;
                    delete nuevoProducto;
                    return;
                }
                producto->siguiente = nuevoProducto;
            }
        }
    
        bool buscarProducto(const std::string& codigo, Producto*& producto) const {
            int index = hash(codigo);
            Producto* p = tabla[index];
            while (p != nullptr) {
                if (p->codigo == codigo) {
                    producto = p;
                    return true;
                }
                p = p->siguiente;
            }
            return false;
        }
    
        void eliminarProducto(const std::string& codigo) {
            int index = hash(codigo);
            Producto* producto = tabla[index];
            Producto* anterior = nullptr;
    
            while (producto != nullptr && producto->codigo != codigo) {
                anterior = producto;
                producto = producto->siguiente;
            }
    
            if (producto == nullptr) {
                return; // Producto no encontrado
            }
    
            if (anterior == nullptr) {
                tabla[index] = producto->siguiente;
            } else {
                anterior->siguiente = producto->siguiente;
            }
    
            delete producto;
        }
    
        void listarProductos() const {
            for (int i = 0; i < capacidad; ++i) {
                Producto* producto = tabla[i];
                while (producto != nullptr) {
                    std::cout << "Código: " << producto->codigo << ", Nombre: " << producto->nombre 
                              << ", Cantidad: " << producto->cantidad << ", Precio: $" << producto->precio << std::endl;
                    producto = producto->siguiente;
                }
            }
        }
    };
    
    int main() {
        Inventario inventario(10);
        inventario.agregarProducto("A001", "Producto 1", 100, 9.99);
        inventario.agregarProducto("A002", "Producto 2", 200, 19.99);
        inventario.agregarProducto("A003", "Producto 3", 150, 14.99);
    
        std::cout << "Lista de productos:" << std::endl;
        inventario.listarProductos();
    
        Producto* producto;
        if (inventario.buscarProducto("A002", producto)) {
            std::cout << "\nProducto encontrado: " << producto->nombre << std::endl;
        } else {
            std::cout << "\nProducto no encontrado." << std::endl;
        }
    
        std::cout << "\nEliminando producto 'A001'..." << std::endl;
        inventario.eliminarProducto("A001");
    
        std::cout << "Lista de productos después de eliminar 'A001':" << std::endl;
        inventario.listarProductos();
    
        return 0;
    }


.. code:: c++

    ## Tu respuesta

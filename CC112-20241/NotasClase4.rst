Otros algoritmos de ordenamiento
--------------------------------

Algoritmo Quicksort
~~~~~~~~~~~~~~~~~~~

El algoritmo Quicksort es una combinación de particiones y recursividad.
La idea principal detrás de este algoritmo es colocar un elemento
llamado ``pivote`` en una posición donde los elementos a su izquierda
sean más pequeños y los elementos a su derecha sean más grandes o
iguales.

QuickSort es un algoritmo de ordenamiento basado en la estrategia de
`divide y
vencerás <https://www.codesdope.com/course/algorithms-divide-and-conquer/>`__.

-  El algoritmo Quick sort comienza a ejecutarse seleccionando el
   elemento pivote, que suele ser el último elemento del arreglo.
-  El elemento pivote se compara con cada elemento antes de colocarlo en
   su posición final en el arreglo.
-  Los elementos de la izquierda (subarreglo 1) del elemento pivote son
   más pequeños que el pivote y los elementos de la derecha (subarreglo
   2) son más grandes que el pivote.
-  Quick Sort funciona de forma recursiva en cada subarreglo hasta que
   todos los elementos pivotantes de cada subarreglo se colocan en sus
   posiciones finales.

**PseudoCodigo**

1. Escoge el último elemento del arreglo. Esto se denomina pivote.
2. Coloca el pivote en su posición final en el arreglo de modo que los
   elementos a su izquierda son menores y los elementos a la derecha del
   pivote son mayores.
3. Particiona el arreglo en el pivote.

   -  Partición A: comienza desde el inicio del arreglo hasta justo
      antes del pivote.
   -  Partición B: comienza desde el elemento justo después del pivote
      hasta el final del arreglo.

4. Aplica recursivamente los pasos 1, 2 y 3 a cada subarreglo
   particionado A y B.

Podemos esquematizar el pseudocódigo:

::

   quickSort(arr[], min, max):
       if min < max:
           pi = particion(arr, min, max)
           quickSort(arr, min, pi - 1)
           quickSort(arr, pi + 1, max)

   partition(arr[], min, max):
       pivot = arr[max]
       i = (min - 1)
       for j = min to max-1:
           if arr[j] < pivot:
               i++
               swap arr[i] with arr[j]
       swap arr[i + 1] with arr[max]
       return (i + 1)

Implementación del algoritmo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Considera un arreglo :math:`x_0 , x_1 , x_2 ,\dots, x_{n-1}` . Si
tomamos el último elemento, :math:`x_{n-1}`, como pivote, y colocamos un
iterador :math:`i` en la posición :math:`0` y otro iterador :math:`j` en
la posición :math:`n -2`. Si :math:`x_i` es más pequeño que el pivote,
aumenta :math:`i` en uno.

Además, si :math:`x_j` es mayor o igual que el pivote, disminuye
:math:`j` en uno. En el caso de que :math:`x_i` sea mayor o igual que el
pivote y que :math:`x_j` sea menor que el pivote, intercambia ambos
elementos y continúa.

El proceso se detiene cuando :math:`i` es mayor que :math:`j`.
Finalmente, simplemente intercambia :math:`x_i` y el pivote. Este se
asegurará de que el pivote esté en la posición correcta. Repite el
proceso con el subarreglo en el lado izquierdo del pivote y con el
subarreglo en el lado derecho del pivote. Al final, se ordenará todo el
arreglo.

El peor de los casos es cuando todos los elementos se ordenan en orden
no ascendente, porque todos los elementos estarán ubicados en el lado
derecho del pivote en cada iteración. Para el primer pivote habrá
:math:`n -1` elementos a su derecha, para el próximo pivote será
:math:`n - 2`, y así sucesivamente.

Para evitar esto, muchos algoritmos ejecutan un algoritmo de ordenación
aleatoria antes de ejecutar ``quicksort`` alcanzando :math:`O(n\log n)`
la mayoría de las veces.

El código siguiente implementa quick sort para ordenar un arreglo
:math:`X` de :math:`n` elementos (:math:`1 \leq n < 20`). La entrada
consiste en el número :math:`n` y los :math:`n` números que forman
:math:`X`. La salida es :math:`X` con sus elementos ordenados en orden
ascendente.

**Complejidad del tiempo:** :math:`O(n^2)`,

Es importante decir que la complejidad de tiempo promedio de este
algoritmo es :math:`O(n \log n)` y es por eso que se usa ampliamente.

Entrada:

-  n: El número de elementos en el arreglo.
-  X: Arreglo a ordenar.

Salida:

El arreglo ordenado.

.. code:: ipython3

    #include <algorithm>
    #include <cstdio>
    using namespace std;
    
    int X[20];
    int n;
    
    void quicksort(int, int);
    int getPivot(int, int);
    
    int main() {
       scanf("%d", &n);
       for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
        }
        
        quicksort(0, n - 1);
    
        for (int i = 0; i < n; i++) {
          printf("%d ", X[i]);
        }
        printf("\n");
    
        return 0;
    }

La función ``quicksort`` definida a continuación, recibe dos enteros que
corresponden al intervalo a ordenar. Usando el pivote, se llama a sí
mismo para ordenar el subintervalo a la izquierda del pivote y el
subintervalo a la derecha del pivote.

.. code:: ipython3

    void quicksort(int a, int b) {
        if (a < b) {
            int p = getPivot(a, b);
            quicksort(a, p - 1);
            quicksort(p + 1, b);
        }
    }

La parte clave del algoritmo quicksort consiste en colocar en la
posición correcta el pivote. La función ``getPivot`` coloca el pivote en
la posición correcta en el intervalo ``[a, b]`` según el algoritmo
descrito anteriormente.

.. code:: ipython3

    int getPivot(int a, int b) {
        int i = a;
        int j = b - 1;
        int p = b;
        
        while (i <= j) {
         if (X[i] < X[p]) {
          i++;
         } else if (X[j] >= X[p]) {
          j--;
         } else if (X[i] >= X[p] && X[j] < X[p]) {
          swap(X[i++], X[j--]);
         }
        }
        swap(X[i], X[p]);
        return i;
    
    }

Quicksort en el peor de los casos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para muchos otros algoritmos que hemos encontrado, el mejor de los casos
fue uno en el que el arreglo ya estaba ordenado. Sin embargo, cuando se
trata de ``quicksort``, el mejor de los casos es aquel en el que el
pivote siempre termina justo en el medio del subarreglo después de la
partición. Curiosamente, esto generalmente ocurre cuando los valores del
arreglo se mezclan bastante bien.

El peor de los casos para quicksort es uno en el que el pivote siempre
termina en un lado del subarreglo en lugar de en el medio. Esto puede
suceder cuando el arreglo está en perfecto orden ascendente o
descendente. En el peor de los casos, Quicksort tiene una eficiencia de
:math:`O(n^2)`.

¿Cómo categorizamos quicksort en términos de notación O?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

La cantidad de pasos de quicksort para :math:`n` elementos en la arreglo
es aproximadamente ``n`` multiplicado por ``log N``, como se muestra en
la siguiente tabla:

== ===== ========== ========================
n  log n n \* log n Pasos Quicksort (approx)
== ===== ========== ========================
4  2     8          8
8  3     24         24
16 4     64         64
32 5     160        160
== ===== ========== ========================

Ahora, no es una coincidencia que la cantidad de pasos en quicksort
simplemente se alinee con ``n* log n``. Si pensamos en quicksort de
manera más amplia, podemos ver por qué es así:

Cada vez que dividimos el arreglo, terminamos dividiéndolo en dos
subarreglos. Suponiendo que el pivote termine en algún lugar en la mitad
del arreglo, que es lo que sucede en el caso promedio, estos dos
subarreglos tienen aproximadamente el mismo tamaño.

¿Cuántas veces podemos dividir un arreglo en mitades hasta que lo
hayamos dividido completamente hasta el punto en que cada subarreglo sea
de tamaño 1? Para una arreglo de tamaño ``n``, esto nos llevará
``log n`` veces.

.. code:: ipython3

    #include<iostream>
    #include<algorithm>
    #include<vector>
    
    using namespace std;
    
    int Particion(vector<int>& vec, int inicial, int fin) {
    
        // Coompleta
        swap(vec[j], pivote);
        return j;
    }
    
    void QuickSort (vector<int>& vec, int inicio, int fin) {
    
        int p;
        
        // Completa
           
        }
    }
    
    int main()
    {
        vector<int> vec = {7, 3, 5, 2, 4, 1, 8, 6};
    
        QuickSort(vec, 0, vec.size()-1);
    
        cout << "Numeros ordenados : ";
        for(auto& it: vec)
            cout << it << " ";
    
        return 0;
    }


**Ejercicio** Realiza una comparación entre el algoritmo
``Insertion sort`` y ``Quicksort`` en el peor de los casos, en el caso
promedio y el mejor de los casos.

.. code:: ipython3

    // Tu respuesta

**Ejercicio:** Revisa `QuickSelect: The Quick Select Algorithm Explained
With Code
Examples <https://www.freecodecamp.org/news/quickselect-algorithm-explained-with-examples/>`__
e implementa el algoritmo ``quickselect`` en C++.

.. code:: ipython3

    // Tu respuesta

**Repaso:** Estudia las demostraciones dados aquí:
https://homepages.bluffton.edu/~nesterd/apps/SortingDemo.html

La complejidad del mergesort es tan buena como la del quicksort
:math:`O(n \log n)`. Eso significa que tenemos dos algoritmos con el
mismo rendimiento.

En la práctica, los programadores pueden elegir uno u otro dependiendo
de factores adicionales. Por lo general, los programas de ``quicksort``
se ejecutan más rápido que el de ``mergesort`` porque su implementación
concreta en un lenguaje de programación es más rápida.

El ``merge sort`` divide los datos antes de mezclarlos, lo que significa
que se pueden **paralelizar**, de modo que un grupo de computadoras
pueda ordenar grandes cantidades de datos, donde cada computadora actúa
coomo un clasificador humano.

**Lectura adicional:** Se puede encontrar una breve explicación de los
algoritmos de ordenamiento en
https://www.codesdope.com/course/algorithms-introduction/

Quick Sort Paralelo
~~~~~~~~~~~~~~~~~~~

Implementar Quicksort de manera paralela en C++ puede hacerse utilizando
hilos para paralelizar el proceso de ordenamiento. El siguiente ejemplo
es una simplificación que muestra cómo podrías adaptar Quicksort para
ejecutar las llamadas recursivas en paralelo usando ``std::thread``, que
es parte de la biblioteca estándar de C++ (C++11 en adelante).

Adaptar Quicksort Paralelo a C++ sin utilizar ``<vector>`` ni
``<algorithm>``, se puede hacer usando arrays estáticos o dinámicos. A
continuación, se muestra cómo se vería este código utilizando arrays
estáticos para simplificar.

.. code:: ipython3

    #include <iostream>
    #include <thread>
    #include <chrono>
    
    void quickSortParallel(int arr[], int low, int high, int profundidad);
    int particion(int arr[], int low, int high);
    void quickSort(int arr[], int low, int high);
    
    int particion(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
    
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = particion(arr, low, high);
    
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    void quickSortParallel(int arr[], int low, int high, int profundidad) {
        if (low < high) {
            int pi = particion(arr, low, high);
    
            if (profundidad > 0) {
                std::thread leftThread(quickSortParallel, arr, low, pi - 1, profundidad - 1);
                std::thread rightThread(quickSortParallel, arr, pi + 1, high, profundidad - 1);
                
                leftThread.join();
                rightThread.join();
            } else {
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }
    }
    
    int main() {
        int arr[] = {10, 7, 8, 9, 1, 5};
        int n = sizeof(arr)/sizeof(arr[0]);
        int maxprofundidad = 2;
    
        // Comienza a medir el tiempo
        auto start = std::chrono::high_resolution_clock::now();
    
        quickSortParallel(arr, 0, n - 1, maxprofundidad);
        
        // Detiene la medición del tiempo
        auto stop = std::chrono::high_resolution_clock::now();
    
        // Calcula la duración
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    
        std::cout << "Array ordenado: \n";
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
        return 0;
    }


Este ejemplo ilustra un enfoque básico y directo. No es el más eficiente
ni el más refinado, pero sirve para demostrar el concepto de
paralelización en Quicksort. Nota que en prácticas más avanzadas y
eficientes se deberían considerar aspectos como el tamaño del arreglo
para decidir cuándo paralelizar y cuándo no, así como el uso de un pool
de hilos para evitar el overhead de crear y destruir hilos
constantemente.

.. code:: ipython3

    #include <iostream>
    #include <vector>
    #include <thread>
    #include <algorithm>
    #include <chrono>
    
    void quickSortParallel(std::vector<int>& arr, int low, int high, int profundidad);
    
    int particion(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
    
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = particion(arr, low, high);
    
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    void quickSortParallel(std::vector<int>& arr, int low, int high, int profundidad) {
        if (low < high) {
            int pi = particion(arr, low, high);
    
            if (profundidad > 0) {
                std::thread leftThread(quickSortParallel, std::ref(arr), low, pi - 1, profundidad - 1);
                std::thread rightThread(quickSortParallel, std::ref(arr), pi + 1, high, profundidad - 1);
                
                leftThread.join();
                rightThread.join();
            } else {
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }
    }
    
    int main() {
        std::vector<int> arr = {10, 7, 8, 9, 1, 5};
        int n = arr.size();
        int maxprofundidad = 2; // 
    
        quickSortParallel(arr, 0, n - 1, maxprofundidad);
    
        std::cout << "Array ordenado: \n";
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    
        return 0;
    }


Sin el uso de ``<vector>`` (es decir, usando arrays estáticos o
dinámicos directamente), la complejidad espacial sigue siendo
``O(logn)`` para la pila de llamadas recursivas. No hay una diferencia
significativa en el uso de memoria entre usar vector y arrays
directamente en este contexto, ya que ambos métodos requieren
almacenamiento para los mismos elementos del arreglo.

Para ejecutar los códigos de Quicksort Paralelo presentados
anteriormente (tanto la versión que utiliza ``std::vector`` como la que
utiliza arrays estáticos), necesitas un compilador de C++ que soporte
C++11 o superior, debido al uso de ``std::thread`` para el paralelismo.
Puedes compilar y ejecutar estos programas, así como medir su tiempo de
ejecució de esta manera:

Para compilar cualquiera de los programas, puedes usar un comando
similar en la terminal si tienes g++ (el compilador de GNU C++)
instalado. Por ejemplo, para el código que utiliza arrays estáticos:

::

   g++ -std=c++11 -pthread tu_programa.cpp -o programa
   ./programa

El flag ``-pthread`` es necesario para permitir el uso de threads, y
-std=c++11 especifica que queremos utilizar la norma C++11 (o puedes
usar una versión más reciente si prefieres).

Para medir el tiempo de ejecución dentro de tus programas de C++, puedes
utilizar la biblioteca que también forma parte de C++11. Por ejemplo, ya
se hizo en un archivo anterior la modificación del main para medir y
mostrar el tiempo de ejecución:

.. code:: ipython3

    #include <iostream>
    // Incluir chrono para medición de tiempo
    #include <chrono>
    
    int main() {
        // Tu arreglo y el llamado a quickSort o quickSortParallel aquí
    
        // Comenzar a medir el tiempo
        auto start = std::chrono::high_resolution_clock::now();
    
        // Llamada a tu función de ordenamiento
        // quickSortParallel(arr, 0, n - 1, maxDepth); por ejemplo
    
        // Finalizar la medición del tiempo
        auto stop = std::chrono::high_resolution_clock::now();
    
        // Calcular la duración
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
        std::cout << "Tiempo de ejecución: "
                  << duration.count() << " microsegundos" << std::endl;
    
        return 0;
    }


Este fragmento de código envuelve la llamada a la función de
ordenamiento con puntos de inicio y finalización del tiempo, utilizando
la alta resolución del reloj de ``std::chrono``. Luego calcula la
duración en microsegundos (puedes cambiar microseconds a milliseconds si
prefieres) y la muestra.

La medición del tiempo de ejecución te dará una buena idea del
rendimiento relativo de diferentes enfoques de ordenamiento en tu
máquina. Sin embargo, los tiempos pueden variar debido a factores como
la carga del sistema operativo, el hardware disponible y el tamaño del
conjunto de datos. Para obtener resultados más consistentes, considera
ejecutar tu programa varias veces y calcular un tiempo medio de
ejecución.

**Ejercicio**: Compara los dos archivos dados anteriormentes y así como
los códigos dados en clase que involucran la librería ``<vector>`` y
``<algorithm>``.

.. code:: ipython3

    ### Tus respuestas

Mergesort paralelo
~~~~~~~~~~~~~~~~~~

El Mergesort paralelo es una versión del algoritmo de ordenamiento
Mergesort diseñada para aprovechar las capacidades de procesamiento
paralelo de los sistemas de cómputo modernos. Mergesort es un algoritmo
de división y conquista que ordena un arreglo dividiéndolo en mitades,
ordenando cada mitad y luego fusionando las mitades ordenadas. La
paralelización de Mergesort se enfoca principalmente en realizar las
divisiones y fusiones en paralelo, mejorando significativamente el
tiempo de ejecución en sistemas con múltiples procesadores o núcleos.

**Funcionamiento del Mergesort paralelo**

-  División en paralelo: La etapa inicial de dividir el arreglo en
   subarreglos más pequeños se puede realizar en paralelo. En un enfoque
   simple, el arreglo se divide a la mitad, y cada mitad se ordena en un
   hilo separado. Este proceso de división puede continuar
   recursivamente, creando más hilos para subarreglos cada vez más
   pequeños hasta que se alcanza un umbral de tamaño de arreglo para el
   cual el coste de crear más paralelismo no compensa los beneficios.

-  Ordenamiento y fusión: Cada hilo tiene la responsabilidad de ordenar
   su asignación de subarreglo. Una vez ordenados los subarreglos, se
   procede a fusionarlos. La fusión de los subarreglos también puede
   paralelizarse, aunque esto es más complejo que paralelizar la
   división debido a la naturaleza secuencial de la fusión tradicional
   de Mergesort. Se pueden emplear técnicas como la fusión en paralelo,
   donde diferentes partes del proceso de fusión se asignan a diferentes
   hilos.

Una implementación básica de Mergesort paralelo en C++ podría utilizar
la biblioteca de hilos ``(<thread>)`` para paralelizar las tareas. Aquí
se presenta un esquema conceptual de cómo podría implementarse:

.. code:: ipython3

    #include <iostream>
    #include <vector>
    #include <thread>
    
    void merge(std::vector<int>& array, int const izquierda, int const medio, int const derecha) {
        auto const subArrayOne = medio - izquierda + 1;
        auto const subArrayTwo = derecha - medio;
    
        std::vector<int> izquierdaArray(subArrayOne), derechaArray(subArrayTwo);
        
        std::copy_n(array.inicio() + izquierda, subArrayOne, izquierdaArray.inicio());
        std::copy_n(array.inicio() + medio + 1, subArrayTwo, derechaArray.inicio());
    
        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
        int indexOfMergedArray = izquierda;
    
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (izquierdaArray[indexOfSubArrayOne] <= derechaArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = izquierdaArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = derechaArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        std::copy(izquierdaArray.inicio() + indexOfSubArrayOne, izquierdaArray.inicio() + subArrayOne, array.inicio() + indexOfMergedArray);
        std::copy(derechaArray.inicio() + indexOfSubArrayTwo, derechaArray.inicio() + subArrayTwo, array.inicio() + indexOfMergedArray);
    }
    
    void parallelMergeSort(std::vector<int>& array, int const inicio, int const end) {
        if (inicio >= end)
            return; 
    
        auto medio = inicio + (end - inicio) / 2;
        std::thread izquierdaThread(parallelMergeSort, std::ref(array), inicio, medio);
        std::thread derechaThread(parallelMergeSort, std::ref(array), medio + 1, end);
    
        izquierdaThread.join();
        derechaThread.join();
    
        merge(array, inicio, medio, end);
    }
    
    int main() {
        std::vector<int> arr = {12, 11, 13, 5, 6, 7};
        parallelMergeSort(arr, 0, arr.size() - 1);
    
        std::cout << "Arreglo ordenado: \n";
        for(auto i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    
        return 0;
    }


El uso de paralelismo introduce un
`overhead <https://medium.com/@chanakadkb/overhead-of-parallelism-d1d3c43abadd>`__
debido a la creación y sincronización de hilos. Es importante limitar el
número de hilos para evitar un uso excesivo de recursos y garantizar que
el coste de crear y gestionar los hilos no supere los beneficios del
paralelismo.

Generalmente, se establece un umbral para el tamaño del subarreglo, por
debajo del cual se usa Mergesort secuencial en lugar de seguir
dividiendo el trabajo en nuevos hilos. Esto ayuda a mantener un balance
entre el paralelismo y el overhead de gestión de hilos.

La paralelización de Mergesort puede ofrecer mejoras significativas de
rendimiento en sistemas multicore, especialmente para conjuntos de datos
grandes, al aprovechar múltiples unidades de procesamiento en paralelo.
Sin embargo, es crucial ajustar la implementación a las características
específicas del hardware y los datos para obtener los mejores
resultados.

**Ejercicio**

Implementa una versión del código anterior sin usar ``<vector>``, por
ejemplo con arrays dinámicos o estáticos. En este caso, utilizaremos
arrays dinámicos (new y delete en C++) para acomodar cualquier tamaño de
entrada.

.. code:: ipython3

    ## Tu respuesta


Ejercicios
~~~~~~~~~~

1. `Algoritmo de bubble
   sort <https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/bubble-sort-15-8064c987/>`__

2. `Old keypad in a foreign
   land <https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/practice-problems/algorithm/old-keypad-in-a-foreign-land-24/>`__.
   Usa el algoritmo de selección.

3. `Monk and Nice
   Strings <https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/practice-problems/algorithm/monk-and-nice-strings-3/>`__.
   Usa el algoritmo de inserción.

4. `Digit
   sum <https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/interesting-number-2-752e7fa2/>`__.
   Usa el algoritmo mergesort.

5. `Pro and Con
   List <https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/pro-and-con-list/>`__.

6. `Sum of sum of
   digits <https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/sum-of-sum-of-digits-6/>`__

7. `Eating
   apples <https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/snake-b0112afa/>`__.
   Usa el algoritmo quicksort.

8. `Prom
   Night <https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/prom-night/>`__

9. `Shil and Birthday
   present <https://www.hackerearth.com/practice/algorithms/sorting/counting-sort/practice-problems/algorithm/shil-and-birthday-present/>`__.
   Usa el algoritmo coutingsort.
10. `Find
    Mex <https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/find-mex-62916c25/>`__.
    Usa el búsqueda lineal.

11. `Base
    numbers <https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/in-another-base-1-e0d0f1ca/>`__.
    Usa una búsqueda binaria.


.. code:: ipython3

    ## Tus respuestas


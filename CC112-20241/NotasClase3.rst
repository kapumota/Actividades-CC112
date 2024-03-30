Algoritmos de ordenamiento
--------------------------
Muchos algoritmos eficientes se basan en ordenar los datos de entrada, ya que el proceso de ordenamiento a menudo simplifica la resolución del problema. El problema básico en el ordenamiento es el siguiente: dado un arreglo que contiene ``n`` elementos, se requiere ordenar los elementos en orden creciente.
En esta sección, repasaremos algunos algoritmos de ordenamiento fundamentales y examinaremos sus propiedades. Aunque es posible diseñar algoritmos de ordenamiento simples, también existen alternativas más eficientes.

Después de revisar la teoría del ordenamiento, nos enfocaremos en la aplicación práctica del ordenamiento en C++.

Revisamos los algoritmos de ordenamiento fundamentales:

1. **Ordenamiento burbuja (bubble sort):** Un algoritmo simple pero ineficiente que compara pares de elementos adyacentes y los intercambia si están en el orden incorrecto. Aunque su complejidad es alta, es útil para entender los conceptos básicos de ordenamiento.

2. **Ordenamiento por inserción (insertion sort):** Este algoritmo construye una lista ordenada uno a la vez mediante la inserción de elementos no ordenados en la posición correcta. Aunque su eficiencia es moderada, es más rápido que el ordenamiento burbuja en la mayoría de los casos.

3. **Ordenamiento por selección (selection sort):** Este método selecciona repetidamente el elemento más pequeño (o más grande) de la porción no ordenada del arreglo y lo coloca al principio (o al final) de la lista ordenada. Aunque su complejidad es similar a la del ordenamiento por inserción, tiende a realizar menos intercambios.

Estos son solo algunos ejemplos de algoritmos de ordenamiento. En la práctica, se pueden utilizar algoritmos más avanzados, como el ordenamiento rápido (Quick Sort) o el ordenamiento por fusión (Merge Sort), que son mucho más eficientes para grandes conjuntos de datos.

En la programación en C++, la biblioteca estándar proporciona una serie de funciones y algoritmos para ordenar contenedores, como ``std::sort``, que implementa un algoritmo de ordenamiento eficiente (generalmente una variante de Quick Sort). Esta función es ampliamente utilizada y eficiente para la mayoría de los casos de uso.

.. code:: c++

    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main() {
        std::vector<int> datos = {4, 2, 6, 1, 3, 5};
        std::sort(datos.begin(), datos.end());

        std::cout << "Datos ordenados:";
        for (int d : datos) {
            std::cout << " " << d;
        }
        std::cout << std::endl;

        return 0;
    }


Bubble sort
^^^^^^^^^^^

Bubble sort o `ordenamiento de burbujas` es un algoritmo de ordenamiento simple que funciona en tiempo :math:`O(n^2)`. El algoritmo consta de :math:`n` rondas y en cada ronda se itera sobre los elementos de un arreglo.

Siempre que se encuentran dos elementos consecutivos que están en orden incorrecto, el algoritmo los intercambia.  La implementación típica del algoritmo en C++ es la siguiente:

.. code:: c++

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arreglo[j] > arreglo[j+1]) {
                swap(arreglo[j],arreglo[j+1]);
            }
        }
    }

Después de la primera ronda del ordenamiento de burbujas, el elemento más grande estará en la posición correcta y, de manera más general, después de ``k`` rondas, los ``k`` elementos más grandes estarán en las posiciones correctas. Por lo tanto, después de ``n`` rondas, se ordenará en todo el arreglo. 

El programa siguiente lee un número :math:`n` (:math:`1 \leq n \leq100`), que indica el número de elementos en el
arreglo :math:`X`. Los siguientes :math:`n` números representan los elementos de :math:`X`.

El programa imprime el arreglo :math:`X` con sus elementos ordenados en orden creciente.

.. code:: c++

    #include <algorithm>
    #include <cstdio>
    #define N 101
    using namespace std;
    int X[N];
    
    int n;
    
    void bubbleSort();
    int main() {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &X[i]);
        }
    
        bubbleSort();
    
        for (int i = 0; i < n; i++) {
            printf("%d ", X[i]);
        }
    
        printf("\n");
        return 0;
    }
    void bubbleSort() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (X[j] > X[j + 1]) {
                    swap(X[j], X[j + 1]);
                }
            }
        }
    }

Ejercicios
^^^^^^^^^^

1. Explica paso a paso el proceso del algoritmo de ordenamiento de burbuja con el arreglo :math:`[4, 2, 7, 1, 3]`.

2. ¿Qué crees que sucede si el arreglo tiene elementos repetidos?.

.. code:: c++

    // Tus respuestas

El mejor caso para la ordenación por burbujas ocurre cuando la lista ya está ordenada o casi ordenada. En el caso de que la lista ya esté ordenada, el algoritmo finalizará después de la primera iteración, ya que no se realizaron intercambios.

**Inversiones**

Un concepto útil al analizar algoritmos de ordenamiento es el de ``inversión``: un par de índices del arreglo ``(a, b)`` tales que :math:`a < b` y ``arreglo[a] >arreglo[b]``, es decir, los elementos están en orden incorrecto.

Ejemplos:

-  Entrada: ``A[] = [3, 2, 1]``

-  Los tres pares de inversiones son : ``(3, 2)``, ``(3, 1)``, ``(2, 1)``

-  Entrada: ``A[] = {6, 3, 5, 2, 7}``

-  Los cinco pares de inversiones son – (6, 3), (6, 5), (6, 2), (3, 2), (5, 2)

El número de inversiones indica cuánto trabajo se necesita para ordenar el arreglo. Un arreglo está completamente ordenado cuando no hay inversiones. Por otro lado, si los elementos del arreglo están en orden inverso, el número de inversiones es:

.. math:: 1 + 2 + 3 + \cdots + (n -1) = \frac{n(n-1)}{2} = O(n^2)

que es el mayor posible.

Al intercambiar un par de elementos consecutivos que están en el orden incorrecto, se elimina exactamente una inversión del arreglo. Por lo tanto, si un algoritmo de ordenamiento solo puede intercambiar elementos consecutivos, cada intercambio elimina como máximo una inversión y la complejidad temporal del algoritmo es al menos :math:`O(n^2)`.

MergeSort
^^^^^^^^^

Si queremos crear un algoritmo de ordenamiento eficiente, debemos poder reordenar los elementos que se encuentran en diferentes partes del arreglo. Existen varios algoritmos de ordenamiento de este tipo que funcionan en el tiempo :math:`O(n\log n)`. Uno de ellos es el de **merge sort**, que se basa en la recursividad. Merge sort ordena un subarreglo
``arreglo[a,b]`` de la siguiente manera:

1. Si :math:`a =b`, no se realiza ninguna acción, ya que un subarreglo que solo contiene un elemento ya está ordenado.

2. Se calcula la posición del elemento medio::math:`k = \lfloor (a + b) /2 \rfloor` .

3. Se ordena recursivamente el subarreglo ``arreglo[a...k]``.

4. Se ordena recursivamente el subarreglo ``arreglo[k +1...b]``.

5. Se fusiona el subarreglo ordenado ``arreglo[a...k]`` y el arreglo
   ``arreglo[k +1...b]`` en un subarreglo ordenado ``arreglo[a...b]``.


Ejemplo
^^^^^^^

Se muestra el proceso del algoritmo de merge sort del arreglo ``A`` y el arreglo ``B`` en un arreglo ``C``, donde ``A`` y ``B`` se ordenan en orden no decreciente.

Básicamente la idea del proceso consiste en colocar un iterador ``i`` al inicio del arreglo ``A`` y un iterador ``j``  al inicio del arreglo ``B``. Si :math:`A_i < B_j` el elemento :math:`A_i` se inserta al final del arreglo ``C`` y ``i`` se mueve a la siguiente posición. De lo contrario, si :math:`A_i \geq B_j` el elemento :math:`B_j` se inserta al final de :math:`C` y :math:`j` se mueve a la siguiente posición. El proceso continúa hasta que todos los elementos de ``A`` o ``B`` se insertan en ``C``.


MergeSort es un algoritmo eficiente porque reduce a la mitad el tamaño del subarreglo en cada paso. Luego, es posible fusionar los subarreglos ordenados en tiempo lineal, porque ya están ordenados. Dado que hay niveles recursivos y el procesamiento de cada nivel requiere un tiempo total de :math:`O(n)`, el algoritmo funciona en el tiempo
:math:`O\log(n)`.

Una implementación
^^^^^^^^^^^^^^^^^^

.. code:: c++

    #include <cstdio>
    #define N 101
    using namespace std;
    
    int X[N], C[N];
    int n;
    
    void mergeSort(int, int);
    void merge(int, int, int);
    
    int main() {
        scanf("%d", &n);
    
        // Lee los numeros a ser ordenados
        for (int i = 0; i < n; i++) {
            scanf("%d", &X[i]);
        }
    
        // Aplicamos merge sort
        mergeSort(0, n - 1);
    
        // Imprimimos el arreglo ordenado
        for (int i = 0; i < n; i++) {
            printf("%d ", X[i]);
        }
        printf("\n");
    
        return 0;
    }


La función ``mergeSort`` recibe un intervalo de los elementos para ordenar, calcula el elemento medio y recursivamente se vuelve a llamar para ordenar ambas mitades del intervalo.

Finalmente se juntan ambas mitades ordenando todos los elementos del intervalo.

.. code:: c++

    void mergeSort(int i, int j) {
     if (i != j) {
        int m = (i + j) / 2;
         mergeSort(i, m);
         mergeSort(m + 1, j);
         merge(i, m, j);
        }
    }

El proceso explicado anteriormente tiene lugar en la función ``merge``, que recibe los índices ``i`` y ``j`` del intervalo a ordenar y el punto medio ``m`` y ordena ambas mitades del arreglo.

.. code:: c++

    void merge(int i, int m, int j) {
        // p y q son los indices que se moverán a través 
        // de cada mitad respectivamente.
        int p = i;
        int q = m + 1;
        int r = i;
        // Sigue comparando los valores de X[p] y X[q] 
        // hasta llegar al final de una de las mitades
    
        while (p <= m && q <= j) {
            if (X[p] <= X[q]) {
              C[r++] = X[p++];
            } else {
              C[r++] = X[q++];
            }
        }
        
        //Agregamos los elementos restantes de la primera mitad.
        while (p <= m) {
            C[r++] = X[p++];
        }
    
        //Agregamos los elementos restantes de la segunda mitad.
        while (q <= j) {
            C[r++] = X[q++];
        }
    
        // Actualizamos el arreglo original
        for (r = i; r <= j; r++) {
          X[r] = C[r];
        }
    }

**Ejercicio:** Supongamos que recibes :math:`k` arreglos ordenados, cada uno con :math:`n` elementos, y deseas combinarlos en un solo arreglo ordenado de :math:`kn` elementos. Un enfoque sería utilizar la subrutina ``merge`` repetidamente, combinar los dos primeros arreglos, luego combinar el resultado con el tercer arreglo, luego con el cuarto arreglo y así sucesivamente hasta que se combine en el arreglo de entrada enésima y final. ¿Cuál es el tiempo de ejecución de este proceso?

.. code:: c++

    // Tu respuesta


Counting sort
^^^^^^^^^^^^^

Este algoritmo ordena un arreglo en tiempo :math:`O(n)` suponiendo que cada elemento del arreglo es un número entero entre :math:`0 \dots c` y :math:`c = 0(n)`.

El algoritmo crea un arreglo contable, cuyos índices son elementos del arreglo original. El algoritmo recorre en iteración el arreglo original y calcula cuántas veces aparece cada elemento en el arreglo.

La construcción del arreglo contable lleva :math:`O(n)` veces. Después de esto, el arreglo ordenado se puede crear en tiempo :math:`O(n)`, porque el número de apariciones de cada elemento se puede recuperar del arreglo contable. Por lo tanto, la complejidad temporal total de counting sort es :math:`O(n)`.

Counting sort es un algoritmo muy eficiente, pero solo se puede usar cuando la constante ``c`` es lo suficientemente pequeña, de modo que los elementos del arreglo se puedan usar como índices en el arreglo contable.

.. code:: c++
   #include <iostream>
    using namespace std;

    void countingSort(int arr[], int n, int max) {
        int count[max + 1] = {0}; // Arreglo contable
        int sortedArr[n];

        // Contar la frecuencia de cada elemento
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        // Recrear el arreglo ordenado usando el arreglo contable
        int index = 0;
        for (int i = 0; i <= max; i++) {
            while (count[i] > 0) {
                sortedArr[index++] = i;
                count[i]--;
            }
        }

        // Copiar el arreglo ordenado de regreso al arreglo original
        for (int i = 0; i < n; i++) {
            arr[i] = sortedArr[i];
        }
    }

    int main() {
        int arr[] = {4, 2, 2, 8, 3, 3, 1};
        int n = sizeof(arr) / sizeof(arr[0]);
        int max = 8; // Suponiendo que el rango máximo de elementos es conocido

        countingSort(arr, n, max);

        cout << "Arreglo ordenado: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        return 0;
    }



Revisa: `Counting Sort in C , C++, Java and
Python <https://www.mygreatlearning.com/blog/counting-sort/>`__.

**Repaso:** Estudia las demostraciones dados aquí:
https://homepages.bluffton.edu/~nesterd/apps/SortingDemo.html

Radix Sort
^^^^^^^^^^^^^
Otro algoritmo de ordenamiento eficiente que no se basa en comparaciones es radix sort. Este algoritmo ordena los elementos basándose en sus dígitos, desde el dígito menos significativo hasta el más significativo o viceversa.

La implementación más común de radix sort utiliza counting sort como subrutina para ordenar los elementos según cada dígito. Primero, se ordenan los elementos según el dígito menos significativo, luego según el siguiente dígito menos significativo, y así sucesivamente hasta que todos los dígitos han sido considerados.

Radix sort tiene una complejidad temporal de :math:`O(kn)` , donde :math:`k` es el número de dígitos en el número más largo del arreglo.

.. code:: c++
    #include <iostream>
    using namespace std;

    // Función auxiliar para obtener el máximo valor en el arreglo
    int getMax(int arr[], int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

     // Función para realizar el counting sort según el dígito representado por exp.
     void countingSort(int arr[], int n, int exp) {
         int output[n];
         int count[10] = {0};

      // Almacenar la frecuencia de ocurrencia de cada dígito en count[]
      for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        }

     // Cambiar count[i] para que contenga la posición real de este dígito en output[]
     for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
      }

     // Construir el arreglo de salida
     for (int i = n - 1; i >= 0; i--) {
         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
         count[(arr[i] / exp) % 10]--;
     }

     // Copiar el arreglo de salida en arr[] para que arr[] contenga los números ordenados según el dígito actual
     for (int i = 0; i < n; i++) {
         arr[i] = output[i];
       }
    }

     // Función principal que implementa Radix Sort
     void radixSort(int arr[], int n) {
     int max = getMax(arr, n);

     // Realizar counting sort para cada dígito.
     // exp es 10^i donde i es el dígito actual.
     for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
       }
    }

    // Función para imprimir el arreglo
    void printArray(int arr[], int n) {
      for (int i = 0; i < n; i++) {
          cout << arr[i] << " ";
       }
       cout << endl;
    }

    int main() {
      int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
      int n = sizeof(arr) / sizeof(arr[0]);

      // Ordenar el arreglo
      radixSort(arr, n);

      // Imprimir el arreglo ordenado
      printArray(arr, n);

      return 0;
    }

El proceso de ordenamiento en radix sort se realiza en varias pasadas a través del arreglo, donde en cada pasada se ordenan los elementos según un dígito específico, comenzando desde el dígito menos significativo hasta el más significativo (o viceversa).

1. Antes de comenzar el proceso de ordenamiento, el algoritmo determina cuántos dígitos tiene el número más grande en el arreglo. Este valor será importante para determinar el número de pasadas que se necesitarán para ordenar completamente el arreglo.

2. El arreglo se recorre varias veces, una vez por cada dígito del número más grande. Durante cada pasada, los elementos del arreglo se agrupan según el valor del dígito correspondiente. Esto se logra utilizando un algoritmo de ordenamiento estable, como el counting sort, para ordenar los elementos según el valor del dígito actual.

3. Es importante que el algoritmo de ordenamiento utilizado en cada pasada sea estable, lo que significa que preserva el orden relativo de los elementos que tienen el mismo valor en el dígito actual. Esto garantiza que el ordenamiento de los dígitos menos significativos no afecte el ordenamiento de los dígitos más significativos.

4. Después de completar todas las pasadas a través del arreglo, los elementos se habrán ordenado completamente según todos los dígitos. El arreglo resultante está completamente ordenado y listo para su uso.

Radix sort es especialmente eficiente cuando los números en el arreglo tienen un número limitado de dígitos y la cantidad total de dígitos es relativamente pequeña en comparación con el tamaño del arreglo. Sin embargo, su complejidad temporal puede ser mayor en comparación con otros algoritmos de ordenamiento cuando los números tienen un número muy grande de dígitos.

Algoritmos de búsqueda
--------------------------

Búsqueda binaria
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La búsqueda binaria es un algoritmo eficiente que se utiliza para buscar un elemento en un arreglo ordenado. Funciona dividiendo repetidamente el espacio de búsqueda a la mitad.

Implementación de la búsqueda
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Supongamos que tenemos un arreglo ordenado de ``n`` elementos y queremos verificar si el arreglo contiene un elemento con un valor objetivo ``x``.

Existen dos formas comunes de implementar un algoritmo de búsqueda binaria:

**Primer método** Esta implementación es similar a buscar una palabra en un diccionario. Inicialmente, mantenemos un subarreglo activo que contiene todos los elementos del arreglo. Luego, en cada paso, reducimos a la mitad el rango de búsqueda verificando el elemento central del subarreglo. Si el elemento central coincide con el valor objetivo, la búsqueda se detiene. De lo contrario, la búsqueda continúa recursivamente en la mitad izquierda o derecha del subarreglo, dependiendo del valor del elemento central.

La búsqueda se puede implementar de la siguiente manera:

.. code:: c++

    int a = 0, b = n-1;
    while (a <= b) {
        int k = (a+b)/2;
        if (arreglo[k] == x) {
            // x encontrado en el indice k
        }
        if (arreglo[k] < x) a = k+1;
        else b = k-1;
    }

En esta implementación tiene una complejidad temporal de :math:`O(\log n)`ya que el tamaño del subarreglo se reduce a la mitad en cada iteración.

**Segundo Método** Otra forma de implementar la búsqueda binaria es recorrer el arreglo de izquierda a derecha dando *saltos*. La longitud del salto inicial es :math:`n/2` y se reduce a la mitad en cada iteración. En cada iteración, se salta hasta que se encuentra el elemento deseado o se sale del arreglo.

El siguiente código implementa la búsqueda:

.. code:: c++

    int k = 0;
    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && arreglo[k+b] <= x) k += b;
    }
    if (arreglo[k] == x) {
    // x encontrado en el indice k
    }

La complejidad temporal del algoritmo es :math:`O(\log n)` , porque el código en el bucle while se ejecuta como máximo dos veces para cada longitud de salto.

Forma práctica
^^^^^^^^^^^^^^

Los algoritmos con complejidades logarítmicas :math:`O(\log n)` son deseables en el diseño de funciones debido a su eficiencia cercana a :math:`O(1)`. La búsqueda binaria es un ejemplo de este tipo de algoritmo, que es comúnmente utilizado para buscar en arreglos ordenados.

La complejidad logarítmica es común en muchos algoritmos eficientes como búsquedas binarias, encontrar valores extremos en árboles binarios de búsqueda, y ciertos algoritmos de divide y vencerás. La búsqueda binaria, por ejemplo, reduce el espacio de búsqueda a la mitad en cada iteración, lo que resulta en una complejidad de :math:`O(\log n)`

La búsqueda binaria sigue una serie de pasos claramente definidos para encontrar un elemento en un arreglo ordenado:

1. Establecimiento de variables: Se inician dos variables, ``min`` y ``max``, donde min representa el índice más bajo del arreglo y ``max`` el índice más alto. Inicialmente, min se establece en 0 y ``max`` en  ``n-1``, donde  ``n`` es el tamaño del arreglo.

2. Cálculo del valor medio: Se calcula el índice medio del rango de búsqueda, promediando los valores de ``min`` y ``max`` y redondeándolo hacia abajo si es necesario.

3. Verificación del elemento medio: Se compara el valor del elemento en el índice medio ``(arr[medio])`` con el valor objetivo. Si son iguales, se devuelve el índice medio, indicando que se ha encontrado el elemento deseado.

4. Ajuste del rango de búsqueda: Si el valor del elemento medio es menor que el objetivo, se actualiza el valor de ``min`` para que apunte al elemento siguiente al medio. Esto reduce el rango de búsqueda a la mitad izquierda del arreglo.

5. Si el valor del elemento medio es mayor que el objetivo, se actualiza el valor de max para que apunte al elemento anterior al medio. Esto reduce el rango de búsqueda a la mitad derecha del arreglo.

6. Repetición del proceso: Se repiten los pasos 2 a 5 hasta que se encuentre el elemento objetivo o el rango de búsqueda se haya reducido a cero.

**Ejemplo de búsqueda binaria**

Veamos un ejemplo concreto para comprender mejor cómo funciona la búsqueda binaria:

Dado el arreglo ordenado ``arr = [4, 8, 10, 14, 27, 31, 46, 52]`` y el objetivo es encontrar el número ``46``:

- Iteración 1:  ``min = 0, max = 7`` y ``medio = (0 + 7)/2 = 3.5`` -> redondear a  ``3``

- El valor en el índice medio es ``arr[3] = 14`` y por lo tanto menos de ``46``, entonces  ``min = medio+ 1 = 4``

- Iteración 2: ``min = 4, max = 7`` y ``medio = (4 + 7)/2 = 5.5`` -> redondear a ``5``

- El valor en el índice medio es ``arr[5] = 31`` y por lo tanto menos de ``46`` entonces ``min = medio + 1 = 6``

- Iteración 3:  ``min = 6, max = 7`` y ``medio = (6 + 7)/2 = 6.5`` -> redondear a ``6``

- El valor en el índice medio es ``arr[6] = 46``, ¡lo que equivale al objetivo! .

En el ejemplo pudimos encontrar el valor objetivo en solo ``3`` iteraciones del código. demostrando su eficiencia al dividir el área de búsqueda a la mitad en cada paso.

En el caso anterior que se ve así,

-  ``N = 8, [4, 8, 10, 14, 27, 31, 46, 52]`` // Comparamos y dividimos  el área de búsqueda por 2
-  ``N = 4, [27, 31, 46, 52]`` // Comparamos y dividimos el área de  búsqueda por 2
-  ``N = 2, [46, 52]`` // Comparamos el valor medio y el objetivo. Coinciden, así que regresamos a la mitad.

Todo esto tomó tres pasos y se divide por 2 cada vez. Si multiplicamos por 2 cada vez tendríamos :math:`2 \times 2 \times 2 = 8`, o :math:`2^3 = 8`.

.. math:: 2^3 = 8 -> \log_2 8 = 3

.. math:: 2^k = n -> \log_2 n = k

Entonces podemos ver que dado que el código se dividía por ``2`` cada vez y comenzamos con ``n`` elementos en el arreglo ordenado, se necesitarán :math:`\log n` iteraciones del algoritmo de búsqueda binaria para encontrar el valor objetivo. Por lo tanto, la complejidad de una búsqueda binaria es :math:`O(\log n)`.


Caso
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Supongamos que estamos resolviendo un problema y tenemos una función ``valid(x)`` que devuelve ``true`` si ``x`` es una solución válida y ``false`` en caso contrario. Además, sabemos que ``valid`` es ``false`` cuando :math:`x < k` y ``true`` cuando :math:`x\geq k`. En esta situación, podemos utilizar la búsqueda binaria para encontrar eficientemente el valor de ``k``.

La idea es realizar una búsqueda binaria del valor más grande de ``x`` para el cual ``valid(x)`` sea ``false``. Por lo tanto, el siguiente valor ``k = x +1`` es el valor más pequeño posible para el cual ``valid(x)`` sea ``true``.

La búsqueda se puede implementar de la siguiente manera:

.. code:: c++

    int x = -1;
    for (int b = z; b >= 1; b /= 2) {
        while (!valid(x+b)) x += b;
        }
    int k = x+1;

La longitud del salto inicial ``z`` tiene que ser un límite superior para la respuesta, es decir, cualquier valor para el cual sabemos con seguridad que ``valid(z)`` es ``true``. El algoritmo llama a la función ``valid(z)`` :math:`O(\log z)` veces, por lo que el tiempo de ejecución depende de la función ``valid``.

Por ejemplo, si la función funciona en tiempo :math:`O(n)`, el tiempo de ejecución es :math:`O(n \log z)`.

Ejercicio
^^^^^^^^^

Escribe una implementación del algoritmo de búsqueda binaria de manera iterativa y recursiva.

.. code:: c++

    // Tu respuesta


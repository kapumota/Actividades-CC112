Análisis de algoritmos
----------------------

El análisis de algoritmos es un proceso fundamental en informática y
matemáticas que se enfoca en evaluar la eficiencia de los algoritmos.
Este análisis busca determinar los recursos que el algoritmo necesita
para completar su tarea, siendo los más comunes el tiempo de ejecución
(cuánto tarda en terminar) y el espacio de memoria (cuánta memoria usa).
A través de este análisis, los desarrolladores e investigadores pueden
comparar algoritmos, prever su comportamiento en diferentes condiciones
y elegir la mejor opción para una tarea específica.

Análisis de casos
~~~~~~~~~~~~~~~~~

-  Peor caso: La máxima cantidad de tiempo y espacio que un algoritmo
   puede requerir. Es útil para garantizar que el algoritmo se ejecutará
   dentro de recursos aceptables en el peor de los escenarios.

-  Caso promedio : Un promedio del tiempo y espacio requeridos, basado
   en una distribución de todas las posibles entradas. Es más
   representativo del rendimiento esperado en la práctica.

-  Mejor caso: El mínimo tiempo y espacio requeridos. Aunque puede ser
   informativo, raramente es útil para la planificación de recursos
   porque se basa en el mejor escenario posible.

Complejidad temporal
~~~~~~~~~~~~~~~~~~~~

La complejidad temporal se refiere a cómo cambia el tiempo de ejecución
de un algoritmo a medida que aumenta el tamaño de entrada. Generalmente
se expresa en términos de notación Big :math:`O` (:math:`O` grande), que
ofrece un límite superior sobre el crecimiento del tiempo de ejecución.
Por ejemplo, un algoritmo con una complejidad temporal de :math:`O(n)`
tardará un tiempo proporcionalmente más largo a medida que el tamaño de
la entrada :math:`n` aumente. Se denota una complejidad temporal donde
los tres puntos representan alguna función. Normalmente, la variable
:math:`n` denota el tamaño de entrada.

Por ejemplo, si la entrada es un arreglo de números, :math:`n` será el
tamaño del arreglo y si la entrada es una cadena, :math:`n` será la
longitud de la cadena.

Complejidad constante
^^^^^^^^^^^^^^^^^^^^^

Cuando hablamos de una complejidad de tiempo o espacio de :math:`O(1)`,
nos referimos a que es “constante”. Esto significa que el tiempo o el
espacio requerido por el algoritmo para ejecutarse no cambia con el
tamaño de la entrada. Independientemente de cuán grande o pequeña sea la
entrada, el algoritmo consumirá el mismo tiempo o espacio.

**Características**

Independencia del tamaño de entrada: La ejecución del algoritmo no se ve
afectada por el tamaño de los datos de entrada. Por ejemplo, acceder a
cualquier elemento de un arreglo por su índice es una operación de
tiempo :math:`O(1)` porque se realiza en un paso, sin importar el tamaño
del arreglo.

Eficiencia: Los algoritmos con complejidad :math:`O(1)` son considerados
muy eficientes, ya que el tiempo o espacio que requieren no aumenta con
el tamaño de la entrada.

**Ejemplos Comunes**

-  Acceder a un elemento de un arreglo por su índice.
-  Insertar o eliminar un elemento en una posición específica de una
   lista enlazada, asumiendo que tienes un puntero directo al nodo en
   cuestión.

La complejidad :math:`O(1)` es un objetivo deseable cuando se diseñan
estructuras de datos o algoritmos, ya que garantiza una previsibilidad
en el rendimiento que no está vinculada al volumen de datos procesados.
Sin embargo, no todos los problemas pueden resolverse de manera que su
solución sea :math:`O(1)`, especialmente aquellos que naturalmente
requieren procesar cada elemento de la entrada.

.. code:: c++

    a++;
    b++;
    c = a+b;

Complejidad lineal
^^^^^^^^^^^^^^^^^^

Cuando hablamos de una complejidad de :math:`O(n)`, nos referimos a
“lineal”. Esto significa que el tiempo o espacio que un algoritmo
requiere crece de manera proporcional al tamaño de la entrada,
:math:`n`. A medida que el tamaño de la entrada aumenta, el tiempo de
ejecución o el espacio utilizado aumenta en una cantidad directamente
proporcional.

La complejidad temporal de un bucle estima la cantidad de veces que se
ejecuta el código dentro del bucle. Por ejemplo, la complejidad temporal
del siguiente código es :math:`O(n)`, porque el código dentro del bucle
se ejecuta :math:`n` veces. Suponemos que ``"..."`` denota un código
cuya complejidad temporal es :math:`O(1)`.

**Características** - La cantidad de trabajo (tiempo de ejecución) o
recursos (espacio) aumenta linealmente con el incremento en el tamaño de
la entrada. Si duplicas el tamaño de la entrada, el tiempo o espacio
necesario se duplicará aproximadamente. - Los algoritmos de complejidad
:math:`O(n)` son generalmente eficientes para tamaños de entrada
pequeños a moderados, pero su rendimiento puede degradarse con entradas
muy grandes.

**Ejemplos comunes**

La búsqueda lineal en un arreglo, donde se verifica cada elemento hasta
encontrar el objetivo. Un bucle simple que recorre cada elemento de un
arreglo o lista para realizar una operación, como sumar todos los
valores.

Aunque una complejidad :math:`O(n)` es menos ideal que :math:`O(1)`, es
común y aceptable para muchas aplicaciones, especialmente aquellas donde
el tamaño de la entrada no es masivo o donde las operaciones dentro del
bucle son relativamente simples. Los diseñadores de algoritmos y
estructuras de datos siempre buscan minimizar la complejidad, pero para
muchos problemas, :math:`O(n)` es la complejidad más baja posible.

Por ejemplo, cualquier problema que requiera examinar cada elemento de
una lista al menos una vez no puede tener una complejidad mejor que
:math:`O(n)` porque cada elemento debe procesarse individualmente.

.. code:: c++

    for (int i = 1; i <= n; i++) {
        ...
    }

Complejidad cuadrática
^^^^^^^^^^^^^^^^^^^^^^

La complejidad cuadrática, denotada como :math:`O(n^2)`, es un término
utilizado en el análisis de algoritmos para describir un algoritmo cuyo
tiempo de ejecución o espacio necesario aumenta proporcionalmente al
cuadrado del tamaño de la entrada :math:`n`. Esto significa que si el
tamaño de la entrada se duplica, el tiempo de ejecución o el espacio
utilizado se cuadruplica. Los algoritmos con complejidad cuadrática son
típicamente menos eficientes que aquellos con complejidades más bajas,
como :math:`O(n)` o :math:`O(\log n)`, especialmente a medida que el
tamaño de la entrada crece.

**Características**

-  La cantidad de trabajo o recursos necesarios crece muy rápidamente
   con el aumento del tamaño de entrada. Esto hace que los algoritmos
   con complejidad :math:`O(n^2)` sean prácticos solo para tamaños de
   entrada relativamente pequeños.

**Ejemplos**

Algoritmos de ordenamiento como el ordenamiento de burbuja (bubble
sort), ordenamiento por inserción (insertion sort), y ordenamiento por
selección (selection sort) en sus implementaciones básicas. Algoritmos
que implican una iteración doble sobre la entrada, como ciertos
algoritmos de búsqueda y procesamiento de matrices.

En el análisis de algoritmos, la presencia de bucles anidados (un bucle
dentro de otro bucle) suele ser un indicador de complejidad
:math:`O(n^2)`, donde el bucle exterior e interior dependen del tamaño
de la entrada.

Entonces, la complejidad temporal del siguiente código es
:math:`O(n^2)`:

.. code:: c++

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ...
        }
    }

En general, si hay :math:`k` bucles anidados y cada bucle pasa por
:math:`n` valores, la complejidad temporal es :math:`O(n^k)`. Esto
significa que el tiempo de ejecución aumenta exponencialmente con el
número de niveles de bucles anidados, lo que puede llevar rápidamente a
una eficiencia muy baja para valores grandes de :math:`n` y :math:`k`.

La identificación de la complejidad temporal como :math:`O(n^k)` en
algoritmos es crucial para entender su escalabilidad y eficiencia.
Algoritmos con esta forma de complejidad se vuelven rápidamente
impracticables a medida que el tamaño de la entrada :math:`n` crece,
especialmente si el número de bucles anidados :math:`k` es grande.

Por lo tanto, los diseñadores de algoritmos buscan optimizar o reducir
el valor de :math:`k`, simplificar la lógica dentro de los bucles, o
encontrar enfoques algorítmicos completamente diferentes para manejar
grandes conjuntos de datos de manera eficiente.

Ejemplos
~~~~~~~~

En los siguientes ejemplos, el código dentro del bucle se ejecuta
:math:`3n`, :math:`n + 5` veces, pero la complejidad temporal de cada
código es :math:`O(n)`.

.. code:: c++

    for (int i = 1; i <= 3*n; i++) {
        ...
    }

.. code:: c++

    for (int i = 1; i <= n+5; i++) {
        ...
    }

Como otro ejemplo, la complejidad temporal del siguiente código es
:math:`O(n^²)` , porque el código dentro del bucle se ejecuta
:math:`1 +2 + \dots +n = \frac{1}{2}(n^2 + n)` varias veces.

.. code:: c++

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ...
        }
    }

Si un algoritmo consta de fases consecutivas, la complejidad temporal
total es la mayor complejidad temporal de una sola fase. La razón de
esto es que la fase más lenta es el cuello de botella del algoritmo. Por
ejemplo, el siguiente código consta de tres fases con complejidades
temporales :math:`O(n)`, :math:`O(n^2)` y :math:`O(n)`.

Por tanto, la complejidad del tiempo total es :math:`O(n^2)`.

.. code:: c++

    for (int i = 1; i <= n; i++) {
        ...
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ...
        }
    }
    for (int i = 1; i <= n; i++) {
        ...
    }

A veces, la complejidad del tiempo depende de varios factores y la
fórmula de la complejidad del tiempo contiene varias variables. Por
ejemplo, la complejidad temporal del siguiente código es :math:`O(nm)`:

.. code:: c++

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ...
        }
    }

**La complejidad temporal de una función recursiva depende de la
cantidad de veces que se llama a la función y de la complejidad temporal
de una sola llamada**. La complejidad del tiempo total es el producto de
estos valores. Por ejemplo, considera la siguiente función:

.. code:: c++

    void f(int n) {
        if (n == 1) return;
        f(n-1);
    }

La llamada provoca :math:`n` llamadas a funciones y la complejidad
temporal de cada llamada es :math:`O(1)`, por lo que la complejidad
temporal total es :math:`O(n)`.

Como otro ejemplo, considera la siguiente función:

.. code:: c++

    void g(int n) {
        if (n == 1) return;
        g(n-1);
        g(n-1);
    }

¿Qué sucede cuando se llama a la función con un parámetro :math:`n`?

Primero, hay dos llamadas con el parámetro ``n-1``, luego cuatro
llamadas con parámetro ``n-2``, luego ocho llamadas con parámetro
:math:`n-3` y así sucesivamente.

En general, habrá :math:`2^k` llamadas con el parámetro :math:`n-k`,
donde :math:`k = 0,1, \dots,n -1`.

Por tanto, la complejidad del tiempo es:

.. math:: 1 + 2 + 4 + \cdots + 2^{n-1} = 2^n -1 = O(2^n)

Complejidades logarítmicas
^^^^^^^^^^^^^^^^^^^^^^^^^^

Las complejidades logarítmicas, denotadas comúnmente como
:math:`O(\log n)`, son una clase importante en el análisis de
algoritmos. Indican que el tiempo de ejecución de un algoritmo (o el
espacio, aunque es menos común) aumenta logarítmicamente a medida que
aumenta el tamaño de la entrada :math:`n`. Esto significa que cada vez
que el tamaño de la entrada se duplica, el tiempo de ejecución solo
aumenta en una cantidad constante. Los algoritmos con complejidad
logarítmica son altamente eficientes, especialmente para grandes
volúmenes de datos.

**Características** 

- Algoritmos con esta complejidad son muy eficientes
ya que, incluso para entradas muy grandes, el incremento en el número de
operaciones requeridas es relativamente pequeño. 

- La base del logaritmo
en la notación :math:`O(\log n)` generalmente no se especifica porque
las complejidades se consideran hasta un factor constante. Sin embargo,
en informática, el logaritmo suele ser en base 2 (debido a la naturaleza
binaria de la computación), aunque matemáticamente, el cambio de base
del logaritmo solo altera el resultado por un factor constante.

**Ejemplos**

La búsqueda binaria en un arreglo ordenado es un ejemplo clásico de un
algoritmo :math:`O(\log n)`, donde se divide a la mitad el espacio de
búsqueda con cada paso. Las operaciones en estructuras de datos
balanceadas, como los árboles binarios de búsqueda balanceados (por
ejemplo, AVL, árboles rojo-negro), donde las operaciones como búsqueda,
inserción y eliminación pueden realizarse en tiempo logarítmico.

Los algoritmos de complejidad logarítmica son particularmente valorados
en el diseño de software y sistemas de procesamiento de datos debido a
su eficiencia con grandes conjuntos de datos. Identificar o desarrollar
algoritmos que operen en :math:`O(\log n)` puede significar una
diferencia sustancial en rendimiento, haciendo viables las operaciones
en tiempo real que de otra manera serían demasiado lentas.

**Búsqueda Binaria**: La búsqueda binaria ilustra bien el concepto de
complejidad logarítmica. Dado un arreglo ordenado de :math:`n`
elementos, la búsqueda binaria comienza en el medio del arreglo y
compara el elemento de búsqueda con el valor medio; dependiendo de si el
elemento buscado es mayor o menor que el valor medio, se continúa la
búsqueda de manera recursiva en la mitad superior o inferior del
arreglo. Este proceso se repite, dividiendo el espacio de búsqueda por
la mitad en cada paso, hasta que se encuentra el elemento o hasta que el
espacio de búsqueda se reduce a cero.

::

   Función BúsquedaBinaria(Arreglo, elemento):
       inicio = 0
       fin = longitud(Arreglo) - 1

       Mientras inicio <= fin:
           medio = (inicio + fin) / 2
           Si Arreglo[medio] == elemento:
               Devolver medio
           Si elemento < Arreglo[medio]:
               fin = medio - 1
           Sino:
               inicio = medio + 1

       Devolver -1  # El elemento no se encontró

La complejidad :math:`O(n \log n)` es crucial en el análisis de
algoritmos, especialmente en el contexto de algoritmos de ordenamiento y
algunas operaciones avanzadas en estructuras de datos. Esta clase de
complejidad combina aspectos lineales y logarítmicos, indicando que el
tiempo de ejecución del algoritmo aumenta linealmente con el tamaño de
la entrada :math:`n`, pero cada operación lineal se multiplica por un
factor logarítmico debido a la naturaleza de las operaciones internas.

**Características**

-  Aunque :math:`O(n \log n)` es más costoso que :math:`O(n)` o
   :math:`O(\log n)`, sigue siendo muy eficiente para muchos tipos de
   problemas, especialmente cuando comparado con complejidades
   cuadráticas :math:`O(n^2)` o peores. Esto hace que los algoritmos
   :math:`O(n \log n)` sean prácticos y ampliamente utilizados para
   grandes volúmenes de datos.

-  Varios algoritmos de ordenamiento eficientes operan en tiempo
   :math:`O(n \log n)` en el caso promedio o incluso en el peor de los
   casos. Estos incluyen mergesort, heapsort, y quicksort (aunque el
   peor caso de quicksort es :math:`O(n^2)`, su caso promedio y su
   comportamiento práctico son generalmente :math:`O(n \log n)`.

-  Además del ordenamiento, la complejidad :math:`O(n \log n)` aparece
   en otras operaciones complejas, como ciertas construcciones de
   árboles de búsqueda binaria balanceados, algoritmos de grafos, y en
   la computación de la Transformada Rápida de Fourier (FFT), que es
   fundamental para el procesamiento digital de señales.

**Importancia**

-  Los algoritmos con complejidad :math:`O(n \log n)` ofrecen un
   equilibrio entre complejidad puramente lineal y las más costosas
   complejidades polinomiales o exponenciales, permitiendo el manejo
   eficiente de grandes conjuntos de datos.

-  En el campo del ordenamiento y otras categorías de algoritmos,
   :math:`O(n \log n)` a menudo se considera un “estándar dorado” para
   la eficiencia. Algunos problemas no pueden resolverse más rápidamente
   que en :math:`O(n \log n)` bajo el modelo de computación basado en
   comparaciones, por lo que alcanzar esta complejidad es un indicador
   de una solución altamente optimizada.

**Mergesort**

Es un ejemplo clásico de un algoritmo con complejidad
:math:`O(n \log n)`. Funciona de la siguiente manera: 

1. **Dividir:**
Divide el conjunto de datos en dos mitades. 

2. **Conquistar:** Ordena recursivamente cada mitad. 

3. **Combinar:** Mezcla las dos mitades ordenadas para formar una única secuencia ordenada.

Cada división reduce el tamaño del problema a la mitad, lo que lleva a
un componente logarítmico :math:`(\log n)` en la complejidad, mientras
que la necesidad de ordenar :math:`n` elementos introduce el componente
lineal, resultando en una complejidad total de :math:`O(n \log n)`.

En resumen, la complejidad :math:`O(n \log n)` es significativa para el
análisis de algoritmos, ya que señala soluciones que son eficientes y
escalables, especialmente valiosas en el procesamiento de grandes
conjuntos de datos donde las operaciones deben ser óptimas tanto en
tiempo como en recursos utilizados.

::

   Función MergeSort(Arreglo):
       Si longitud(Arreglo) > 1:
           medio = longitud(Arreglo) / 2
           Izquierda = Arreglo[0:medio]
           Derecha = Arreglo[medio:longitud(Arreglo)]

           MergeSort(Izquierda)
           MergeSort(Derecha)

           i = j = k = 0

           # Mezclar los subarreglos Izquierda y Derecha en Arreglo
           Mientras i < longitud(Izquierda) y j < longitud(Derecha):
               Si Izquierda[i] < Derecha[j]:
                   Arreglo[k] = Izquierda[i]
                   i += 1
               Sino:
                   Arreglo[k] = Derecha[j]
                   j += 1
               k += 1

           # Copiar los elementos restantes de Izquierda, si hay alguno
           Mientras i < longitud(Izquierda):
               Arreglo[k] = Izquierda[i]
               i += 1
               k += 1

           # Copiar los elementos restantes de Derecha, si hay alguno
           Mientras j < longitud(Derecha):
               Arreglo[k] = Derecha[j]
               j += 1
               k += 1

Lista de complejidades temporales
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La siguiente lista contiene complejidades temporales comunes de los
algoritmos:

-  :math:`O(1)`: El tiempo de ejecución de un algoritmo de tiempo
   constante no depende del tamaño de la entrada. Un algoritmo típico de
   tiempo constante es una fórmula directa que calcula la respuesta.

-  :math:`O(\log n)`: Un algoritmo logarítmico suele reducir a la mitad
   el tamaño de entrada en cada paso. El tiempo de ejecución de dicho
   algoritmo es logarítmico, porque :math:`\log_2 n` es igual al número
   de veces que :math:`n` debe dividirse por :math:`2` para obtener
   :math:`1`. Ten en cuenta que la base del logaritmo no se muestra en
   la complejidad del tiempo.

-  :math:`O(\sqrt{n})` : Un algoritmo de raíz cuadrada es más lento pero
   más rápido que :math:`O(\log n)`. Una propiedad especial de las
   raíces cuadradas es que :math:`\sqrt{n} = n/\sqrt{n}` tal que ``n``
   elementos se pueden dividir en :math:`O(\sqrt{n})` bloques de
   :math:`O(\sqrt{n})` elementos.

-  :math:`O(n)` Un algoritmo lineal pasa por la entrada un número
   constante de veces. Esta suele ser la mejor complejidad de tiempo
   posible, porque generalmente es necesario acceder a cada elemento de
   entrada al menos una vez antes de informar la respuesta.

-  :math:`O(n\log n)` Esta complejidad temporal a menudo indica que el
   algoritmo ordena la entrada, porque la complejidad temporal de los
   algoritmos de clasificación eficientes es :math:`O(n\log n)` . Otra
   posibilidad es que el algoritmo utilice una estructura de datos donde
   cada operación lleve :math:`O(\log n)` veces.

-  :math:`O(n^2)` Un algoritmo cuadrático suele contener dos bucles
   anidados. Es posible revisar todos los pares de elementos de entrada
   en :math:`O(n^2)` veces.

-  :math:`O(n^3)` Un algoritmo cúbico suele contener tres bucles
   anidados. Es posible recorrer todos los tripletes de los elementos de
   entrada en :math:`O(n^3)` veces.

-  :math:`O(2^n)` Esta complejidad temporal a menudo indica que el
   algoritmo recorre en iteración todos los subconjuntos de elementos de
   entrada. Por ejemplo, los subconjuntos de :math:`\{ 1, 2,3\}` son
   :math:`\emptyset, \{1\}, \{2\}, \{3\}\{1, 2\}\{1, 3\}, \{2,3\}` y
   :math:`\{1, 2, 3\}` .

-  :math:`O(n!)` Esta complejidad temporal a menudo indica que el
   algoritmo itera a través de todas las permutaciones de los elementos
   de entrada. Por ejemplo, las permutaciones de :math:`\{1,2, 3\}` son
   :math:`(1, 3, 2), (2, 1, 3),(2, 3, 1), (3, 1, 2)` y
   :math:`(3 , 2, 1)`.

Un algoritmo es polinómico si su complejidad temporal es como máximo
:math:`O(n^k)` donde :math:`k` es una constante. Todas las complejidades
de tiempo anteriores excepto :math:`O(2^n)` y :math:`O(n!)` son
polinomiales. En la práctica, la constante :math:`k` suele ser pequeña y
por lo tanto, una complejidad de tiempo polinómica significa
aproximadamente que el algoritmo puede procesar entradas grandes.

La mayoría de los algoritmos de varios cursos son polinomiales.

Aún así, hay muchos problemas importantes para los cuales no se conoce
ningún algoritmo polinomial, es decir, nadie sabe cómo resolverlos de
manera eficiente. Los **problemas NP-hard** son un conjunto importante
de problemas para los cuales no se conoce ningún algoritmo polinomial.

Complejidad espacial
~~~~~~~~~~~~~~~~~~~~

La complejidad espacial de un algoritmo de ordenación se refiere a la
cantidad de memoria adicional que necesita el algoritmo para ejecutar su
tarea de ordenar los elementos de una lista o arreglo. Este aspecto es
tan importante como la complejidad temporal (el tiempo que tarda en
ejecutarse), especialmente en contextos donde los recursos de memoria
son limitados o cuando se trabaja con grandes volúmenes de datos.

**Ordenamiento por Burbuja, Inserción y Selección** Complejidad
espacial: :math:`O(1)`

Estos algoritmos de ordenación realizan el ordenamiento “in situ”, es
decir, dentro del propio arreglo sin necesidad de estructuras
adicionales significativas, más allá de unas pocas variables temporales.
Esto los hace muy eficientes en términos de uso de memoria.

**Merge Sort** Complejidad espacial: :math:`O(n)`

Aunque Merge Sort es muy eficiente en tiempo, su principal desventaja es
su complejidad espacial, ya que necesita un espacio adicional
proporcional al tamaño del arreglo de entrada para realizar la mezcla de
los subarreglos. Esto se debe a que crea copias de subsecciones del
arreglo original para luego mezclarlas ordenadamente.

**Quicksort** Complejidad espacial:

Peor Caso: :math:`O(n)` (dependiendo de la implementación)

Caso Promedio: :math:`O(\log n)`

Quicksort es un algoritmo de división y conquista que, en su
implementación más común, realiza el ordenamiento “in situ”. Sin
embargo, debido a su naturaleza recursiva, el uso de la pila para las
llamadas recursivas puede llevar a una complejidad espacial de
:math:`O(\log n)` en el caso promedio, debido a la profundidad del árbol
de recursión.

En el peor de los casos, si cada partición divide el arreglo en un
subarreglo de un elemento y otro de :math:`n-1` elementos, la
profundidad de la recursión (y por lo tanto el espacio de la pila) puede
aumentar a :math:`O(n)`.

**Ordenamiento Radix (Radix Sort) y Ordenamiento por Conteo (Counting
Sort)** Complejidad espacial: Variable

Estos algoritmos no comparativos tienen complejidades espaciales que
dependen de los datos de entrada y los detalles específicos de su
implementación. Por ejemplo, Counting Sort necesita un espacio adicional
para el arreglo de conteo, cuyo tamaño depende del rango de los datos de
entrada.

Estimación de la eficiencia
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Calculando la complejidad temporal de un algoritmo, es posible
comprobar, antes de implementarlo, que es lo suficientemente eficiente
para resolver un problema. El punto de partida de las estimaciones es el
hecho de que un ordenador moderno puede realizar unos cientos de
millones de operaciones sencillas en un segundo.

Por ejemplo, supongamos que el límite de tiempo para un problema es un
segundo y el tamaño de entrada es :math:`n =10^{5}`. Si la complejidad
del tiempo es :math:`O(n^2)` el algoritmo realizará aproximadamente
:math:`(10^{5})^2 = 10^{10}` operaciones. Esto debería tardar al menos
unas decenas de segundos, por lo que el algoritmo parece demasiado lento
para resolver el problema.

Sin embargo, si la complejidad del tiempo es :math:`O(n\log n)`, solo se
tratará de :math:`10^{5}\log 10^{5} \approx 1.6 \cdot 10^{6}`
operaciones y el algoritmo seguramente se ajustará al límite de tiempo.

Por otro lado, dado el tamaño de la entrada, podemos intentar adivinar
la complejidad temporal requerida del algoritmo que resuelve el
problema.

**Ejemplo:** `Knowing the complexity in competitive
programming <https://www.geeksforgeeks.org/knowing-the-complexity-in-competitive-programming/>`__.

Por ejemplo, si el tamaño de entrada es :math:`n = 10^5` , probablemente
se espera que la complejidad temporal del algoritmo sea :math:`O(n)` o
:math:`O(n\log n)`. Esta información facilita el diseño del algoritmo,
porque descarta enfoques que producirían un algoritmo con una peor
complejidad temporal.

Aun así, es importante recordar que la complejidad del tiempo es sólo
una estimación de la eficiencia, porque oculta los factores constantes.
Por ejemplo, un algoritmo que se ejecuta en tiempo :math:`O(n)` puede
realizar :math:`n/2` o :math:`5n` operaciones, lo que tiene un efecto
importante en el tiempo de ejecución real del algoritmo.

Definiciones formales
^^^^^^^^^^^^^^^^^^^^^

¿Qué significa exactamente que un algoritmo funciona en tiempo
:math:`O(f(n)`)?

Significa que hay constantes :math:`c` y :math:`n_0` tales que el
algoritmo realiza como máximo :math:`cf(n)` operaciones para todas las
entradas donde :math:`n \ge n_0`. Por tanto, la notación :math:`O`
proporciona un límite superior para el tiempo de ejecución del algoritmo
para entradas suficientemente grandes.

Por ejemplo, es técnicamente correcto decir que la complejidad temporal
del siguiente algoritmo es :math:`O(n^2)`.

.. code:: c++

    for (int i = 1; i <= n; i++) {
        ...
    }

Sin embargo, un límite mejor es :math:`O(n)` y sería muy engañoso dar el
límite :math:`O(n^2)`, porque en realidad todo el mundo supone que la
notación :math:`O` se utiliza para dar una estimación precisa de la
complejidad del tiempo.

También hay otras dos notaciones comunes. La notación :math:`\Omega`
proporciona un límite inferior para el tiempo de ejecución de un
algoritmo. La complejidad temporal de un algoritmo es
:math:`\Omega(f(n))` , si hay constantes :math:`c` y :math:`n_0` tales
que el algoritmo realiza al menos :math:`cf(n)` operaciones para todas
las entradas donde :math:`n \geq n_0`.

Finalmente, la notación :math:`\Theta` da un límite exacto: la
complejidad temporal de un algoritmo es :math:`\Theta(f(n))` si es a la
vez :math:`O(f(n))` y :math:`\Omega(f(n)`. Por ejemplo, dado que la
complejidad temporal del algoritmo anterior es :math:`O(n)` y
:math:`\Omega(n)` es también :math:`\Theta(n)`.

Podemos utilizar las notaciones anteriores en muchas situaciones, no
sólo para referirnos a las complejidades temporales de los algoritmos.
Por ejemplo, podríamos decir que un arreglo contiene :math:`O(n)`
valores o que un algoritmo consta de :math:`O(\log n)` pasos.

Ejercicios
~~~~~~~~~~

1. Suma máxima de subarreglo

   Dada un arreglo de n números, calcula la suma máxima de un
   subarreglo, es decir, la suma más grande posible de una secuencia de
   valores consecutivos en el arreglo. El problema es interesante cuando
   puede haber valores negativos en el arreglo.

   Una forma sencilla de resolver el problema es revisar todos los
   subarreglos posibles, calcular la suma de los valores en cada
   subarreglo y mantener la suma máxima. El siguiente código implementa
   este algoritmo:

.. code:: c++

    int mejor = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int suma = 0;
            for (int k = a; k <= b; k++) {
                suma += arreglo[k];
            }
            mejor = max(mejor,suma);
        }
    }
    cout << mejor << "\n";

¿Cuál es la complejidad del tiempo del anterior algoritmo?.

.. code:: c++

    // Tu respuesta

Es fácil hacer que el algoritmo sea más eficiente eliminando un bucle.
Esto es posible calculando la suma al mismo tiempo que se mueve el
extremo derecho del subarreglo. El resultado es el siguiente código:

.. code:: c++

    int mejor = 0;
    for (int a = 0; a < n; a++) {
        int suma = 0;
        for (int k = a; k <= b; k++) {
            suma += arreglo[k];
            mejor = max(mejor,suma);
        }
    }
    cout << mejor << "\n";

¿Cuál es la complejidad del tiempo del anterior algoritmo?.

.. code:: c++

    // Tu respuesta

Resulta que es posible resolver el problema en tiempo :math:`O(n)`, lo
que significa que solo un bucle es suficiente. La idea es calcular, para
cada posición del arreglo, la suma máxima de un subarreglo que termina
en esa posición. Después de esto, la respuesta al problema es el máximo
de esas sumas.

Considera el subproblema de encontrar la suma máxima del subarreglo que
termina en la posición :math:`k`.

Hay dos posibilidades:

1. El subarreglo solo contiene el elemento en la posición :math:`k`.
2. El subarreglo consta de un subarreglo que termina en la posición
   :math:`k -1`, seguido por el elemento en la posición :math:`k`.

En el último caso, como queremos encontrar un subarreglo con suma
máxima, el subarreglo que termina en la posición :math:`k-1` también
debe tener la suma máxima. Por lo tanto, podemos resolver el problema de
manera eficiente calculando la suma máxima del subarreglo para cada
posición final de izquierda a derecha.

El siguiente código implementa el algoritmo:

.. code:: c++

    int mejor = 0, suma = 0;
    for (int k = 0; k < n; k++) {
        suma = max(arreglo[k],suma+arreglo[k]);
        mejor = max(mejor,suma);
        }
        cout << mejor << "\n";

¿Cuál es la complejidad del tiempo del anterior algoritmo?.

.. code:: c++

    // Tu respuesta

Revisa: `Efficient Algorithms and Intractable
Problems <https://cs170.org/>`__.

Memoización
~~~~~~~~~~~

**Ejemplo**: Serie de Fibonacci

.. code:: c++

    int fibonacci(int n, int cache[]) {
        if (cache[n] != -1) {
            return cache[n];
        }
    
        int resultado;
        if (n == 0) {
            resultado = 0;
        } else if (n == 1) {
            resultado = 1;
        } else {
            resultado = fibonacci(n - 1, cache) + fibonacci(n - 2, cache);
        }
    
        cache[n] = resultado;
        return resultado;

Complejidad temporal
^^^^^^^^^^^^^^^^^^^^

Se verifica el caché para ver si ya hay una respuesta almacenada en el
enésimo lugar y se devuelve si está allí. De lo contrario, la suma de
``fibonacci (n - 1)`` y ``fibonacci (n - 2)`` se llama de forma
recursiva y la suma se establece en una variable.

Esta suma se coloca en el arreglo de caché en el lugar :math:`n` y luego
se devuelve el valor de la suma. Con esta solución en memoización, cada
vez que se llama a ``fibonacci(n)`` y :math:`n` ya se ha resuelto una
vez, ``cache[n]`` ya contendrá la respuesta y la devolverá.

La complejidad temporal de llamar recursivamente a
``fibonacci (n - 1) + fibonacci (n - 2)`` es :math:`O(2^n)` y mejora
mucho con la memoización: :math:`O(n)`.

Complejidad espacial
^^^^^^^^^^^^^^^^^^^^

Utilizando la técnica de memorización, cada valor de ‘fibonacci’ se
calculará solo una vez. Entonces, la complejidad del espacio será
:math:`O(n)`, donde ‘n’ es el número de entrada para ‘fibonacci’ (el
arreglo para la memorización contendrá ‘n’ números).

Tabulación
~~~~~~~~~~

La tabulación es similar en el sentido de que crea un caché, pero el
enfoque es diferente. Un algoritmo de tabulación se centra en llenar las
entradas de la caché, hasta alcanzar el valor objetivo.

.. code:: c++

    int fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            int tabla[n + 1];
            tabla[0] = 0;
            tabla[1] = 1;
            for (int i = 2; i <= n; i++) {
                tabla[i] = tabla[i - 1] + tabla[i - 2];
            }
            return tabla[n];
        }
    }

Ejercicio
^^^^^^^^^

-  Analiza la complejidad temporal y espacial de la tabulación.

.. code:: c++

    # Tu respuesta

Administración de la memoria
----------------------------

Stack
~~~~~

Estas son algunas de las propiedades únicas del stack:

-  El stack es un bloque de memoria contiguo.
-  Tiene un tamaño máximo fijo. Si un programa excede el tamaño máximo
   del stack, el programa fallará. Esta condición se denomina
   desbordamiento del stack (stack overflow).
-  La memoria de stack nunca se fragmenta.
-  La asignación de memoria desde el stack es (casi) siempre rápida. Las
   fallas de página son posibles pero ocurren raras veces.
-  Cada subproceso en un programa tiene su propio stack.

Ejemplo
^^^^^^^

El siguiente código de ejemplo demuestra cómo crece y se contrae el
stack al entrar y salir de funciones:

.. code:: c++

    // Completa ...
    
    void func1() {
      auto i = 0;
      std::cout << "func1(): " << std::addressof(i) << '\n';
    }
    
    void func2() {
       auto i = 0;
       std::cout << "func2(): " << std::addressof(i) << '\n';
       func1();
    }
    int main() {
       auto i = 0;
       std::cout << "main(): " << std::addressof(i) << '\n';
        func2();
        func1();
    }


**Discusión** ¿qué tan grande es el stack y qué sucede cuando alcanzamos
el límite del stack?

.. code:: c++

    // Tu respuesta

Ejemplo
^^^^^^^

Escribe un programa para ver qué tan grande es el stack en la
computadora que estás trabajando. Compara tus resultados con el comando:
``ulimit -s.``

.. code:: c++

    // Completa 
    
    auto func(std::byte* stack_direccion_inferior) -> void {
      std::byte data[1024];
      std::cout << stack_direccion_inferior - data << '\n';
      func(stack_direccion_inferior);
    }
    
    int main() {
          std::byte b;
            func(&b);
    }

Lectura: https://google.github.io/googletest/primer.html

.. code:: c++

    // Tu respuesta

Heap
^^^^

El heap es donde viven los datos con almacenamiento dinámico.

El patrón de asignación y desasignación de la memoria del stack es
secuencial, en el sentido de que la memoria siempre se desasigna en el
orden inverso al que se asignó. Por otro lado, para la memoria dinámica,
las asignaciones y desasignaciones pueden ocurrir arbitrariamente.

La duración dinámica de los objetos y los tamaños variables de las
asignaciones de memoria aumentan el riesgo de tener memoria fragmentada.

Objetos en la memoria
~~~~~~~~~~~~~~~~~~~~~

Todos los objetos que usamos en un programa C++ residen en la memoria.

Crear y eliminar objetos
^^^^^^^^^^^^^^^^^^^^^^^^

Considera la siguiente forma de usar ``new`` para crear un objeto en el
free store y luego eliminarlo usando ``delete``:

.. code:: c++

    auto* user = new User{"Cesar"}; // asignar y construir
    
    user->print_name();  // usar objeto 
    delete user ; // destruir y desasignar 


No se recomienda que llames a ``new`` y ``delete`` explícitamente de
esta manera, pero ignoremos eso por ahora.

Vayamos al grano como sugieren los comentarios, ``new`` en realidad hace
dos cosas:

-  Asigna memoria para contener un nuevo objeto del tipo ``User``
-  Construye un nuevo objeto ``User`` en el espacio de memoria asignado
   llamando al constructor de la clase ``User``.

Lo mismo ocurre esto con ``delete``:

-  Destruye el objeto ``User`` llamando a su destructor
-  Desasigna/libera la memoria en la que se colocó el objeto User

Ubicación nueva
^^^^^^^^^^^^^^^

C++ nos permite separar la asignación de memoria de la construcción de
objetos. Podríamos, por ejemplo, asignar un arreglo de bytes con
``malloc()`` y construir un nuevo objeto ``User`` en esa región de la
memoria.

Echa un vistazo al siguiente fragmento de código:

.. code:: c++

    auto* memoria = std::malloc(sizeof(User));
    auto* user = ::new (memoria) User("Cesar");

No hay eliminación de ubicación, por lo que para destruir el objeto y
liberar la memoria, debemos llamar al destructor explícitamente y luego
liberar la memoria:

.. code:: c++

    user->~User();
    std::free(memory);

C++17 introduce un conjunto de funciones de utilidad en ``<memory>``
para construir y destruir objetos sin asignar o desasignar memoria.
Entonces, en lugar de llamar a la ubicación ``new``, ahora es posible
usar algunas de las funciones de ``<memory>`` cuyos nombres comienzan
con ``std::uninitialized_`` para construir, copiar y mover objetos a un
área de memoria no inicializada.

Y en lugar de llamar explícitamente al destructor, ahora podemos usar
``std::destroy_at()`` para destruir un objeto en una dirección de
memoria específica sin desasignar la memoria.

El ejemplo anterior podría reescribirse usando estas nuevas funciones.
Así es como se vería:

.. code:: c++

    auto* memoria = std::malloc(sizeof(User));
    auto* user_ptr = reinterpret_cast<User*>(memoria);
    std::uninitialized_fill_n(user_ptr, 1, User{"Cesar"});
    std::destroy_at(user_ptr);
    std::free(memoria);


C++20 también presenta ``std::construct_at()``, que hace posible
reemplazar la llamada ``std::uninitialized_fill_n()`` con:

.. code:: c++

    std::construct_at(user_ptr, User{"Cesar"});  // C++20 


Regresando a los punteros
~~~~~~~~~~~~~~~~~~~~~~~~~

Una de las características clave del lenguaje C++ es el concepto de
puntero y sabemos que los punteros son extremadamente útiles para
asignar memoria para arreglos cuyos tamaños no se conocen cuando se
compila el código.

Vemos algunas características de los punteros que se han introducido en
los estándares C++ recientes.

Punteros y la memoria de la computadora
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Los punteros se presentan mejor explicando cómo se relacionan con el
almacenamiento de variables en la memoria de la computadora.

**Direcciones**

Supongamos que se declara una variable entera ``suma_total`` y se le
asigna el valor 10:

.. code:: c++

    int suma total= 10;

La dirección, es decir, la ubicación de esta variable en la memoria de
la computadora viene dada por ``&suma_total`` y se puede imprimir en la
consola de la forma habitual (como se muestra a continuación), aunque
esta dirección no tendrá sentido.

.. code:: c++

    std::cout << &suma_total<< "\n"; 

Variables de puntero
^^^^^^^^^^^^^^^^^^^^

Podemos declarar variables de puntero que son variables que almacenan
direcciones, es decir, la ubicación en la memoria de la computadora de
otras variables.

.. code:: c++

    double* p_x;
    int* p_i;

Todas las variables de puntero requieren un asterisco cuando se
declaran. Por lo tanto, en el siguiente código, ``p_x``, ``p_y``,
``p_i`` son punteros, mientras que ``j`` es una variable entera.

.. code:: c++

    double *p_x, *p_y;
    int *p_i, j;

Ejemplo
^^^^^^^

El siguiente código muestra cómo los punteros a variables de punto
flotante de doble precisión se pueden combinar con variables de punto
flotante de doble precisión.

.. code:: c++

    double y, z;
    double* p_x; 
    z = 3.0;
    p_x = &z; 
    y = *p_x + 1.0;

Advertencias sobre el uso de punteros
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

No se debe usar un puntero de variable hasta que primero se le haya
asignado una dirección válida. Por ejemplo, el siguiente fragmento de
código puede causar problemas difíciles de localizar.

.. code:: c++

    double* p_x;
    *p_x = 1.0; // ver aliasing

**Pregunta:** Explica el problema que podría suceder aquí.

.. code:: c++

    // Tu respuesta

Cambiar el contenido de una ubicación no especificada en la memoria de
una computadora, como se hace en el código anterior, claramente tiene el
potencial de causar problemas que pueden ser difíciles de localizar.

Este problema se puede evitar mediante el uso de la palabra clave
``new``, como se muestra a continuación, para asignar una dirección de
memoria válida a ``p_x`` y la palabra clave ``delete`` que libera esta
memoria para que la utilicen otras partes del programa cuando esta
memoria ya no sea necesaria.

.. code:: c++

    double* p_x;
    p_x = new double;
    *p_x = 1.0;
    delete p_x;

En el siguiente código se muestra otra razón para usar los punteros con
cuidado.

.. code:: c++

    double y;
    double* p_x;
    y = 3.0;
    p_x = &y;
    std::cout << "y = " << y << "\n";
    *p_x = 1.0; 
    std::cout << "y = " << y << "\n";


**Pregunta:** Explica el problema que podría suceder aquí.

.. code:: c++

    // Tu respuesta

Una situación en la que se puede acceder al contenido de la misma
variable usando diferentes nombres como en el código anterior, se conoce
como **aliasing**.

En C++, es más probable que esto suceda cuando hay punteros
involucrados, ya sea cuando dos punteros tienen la misma dirección en la
memoria o cuando un puntero hace referencia al contenido de otra
variable.

Cuando uno o más punteros permiten acceder a la misma variable con
diferentes nombres, el aliasing se conoce como **aliasing de puntero**.

Asignación dinámica de memoria para arreglos
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Uno de los principales usos de los punteros es la asignación dinámica de
memoria para almacenar arreglos.

Otro uso de los punteros para la asignación dinámica de memoria es el
almacenamiento eficiente de arreglos de tamaño irregular, por ejemplo,
una matriz triangular inferior.

La asignación dinámica de memoria nos permite asignar la memoria de
manera más prudente.

Vectores
^^^^^^^^

Para usar punteros para crear un arreglo unidimensional de números de
coma flotante de doble precisión de longitud 10 llamado ``x``, usamos la
siguiente sección de código.

.. code:: c++

    double* x;
    x = new double [10];

En la asignación dinámica de memoria para el arreglo utilizando el
puntero ``x`` anterior, ``x`` almacena la dirección del primer elemento
del arreglo.

Esto se puede ver imprimiendo tanto el puntero ``x`` como la dirección
del primer elemento del arreglo, como se muestra a continuación:

.. code:: c++

    std::cout << x << "\n";
    std::cout << &x[0] << "\n"; 

La memoria asignada a ``x`` puede ser y debe ser desasignada usando la
declaración a continuación cuando ya no se requiera este arreglo.

.. code:: c++

    delete[] x;

A continuación se muestra un código de ejemplo que usa memoria asignada
dinámicamente para arreglos.

Este código crea dos arreglos, ``x`` e ``y``, ambas de tamaño 10. Luego,
los elementos de ``x`` se asignan manualmente. Luego, los elementos de
``y`` se configuran para que tengan el doble del valor del elemento
correspondiente de ``x``. Finalmente, se elimina toda la memoria
asignada.

.. code:: c++

    #include <iostream>
    
    int main(int argc, char* argv[])
    {
       double* x;
       double* y;
       x = new double [10];
       y = new double [10];
    
       for (int i=0; i<10; i++)
       {
          x[i] = ((double)(i));
          y[i] = 2.0*x[i];
       }
    
       delete[] x;
       delete[] y;
    
       return 0;
    }

**Revisión:** https://godbolt.org/

Matrices
^^^^^^^^

La memoria para matrices también se puede asignar dinámicamente. Por
ejemplo, para crear una matriz bidimensional de números de punto
flotante de doble precisión con 5 filas y 3 columnas llamada A, usamos
la siguiente sección de código.

.. code:: c++

    int filas = 5, cols = 3;
    double** A;
    
    A = new double* [filas];
    for (int i=0; i<filas; i++)
    {
        A[i] = new double [cols];
    }

El arreglo se puede usar entonces de la misma manera que si se hubiera
creado usando la declaración:

.. code:: c++

    double A[5][3];

Al asignar memoria para la matriz dinámicamente en el código anterior,
la variable A,tiene las siguientes propiedades después de ejecutar el
fragmento de código:

-  Cada ``A[i]`` es un puntero y contiene la dirección de ``A[i][0]``

-  ``A`` contiene la dirección del puntero ``A[0]``.

Como fue el caso de los vectores, es importante desasignar la memoria
asignada dinámicamente para una matriz cuando ya no se necesita.

La memoria asignada para el arreglo A se puede liberar usando el
siguiente código.

.. code:: c++

    for (int i=0; i<rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;

Matrices de tamaño irregular
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Supongamos que queremos construir una matriz triangular inferior A de
números enteros con 1000 filas y 1000 columnas. Esto se puede hacer
claramente utilizando la siguiente declaración:

.. code:: c++

    int A[1000][1000];

Sin embargo, la declaración anterior desperdicia una cantidad
considerable de memoria almacenando las entradas superdiagonales del
arreglo que sabemos de antemano que toman el valor 0.

Podemos evitar desperdiciar esta memoria asignando la memoria para esta
matriz de forma dinámica y solo asignando memoria para los elementos
diagonales y subdiagonales.

Esto se demuestra en el fragmento de código a continuación, donde en la
fila ``i`` del arreglo declaramos ``i+1`` elementos distintos de cero,
es decir, ``1`` elemento en la fila ``0``, ``2`` elementos en la fila
``1`` y así sucesivamente.

La memoria puede y debe eliminarse de la misma manera cuando ya no se
necesita este arreglo.

.. code:: c++

    int** A;
    A = new int* [1000];
    for (int i=0; i<1000; i++)
    {
       A[i] = new int[i+1];
    }

Pointer aliasing
^^^^^^^^^^^^^^^^

Dimos un ejemplo en el que una variable de puntero ``p_x`` apuntaba a la
ubicación de memoria de la variable ``y``. Se realizó un cambio en esa
variable eliminando la referencia del puntero ``p_x``.

Esta situación puede generar cierta confusión, aunque en un fragmento de
código corto es fácil ver que las dos variables conducen al mismo lugar:
``*p_x`` es un alias para ``y``.

En programas a gran escala, puede que no sea tan fácil ver dónde los
punteros son alias para otras variables. Un buen ejemplo de esto sería
una operación de suma de vectores o matrices en la que los vectores o
matrices se almacenan como matrices y se pasan a una función a través de
punteros. Esto da la posibilidad del código de la función puede estar en
un archivo diferente y que las variables pueden tomar diferentes nombres
dentro de la definición de la función.

La operación para calcular la suma de el arreglo A = B + C probablemente
se implementaría en dicha función mediante un bucle anidado sobre los
elementos de las matrices, de modo que la implementación real se
convierta en un elemento

``A[i][j] = B[i][ j] + C[i][j]``.

Puede haber un alias de puntero desconocido en esta función, porque el
usuario puede desear incrementar una matriz por otra, es decir, calcular
X = X + Y.

Resulta que este alias de puntero será seguro, porque el bucle interno
calculará efectivamente ``X[ i][j] += Y[i][j]`` según lo previsto. Cada
uno de los componentes ``(i, j)`` del resultado es independiente de los
demás.

Sin embargo, ¿qué pasaría si el usuario estuviera usando una operación
de producto matriz-matriz?

En el cálculo A= BC, el componente ``A[i][j]`` depende de partes de B y
C distintas de ``B[i][j]`` y ``C[i][j]``. Esto significa que, si el
usuario desea calcular X = XY usando una función escrita para calcular
A=BC, existe la posibilidad de que se escriban algunos componentes de X
antes de leerlos lo que provocaría un cálculo incorrecto.

**Discusión:** ¿Cómo resolverías este tipo problemas?

.. code:: c++

    // Tu respuesta

Asignación dinámica segura
~~~~~~~~~~~~~~~~~~~~~~~~~~

Puede haber circunstancias en las que no sea posible asignar memoria
porque el número de elementos en un arreglo se ha establecido con un
argumento negativo o porque no hay suficiente memoria física disponible
para el programa.

Establecer el número de elementos en un arreglo en un número negativo es
más fácil de lo que se piensa. Si el tamaño de un problema se configura
a través de un archivo de entrada, es fácil que se escriba mal el
tamaño. Más sutilmente, si se asigna un número a un entero que es mayor
que el valor máximo que ese entero puede almacenar, entonces el valor
entero almacenado puede ser en realidad un número negativo: esto se
conoce como error de desbordamiento (overflow error).

Las implementaciones de C++ pueden variar en la forma en que tratan
dichos errores. El comportamiento predeterminado es lanzar una excepción
cuando se encuentra un error de memoria. Si tu implementación de C++ no
arroja este tipo de excepción, entonces una forma segura de programar es
probar que a tu variable se le ha asignado un valor como se ilustra en
el siguiente código:

.. code:: c++

    double* p_x;
    p_x = new double[10000];
    assert (p_x != NULL);

Cada new tiene un delete
^^^^^^^^^^^^^^^^^^^^^^^^

Señalamos que toda la memoria asignada dinámicamente debe liberarse o de
lo contrario puede quedarse sin memoria. Este problema es
particularmente notable cuando la memoria se asigna dinámicamente dentro
del cuerpo de un bucle ``for`` como el que se muestra a continuación:

.. code:: c++

    for (int i=0; i<10000; i++)
    {
       double** A;
        A = new double* [50];
        for (int j=0; j<50; j++)
         {
            A[j] = new double [50];
         }
    }

**Pregunta:** ¿ Qué ocurre en el código anterior?

.. code:: c++

    // Tu respuesta

Administración de memoria de C++ moderna
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

La administración de memoria flexible de C++ le dio una ventaja sobre
los lenguajes que usan recolección de basura, como Java. Sin embargo,
también hicimos una advertencia: esta administración de memoria flexible
significa que tú eres el responsable de asegurarse de que la memoria se
administre correctamente.

El estándar de C++ ha introducido construcciones de punteros
inteligentes (smart pointers) que facilitan la administración de la
memoria, lo que proporciona un compromiso eficiente entre dar
responsabilidad al programador y la recolección automática de basura en
tiempo de ejecución.

Estas construcciones se introdujeron por primera vez en la
especificación C++ 11 y se refinaron en especificaciones posteriores.

El puntero inteligente unique_ptr
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ya advertimos sobre los peligros del alias de puntero. En particular
notamos que puede haber momentos en que un programador suponga que dos
punteros apuntan a diferentes datos, pero que esta suposición puede no
ser cierta.

Cuando dos punteros apuntan a la misma pieza de datos pueden producirse
errores, como que un elemento de un arreglo se sobrescriba antes de que
se haya leído su valor.

C++ 11 proporciona un tipo de puntero inteligente que puede protegerte
contra errores del aliasing. Este puntero inteligente ``unique_ptr``
permite que el sistema en tiempo de ejecución supervise ciertos punteros
de forma individual.

El ejemplo de su uso dado en el siguiente código es un poco artificial
porque el verdadero poder de la construcción no se puede ver hasta que
se usa con funciones. Sin embargo, el programa servirá para ilustrar
algunas de las características principales.

Nota: es posible que tu compilador de C++ no acepte este programa, ya
que la mayoría de los compiladores actuales están configurados para leer
programas estándar C++98 más antiguos de forma predeterminada.

Para compilar el programa, deberás agregar un indicador para indicar que
el código se adhiere al estándar C++ 11.

.. code:: c++

    g++ -std=c++11 -o prg prg.cpp

.. code:: c++

    #include <memory> // Requiere C++11 o ++
    #include <cassert>
    
    int main()
    {
       std::unique_ptr<int> p_x(new int);
       *p_x = 5;  
    
       // int* p_y = p_x;
       int* p_y = p_x.get();  
    
       std::unique_ptr<int> p_z;
    
       // p_z = p_x;
       p_z = std::move(p_x); 
       assert(p_z); 
       assert(!p_x);
       p_z.reset();
       assert(!p_z);
       exit(0);
    }

**Pregunta** Explica y compila el programa anterior.

.. code:: c++

    // Tu respuesta

El puntero inteligente shared_ptr
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El concepto detrás de un puntero compartido inteligente es simple. Junto
con la dirección del recurso subyacente, el puntero también realiza un
seguimiento de la cantidad de veces que se ha utilizado este recurso.

Inicialmente el conteo será 1, pero aumentará cuando el puntero se pase
entre varias partes del programa. Cada vez que finalice un uso del
puntero, el conteo de uso se reducirá. Cuando el conteo llega a 0 y no
hay usos conocidos del puntero, el recurso original se liberará. Todo
esto sucede automáticamente sin que el usuario tenga que preocuparse por
ello.

Es efectivamente un recolector de basura local que administra una
pequeña parte de la memoria.

.. code:: c++

    #include <memory> // Requiere C++11 o ++
    #include <iostream>
    
    int main()
    {
       std::shared_ptr<int> p_x(new int);
       std::cout<<"p_x usa conteo : "<<p_x.use_count()<<"\n";
       *p_x = 5; 
    
       std::shared_ptr<int> p_y = p_x;
       std::cout<<"p_x usa conteo: "<<p_x.use_count()<<"\n";
       p_y.reset();
       std::cout<<"p_x usa conteo: "<<p_x.use_count()<<"\n";
       p_x.reset();
       std::cout<<"p_x usa conteo: "<<p_x.use_count()<<"\n";
    return 0;
    }

**Pregunta**: Explica y compila el programa anterior.

.. code:: c++

    // Tu respuesta

Ejercicios
~~~~~~~~~~

1. Escribe código que declare un entero ``i`` para que tome el valor 5.
   Declara un puntero a un entero ``p_j`` y almacena la dirección de
   ``i`` en este puntero. Multiplica el valor de la variable ``i`` por 5
   usando una línea de código que solo usa la variable de puntero.
   Declara otro puntero a un número entero ``p_k`` y usa la palabra
   clave ``new`` para asignar una ubicación en la memoria que almacena
   este puntero. Luego almacena el contenido de la variable ``i`` en
   esta ubicación. Ahora cambia el valor señalado por ``p_j`` a 0.
   Verifica que tu programa sea correcto generando el valor de ``i`` y
   los valores señalados por ``p_j`` y ``p_k``.

2. Escribe código que asigne memoria dinámicamente a dos vectores de
   números punto flotante de doble precisión, longitud 3, asigne valores
   a cada una de las entradas y luego desasigne la memoria antes de que
   finalice el código. Extiende este código para que calcule el producto
   escalar (punto) de estos vectores y lo imprima en la pantalla antes
   de que se desasigne la memoria. Coloca la asignación de memoria, el
   cálculo y la desasignación de memoria dentro de un bucle ``for`` que
   se ejecute 1,000,000,000 veces: si la memoria no se desasigna
   correctamente, tu código usará todos los recursos disponibles y tu
   computadora puede tener problemas.

3. Hemos presentado las construcciones ``unique_ptr`` y ``shared_ptr``.
   Otro puntero inteligente útil es ``weak_ptr``, que es un puntero
   inteligente que no contribuye al conteo de uso. Se puede utilizar en
   situaciones en las que es necesario acceder a las variables, pero
   solo cuando existen. Tiene funciones que se pueden utilizar para
   comprobar si un recurso se ha eliminado y, si no se ha eliminado,
   para acceder al recurso. Utiliza el último listado de este cuaderno y
   agrega un puntero inteligente adicional: un ``weak_ptr`` que se
   inicializa con el valor ``p_x``. Experimenta con el resultado del
   valor original de ``p_x`` (es decir, el valor 5) a través de este
   puntero inteligente. Prueba esto antes y después, el ``p_x`` se
   restablece.

.. code:: c++

    // Tus respuestas.


Fundamentos de Programación
===========================

Funciones
---------

Las funciones son componentes importantes de los programas C++. El
primer ejemplo que hemos visto es la función ``main`` del programa
``hello-world``.

Argumentos
~~~~~~~~~~

C++ distingue dos formas de pasar argumentos: por valor y por
referencia.

Llamada por valor
^^^^^^^^^^^^^^^^^

Cuando pasamos un argumento a una función, crea una copia de forma
predeterminada. Por ejemplo, la siguiente función incrementa x pero no
visiblemente para el mundo exterior:

.. code:: c++

    void incremento (int x) 
    { 
        x++; 
    } 
    
    int main() 
    { 
        int i= 4; 
        incremento(i);        // No incrementa i 
        cout ≪ "i es " ≪ i ≪ '\n'; 
    
    } 

El resultado es 4. La operación ``x++`` solo incrementa una copia local
de ``i`` dentro de la función de incremento, pero no ``i`` en sí. Este
tipo de transferencia de argumentos se conoce como ``llamada por valor``
o ``paso por valor``.

Llamada por Referencia
^^^^^^^^^^^^^^^^^^^^^^

Para modificar los parámetros de la función, tenemos que pasar el
argumento por referencia:

.. code:: c++

    void incremento ( int & x) 
    { 
       x ++; 
    } 

Ahora, la variable en sí se incrementa y el resultado será 5 como se
esperaba. Discutiremos las referencias con más detalle cuando veamos
punteros y arreglos.

Las variables temporales, como el resultado de una operación, no se
pueden pasar por referencia:

.. code:: c++

    incremento (i+ 9); // Error: temporal no referible  

Para pasar la expresión a esta función, debemos almacenarla en una
variable por adelantado y pasar esa variable. Obviamente, modificar
funciones en variables temporales no tiene sentido de todos modos ya que
nunca vemos el impacto de la modificación.

Las estructuras de datos más grandes, como vectores y arreglos, casi
siempre se pasan por referencia para evitar costosas operaciones de
copia.

Argumentos predeterminados
^^^^^^^^^^^^^^^^^^^^^^^^^^

Si un argumento suele tener el mismo valor, podemos declararlo con un
valor predeterminado. Digamos que implementamos una función que calcula
la raíz enésima y principalmente la raíz cuadrada, entonces podemos
escribir:

.. code:: c++

    double raiz  (double x, int grado = 2) {...}  


Esta función se puede llamar con uno o dos argumentos:

.. code:: c++

    x= raiz(3.5, 3);

.. code:: c++

    y= raiz(7.0); // como raíz(7.0,  2)  

Podemos declarar múltiples valores predeterminados pero solo al final de
la lista de parámetros. En otras palabras, después de un argumento con
un valor predeterminado no podemos tener uno sin ese valor.

Los valores predeterminados también son útiles cuando se agregan
parámetros adicionales. Supongamos que tenemos una función que dibuja
círculos:

.. code:: c++

    dibuja_circulos(int x, int y, float radio);  

Estos círculos son todos negros. Luego agregamos un color:

.. code:: c++

    dibuja_circulos(int x, int y, float radio , color c= black);  

Gracias al argumento predeterminado, no necesitamos
`refactorizar <https://www.ionos.es/digitalguide/paginas-web/desarrollo-web/que-es-la-refactorizacion/>`__
la aplicación ya que las llamadas a dibuja_circulos con tres argumentos
aún funcionan.

Retornando resultados
~~~~~~~~~~~~~~~~~~~~~

En los ejemplos anteriores, solo devolvimos ``double`` o ``int``. Estos
son tipos ``return`` de buen comportamiento. Ahora veremos los extremos:
muchos datos o ningún dato.

Estructuras de datos grandes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Las funciones que calculan nuevos valores de grandes estructuras de
datos son más difíciles. La buena noticia es que los compiladores son lo
suficientemente inteligentes como para omitir la copia del valor de
retorno en muchos casos. Además, la `semántica de
movimiento <https://saturncloud.io/blog/what-is-move-semantics/>`__
donde se roban datos de temporales evita copias cuando no se aplica la
omisión antes mencionada.

Las bibliotecas avanzadas evitan por completo devolver grandes
estructuras de datos con una técnica llamada `expression
templates <https://en.wikipedia.org/wiki/Expression_templates>`__ y
retrasan el cálculo hasta que se sabe dónde almacenar el resultado. En
cualquier caso, no debemos devolver referencias a variables de funciones
locales.

No devolver nada
^^^^^^^^^^^^^^^^

Sintácticamente, cada función debe devolver algo incluso si no hay nada
que devolver. Este dilema se resuelve mediante el tipo denominado
``void``.

Por ejemplo, una función que simplemente imprime ``x`` no tiene
resultado:

.. code:: c++

    void print_x(int x)  
    {  
        std::cout ≪ "El valor x es " ≪ x ≪ '\n';  
    
    }  

``void`` no es un tipo real, sino más bien un marcador de posición que
nos permite omitir el retorno de un valor. No podemos definir objetos
``void``:

.. code:: c++

    void  nothing; // Error: no hay objetos void  

Una función ``void`` se puede terminar antes:

.. code:: c++

    double dos_norm ( const vector & v ) { ... }
    
    void _computacion ( const vector & x , double eps , vector & y ) 
    { 
        for (...) { 
            ... 
            if ( dos_norm ( y ) < eps ) 
                   return ; 
    
        } 
    } 

con ``return`` sin argumentos. Devolver algo en una función ``void``
sería un error. Lo único que puede aparecer en una declaración de
``return`` es la llamada de otra función ``void`` (como un atajo de la
llamada más un ``return`` vacío).

Inlining
~~~~~~~~

Llamar a una función es relativamente costoso: se deben almacenar los
registros, copiar los argumentos en la pila, etc. Para evitar esta
sobrecarga, el compilador puede llamar a funciones ``inline``. En este
caso, la llamada a la función se sustituye por las operaciones
contenidas en la función.

El programador puede pedirle al compilador que lo haga con la palabra
clave adecuada:

.. code:: c++

    inline double cuadrado ( double x ) { return x* x ; } 

Sin embargo, el compilador no está obligado a incorporarlo. Por el
contrario, puede incorporar funciones sin la palabra clave si esto
parece prometedor para el rendimiento.

La declaración ``inline`` todavía tiene su uso: para incluir una función
en múltiples unidades de compilación.

Sobrecarga
~~~~~~~~~~

En C++, las funciones pueden compartir el mismo nombre siempre que sus
declaraciones de parámetros sean suficientemente diferentes. Esto se
llama
`sobrecarga <https://www.programiz.com/cpp-programming/function-overloading>`__
de funciones. Veamos primero un ejemplo:

.. code:: c++

    # include <iostream> 
    # include <cmath> 
    
    int dividir ( int a , int b) { 
         return a / b ; 
    
    } 
    float dividir ( float a , float b) { 
         return std :: floor ( a / b ) ; 
    
    } 
    
    int main () { 
        int x= 5, y= 2; 
        float n= 5.0 , m = 2.0; 
        std :: cout << dividir (x , y ) << std :: endl ; 
        std :: cout <<dividir (n , m ) <<  std :: endl ; 
        std :: cout <<dividir (x , m ) <<  std :: endl ;  // Error: ambiguo  
    
    } 

Aquí definimos la función ``dividir`` dos veces: con parámetros ``int``
y ``float``. Cuando llamamos a ``dividir``, el compilador realiza una
resolución de sobrecarga (`overload
resolution <https://www.ibm.com/docs/en/i/7.5?topic=only-overload-resolution-c>`__):

1. ¿Existe una sobrecarga que coincida exactamente con los tipos de
   argumento? Tómalo; de lo contrario:
2. ¿Existen sobrecargas que coincidan después de la conversión?
   ¿Cuántos?

   -  ``0``: Error: No se encontró ninguna función coincidente.
   -  ``1``: Tómalo.
   -  ``> 1``: Error: llamada ambigua.

¿Cómo se aplica esto al ejemplo? Las llamadas ``dividir(x, y)`` y
``dividir(n, m)`` son coincidencias exactas. Para ``dividir (x, m)``,
ninguna sobrecarga coincide exactamente y ambas mediante conversión
implícita, por lo que es ambigua.

El término conversión implícita (implicit conversion) requiere alguna
explicación.

Ya hemos visto que los tipos numéricos del lenguaje se pueden convertir
entre sí. Estas son conversiones implícitas como se demuestra en el
ejemplo. Cuando luego definimos nuestros propios tipos, podemos
implementar una conversión de otro tipo a él o, por el contrario, de
nuestro nuevo tipo a uno existente.

En términos más formales, las sobrecargas de funciones deben diferir en
su firma. En C++, la firma consta de

-  El nombre de la función;
-  El número de argumentos, llamado Arity; y
-  Los tipos de argumentos (en su orden respectivo).

Por el contrario, las sobrecargas que varían sólo en el tipo de return o
en los nombres de los argumentos tienen la misma firma y se consideran
redefiniciones (prohibidas):

::

   void f ( int x ) {} 
   void f(int y) {} // Redefinición: solo el nombre del argumento es diferente 
   long f(int x) {} // Redefinición: solo el tipo de retorno es diferente  

No hace falta decir que las funciones con diferentes nombres o aridades
son distintas. La presencia de un símbolo de referencia convierte el
tipo de argumento en otro tipo de argumento (por lo tanto, ``f(int)`` y
``f(int&)`` pueden coexistir).

Las tres sobrecargas siguientes tienen firmas diferentes:

::

   void f ( int x ) {} // #1 
   void f ( int & x ) {} // #2 
   void f ( const int & x ) {} // #3 

Este fragmento de código se compila. Sin embargo, surgirán problemas
cuando llamemos a ``f``:

::

   int   i= 3; 
   const int ci= 4; 
   f(i); 
   f(ci); 
   f(3);  

Escribe un programa en C++ a partir de la información anterior.

.. code:: c++

    // Tu respuesta

Como las tres llamadas a funciones son ambiguas: para la primera
llamada, ``#1`` y ``#2`` son coincidencias iguales, y para las otras
llamadas ``#1`` y ``#3``. Combinar sobrecargas de argumentos de
referencia y valor casi siempre falla. Por lo tanto, cuando una
sobrecarga tiene un argumento calificado por referencia, el argumento
correspondiente de las otras sobrecargas también debe estar calificado
por referencia.

Implementa una nueva versión omitiendo la sobrecarga de argumentos de
valor de manera que ``f(3)`` y ``f(ci)`` se resolverán con la sobrecarga
con la referencia constante y ``f(i)`` con una mutable (no constante).

.. code:: c++

    // Tu respuesta

La función main
~~~~~~~~~~~~~~~

La función ``main`` no es fundamentalmente diferente de cualquier otra
función. Hay dos firmas permitidas en el estándar:

.. code:: c++

    int main()  

o:

.. code:: c++

    int main(int argc, char* argv[])  

Este último equivale a:

.. code:: c++

    int main(int argc, char** argv)  


El parámetro ``argv`` contiene la lista de argumentos y ``argc`` su
longitud. El primer argumento (``argv[0]``) es en la mayoría de los
sistemas el nombre del ejecutable llamado (que puede ser diferente del
nombre del código fuente). Para jugar con los argumentos, podemos
escribir un programa corto llamado ``argc_argv_test``:

.. code:: c++

    int main ( int argc , char * argv []) 
    { 
    
       for ( int i = 0; i < argc ; ++ i) 
          cout << argv [i] <<'\n'; 
       return 0; 
    
    } 

Llamar a este programa con las siguientes opciones:

.. code:: c++

    argc_argv_test primero segundo tercero cuarto

Produce:

.. code:: c++

    primero 
    segundo  
    tercero  
    cuatro  

Como puedes ver, cada espacio en el comando divide los argumentos. La
función ``main`` devuelve un número entero como código de salida que
indica si el programa finalizó correctamente o no. Devolver 0 (o la
macro ``EXIT_SUCCESS`` de ``<cstdlib>``) representa el éxito y cualquier
otro valor es un fracaso.

Se cumple con los estándares omitir la declaración return en la función
``main``. En este caso, ``return 0`` se inserta automáticamente.

Ejercicios
~~~~~~~~~~

1. Escribe un programa que reciba desde el teclado y muestre en pantalla
   las primitivas como ``char``, ``short integer``, ``long integer``,
   ``float``, ``double``, ``long double`` y ``string`` usando
   ``scanf()/ printf()`` así como ``cin/ cout``.

2. ``145`` es un número curioso, ¡como el
   ``1! + 4! + 5! = 1 + 24 + 120 = 145``. Escribe un programa para
   encontrar todos los números hasta ``10000`` que son iguales a la suma
   del factorial de sus dígitos.

3. La secuencia de Fibonacci está definida por la relación de
   recurrencia:

   ::

      F(n)= F(n-1 ) + F(n-2), donde F(1) = 1 y F(2) = 1.

   Por tanto los primeros ``12`` términos serán:

::

   F(1) = 1
   F(2) = 1
   F(3) = 2
   F(4) = 3
   F(5) = 5
   F(6) = 8
   F(7) = 13
   F(8) = 21
   F( 9 ) = 34
   F(10) = 55
   F(11) = 89
   F(12) = 144

El duodécimo término, ``F(12 )``, es el primer término que contiene tres
dígitos. Escribe un programa para encontrar el índice del primer término
de la secuencia de Fibonacci que contenga 10 dígitos?

4. Escribe un programa que tenga una función ``encontrarMax()`` que
   reciba un número variable de argumentos y encuentre y devuelva el
   máximo de ellos.

.. code:: c++

    // Tus respuestas

Manejo de errores
-----------------

``Un error no se convierte en error hasta que te niegas a corregirlo``
—-> Orlando Aloysius Battista

Las dos formas principales de abordar comportamientos inesperados en C++
son las ``aserciones`` y las ``excepciones``. El primero está destinado
a detectar errores de programación y el segundo a situaciones
excepcionales que impidan la correcta continuación del programa. Para
ser honesto, la distinción no siempre es obvia.

Aserciones
~~~~~~~~~~

La macro ``assert`` del encabezado ``<cassert>`` se hereda de C pero
sigue siendo útil. Evalúa una expresión y, cuando el resultado es
``false``, el programa finaliza inmediatamente.

Debe usarse para detectar errores de programación.

Digamos que implementamos un algoritmo que calcula la raíz cuadrada de
un número real no negativo. Entonces sabemos por las matemáticas que el
resultado no es negativo. De lo contrario, algo anda mal en el cálculo:

.. code:: c++

    # include < cassert > 
    
    double raiz_cuadrada ( double x ) 
    { 
        verificar_algo ( x >= 0); 
        ... 
        assert(resultado >= 0.0); 
        return resultado 

La forma de implementar el control inicial queda abierta por el momento.
Cuando el resultado es negativo, la ejecución del programa imprimirá un
error como este:

.. code:: c++

    assert_test : assert_test . cpp :10: double raiz_cuadrado ( double ): 
    Assertion ' resultado >= 0 . 0 ' failed 

La aserción requiere que el resultado sea mayor o igual a cero, de lo
contrario, la implementación contiene un error y debemos solucionarlo
antes de utilizar esta función para aplicaciones serias.

Después de solucionar el error, es posible que tengamos la tentación de
eliminar las aserciones. No deberíamos hacerlo.

Quizás algún día cambiemos la implementación, entonces todavía tenemos
todas las pruebas funcionando. En realidad, las aserciones sobre
`post-condiciones <https://stackoverflow.com/questions/28416392/pre-conditions-and-post-condition-in-c>`__
son de alguna manera como pruebas de pequeñas unidades.

Una gran ventaja de ``assert`` es que podemos dejarlo desaparecer por
completo mediante una simple declaración de macro. Antes de incluir
``<cassert>`` podemos definir ``NDEBUG``:

.. code:: c++

    # define NDEBUG 
    
    # include < cassert > 

y todas las aserciones están deshabilitadas; es decir, no provocan
ninguna operación en el ejecutable.

En lugar de cambiar las fuentes del programa cada vez que cambiamos
entre el modo de depuración y el modo de lanzamiento, es mejor y más
limpio declarar ``NDEBUG`` en los indicadores del compilador
(generalmente -D en Linux y /D en Windows)

.. code:: c++

    g ++ my_app . cpp -o my_app -O3 - DNDEBUG 

El software con aserciones en núcleos críticos puede ralentizarse en un
factor de dos o más cuando las aserciones no están deshabilitadas en el
modo de lanzamiento. Los buenos sistemas de compilación como
`CMake <https://cmake.org/>`__ activan ``-DNDEBUG`` automáticamente en
los indicadores de compilación del modo de lanzamiento.

Dado que las aseveraciones se pueden desactivar tan fácilmente, debemos
seguir este consejo:

**Programación defensiva: Prueba tantas propiedades como pueda.**

Los programadores responsables implementan grandes conjuntos de pruebas.
Sin embargo, esto no es garantía de que el programa funcione en todas
las circunstancias.

Una aplicación puede funcionar durante años a las mil maravillas y un
día falla. En esta situación, podemos ejecutar la aplicación en modo
depuración con todas las aserciones habilitadas y en la mayoría de los
casos serán de gran ayuda para encontrar el motivo del fallo. Sin
embargo, esto requiere que la situación de falla sea reproducible y que
el programa en modo de depuración más lento alcance la sección crítica
en un tiempo razonable.

Excepciones
~~~~~~~~~~~

Las aserciones nos ayudan a detectar errores de programación. Sin
embargo, hay muchas situaciones críticas que no podemos evitar ni
siquiera con la programación más inteligente, como archivos que
necesitamos leer pero que se eliminan. O que un programa necesita más
memoria de la que está disponible en la máquina real. Otros problemas se
pueden prevenir en teoría, pero el esfuerzo práctico es
desproporcionadamente alto, por ejemplo, comprobar si una matriz es
regular es factible. En tales casos, suele ser más eficaz intentar
realizar la tarea y comprobar si hay excepciones a lo largo del camino.

Antes de ilustrar el manejo de errores a la antigua, presentamos a un
antihéroe ``CBurro``, que es un matemático ingenioso y considera la
programación como un mal necesario para demostrar cuán magníficamente
funcionan sus algoritmos. Es inmune a las novedosas tonterías de la
programación moderna.

Su enfoque favorito para abordar problemas computacionales es devolver
un código de error (como lo hace la función ``main``). Digamos que
queremos leer una matriz de un archivo y comprobar si el archivo
realmente está allí. Si no, devolvemos un código de error de ``1``:

.. code:: c++

    int leer_archivo_matriz(const char* fnombre, matrix &A )  
    {  
          fstream f(fnombre);  
          if (!f.is_open())  
            return 1;  
            ...
    
          return 0;  
    
    }  

Entonces, verificó todo lo que pudiera salir mal e informó con el código
de error apropiado. Esto está bien cuando se evaluó el error y se
reaccionó apropiadamente. Pero, ¿qué sucede cuando simplemente se ignora
su código de retorno? ¡Nada! El programa continúa y podría colapsar más
adelante debido a datos absurdos, o peor aún, podría producir resultados
sin sentido que personas descuidadas podrían utilizar para construir
automóviles o aviones.

Sin embargo, trasladar este razonamiento a dinosaurios programadores
como CBurro podría no convencerlos.

Podemos obtener un poco más de seguridad con C++17. C++ 17 introduce el
atributo ``[[nodiscard]]`` para indicar que el valor de retorno no debe
descartarse:

.. code:: c++

    [[ nodiscard ]] int leer_archivo_matriz ( const char * fnombre , matrix & A ) 

Como consecuencia, cada llamada que ignore el valor de retorno provocará
una advertencia y con un indicador del compilador adicional podemos
convertir cada advertencia en un error. Por otro lado, también podemos
suprimir esta advertencia con otro indicador del compilador.

Por lo tanto, el atributo no nos garantiza que se utilice el código de
retorno. Además, simplemente almacenar el valor de retorno en una
variable ya cuenta como uso, independientemente de si volvemos a tocar
esta variable.

Una desventaja adicional de los códigos de error es que no podemos
devolver los resultados computacionales y tenemos que pasarlos como
argumentos de referencia. Esto nos impide construir expresiones con el
resultado. La forma inversa es devolver el resultado y pasar el código
de error como un argumento de función (referido), lo cual no es mucho
menos engorroso.

Throwing
^^^^^^^^

El mejor enfoque para solucionar los problemas es lanzar un exceptión.

.. code:: c++

    matrix leer_archivo_matriz(const std::string& fnombre)  
    {  
    
            fstream f(fnombre);  
            if (!f.is_open()) 
            throw "No se puede abrir el archivo.";  
            ... 
    
     }  

C++ nos permite usar ``throw`` como excepción: cadenas, números, tipos
de usuarios, etc. Sin embargo, para tratar las excepciones correctamente
es mejor definir tipos de excepción o utilizar los de la biblioteca
estándar:

.. code:: c++

    struct no_puedes_abrir_archivo{};  
    
    matrix leer_archivo_matriz(const std::string& fnombre)  
    
    {  
        fstream f(fnombre);  
        if (!f.is_open()) 
            throw no_puedes_abrir_archivo{} ;      
        matrix  A; // completar A con datos (posiblemente lanzar una excepción)  
    
        return A; 
     } 

Aquí, introdujimos nuestro propio tipo de excepción. Luego, explicaremos
en detalle cómo se pueden definir las clases.

En el ejemplo anterior, definimos una clase vacía que solo requiere
llaves de apertura y cierre seguidas de un punto y coma. Los proyectos
más grandes suelen establecer una jerarquía completa de tipos de
excepciones que normalmente se derivan de ``std::exception``.

Captura
^^^^^^^

Para reaccionar ante una excepción, tenemos que detectarla. Esto se hace
en un bloque ``try-catch``. En el ejemplo lanzamos una excepción para un
archivo que no pudimos abrir, que podemos detectar ahora:

.. code:: c++

    try { 
        A = leer_archivo_matriz(" no_existe . dat " ); 
       } catch ( const no_puedes_abrir_archivo & e ) { 
    
         { // Aquí podemos solucionarlo
    
       }  

Podemos escribir múltiples cláusulas ``catch`` en el bloque para manejar
diferentes tipos de excepciones en una ubicación. Discutir esto en
detalle tiene mucho más sentido después de introducir las clases y la
herencia.

Manejo de excepciones
^^^^^^^^^^^^^^^^^^^^^

El manejo más sencillo es delegarlo al que llama. También podemos
detectar la excepción, proporcionar un mensaje de error informativo y
finalizar el programa:

.. code:: c++

    try { 
        A = leer_archivo_matriz(" no_existe . dat " ); 
       } catch ( const no_puedes_abrir_archivo & e ) { 
         cerr << " Hey  tu archivo no existe .\ n " ; 
        exit ( EXIT_FAILURE ) ; 
       } 

Una vez que se detecta la excepción, se considera que el problema está
resuelto y la ejecución continúa después de los bloques ``catch``.

Para finalizar la ejecución, utilizamos la salida desde el encabezado
``<cstdlib>``. La función ``exit`` finaliza la ejecución incluso cuando
no estamos en la función ``main``. Solo debe usarse cuando una ejecución
posterior es demasiado peligrosa y tampoco hay esperanzas de que las
funciones que llaman tengan alguna solución para la excepción.

Alternativamente, podemos continuar después de la queja o de una acción
de rescate parcial volviendo a lanzar la excepción, lo que podría
tratarse más adelante:

.. code:: c++

    try { 
    
        A = leer_archivo_matriz(" no_existe . dat " ); 
       } catch ( const no_puedes_abrir_archivo & e ) { 
         cerr <<"  El archivo no está aquí. Que el llamador me ayude\ n " ; 
         throw 
    
      } 

En este caso, ya estamos en la función ``main`` y no hay otra función en
la pila de llamadas para detectar la excepción. Ignorar una excepción se
implementa fácilmente mediante un bloque vacío:

.. code:: c++

    catch ( const no_puedes_abrir_archivo & e ) // El archivo es basura 

Hasta ahora, el manejo de excepciones no resolvió realmente el problema
de perder un archivo. Si el nombre del archivo lo proporciona un
usuario, podemos molestarlo hasta que consigamos uno que funcione:

.. code:: c++

    bool sigue_probando = true ; 
    do { 
        std :: string fnombre ; 
        cout << " Ingresa el archivo de nombres : " ; 
        cin >> fnombre ; 
    
    try { 
        A = leer_archivo_matriz (fnombre); 
         ... 
        sigue_probando = false ; 
    
         }catch ( const no_puedo_abrir_archivo & e ) { 
            cout << " No se pudo abrir el archivo. Prueba otro !\ n " ; 
      } 
    
    } while ( sigue_probando ); 

Cuando llegamos al final del bloque ``try`` sabemos que no se lanzó
ninguna excepción y podemos dar por terminado el día. De lo contrario
aterrizamos en uno de los bloques ``catch`` y ``sigue_probando`` sigue
siendo ``true``.

Ventajas de las excepciones
~~~~~~~~~~~~~~~~~~~~~~~~~~~

El manejo de errores es necesario cuando un programa se topa con un
problema que no se puede solucionar donde se detecta. Por lo tanto,
debemos comunicar esto a la función que llama con la esperanza de que el
problema detectado pueda resolverse o al menos tratarse de una manera
que sea aceptable para el usuario.

Teniendo esto en cuenta, las excepciones tienen las siguientes ventajas
sobre los códigos de error:

-  Las interfaces de funciones son más claras.
-  Devolver resultados en lugar de códigos de error permite anidar
   llamadas a funciones.
-  Los errores no tratados abandonan inmediatamente la aplicación en
   lugar de continuar silenciosamente con datos corruptos.
-  Las excepciones se propagan automáticamente a la pila de llamadas.
-  La comunicación explícita de códigos de error confunde la estructura
   del programa.

Un ejemplo de práctica se refiere a una factorización LU. No se puede
calcular para una matriz singular. No hay nada que podamos hacer al
respecto. Sin embargo, en el caso de que la factorización fuera parte de
un cálculo iterativo, pudimos continuar la iteración de alguna manera
sin esa factorización. Aunque esto también sería posible con el manejo
de errores tradicional, las excepciones nos permiten implementarlo de
manera mucho más legible y elegante.

Podemos programar la factorización para el caso regular y cuando
detectamos la singularidad, lanzamos una excepción. Entonces depende de
quien llama cómo lidiar con la singularidad en el contexto respectivo,
si es posible.

C++ 11 agregó una nueva calificación para especificar que no se deben
eliminar excepciones de la función, por ejemplo:

.. code:: c++

    double raiz_cuadrada(double x) noexcept { ... } 

El beneficio de esta calificación es que el código de llamada nunca
necesita verificar las excepciones lanzadas después de
``raíz_cuadrada``. Si se produce una excepción a pesar de la
calificación, el programa finaliza.

Aserciones estáticas
~~~~~~~~~~~~~~~~~~~~

Los errores de programa que ya se pueden detectar durante la compilación
pueden generar un ``static_assert``. En este caso, se emite un mensaje
de error y se detiene la compilación.

.. code:: c++

    static_assert(sizeof(int) >= 4,  
          "int es demasiado chico en esta plataforma para 70000");  
    
     const int capacidad = 70000;  

En este ejemplo, almacenamos el valor literal 70000 en un ``int``. Antes
de hacer esto, verificamos que el tamaño de ``int`` sea lo
suficientemente grande en la plataforma para la que se compila este
fragmento de código para mantener el valor correctamente.

Todo el poder de ``static_assert`` se desata con la
`metaprogramación <https://en.wikipedia.org/wiki/Template_metaprogramming>`__.

Ejercicios
~~~~~~~~~~

1. Escribe un programa en C++ para calcular la raíz cuadrada de un
   número. Se debe probar la validez del valor de entrada. Si es
   negativo, ¿la función definida por el usuario ``raiz_cuadrada()``
   debería generar una excepción?

2. Escribe un programa en C++ que divida dos números complejos.
   Sobrecargue el operador de división (/). ¿Puede este programa manejar
   casos como la división por cero usando excepciones?

3. ¿Cuál es el resultado del siguiente código C++?

   ::

      #include <iostream>
      using namespace std;
      int main()
      {
          int var = -12;
          try {
              cout<<"en  try\n";
              if (var < 0)
              {
                  throw var;
                  cout<<"despues throw\n";
          }
       }
       catch (int var ) {
          cout<<"Excepcion Caught\n";
        }
          cout<<"despues de catch\n";
          return 0;
      }

4. ¿Cuál es el resultado del siguiente código C++?

   ::

      #include <iostream>
      using namespace std;
      int main()
      {
       try
       {
         try
            {
              throw 20;
             }
             catch (int n)
             {
                 cout << "Catch interno\n";
             }
       }
      catch (int x)
      {

         cout << "Catch externo\n";
      }
         return 0;

5. ¿Cuál es el resultado del siguiente código C++?

::

     #include <iostream>
     using namespace std;
     
     void Division(const double a, const double b);
     
     int main()
     {
         double op1=0, op2=10;
     try
     {
         Division(op1, op2);
     }
     catch (const char* Str)
     {
         cout << "\nMal operator: " << Str;
     }
         return 0;
     }

     void Division(const double a, const double b)
     {
         double res;
         if (b == 0)
             throw "Division por cero no esta permitida";
         res = a / b;
         cout << res;
     }
     

.. code:: c++

    // Tus respuestas

Referencias
~~~~~~~~~~~

-  Discovering Modern C++ An Intensive Course for Scientists, Engineers,
   and Programmers Peter Gottschling. Second Edition. 2022 Pearson
   Education, Inc.
-  C++ crash course : a fast-paced introduction / Josh Lospinoso. First
   edition. San Francisco, CA : No Starch Press, Inc.2019

Fundamentos de Programación
===========================

La programación es algo que se ha convertido en parte de nuestra vida
cotidiana a tal manera que nos resulta natural que está presente en
nuestros teléfonos inteligentes, computadoras, televisores, automóviles,
etc.

La programación competitiva es una herramienta para los ingenieros de
software o todo profesional de Ciencias de la Computación pues ayuda a
mejorar las habilidades para resolver problemas relacionados con los
algoritmos.

Concursos de Programación
^^^^^^^^^^^^^^^^^^^^^^^^^

Una olimpiada de Informática consiste en resolver diferentes problemas
utilizando lógica y computadoras. Cada país organiza preliminares y un
concurso nacional, luego seleccionan a cuatro estudiantes para
participar en la Olimpiada Internacional de Informática que se realiza
cada año. El siguiente
`enlace <http://www.ioinformatics.org/history.shtml>`__ contiene los
resultados, problemas y soluciones de todos los concursos que se han
realizado desde 1989.

Para los estudiantes universitarios existe el
`ACM-ICPC <https://icpc.global/>`__. Aquí, cada equipo consta de tres
estudiantes y un entrenador.

Jueces en línea
^^^^^^^^^^^^^^^

Los jueces en línea son sitios web donde puedes encontrar problemas de
diferentes categorías y enviar su solución, que luego se evalúan
comparándolo con las entradas y salidas de las pruebas y dar un
resultado.

Algunos de los jueces en línea más populares son:

-  `Leetcode <https://leetcode.com/>`__. Uno de los sitios más populares
   para capacitarse para entrevistas de trabajo en las principales
   empresas tecnológicas. Contiene problemas de diferentes categorías.

-  `Project Euler <https://projecteuler.net/>`__. Enfocado a las
   matemáticas, no es necesario enviar un código fuente, solo la
   respuesta al problema.

-  `Codeforces <https://codeforces.com/>`__. Uno de los mejores jueces
   en línea para practicar, contiene problemas de diferentes categorías
   y con frecuencia programa competencias. También hay excelentes
   tutoriales y debates sobre soluciones.

-  `UVA Online Judge <https://onlinejudge.org/index.php>`__. Aquí puede
   encontrar problemas de cualquier tipoy hay más de 4000 problemas para
   elegir.

-  `Hacker Rank <https://www.hackerrank.com/>`__. Un juez en línea para
   comenzar a codificar, tienen un camino para que pueda comenzar con
   problemas fáciles y luego pasar a los más complicados.

-  `CodeChef <https://www.codechef.com/>`__. Esta plataforma es útil
   para preparar a los estudiantes para competencias de programación y
   para que los profesionales mejoren sus habilidades de codificación.
   Tiene una gran comunidad de desarrolladores y soporta más de 50
   lenguajes de programación.

-  `Topcoder <https://www.topcoder.com/>`__. Contiene tutoriales que
   explican con gran detalle diferentes algoritmos. Al resolver un
   problema los puntos obtenidos al resolverlo disminuyen a medida que
   pasa el tiempo, por lo que si deseas mejorar tu velocidad de
   codificación, este es el lugar correcto.

-  `Omega UP <https://omegaup.com/>`__. Excelente herramienta para
   enseñar programación de computadoras. Es muy fácil crear tus propios
   problemas y también hay una gran base de datos de problemas para
   resolver.

C y C++
~~~~~~~

C++ es un lenguaje rápido que otros lenguajes como Java o Python
utilizado en las competencias de programación donde podemos implementar
estructuras de datos más complejas, manipular cadenas, usar algoritmos
predefinidos, etc.

Hay algunas ocasiones usamos funciones C para leer los datos de entrada
y escribir los datos de salida. C++ tiene a ``cin`` y ``cout`` para
manejar la entrada y salida respectivamente, pero son lentos en
comparación con las funciones de C ``scanf`` y ``printf``.

Aun así, las funciones de C++ se pueden optimizar agregando las
siguientes líneas al comienzo de la función ``main``

::

   cin.tie(0);  
   ios_base::sync_with_stdio(0); 

Revisar:`Significance of ios_base::sync_with_stdio(false);
cin.tie(NULL); <https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull>`__.

Utilizaremos C++ en todo este curso

Recursividad
------------

``Primero, resuelve el problema. Luego, escribe el código`` –>
``John Johnson``

La recursividad es una herramienta muy poderosa y muchos de los
algoritmos contenidos en este la usan. Es por eso que decidimos agregar
una breve descripción del mismo.

Cuando se llama a una función dentro de la misma función, decimos que
esta función es una función recursiva. Supongamos que hay una función
:math:`f(n)`, que devuelve el factorial de un número dado n. Lo sabemos:

::

   f(0) = 1
   f(1) = 1
   f(2) = 1 x 2   
   f(3) = 1 x 2 x 3 = f(2) x f(3)
   ...
   f(n) = 1 x 2 x 3...f(n) = f(n-1) x n  


Vemos que el factorial de n se obtiene multiplicando n por el factorial
de n - 1, y el factorial de n - 1 se obtiene por el factorial de n -2, y
así hasta llegar a 0!. Entonces decimos que 0! es el **caso base**, ya
que es el que genera el resto de los factoriales. Si vemos esto como una
función recursiva, se vería como:

.. code:: c++

    int f(unsigned int n) {
        if (n == 0) {
            return 1;
      }
        return n * f(n - 1);
    }

La validación para verificar si n es cero es crítica, porque sin ella la
recursividad nunca se detendría y la memoria de nuestra computadora
eventualmente colapsaría. Cada vez que se llama recursivamente a una
función, toda la memoria que usa se almacena en un **heap**, y esa
memoria se libera hasta que finaliza la función. Por eso es
indispensable agregar una condición de parada y evitar terminar en un
proceso *infinito*.

Resumiendo, hay dos partes fundamentales que toda función recursiva debe
tener:

1. La función debe llamarse a sí misma dentro de la función.

2. Se debe dar una condición de parada o caso base para evitar un
   proceso infinito.

Dos tipos de recursión
~~~~~~~~~~~~~~~~~~~~~~

**PROBLEMA: ¿Cuantos loritos tenemos?**

Los pasajeros del Ferrocarril Tropical Paradise (TPR) esperan ver
docenas de coloridos loritos desde las ventanas del tren. Debido a esto,
el ferrocarril se interesa mucho en la salud de la población local de
loritos y decide hacer un recuento de la cantidad de loritos a la vista
de cada andén a lo largo de la línea principal. Cada plataforma cuenta
con un empleado de TPR (consulta la figura ), que es capaz de
contar loritos. Desafortunadamente, el trabajo se complica por el
primitivo sistema telefónico. Cada plataforma puede llamar sólo a sus
vecinos inmediatos. ¿Cómo obtenemos el total de loritos en la terminal
de la línea principal?

.. image:: Imagenes/Semana1/Recursividad1.png

Los empleados de las cinco estaciones solo pueden comunicarse con sus
vecinos inmediatos.

Supongamos que hay 7 loritos de Art en la terminal principal, 5 loritos
con Belinda, 3 loritos con Cory, 10 loritos con Debbie y 2 loritos con Evan
en la última estación. El número total de loritos es entonces 27.

La pregunta es, ¿cómo van a trabajar juntos los empleados para comunicar
este total a Art?

Cualquier solución a este problema requerirá una cadena de
comunicaciones desde la terminal principal hasta el final de la línea y
viceversa. Se le pedirá al miembro del personal en cada plataforma que
cuente los loritos y luego informe sus observaciones.

Aun así, hay dos enfoques distintos para esta cadena de comunicaciones,
y esos enfoques corresponden a las técnicas de recursión dados en esta
clase.

**Enfoque 1**

En este enfoque, mantenemos un total acumulado de los loritos a medida
que avanzamos en las comunicaciones salientes entre estaciones. Cada empleado, al hacer
la solicitud del siguiente empleado en la línea, pasa la cantidad de
loritos vistos hasta el momento. Cuando se llega al final, Evan será el primero 
en descubrir el total de loritos, que pasará a Debbie, quien se lo pasará a Cory
y así sucesivamente (como se muestra en la figura).

.. image:: Imagenes/Semana1/Recursividad2.png

Numeración de los pasos tomados en el Enfoque 1 para el problema de
contar loritos.

1.  ART comienza contando los loritos alrededor de su plataforma. Cuenta
    7 loritos.
2.  ART a BELINDA: “Hay 7 loritos aquí en la terminal principal”.
3.  BELINDA cuenta 5 loritos alrededor de su plataforma para un total
    acumulado de 12.
4.  BELINDA a CORY: “Hay 12 loritos alrededor de las dos primeras
    estaciones”.
5.  CORY cuenta 3 loritos.
6.  CORY a DEBBIE: “Hay 15 loritos alrededor de las tres primeras
    estaciones”.
7.  DEBBIE cuenta 10 loritos.
8.  DEBBIE a EVAN: “Hay 25 loritos alrededor de las primeras cuatro
    estaciones”.
9.  EVAN cuenta 2 loritos y descubre que el número total de loritos es
    27.
10. EVAN a DEBBIE: “El número total de loritos es 27”.
11. DEBBIE a CORY: “El número total de loritos es 27”.
12. CORY a BELINDA: “El número total de loritos es 27.”
13. BELINDA a ART: “El número total de loritos es 27”.

Este enfoque es análogo a la **recursión de cola**. En la recursividad
de cola, la llamada recursiva ocurre después del procesamiento; **la
llamada recursiva es el último paso en la función**.

En la cadena de comunicaciones anterior, ten en cuenta que el “trabajo”
de los empleados, el conteo y la suma de loritos, ocurre antes de que
señalen al siguiente empleado en la línea.

Todo el trabajo ocurre en la cadena de comunicaciones salientes, no en
la cadena entrante. Estos son los pasos que sigue cada empleado:

1. Contar los loritos visibles desde la plataforma de la estación.
2. Agrega este conteo al total dado por la estación anterior.
3. Llama a la siguiente estación para pasar la suma acumulada de conteos
   de loritos.
4. Espera a que la siguiente estación llame con el conteo total de
   loritos y luego pase este total a la estación anterior.

**Enfoque 2**

En este enfoque, sumamos los recuentos de loritos desde el otro extremo.
Cada empleado, al comunicarse con la siguiente estación en la línea,
solicita el número total de loritos desde esa estación en adelante.
Luego, el empleado suma la cantidad de loritos en su propia estación y
pasa este nuevo total por la línea (como se muestra en la figura ).

.. image:: Imagenes/Semana1/Recursividad3.png

Numeración de los pasos tomados en el Enfoque 2 para el problema de
contar loritos.

1.  ART a BELINDA: “¿Cuál es el número total de loritos desde tu
    estación hasta el final de la línea?”
2.  BELINDA a CORY: “¿Cuál es el número total de loritos desde tu
    estación hasta el final de la línea?”
3.  CORY a DEBBIE: “¿Cuál es el número total de loritos desde tu
    estación hasta el final de la línea?”
4.  DEBBIE a EVAN: “¿Cuál es el número total de loritos desde tu
    estación hasta el final de la línea?”
5.  EVAN es el final de la línea. Cuenta 2 loritos.
6.  EVAN a DEBBIE: “El número total de loritos aquí al final es 2”.
7.  DEBBIE cuenta 10 loritos en su estación, por lo que el total desde
    su estación hasta el final es 12.
8.  DEBBIE a CORY: “El número total de loritos desde aquí hasta el final
    es 12”.
9.  CORY cuenta 3 loritos.
10. CORY a BELINDA: “El número total de loritos desde aquí hasta el
    final es 15.”
11. BELINDA cuenta 5 loritos.
12. BELINDA a ART: “El total de loritos de aquí al final es 20”.
13. ART cuenta 7 loritos en la terminal principal, haciendo un total de
    27.

Este enfoque es análogo a la **recursividad de cabecera**. En la
**recursividad de cabecera**, la llamada recursiva ocurre antes que el
otro procesamiento**.

Aquí, la llamada a la siguiente estación ocurre primero, antes de contar
los loritos o la sumatoria. El trabajo se pospone hasta después de que
las estaciones de la línea hayan informado sus totales. Estos son los
pasos que sigue cada empleado:

1. Llama a la siguiente estación.
2. Cuenta los loritos visibles desde el andén de la estación.
3. Agrega este conteo al total dado por la siguiente estación.
4. Pasa la suma resultante a la estación anterior.

**Pregunta** ¿cuales son los efectos prácticos para los diferentes
enfoques?

.. code:: c++

    // Tus respuestas


**Referencia**:A Think like a Think Programmer: An Introduction to Creative Problem Solving, V. Anton Spraul No Starch Press, Inc. 2012.

Paso de soluciones iterativas a recursivas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Escribe una función recursiva a la que se le dé un arreglo de enteros y
el tamaño del arreglo como parámetros. La función devuelve la suma de
los enteros del arreglo.

Empecemos con una solución iterativa a este problema:

.. code:: c++

    int sumaInterativaArray(int enteros[], int tam) {
        int suma = 0;
        for (int i = 0; i < tam; i++) {
            suma += enteros[i];
        }
        return suma;
    }

El siguiente paso es escribir código que esté a mitad de camino entre la
solución iterativa y la solución recursiva final deseada. Mantendremos
la función iterativa y agregaremos una segunda función a la que nos
referiremos como ``delegado``.

El delegado entregará la mayor parte del trabajo a la función iterativa
previamente escrita y usará esta información para resolver el problema
general.

Para escribir un delegado, tenemos que seguir dos reglas:

-  El delegado debe manejar completamente el caso más trivial, sin
   llamar a la función iterativa.
-  El delegado, al llamar a la función iterativa, debe pasar una versión
   más pequeña del problema.

.. code:: c++

    int sumaDelegadaArray(int enteros[], int tam) {
        if (tam == 0) return 0;
        int ultimoNumero = enteros[tam - 1];
        int sumaTodosMenosUno = sumaIterativaArray(enteros, tam - 1);
        return ultimoNumero + sumaTodosMenosUno;
    }

Para convertir esta solución iterativa en una solución recursiva, sólo
se requiere un paso adicional y simple: hacer que la función delegada se
llame a sí misma donde antes llamaba a la función iterativa.

Entonces podemos eliminar la función iterativa por completo.

.. code:: c++

    int sumaRecursivaArray(int enteros[], int tam) {
        if (tam == 0) return 0;
        int ultimoNumero = enteros[tam - 1];
        int sumaTodosMenosUno = sumaRecursivaArray(enteros, tam - 1);
        return ultimoNumero + sumaTodosMenosUno;
    }

Errores comunes
~~~~~~~~~~~~~~~

**Demasiados parámetros**

Considera el problema de calcular recursivamente la suma de un arreglo
de enteros.

Al escribir una solución iterativa a este problema, el programador sabe
que se necesitará una variable de ``total acumulado`` (en la solución
iterativa provista, se llamó ``suma``) y el arreglo se sumará a partir
del primer elemento.

Teniendo en cuenta la solución recursiva, el programador naturalmente
imagina una implementación que refleja más directamente la solución
iterativa, con una variable total acumulada y la primera llamada
recursiva manejando el primer elemento del arreglo.

Este enfoque, sin embargo, requiere que la función recursiva pase el
total acumulado y la ubicación donde debe comenzar a procesarse la
siguiente llamada recursiva. Tal solución se vería así:

::

   int sumaRecursivaArrayExtraParametros(int enteros[], int tam, int suma, int actualIndice) {
       if (actualIndice == tam) return suma;
       suma += enteros[actualIndice];
       return sumaRecursivaArrayExtraParametros(enteros, tam, suma, actualIndice + 1);
   }

Desde el punto de vista del código del cliente, los parámetros
adicionales no tienen sentido y siempre tendrán que ser ceros en la
llamada, como se muestra en este ejemplo:

.. code:: c++

    //int a[10] = {20, 3, 5, 22, 7, 9, 14, 17, 4, 9};
    //int total = sumarecursivaArrayExtraParametros(a, 10, 0, 0);

**Variables globales**

Las variables globales siempre deben evitarse en funciones recursivas
cuando sea posible.Supongamos que se nos pide que escribamos una función
recursiva que cuente el número de ceros que aparecen en un arreglo de
enteros.

Este es un problema simple de resolver usando iteración:

.. code:: c++

    int conteoIterativoCeros(int numeros[], int tam) {
        int suma = 0;
        int conteo = 0;
        for (int i = 0; i < tam; i++) {
            if (numeros[i] == 0) conteo ++;
        }
        return conteo;
    }

No podemos simplemente declarar ``conteo`` como una variable local en la
versión recursiva porque entonces sería una nueva variable en cada
llamada recursiva.

Así que podríamos tener la tentación de declararlo como una variable
global:

::

   int conteo;
   int conteoRecursivoCeros(int numeros[], int tam){
       if (tam == 0) return conteo;
       if (numeros[tam - 1] == 0) conteo++;
       conteoRecursivoCeros(numeros, tam - 1);
   }

Algunos programadores pueden intentar mitigar el problema haciendo que
la variable sea local, pero estática:

::

   int conteoEstaticoCeros(int numeros[], int tam) {
       static int conteo = 0;
       if (tam == 0) return conteo;
       if (numeros[tam - 1] == 0) conteo++;
       conteoEstaticoCeros(numeros, tam - 1);
   }

La solución para evitar la variable global es suponer que una llamada
recursiva con un valor más pequeño para el tamaño devolverá el resultado
correcto y calculará el valor correcto para el arreglo general a partir
de eso.

Esto conducirá a una solución recursiva :

.. code:: c++

    int conteoRecursivoCeros(int numeros[], int tam) {
    if (tam == 0) return 0;
        int conteo = conteoRecursivoCeros(numeros, tam - 1);
        if (numeros[tam - 1] == 0) conteo++;
        return conteo;
    }

Ejercicios
----------

Como siempre, ¡es imperativo probar las ideas presentadas en este
cuaderno!.

1. Escribe una función para calcular la suma de solo los números
   positivos en un arreglo de enteros. Primero, resuelve el problema
   usando iteración. Luego, utilizando alguna técnica de esta clase,
   convierte tu función iterativa en una función recursiva.

2. Considera un arreglo que representa una cadena binaria, donde el
   valor de datos de cada elemento es 0 o 1. Escribe una función
   booleana para determinar si la cadena binaria tiene paridad impar (un
   número impar de 1 bits). Sugerencia: recuerda que la función
   recursiva devolverá true (odd) o false (even), no el recuento de 1
   bits. Resuelve el problema primero usando iteración, luego
   recursividad.

3. Escribe una función a la que se le pase un arreglo de enteros y un
   número “objetivo” y que devuelva el número de ocurrencias del
   objetivo en el arreglo. Resuelve el problema primero usando
   iteración, luego recursividad.

4. Encuentra un problema sobre procesar un arreglo unidimensional que ya
   hayas resuelto o que sea trivial para ti en tu nivel de habilidad
   actual y resuelve el problema (o resuelvas de nuevo) usando
   recursividad.

.. code:: c++

    // Tus respuestas

Los enfoques top-down y bottom-up
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Los algoritmos están diseñados utilizando dos enfoques: el de
``top-down`` y el de ``bottom-up`` . En el enfoque de ``top-down`` un
módulo complejo se divide en submódulos. Por otro lado, el enfoque
``bottom-up`` comienza con módulos elementales que luego se van
combinando más. El propósito apriori de un algoritmo es operar los datos
comprendidos en la estructura de datos. En otras palabras, se utiliza un
algoritmo para realizar operaciones con los datos dentro de las
estructuras de datos.

Un algoritmo complicado se divide en pequeñas partes llamadas módulos y
el proceso de división se conoce como modularización. La modularización
reduce significativamente las complicaciones de diseñar un algoritmo y
hace que su proceso sea más fácil de diseñar e implementar.

El enfoque de ``top-down`` enfatiza el aislamiento de los submódulos
(significa el bajo acoplamiento entre los módulos) mientras ignora la
identificación del concepto de comunicación y reutilización. Mientras
que en el enfoque ``bottom-up``, el ocultamiento de la información y la
reutilización son los factores destacados.

Si cualquier problema se puede dividir en subproblemas, que a su vez se
dividen en subproblemas más pequeños y si hay superposiciones entre
estos subproblemas, entonces las soluciones a estos subproblemas se
pueden guardar para una referencia futura. De esta manera, se puede
mejorar la eficiencia de la CPU.

Este método de resolver una solución se conoce como **programación
dinámica**.

Estos problemas implican calcular repetidamente el valor de los mismos
subproblemas para encontrar la solución óptima, es decir ayuda a
resolver eficientemente una clase de problemas que tienen **subproblemas
superpuestos** y propiedades de **subestructura óptimas**

La programación dinámica es principalmente una optimización sobre la
recursividad. Siempre que veamos una solución recursiva que tenga
llamadas repetidas para las mismas entradas, podemos optimizarla usando
la programación dinámica.

La idea es simplemente almacenar los resultados de los subproblemas, de
modo que no tengamos que volver a calcularlos cuando sea necesario más
adelante. Esta simple optimización reduce las complejidades temporales
de exponencial a polinómica.

Por ejemplo, si escribimos una solución recursiva simple para los
números de Fibonacci, obtenemos una complejidad temporal exponencial y
si la optimizamos almacenando soluciones de subproblemas, la complejidad
temporal se reduce a lineal.

Todo puede implementarse mediante ``memorización (top-down)`` o
``tabulación (bottom-up)``. Si estas interesado más sobre este tema
puedes leer:
https://jarednielsen.com/dynamic-programming-memoization-tabulation/.

Memorización
~~~~~~~~~~~~

La memorización es una forma de mejorar la recursividad. Es una técnica
que consiste en almacenar en memoria valores que ya hemos calculado para
evitar calcularlos de nuevo, mejorando así el tiempo de ejecución del
algoritmo. Hagamos un ejemplo para ver la importancia de usar la
memorización.

Considera la función de recurrencia siguiente, que calcula el n-ésimo
número de Fibonacci. Los primeros dos números de Fibonacci son 1, y el
n-ésimo número de Fibonacci es la suma de los dos números de Fibonacci
anteriores, para :math:`n \geq 2`.

.. code:: c++

    int f(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        
        return f(n - 1) + f(n - 2);
    }


Ahora, supongamos que queremos obtener el quinto número de Fibonacci.

**Pregunta**:Realiza un dibujo explicando, cual es el procedimiento de
recursividad?

.. code:: c++

    // Tu respuesta

Pero si usamos un arreglo para almacenar los valores de todos los
números de Fibonacci ya calculados y usamos esos valores entonces
evitaremos ejecutar las mismas operaciones nuevamente y eso mejorará el
tiempo de ejecución de nuestro código.

Considera el arreglo ``Fibo`` contiene que inicialmente contiene solo 0
y se usará para almacenar los números de Fibonacci. La función de
recursión que usa memorización se vería de la siguiente manera:

.. code:: c++

    int f(int n) {
        if (n == 0 || n == 1) {
            return 1;
    }
    if (Fibo[n] == 0) {
        Fibo[n] = f(n - 1) + f(n - 2);
    }
        return Fibo[n];
    
    }

En el código mostrado anteriormente notamos que solo llamamos a la
función recursiva si el valor de ``Fibo[n]`` es cero, lo que significa
que aún no hemos calculado el n-ésimo número de Fibonacci. De lo
contrario, devolvemos el valor ya calculado almacenado en ``Fibo[n]``.

La **memorización** es un proceso de optimización. En términos simples,
almacenamos los resultados intermedios de las soluciones de
subproblemas, lo que nos permite acelerar el cálculo de la solución
general.

La mejora se puede reducir de una solución de tiempo exponencial a una
solución de tiempo polinómico, con la sobrecarga de utilizar memoria
adicional para almacenar resultados intermedios.

Tabulación
~~~~~~~~~~

La tabulación es un enfoque en el que se resuelve un problema de
programación dinámica llenando primero una tabla y luego calculando la
solución al problema original basándose en los resultados de esta tabla.

Si bien los problemas de programación dinámica, como el cálculo de
Fibonacci, son de naturaleza recursiva, una implementación de tabulación
es siempre iterativa. En este caso, este sería el enfoque más natural:
hacer un bucle del 1 al 50 calculando todos los números de Fibonacci a
medida que avanza.

::

   fib[0] = 0 
   fib[1] = 1 
   for i in range (48): 
     fib[i+2] = fib[i] + fib[i+1] 

En cualquier escenario interesante, la solución ``bottom-up`` suele ser
más difícil de entender. Sin embargo, una vez que lo entiendas,
normalmente obtendrás una idea mucho más clara de cómo funciona el
algoritmo.

Si tenemos un función ``fib`` para los números de Fibonacci memorizada:

.. code:: c++

    list mem = []; 
    int resultado = 0; 
    fib_mem(n){ 
      if(mem[n]!=Null) if(n < 2) 
        resultado = n; 
       else 
        resultado = fib_mem(n –2) + fib_mem(n –1)  ; 
    
      mem[n]=resultado; 
    
    return mem[n]; 

Como puede ver, ``fib_mem(k)`` solo se calculará como máximo una vez
para cada ``k``. (La segunda vez devolverá el valor memorizado).

Para ``fib_mem(4)``, las llamadas se realizarían en el siguiente orden:

::

   fib_mem(4)
       fib_mem(3)
           fib_mem(2)
               fib_mem(1)
               fib_mem(0)
           fib_mem(1)    // ya calculado
       fib_mem(2)   // ya calculado

Este enfoque es de ``top-down`` como se ha mencionado ya que el problema
original, ``fib_mem(4)`` está en la parte superior del cálculo anterior.

Ahora veamos el método de tabulación en este ejemplo a través de los
siguientes pasos:

-  Se crea una función de número entero para tomar la entrada ``N`` y
   crear el arreglo para el caché.
-  El arreglo de caché se inicializa para los elementos ``0`` y ``1``.
-  Otros elementos de la serie de Fibonacci se almacenan en la caché
   mediante un bucle for.
-  Finalmente, después de devolver el ``caché [n]``, se escribe la
   función ``main`` para imprimir la salida.

La versión tabulada de ``fib`` se ve así:

.. code:: c++

    fib_tab(n){  
       list mem = []; 
       mem[0] = 0; 
       mem[1]=1; 
       for(int i =0; i<n; i++){ 
           mem[i] = mem[i –2] + mem[i- 1]; 
    
     }  
    
       return mem[n] 

El cálculo de ``fib_tab(4)`` se puede describir de la siguiente manera:

.. code:: c++

    mem[0]=0
    mem[1] = 1
    mem[2] = mem[0]+ mem[1]
    mem[3] = mem[1] + mem[2]
    mem[4] = mem[2] + mem[3]

A diferencia de la técnica de memorización, este cálculo es
``bottom-up`` ya que el problema original, ``fib_tab(4)``, está al final
del cálculo.

Comentarios
~~~~~~~~~~~

1. El enfoque de top-down descompone la tarea grande en subtareas más
   pequeñas, mientras que el enfoque de bottom-up primero elige resolver
   las diferentes partes fundamentales de la tarea directamente y luego
   combina esas partes en un programa completo.

2. Cada submódulo se procesa por separado en un enfoque top-down. Por el
   contrario, el enfoque bottom-up implementa el concepto de ocultación
   de información examinando los datos que se van a encapsular.

3. Los diferentes módulos con un enfoque de top-down no requieren mucha
   comunicación. Por el contrario, el enfoque bottom-up necesita la
   interacción entre los módulos fundamentales separados para
   combinarlos más adelante.

4. El enfoque de top-down puede producir redundancia, mientras que el
   enfoque de bottom-up no incluye información redundante.

5. El enfoque bottom-up se utiliza previamente en las pruebas. Por el
   contrario, el enfoque de top-down se utiliza en la documentación de
   módulos, la creación de casos de prueba, la depuración, etc.

En cualquier escenario interesante, la solución ``bottom-up`` suele ser
más difícil de entender. Sin embargo, una vez que lo entiendas,
normalmente obtendrás una idea mucho más clara de cómo funciona el
algoritmo. En la práctica, al resolver problemas no triviales, se
recomienda primero escribir el enfoque de ``top-down`` y probarlo en
pequeños ejemplos.

Ejercicios
~~~~~~~~~~

Robot y rutas
^^^^^^^^^^^^^

La programación dinámica es una excelente manera de resolver problemas
que giran en torno a rutas.

Dada una cuadrícula de tamaño ``(M x N)``. Un robot ingresa a la
cuadrícula desde las coordenadas ``(0, 0)``. Algunas celdas de la
cuadrícula están bloqueadas. Descubre el número total de caminos que
puede tomar el robot para llegar a la celda ``(M -1, N - 1)``.

Nota: el movimiento del robot está limitado a un paso hacia el Sur o un
paso hacia el Este.

**Entrada**

La primera línea de la entrada serán las dimensiones de la cuadrícula,
es decir, ``R``, ``C`` y el número de celdas bloqueadas en la
cuadrícula. Las siguientes líneas ``P`` contendrán las coordenadas de
los bloques.

Por ejemplo:

::

   Entrada:
   4 3 2
   3 3
   3 1
    
   Solucion:
   2

En la programación dinámica, nunca desperdiciamos los cálculos
anteriores. Esto distingue la programación dinámica de la recursividad.
Usamos programación dinámica porque hace que la solución sea muchas
veces más óptima que las soluciones recursivas.

A continuación se muestra el proceso paso a paso que seguiremos para
codificar la solución.

::

        * Para llegar a la celda (i, j), sólo podemos pasar por dos caminos.
            - A través de (i - 1, j)
                - Descendiendo un nivel desde la fila superior.
            - O a través de (i, j - 1)
                - Avanzando un paso hacia el este.
        * Crea una matriz 2D para almacenar las respuestas a subproblemas más pequeños.
        * El número total de formas para cada celda es el resultado de la relación recursiva.
            - Relación recursiva: m[i][j] = m[i-1][j] + m[i][j - 1];
        * Primero comprobaremos los casos base.
            - si(i == 0 || j == 0)
            - Representa la fila superior o la columna más a la izquierda.
            - Solo hay una forma de llegar a los elementos de estas filas, dado que no hay ningún bloque.
        * Si la celda superior está bloqueada: m[i][j] = m[i][j-1]
        * Si la celda izquierda está bloqueada: m[i][j] = m[i -1][j]
        * Haremos esto para todas las celdas. Y almacenamos las respuestas en una matriz.

Implementa un programa en C++ de este problema.

.. code:: c++

    //Tu respuesta

Distancia de Levenshtein
^^^^^^^^^^^^^^^^^^^^^^^^

La distancia de Levenshtein es una forma de cuantificar qué tan
diferentes son dos cadenas entre sí contando el número mínimo de
operaciones necesarias para transformar una cadena en la otra. Para dos
palabras es el número mínimo de ediciones de un solo carácter (es decir,
inserciones, eliminaciones o sustituciones) necesarias para cambiar una
palabra por otra. Cada una de estas operaciones tiene un coste unitario.

Por ejemplo, la distancia de Levenshtein entre ``kitting`` y ``sitting``
es 3. El script de edición mínimo que transforma el primero en el
segundo es:

::

   kitten —> sitten (substitucion de s por k)
   sitten —> sittin (substitucion de i por e)
   sittin —> sitting (insercion de g al final) 

Este problema a tiene una subestructura óptima. Eso significa que el
problema puede dividirse en ``subproblemas`` más pequeños y simples, que
a su vez pueden dividirse en subproblemas aún más simples y así
sucesivamente, hasta que, finalmente, la solución se vuelve trivial.

**Problema:** Transforma la cadena ``X[1...m]`` en ``Y[1...n]``
realizando operaciones de edición en la cadena ``X``.

**Subproblema:** Transforma la subcadena ``X[1...i]`` en ``Y[1...j]``
realizando operaciones de edición en la subcadena ``X``.

**Caso 1:** hemos llegado al final de cualquiera de las subcadenas.

Si la subcadena ``X`` está vacía, inserta todos los caracteres restantes
de la subcadena ``Y`` en ``X``. El costo de esta operación es igual al
número de caracteres que quedan en la subcadena ``Y``.

::

   ('', 'ABC') ——> ('ABC', 'ABC') (costo = 3)

Si la subcadena ``Y`` está vacía, inserta todos los caracteres restantes
de la subcadena ``X`` en ``Y``. El costo de esta operación es igual al
número de caracteres que quedan en la subcadena ``X``.

::

   ('ABC', '') ——> ('', '') (costo = 3)

**Caso 2:** Los últimos caracteres de las subcadenas ``X`` e ``Y`` son
iguales.

Si los últimos caracteres de la subcadena ``X`` y la subcadena ``Y``
coinciden, no es necesario hacer nada, simplemente recurre para la
subcadena restante ``X[0...i-1], Y[0...j-1]``. Como no implica ninguna
operación de edición, el coste será 0.

::

   ('ACC', 'ABC') ——> ('AC', 'AB') (costo = 0)

**Caso 3:** Los últimos caracteres de las subcadenas ``X`` e ``Y`` son
diferentes.

Si los últimos caracteres de la subcadena ``X`` e ``Y`` son diferentes,
devuelve el mínimo de las siguientes operaciones:

-  Inserta el último carácter de ``Y`` en ``X``. El tamaño de ``Y`` se
   reduce en ``1`` y ``X`` permanece igual. Esto representa
   ``X[1...i]``, ``Y[1...j-1]`` a medida que avanzamos en la subcadena
   objetivo, pero no en la subcadena de origen.

   ::

      ('ABA', 'ABC') ——> ('ABAC', 'ABC') == ('ABA', 'AB') (usando el caso 2)

-  Elimina el último carácter de ``X``. El tamaño de ``X`` se reduce en
   ``1`` y ``Y`` permanece igual. Esto representa
   ``X[1...i-1], Y[1...j]`` a medida que avanzamos en la cadena de
   origen, pero no en la cadena objetivo.

   ::

      ('ABA', 'ABC') ——> ('AB', 'ABC')

-  Sustituye (reemplaza) el carácter actual de ``X`` por el carácter
   actual de ``Y``. El tamaño de ``X`` e ``Y`` se reduce en 1. Esto
   representa ``X[1...i-1], Y[1...j-1]`` a medida que nos movemos tanto
   en la cadena de origen como en la de objetivo.

   ::

      ('ABA', 'ABC') —> ('ABC', 'ABC') == ('AB', 'AB') (usando el caso 2)

   Es básicamente lo mismo que el caso 2, donde los dos últimos
   caracteres coinciden y nos movemos tanto en la cadena de origen como
   en la de objetivo, excepto que cuesta una operación de edición.

1. Define el problema de Levenshtein manera recursiva y realiza una
   implementación en C++ de tus respuesta.

.. code:: c++

    // Tu respuesta

El problema tiene una subestructura óptima. La solución anterior también
presenta subproblemas superpuestos. Si dibujamos el árbol de
recursividad de la solución, podemos ver que los mismos subproblemas se
calculan repetidamente (realiza eso).

Sabemos que los problemas con una subestructura óptima y subproblemas
superpuestos se pueden resolver mediante programación dinámica, en la
que las soluciones de los subproblemas se memorizan en lugar de
calcularse repetidamente.

La versión memorizada sigue el enfoque de ``top-down``, ya que primero
dividimos el problema en subproblemas y luego calculamos y almacenamos
valores. También podemos resolver este problema usando ``bottom-up``. En
el enfoque ``bottom-up``, primero resolvemos los subproblemas más
pequeños y luego solucionamos los subproblemas más grandes a partir de
ellos.

La invariante mantenida en todo el algoritmo es que podemos transformar
el segmento inicial ``X[1..i]`` en ``Y[1...j]`` usando un mínimo de
operaciones ``T[i, j]``. Al final, el elemento de la matriz inferior
derecha contiene la respuesta.

Por ejemplo, sea ``X`` ``kitten`` e ``Y`` ``sitting``. La distancia de
Levenshtein entre ``X`` e ``Y`` es 3.

2. Escribe una tabla que muestran la distancia de Levenshtein de la
   subcadena ``X[0..i-1]`` e ``Y[0...j-1]``.

.. code:: c++

    // Tu respuesta

3. [Opcional] Implementa una versión iterativa del problema.

.. code:: c++

    // Tu respuesta

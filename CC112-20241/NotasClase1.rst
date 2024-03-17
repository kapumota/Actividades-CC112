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

Recursividad
------------

``Primero, resuelve el problema. Luego, escribe el código`` –>
``John Johnson``


Cuando se llama a una función dentro de la misma función, decimos que
esta función es una función recursiva. Supongamos que hay una función
:math:`f(n)`, que devuelve el factorial de un número dado n:

::

   f(0) = 1
   f(1) = 1
   f(2) = 1 x 2   
   f(3) = 1 x 2 x 3 = f(2) x f(3)
   ...
   f(n) = 1 x 2 x 3...f(n) = f(n-1) x n  


Vemos que el factorial de `n` se obtiene multiplicando n por el factorial
de `n - 1` y el factorial de `n - 1` se obtiene por el factorial de `n -2`, y
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

La validación para verificar si `n` es cero es crítica, porque sin ella la
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

Tipos de recursión
~~~~~~~~~~~~~~~~~~~~~~
En la programación, la recursión puede clasificarse principalmente en dos tipos, según cómo se manejan las llamadas recursivas y cómo se acumulan los resultados. Estos dos tipos son:

**Recursión Lineal o Simple**

En la recursión lineal o simple, cada llamada a la función realiza a lo sumo una llamada recursiva adicional. Este tipo de recursión es relativamente fácil de seguir, ya que el flujo del programa se bifurca en un camino lineal; es decir, cada llamada espera a que la siguiente llamada recursiva termine antes de continuar. Un ejemplo clásico de recursión lineal es el cálculo del factorial de un número, donde cada función llama a sí misma con un argumento decrecido en uno hasta que se alcanza el caso base.

.. code:: c++ 

    int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
    }

**Recursión de Cola (tail recursion)**

Un subtipo especial de recursión lineal es la recursión de cola, donde la llamada recursiva es la última operación que realiza la función antes de devolver su valor. En la recursión de cola, no hay necesidad de mantener información sobre las llamadas anteriores en la pila de llamadas si el compilador o el intérprete optimizan el código para reutilizar el marco de pila de la función actual. Esto significa que la recursión de cola puede ser tan eficiente como un bucle iterativo en términos de uso de memoria.

.. code:: c++

    int factorialDeCola(int n, int acumulador = 1) {
    if (n <= 1) return acumulador;
        else return factorialDeCola(n - 1, n * acumulador);
    }

**Recursión múltiple**

La recursión múltiple ocurre cuando una función se llama a sí misma más de una vez dentro de su cuerpo. La serie de Fibonacci es un ejemplo clásico, donde para calcular un término, se necesitan los dos términos precedentes, lo que resulta en dos llamadas recursivas. Este tipo de recursión puede ser más difícil de analizar y optimizar, ya que el árbol de llamadas crece exponencialmente con cada nivel de profundidad.

.. code:: c++

    int fibonacci(int n) {
        if (n <= 1) return n;
        else return fibonacci(n - 1) + fibonacci(n - 2);
        }

**Recursión anidada**

En la recursión anidada, una llamada recursiva ocurre como parte de la argumentación a otra llamada de la misma función o de una diferente. Este tipo de recursión puede llevar a una complejidad aún mayor en el árbol de llamadas, ya que cada llamada puede generar múltiples llamadas adicionales antes de completarse.

.. code:: c++

    int funcionAnidada(int n) {
    if (n <= 10) return n;
        return funcionAnidada(funcionAnidada(n / 2));
    }

**Recursión mutua o indirecta**

Ocurre cuando dos o más funciones se llaman entre sí de manera recursiva. Esto significa que hay un ciclo de llamadas entre distintas funciones antes de llegar al caso base. La recursión mutua puede ser útil para resolver problemas que naturalmente se dividen en tareas que requieren alternar entre diferentes operaciones.

.. code:: c++

    void funcionA(int n);
    void funcionB(int n);

    void funcionA(int n) {
    if (n > 0) {
        cout << "A " << n << endl;
        funcionB(n - 1);
        }
    }

    void funcionB(int n) {
    if (n > 0) {
        cout << "B " << n << endl;
        funcionA(n / 2);
        }
    }

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

Los enfoques top-down y bottom-up
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Los enfoques de diseño de algoritmos "top-down" y "bottom-up" tienen una relación interesante y complementaria con las funciones iterativas y recursivas en la programación. Aunque no existe una correspondencia uno a uno entre estos conceptos, sus interacciones ofrecen perspectivas útiles sobre cómo se pueden estructurar y resolver los problemas computacionales.


El enfoque "top-down" se basa en comenzar con el problema principal y descomponerlo en subproblemas más pequeños hasta llegar a casos simples que se pueden resolver directamente. Este método es naturalmente afín a la recursión:

    Recursión: Las funciones recursivas implementan un enfoque "top-down" al dividir automáticamente un problema en versiones más pequeñas de sí mismo. Cada llamada recursiva aborda un subconjunto del problema original hasta llegar a un caso base simple. La solución al problema general se construye entonces a partir de las soluciones a estos subproblemas.

Ejemplo: Ordenamiento Merge Sort

Merge Sort es un claro ejemplo de un algoritmo que sigue un enfoque "top-down". Primero, divide el arreglo en dos mitades, luego ordena cada mitad recursivamente, y finalmente fusiona las dos mitades ordenadas. Aquí, la descomposición del problema y la recursión trabajan de la mano.


Por otro lado, el enfoque "bottom-up" comienza con los casos más simples o componentes básicos y los combina gradualmente para construir la solución a problemas más grandes o al problema general. Este método se alinea bien con las funciones iterativas:

    Funciones Iterativas: Típicamente implementan un enfoque "bottom-up", especialmente evidente en algoritmos dinámicos y en la iteración sobre estructuras de datos. Aquí, se comienza con un conocimiento base o casos simples y se itera para construir soluciones más complejas, agregando y combinando resultados paso a paso.

Ejemplo: Programación dinámica - Fibonacci

En la programación dinámica para calcular números de Fibonacci, se comienza calculando `fib(0)` y `fib(1)` y luego se iteran hacia arriba hasta el n deseado, utilizando los resultados anteriores para construir los siguientes. Esto es un claro enfoque "bottom-up", donde se acumulan los resultados desde el caso base.


Aunque los enfoques "top-down" y "bottom-up" tienen sus representaciones naturales en la recursión y la iteración, respectivamente, el uso de uno sobre el otro no es exclusivo. Algunos problemas pueden abordarse efectivamente desde ambos enfoques, y la elección entre iteración y recursión puede depender de factores como la claridad del código, la eficiencia y las limitaciones del lenguaje de programación.

    Optimización de recursión a iteración: En muchos casos, un diseño recursivo "top-down" puede ser reescrito como un algoritmo iterativo "bottom-up" para mejorar la eficiencia, especialmente para evitar el exceso de llamadas recursivas y el uso excesivo de la pila.

    Recursión de Cola y bottom-up: La recursión de cola es un ejemplo interesante donde un diseño recursivo se aproxima en comportamiento y eficiencia a un enfoque iterativo, especialmente cuando el compilador aplica optimizaciones de recursión de cola.

Funciones Lambdas
~~~~~~~~~~

Las funciones lambda, introducidas en C++11, son una característica poderosa que permite definir funciones anónimas directamente dentro de expresiones:

.. code:: C++

    [ capture ] ( parameters ) -> return_type {
        // cuerpo
    }

Donde:

    capture: Define qué variables externas al cuerpo de la lambda son accesibles dentro de ella y cómo (por valor o por referencia). Si se captura por valor, la lambda tiene una copia de la variable; si se captura por referencia, trabaja directamente sobre la original.
    parameters: Lista de parámetros para la función, similar a los parámetros de una función normal.
    return_type: Tipo de retorno de la función. Es opcional y puede ser inferido automáticamente por el compilador en muchos casos.
    body: Cuerpo de la función, donde se implementa la lógica de la lambda

Ejemplo

.. code:: C++
   
    #include <iostream>
    #include <functional>
    #include <unordered_map>
    using namespace std;

    int main() {
        unordered_map<int, int> memo;

        function<int(int)> fibonacci = [&memo, &fibonacci](int n) -> int {
            if (n <= 1) return n;
            if (memo.count(n)) return memo[n];
            memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
            return memo[n];
            };

        int n = 10;
        cout << "Fibonacci de " << n << " es " << fibonacci(n) << endl;
        return 0;
    }

Este ejemplo demuestra cómo una lambda puede capturar variables externas (`memo`) y otra lambda (`fibonacci`) por referencia, lo que permite la recursividad y la memoización. La clave aquí es que la lambda `fibonacci se captura por referencia en su propio cuerpo, permitiéndole llamarse a sí misma de manera recursiva.

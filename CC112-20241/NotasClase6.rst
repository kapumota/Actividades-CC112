Chars
~~~~~

El tipo de datos ``char`` fue diseñado para contener un solo carácter.
Un carácter puede ser una sola letra, número, símbolo o espacio en
blanco.

``char`` es un tipo integral, lo que significa que el valor subyacente
se almacena como un número entero. De manera similar a cómo un valor
booleano 0 se interpreta como ``False`` y un valor distinto de cero se
interpreta como ``True``, el número entero almacenado por una variable
``char`` se interpreta como un carácter ASCII.

`ASCII <https://www.ascii-code.com/>`__ define una forma particular de
representar los caracteres ingleses (además de algunos otros símbolos)
como números entre ``0`` y ``127``. Por ejemplo, el código ASCII ``97``
se interpreta como el carácter ``'a'``.

Los caracteres literales siempre se colocan entre comillas simples (por
ejemplo, ``'g'``, ``'1'``, ``' '``).

Inicializando caracteres
^^^^^^^^^^^^^^^^^^^^^^^^

Puedes inicializar variables char usando literales de caracteres:

.. code:: c++

    char ch2{'a'}; // inicializa con 'a' (almacenado como entero 97) (preferido)

También puedes inicializar caracteres con números enteros, pero esto
debe evitarse si es posible.

.. code:: c++

    char ch1{ 97 }; // inicializa con el entero 97 ('a') (no preferido)

**Advertencia**

Ten cuidado de no mezclar números de caracteres con números enteros. Las
siguientes dos inicializaciones no son iguales:

.. code:: c++

    char ch{5}; // inicializa con entero 5 (almacenado como entero 5)
    char ch{'5'}; // inicializa con '5' (almacenado como entero 53)

Los números de caracteres están destinados a usarse cuando queremos
representar números como texto, en lugar de números para aplicar
operaciones matemáticas.

Impresión de caracteres
^^^^^^^^^^^^^^^^^^^^^^^

Cuando se usa ``std::cout`` para imprimir un carácter, ``std::cout``
genera la variable ``char`` como un carácter ASCII:

.. code:: c++

    #include <iostream>
    
    int main()
    {
        char ch1{ 'a' }; 
        std::cout << ch1; 
    
        char ch2{ 98 }; // (no preferido)
        std::cout << ch2; 
    
    
        return 0;
    }

Ingresando caracteres
^^^^^^^^^^^^^^^^^^^^^

El siguiente programa le pide al usuario que ingrese un carácter, luego
imprime el carácter:

.. code:: c++

    // Completa

**Ejercicio**

¿Qué sucede aquí?

.. code:: c++

    #include <iostream>
    
    int main()
    {
        std::cout << "Ingresa un caracter del teclado: "; 
    
        char ch{};
        std::cin >> ch; 
        std::cout << "Tu has ingresado " << ch << '\n';
    
        std::cin >> ch; 
        std::cout << "Tu has ingresado : " << ch << '\n';
    
        return 0;
    }

Tamaño de caracteres, rango y signo predeterminado
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

``char`` está definido por C++ para que siempre tenga un tamaño de 1
byte. De forma predeterminada, un carácter puede ser ``signed`` o no
``unsigned``. Si estás utilizando caracteres para contener caracteres
ASCII, no necesitas especificar esto (ya que los caracteres con y sin
signo pueden contener valores entre 0 y 127).

Si estás utilizando un carácter para contener números enteros pequeños
(algo que no debes hacer a menos que estés optimizando explícitamente el
espacio), siempre debes especificar si es ``signed`` o no.

Un carácter ``signed`` puede contener un número entre ``-128`` y
``127``. Un carácter ``unsigned`` puede contener un número entre ``0`` y
``255``.

Secuencias de escape
^^^^^^^^^^^^^^^^^^^^

Hay algunos caracteres en C++ que tienen un significado especial. Estos
caracteres se denominan ``secuencias de escape``. Una `secuencia de
escape <https://en.cppreference.com/w/cpp/language/escape>`__ comienza
con un carácter ``'\'`` (barra invertida) y luego una letra o número
siguiente.

.. code:: c++

    #include <iostream>
    
    int main()
    {
        std::cout << "Primer linea\nSegunda linea\n";
        return 0;
    }

.. code:: c++

    #include <iostream>
    
    int main()
    {
        std::cout << "C\tJava\tPython\tC++";
        return 0;
    }

Otras tres secuencias de escape son:

``\'`` imprime una comilla simple

``\"`` imprime una comilla doble

``\\`` imprime una barra invertida

.. code:: c++

    #include <iostream>
    
    int main()
    {
        std::cout << "\"Este es un texto citado \"\n";
        std::cout << "Esta cadena contiene un unico backslash \\\n";
        std::cout << "6F en hex es el char '\x6F'\n";
        return 0;
    }

Evita los literales de varios caracteres
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Por motivos de compatibilidad con versiones anteriores, muchos
compiladores de C++ admiten literales de varios caracteres, que son
literales de caracteres que contienen varios caracteres (por ejemplo,
``'56'``). Si son compatibles, tienen un valor definido por la
implementación (lo que significa que varía según el compilador).

Dado que no forman parte del estándar C++ y su valor no está
estrictamente definido, se deben evitar los literales de varios
caracteres.

Evita los literales de varios caracteres (por ejemplo, ``'56'``).

El soporte literal de múltiples caracteres a veces causa problemas para
los nuevos programadores. Considera el siguiente programa simple:

.. code:: c++

    #include <iostream>
    
    int suma(int x, int y)
    {
        return x + y;
    }
    
    int main()
    {
        std::cout << suma(1, 2) << '/n';
        return 0;
    }

¿Qué sucede?

.. code:: c++

    // Tu respuesta

Cadenas
~~~~~~~

Ni C ni C++ tienen un tipo de cadena incorporado predeterminado. Las
cadenas de ``estilo C`` o ``C-cadenas`` simplemente se implementan como
un arreglo de caracteres que termina con un carácter nulo (también
conocido como ``0``). Esta última parte de la definición es importante:
todas las cadenas estilo C son arreglo de caracteres, pero no todos los
arreglos de caracteres son cadenas estilo C.

.. code:: c++

    const char * str = "Este es un literal de cadena. ¿Ves las comillas dobles?"

Los literales de cadena se indican mediante comillas dobles (``"``) y se
almacenan como ``(const) C-cadena``. El carácter nulo se agrega
automáticamente al final.

La biblioteca estándar contiene funciones para procesar C-cadenas, como
``strlen``, ``strcpy`` y ``strcat``. Estas funciones se definen en el
encabezado de C ``string.h`` y en el encabezado de C++ ``cstring``.
Estas funciones requieren que las cadenas terminen con un carácter nulo
para funcionar correctamente.

.. code:: c++

    #include <iostream>
    #include <cstring>
    using namespace std;
    int main ()
    {
        char s1[10] = "Kapu";
        char s2[7] = "mota";
        strcat (s1, s2);
        cout << s1 << endl;
    }

.. code:: c++

    #include <iostream>
    #include <cstring>
    using namespace std;
    int main()
    {
        char s1[10] = "";
        char s2[7] = "Kapu";
        strcpy (s1, s2);
        cout << s1 << endl;
    }

.. code:: c++

    #include <iostream>
    #include <cstring>
    using namespace std;
    int main()
    {
        char s1[20] = "Programming";
        char s2[10] = "gram";
        cout << strstr (s1, s2) << endl;
    }

Desventajas de las C-cadenas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Los arreglos de C no rastrean su propio tamaño. Deben mantenerse al día
con el tamaño por su cuenta o confiar en la función ``strlen`` de tiempo
lineal para determinar el tamaño de cada cadena durante el tiempo de
ejecución.

Dado que C no tiene el concepto de ``protección de límites``, el uso del
carácter nulo es de suma importancia: las funciones de la biblioteca de
C lo requieren o bien operan más allá de los límites del arreglo.

Trabajar con ``C-cadenas`` no es intuitivo. Se requieren funciones para
comparar cadenas y la salida de funciones como ``strcmp`` no es
intuitiva. Para funciones como ``strcpy`` y ``strcat`` el programador
debe recordar el orden correcto de los argumentos para cada llamada.
Invertir argumentos puede tener un efecto negativo.

Muchas ``C-cadenas`` se utilizan como arreglo de tamaño fijo. Esto es
cierto tanto para los literales como para los arreglos que se declaran
en la forma ``char str[32]``.

Para las cadenas de tamaño dinámico, los programadores deben preocuparse
por asignar, cambiar el tamaño y copiar manualmente las cadenas.

El concepto de tamaño/longitud de una cadena estilo C no es intuitivo y
comúnmente da como resultado errores. El carácter nulo que marca el
final requiere un byte de almacenamiento en un arreglo ``char``. Esto
significa que una cadena de longitud 24 debe almacenarse en un arreglo
de caracteres de 25 bytes. Sin embargo, la función ``strlen`` devuelve
la longitud de la cadena sin el carácter nulo.

Este simple hecho ha hecho tropezar a muchos programadores al copiar la
memoria. Eventualmente, termina con una cadena no terminada en nulo, lo
que hace que las funciones de la biblioteca de cadenas operen fuera de
los límites.

¿Y si pudiéramos arreglar esas desventajas?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Aquí hay algunas ideas:

-  Tener capacidad de almacenamiento flexible

-  Recuperación de longitud de cadena en tiempo constante (en lugar de
   una verificación funcional en tiempo lineal)

-  Encontrar mecanismos para preocuparse por la gestión manual de la
   memoria o el cambio de tamaño de las cadenas

-  Que los problemas de límites se manejan por el desarrollador, con o
   sin un carácter nulo.

-  Tener una asignación intuitiva usando el operador ``=`` en lugar de
   ``strcpy``

-  Tener una comparación intuitiva utilizando el operador == en lugar de
   ``strcmp``

-  Usar interfaces intuitivas para otras operaciones como concatenación,
   tokenización.

La clase std::string
^^^^^^^^^^^^^^^^^^^^

La clase ``std::string`` de C++ soluciona la mayoría de estos problemas.
Fundamentalmente, puede considerar ``std::string`` como un contenedor
para manejar arreglos de caracteres, similar a ``std::vector<char>`` con
algunas funciones especializadas.

Esta clase administra el almacenamiento subyacente, almacenando las
cadenas de manera contigua. Puedes obtener acceso a este búfer
subyacente utilizando la función ``c_str()``, que devolverá un puntero
al arreglo de caracteres que terminan en nulo. Esto permite que
``std::string`` interopere con las API de ``C-cadenas``.

En general la clase ``string`` sirve para manejar y manipular cadenas de
caracteres. Sin embargo, debido a que las cadenas son de hecho,
secuencias de caracteres, también podemos representarlas como arreglos
de elementos de tipos de carácter.

Por ejemplo, lo siguiente declara un arreglo que puede almacenar hasta
``20`` elementos de tipo ``char``:

Revisa: https://cplusplus.com/reference/string/string/

.. code:: c++

    char my_array[20];

Este arreglo tiene capacidad para almacenar secuencias de hasta 20
caracteres, pero también se pueden almacenar secuencias más cortas. Por
ejemplo, en algún punto de un programa se puede almacenar en
``my_array`` la secuencia ``hola`` o la secuencia ``Feliz Navidad``, ya
que ambas cabrían en una secuencia con capacidad para 20 caracteres.

Por convención, el final de las cadenas representadas en secuencias de
caracteres se señala mediante un carácter especial llamado carácter nulo
(``null``) representado por 0 o usando el valor literal ``'\0'`` (barra
invertida, cero) como mencionamos anteriormente.

.. code:: c++

    #include <iostream>
    
    int main()
    {
        std::cout << "Hello, world!\n";
        return 0;
    }

std::string
^^^^^^^^^^^

La forma más sencilla de trabajar con cadenas y objetos de cadena en C++
es a través del tipo ``std::string``, que se encuentra en el encabezado
``<string>``.

Podemos crear objetos de tipo ``std::string`` como cualquier otro
objeto.

.. code:: c++

    #include <string> // permite usar std::string
    
    int main()
    {
        std::string name {}; // cadena vacia
    
        return 0;
    }

Al igual que las variables normales, puedes inicializar o asignar
valores a los objetos ``std::string`` como cabría esperar:

.. code:: c++

    #include <string>
    
    int main()
    {
        std::string nombre { "Checha" }; // inicializa nombre con la cadena literal "Checha"
        nombre = "Z";              // cambia el nombre a "Z"
    
        return 0;
    }

Salida de cadena
^^^^^^^^^^^^^^^^

Los objetos ``std::string`` se pueden generar como se esperaba usando
``std::cout``:

.. code:: c++

    #include <iostream>
    #include <string>
    
    int main()
    {
        std::string nombre { "Z" };
        std::cout << "Mi nombre es: " << nombre << '\n';
    
        return 0;
    }

Las cadenas vacías no imprimirán nada:

.. code:: c++

    #include <iostream>
    #include <string>
    int main()
    {
    std::string vacio{ };
    std::cout << '[' << vacio << ']';
    return 0;

Entrada de cadena con std::cin
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¡Usar cadenas con ``std::cin`` puede generar algunas sorpresas!.
Considera el siguiente ejemplo:

.. code:: c++

    #include <iostream>
    #include <string>
    int main()
    {
        std::cout << "Ingresa tu nombre: ";
        std::string nombre{};
    
        std::cin >> nombre; 
        std::cout << "Ingresa tu edad: ";
        std::string edad{};
    
        std::cin >> edad;
        std::cout << "Tu nombre es " << nombre << " y  tu edad es " << edad << '\n';
    
            return 0;
    }

Usa std::getline() para ingresar texto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para leer una línea completa de entrada en una cadena, es mejor usar la
función ``std::getline()``. ``std::getline()`` requiere dos argumentos:
el primero es ``std::cin`` y el segundo es su variable de cadena.

Aquí está el programa anterior que el anterior usando
``std::getline()``:

.. code:: c++

    #include <iostream>
    #include <string>
    int main()
    {
        std::cout << "Ingresa tu nombre: ";
        std::string nombre{};
        std::getline(std::cin >> std::ws, nombre);
        
        std::cout << "Ingresa tu edad: ";
        std::string edad{};
        std::getline(std::cin >> std::ws, edad);
    
        std::cin >> edad;
        std::cout << "Tu nombre es " << nombre << " y  tu edad es " << edad << '\n';
    
        return 0;
    }

¿Qué es std::ws?
^^^^^^^^^^^^^^^^

C++ también admite manipuladores de entrada, que alteran la forma en que
se acepta la entrada. El manipulador de entrada ``std::ws`` le dice a
``std::cin`` que ignore cualquier espacio en blanco inicial antes de la
extracción. El espacio en blanco inicial es cualquier carácter de
espacio en blanco (espacios, tabuladores, líneas nuevas) que aparece al
comienzo de la cadena.

Exploremos por qué esto es útil. Considera el siguiente programa:

.. code:: c++

    #include <string>
    #include <iostream>
    
    int main()
    {
        std::cout << "Escoge 1 o 2: ";
        int eleccion{};
        std::cin >> eleccion;
    
        std::cout << "Ahora ingresa tu nombre : ";
        std::string nombre{};
        std::getline(std::cin, nombre); // nota: no std::ws aqui
    
        std::cout << "Hola, " << nombre << ", tu escogiste " << eleccion << '\n';
    
        return 0;
    }

¿Vés algún problema en los resultados?

.. code:: c++

    #include <string>
    #include <iostream>
    
    int main()
    {
        std::cout << "Escoge 1 o 2: ";
        int eleccion{};
        std::cin >> eleccion;
    
        std::cout << "Ahora ingresa tu nombre : ";
        std::string nombre{};
        std::getline(std::cin >> std::ws, nombre); // nota: no std::ws aqui
    
        std::cout << "Hola, " << nombre << ", tu escogiste " << eleccion << '\n';
    
        return 0;

Mejores prácticas
^^^^^^^^^^^^^^^^^

Se usa ``std::getline()`` para leer cadenas, usa el manipulador de
entrada ``std::cin >> std::ws`` para ignorar los espacios en blanco
iniciales.

El uso del operador de extracción (``>>``) con ``std::cin`` ignora los
espacios en blanco iniciales. ``std::getline()`` no ignora los espacios
en blanco iniciales a menos que uses el manipulador de entrada
``std::ws``.

Longitud de cadenas
^^^^^^^^^^^^^^^^^^^

Si queremos saber cuántos caracteres hay en un ``std::string`` podemos
preguntarle a un objeto ``std::string`` por su longitud. La sintaxis
para hacer esto es diferente a la que ha visto antes, pero es bastante
sencilla:

.. code:: c++

    #include <iostream>
    #include <string>
    
    int main()
    {
        std::string nombre{ "Z" };
        std::cout << nombre << " tiene " << nombre.length() << " caracteres\n";
    
        return 0;
    }

std::string puede ser costoso de inicializar y copiar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cada vez que se inicializa un ``std::string``, se realiza una copia de
la cadena utilizada para inicializarlo. Y cada vez que se pasa un
``std::string`` por valor a un parámetro ``std::string`` se realiza otra
copia. Hacer copias de cadenas es costoso y debe evitarse si es posible.

No pases ``std::string`` por valor, ya que hacer copias de
``std::string`` es costoso. Prefiere los parámetros
``std::string_view``.

Considera el siguiente programa:

.. code:: c++

    #include <iostream>
    
    int main()
    {
        int x { 5 };
        std::cout << x << '\n';
    
        return 0;
    }

Cuando se ejecuta la definición de ``x`` el valor de inicialización 5 se
copia en la memoria asignada para ``int x``. Para tipos fundamentales,
inicializar (o copiar) una variable es rápido.

Ahora considera este programa similar:

.. code:: c++

    #include <iostream>
    #include <string>
    
    int main()
    {
        std::string s{"Hello, world!" };
        std::cout << s << '\n';
    
        return 0;
    }

Vemos algo similar en este ejemplo:

.. code:: c++

    #include <iostream>
    #include <string>
    
    void imprimirCadena(std::string str)
    {
        std::cout << str << '\n';
    }
    
    int main()
    {
        std::string s{ "Hello, world!" };
        imprimirCadena(s);
    
        return 0;
    }

std::string_view (C++17)
^^^^^^^^^^^^^^^^^^^^^^^^

Para solucionar el problema de que ``std::string`` es caro de
inicializar (o copiar), C++17 introdujo ``std::string_view`` (que vive
en el encabezado ``<string_view>``).

``std::string_view`` proporciona acceso de solo lectura a una cadena
existente (una cadena literal de estilo C, una ``std::string`` o un
arreglo de caracteres) sin hacer una copia.

El siguiente ejemplo es idéntico al anterior, excepto que reemplazamos
``std::string`` con ``std::string_view``.

.. code:: c++

    // Completa

Mejores prácticas
^^^^^^^^^^^^^^^^^

Prefiere ``std::string_view`` sobre ``std::string`` cuando necesites una
cadena de solo lectura, especialmente para parámetros de función.

Funciones de la clase std::string
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La función ``length()`` averiguará la longitud de la cadena. Un
beneficio de la orientación a objetos es que podemos llamar a las
funciones sobre el objeto ya que están dentro del objeto. La función
``size()`` es lo mismo.

.. code:: c++

    // length() y size()
    
    #include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string str = "Hello World";
        cout << "Longitud: " << str.length () << endl;
        cout << "Tamaño: " << str.size () << endl;
    }

Si queremos declarar e inicializar un objeto de cadena, escribimos,

::

   String str = "Bienvenido";

Si inicializamos se creará un objeto de cadena. Esto creará un arreglo
internamente. No tenemos que declarar un arreglo, internamente se creará
un arreglo y dentro de ese arreglo, la palabra ``"Bienvenido"`` se
almacenará letra por letra. Luego, también se inserta un carácter nulo.

Una cosa importante es que se ha creado una cadena más grande. No se
creará un arreglo de tamaño exacto que se requiere para una cadena, sino
se creará uno de tamaño un poco más grande. El tamaño del arreglo se
creará más grande que la cadena. Así tendremos algo más de capacidad
para almacenar o ampliar el sistema.

Este tamaño del arreglo se conoce como la capacidad de una cadena y la
cantidad de letras que se almacenan hasta el carácter nulo se denomina
longitud de una cadena o también se denomina tamaño de una cadena.

El siguiente código da la capacidad de una cadena y no creará un arreglo
exactamente del tamaño de la cadena. Se creará de un tamaño un poco más
grande.

.. code:: c++

    // capacity()
    
    #include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string str = "Hello World";
        cout << "Capacidad: " << str.capacity () << endl;
    }

Esta función se utiliza para aumentar la capacidad de una cadena.
Podemos mencionar el tamaño y cambiar la capacidad.

.. code:: c++

    // resize()
    
    #include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string str = "Hello World";
        str.resize (40);
        cout << "Capacidad: " << str.capacity () << endl;

Dependiendo del compilador, esta función proporciona el tamaño máximo
posible para una cadena que podemos tener en el compilador. Esto puede
variar de un compilador a otro.

.. code:: c++

    // max_size()
    
    #include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string str = "Hello World";
        cout << "Max: " << str.max_size () << endl;
    }

Esta borrará el contenido de una cadena.

.. code:: c++

    // clear()
    
    #include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string str = "Hello World";
        str.clear ();
        cout << "Longitud: " << str.length () << endl;
    }

Esta averiguará si una cadena está vacía o no.

.. code:: c++

    // empty()
    
    #include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string str = "Hello World";
        if (!str.empty ())
        {
            cout << "Cadena no vacia.";
        }
    }

Ejercicios
~~~~~~~~~~

1 . Escribe un programa que confirma si el usuario es un robot o no.

2 . Escribe un programa que le pida al usuario que ingrese su nombre
completo y su edad. Como salida, dígale al usuario la suma de su edad y
el número de letras en su nombre (usa la función
``std::string::length()`` para obtener la longitud de la cadena). Para
simplificar, cuenta los espacios en el nombre como una letra.

3 . Encuentra 3 problemas (que afectan a 4 líneas) en el siguiente
código.

.. code:: c++

    #include <cstdint> // para std::uint8_t
    #include <iostream>
    
    int main()
    {
      std::cout << "Cual es tu edad?\n";
    
      std::uint8_t edad{};
      std::cin >> edad;
    
      std::cout << "Puedes viajar a Andromeda Z-X111 [";
    
      if (edad >= 16)
        std::cout << "x";
      else
        std::cout << " ";
    
      std::cout << "]\n";
    
      return 0;
    }

.. code:: c++

    // Tus respuestas

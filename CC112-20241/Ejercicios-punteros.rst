Actividad de fundamentos de programación
----------------------------------------

Completa con tus propias palabras los comentarios en lugar de los signos
de interrogación

Los punteros también tiene un tipo
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: c++

    int i = 88;
    double d = 55.66;
    int * iPtr = &i;    
    double * dPtr = &d; 
     
    iPtr = &d;   //??
    dPtr = &i;   // ??
    iPtr = i;    //??
    int j = 99;
    iPtr = &j;  //

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int main() {
       int numero = 88;   //??
       int * pNumero;      // ??
       pNumero = &numero;  // ??
     
       cout << pNumero << endl;  // ??
       cout << &numero << endl;  // ??
       cout << *pNumero << endl; // ??
       cout << numero << endl;   // ??
     
       *pNumero = 99;            // ??
       cout << pNumero << endl;  // ??
       cout << &numero << endl;  // ??
       cout << *pNumero << endl; // ??
       cout << numero << endl;   // ??
                                 // ??
     
       cout << &pNumero << endl

Punteros nulos
~~~~~~~~~~~~~~

.. code:: c++

    int * iPtr = 0;         //??
    cout << *iPtr << endl;  // ??
     
    int * p = NULL;         // ??

Variables de referencia
~~~~~~~~~~~~~~~~~~~~~~~

Referencias (o Alias) (&)
^^^^^^^^^^^^^^^^^^^^^^^^^

Recuerda que C/C++ usa ``&`` para indicar la dirección del operador en
una expresión. C++ asigna un significado adicional a ``&`` en la
declaración para declarar una variable de referencia.

El significado del símbolo ``&`` es diferente en una expresión y en una
declaración. Cuando se usa en una expresión, ``&`` denota el operador de
dirección que devuelve la dirección de una variable.

Sin embargo, cuando ``&`` se usa en una declaración (incluidos los
parámetros formales de la función), es parte del identificador de tipo y
se usa para declarar una variable de referencia (o referencia, alias o
nombre alternativo). Se utiliza para proporcionar otro nombre, otra
referencia o alias a una variable existente.

Sintaxis:

::

   tipo &nuevoNombre = nombreExistente;
   // o
   tipo& nuevoNombre = nombreExistente;
   // o
   tipo  & nuevoNombre = nombreExistente;

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int main() {
       int numero = 88;          // ??
       int & refNumero = numero; // ??
                                 
     
       cout << numero << endl;    // ??
       cout << refNumero << endl; // ??
     
       refNumero = 99;            // ??
       cout << refNumero << endl;
       cout << numero << endl;    // ??
     
       numero = 55;               // ??
       cout << numero << endl;
       cout << refNumero << endl; // ??
    }

Referencias y punteros
~~~~~~~~~~~~~~~~~~~~~~

.. code:: c++

    int & iRef; //??

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int main() {
       int numero1 = 88, numero2 = 22;
     
       // ???
       int * pNumero1 = &numero1;  // ??
       *pNumero1 = 99;             // ??
       cout << *pNumero1 << endl;  // ??
       cout << &numero1 << endl;   // ??
       cout << pNumero1 << endl;   // ??
       cout << &pNumero1 << endl;  // ??
       pNumero1 = &numero2;        // ??
     
       // ???
       int & refNumero1 = numero1;  // ??
       refNumero1 = 11;             // ??
       cout << refNumero1 << endl;  // ??
       cout << &numero1 << endl;    // ??
       cout << &refNumero1 << endl; // ??
       //refNumero1 = &numero2;     // ??
                                    // ??'
       refNumero1 = numero2;        // ??
                                    // ??
       numero2++;   
       cout << refNumero1 << endl;  // ??
       cout << numero1 << endl;     // ??
       cout << numero2 << endl;     // ??
    }

Paso por referencia a funciones con argumentos de referencia frente a argumentos de puntero
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Paso por valor
^^^^^^^^^^^^^^

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int square(int);
     
    int main() {
       int numero = 8;
       cout <<  "En main(): " << &numero << endl;  //??
       cout << numero << endl;         // ??
       cout << cuadrado(numero) << endl; // ??
       cout << numero << endl;         // ??
    }
     
    int cuadrado(int n) {  // ??
       cout <<  "En cuadrado(): " << &n << endl;  // ??
       n *= n;           // ??
       return n;
    }

**Paso por referencia con argumentos de puntero**

.. code:: c++

    #include <iostream>
    using namespace std;
     
    void cuadrado(int *);
     
    int main() {
       int numero = 8;
       cout <<  "En main(): " << &numero << endl;  //??
       cout << numero << endl;   // ??
       cuadrado(&numero);          // ??
       cout << numero << endl;   // ??
    }
     
    void cuadrado(int * pNumero) {  // ??
       cout <<  "En cuadrado(): " << pNumero << endl;  //??
       *pNumero *= *pNumero;      // ??
    }

**Paso por referencia con argumentos de referencia**

.. code:: c++

    #include <iostream>
    using namespace std;
     
    void square(int &);
     
    int main() {
       int numero = 8;
       cout <<  "En main(): " << &numero << endl;  // ??
       cout << numero << endl;  // ??
       cuadrado(numero);          //??
       cout << numero << endl;  // ??
    }
     
    void cuadrado(int & rNumero) {  // ??
       cout <<  "En cuadrado(): " << &rNumero << endl;  // ??
       rNumero *= rNumero;        // ??
    }

Parámetros de puntero/referencia de función “const”
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Un parámetro formal de función constante no se puede modificar dentro de
la función. Utiliza ``const`` siempre que sea posible, ya que te protege
de modificar inadvertidamente el parámetro y te protege contra muchos
errores de programación.

Un parámetro de función constante puede recibir argumentos tanto
constantes como no constantes. Por otro lado, un parámetro de
puntero/referencia de función no constante solo puede recibir un
argumento no constante.

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int cuadradoConst(const int);
    int cuadradoNonConst(int);
    int cuadradoConstRef(const int &);
    int cuadradoNonConstRef(int &);
     
    int main() {
       int numero = 8;
       const int constNumero = 9;
       cout << cuadradoConst(numero) << endl;
       cout << cuadradoConst(constNumero) << endl;
       cout << cuadradoNonConst(numero) << endl;
       cout << cuadradoNonConst(constNumero) << endl;
     
       cout << cuadradoConstRef(numero) << endl;
       cout << cuadradoConstRef(constNumero) << endl;
       cout << cuadradoNonConstRef(numero) << endl;
       // cout << cuadradoNonConstRef(constnumero) << endl;
           // ???
    }
     
    int cuadradoConst(const int numero) {
       // numero *= numero;  // ??
       return numero * numero;
    }
     
    int cuadradoNonConst(int numero) {  // ??
       numero *= numero;
       return numero;
    }
     
    int cuadradoConstRef(const int & numero) {  //??
       return numero * numero;
    }
     
    int cuadradoNonConstRef(int & numero) {  // ??
       return numero * numero;
    }

Pasando el valor de retorno de la función
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pasar el valor de retorno como referencia**

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int & cuadradoRef(int &);
    int * cuadradoPtr(int *);
     
    int main() {
       int numero1 = 8;
       cout <<  "En main() &numero1: " << &numero1 << endl;  //??
       int & resultado = cuadradoRef(numero1);
       cout <<  "En main() &resultado: " << &resultado << endl;  //??
       cout << resultado << endl;   // ??
       cout << numero1 << endl;  // ??
     
       int numero2 = 9;
       cout <<  "En main() &numero2: " << &numero2 << endl;  //??
       int * pResultado = cuadradoPtr(&number2);
       cout <<  "En main() pResultado: " << pResultado << endl;  // ??
       cout << *pResultado << endl;   // ??
       cout << numero2 << endl;    // ??
    }
     
    int & cuadradoRef(int & rNumber) {
       cout <<  "En cuadradoRef(): " << &rNumero << endl;  //??
       rNumero *= rNumero;
       return rNumero;
    }
     
    int * cuadradoPtr(int * pNumero) {
       cout <<  "En cuadradoPtr(): " << pNumero << endl;  // ??
       *pNumero *= *pNumero;
       return pNumero;
    }

No debes pasar la variable local de la función como valor de retorno por
referencia

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int * cuadradoPtr(int);
    int & cuadradoRef(int);
     
    int main() {
       int numero = 8;
       cout << numero << endl;  // ??
       cout << *cuadradoPtr(numero) << endl;  // ??
       cout << cuadradoRef(numero) << endl;   // ??
    }
     
    int * cuadradoPtr(int numero) {
       int resultadoLocal = numero * numero;
       return &resultadoLocal;
          // ??
     
    int & cuadradoRef(int numero) {
       int resultadoLocal = numero * numero;
       return resultadoLocal;
          // ??
    }

Pasar memoria asignada dinámicamente como valor de retorno por
referencia

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int * cuadradoPtr(int);
    int & cuadradoRef(int);
     
    int main() {
       int numero = 8;
       cout << numero << endl;  // ??
       cout << *cuadradoPtr(numero) << endl;  // ??
       cout << cuadradoRef(numero) << endl;   // ??
    }
     
    int * cuadradoPtr(int numero) {
       int * resultadoAsignadoDinamicamente= new int(numero * numero);
       return resultadoAsignadoDinamicamente;
    }
     
    int & cuadradoRef(int numero) {
       int * resultadoAsignadoDinamicamente= new int(numero * numero);
       return *resultadoAsignadoDinamicamente;
    }

El arreglo se trata como un puntero
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int main() {
       const int TAM = 5;
       int numeros[TAM] = {11, 22, 44, 21, 41};  // ???
     
       // numeros = &numeros[0] ???
       cout << &numeros[0] << endl; // ???
       cout << numeros << endl;     // ??
       cout << *numeros << endl;         // ??
       cout << *(numeros + 1) << endl;   // ??
       cout << *(numeros + 4) << endl;   // ??
    }

Aritmetica de punteros
~~~~~~~~~~~~~~~~~~~~~~

.. code:: c++

    int numeros[] = {11, 22, 33};
    int * iPtr = numeros;
    cout << iPtr << endl;        // 0x22cd30
    cout << iPtr + 1 << endl;    // 0x22cd34 (incrementa 4 - sizeof int)
    cout << *iPtr << endl;       // 11
    cout << *(iPtr + 1) << endl; // 22 
    cout << *iPtr + 1 << endl;   // 12

sizeof del arreglo
~~~~~~~~~~~~~~~~~~

.. code:: c++

    nt numeros[100];
    cout << sizeof(numeros) << endl;     // (400)??
    cout << sizeof(numeros[0]) << endl;  // 4 ??
    cout << "La dimension del arreglo es " << sizeof(numeros) / sizeof(numeros[0]) << endl;

Pasar un arreglo dentro y fuera de una función
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Un arreglo se pasa a una función como un puntero al primer elemento del
arreglo. Puedes utilizar notación del arreglo (por ejemplo, ``int[]``) o
notación de puntero (por ejemplo, ``int*``) en la declaración de
función.

El compilador siempre lo trata como un puntero (por ejemplo,\ ``int*``).
Por ejemplo, las siguientes declaraciones son equivalentes:

.. code:: c++

    int max(int numeros[], int tam);
    int max(int *numeros, int tam);
    int max(int numeros[50], int tam);

El compilador los tratará como ``int*``, como se muestra a continuación.
Se ignora el tamaño del arreglo proporcionada en ``[]``.

.. code:: c++

    int max(int*, int);

.. code:: c++

    #include <iostream>
    using namespace std;
     
    // comenta el codigo
    int max(const int arr[], int tam);
    void reemplazarPorMaximo(int arr[], int tam);
    void imprimir(const int arr[], int tam);
     
    int main() {
       const int TAM = 4;
       int numeros[TAM] = {11, 22, 33, 22};
       imprimir(numeros, TAM);
       cout << max(numeros, TAM) << endl;
       reemplazarPorMaximo(numeros, TAM);
       imprimir(numeros, TAM);
    }
     
    // comenta el codigo
    int max(const int arr[], int tam) {
       int max = arr[0];
       for (int i = 1; i < tam; ++i) {
          if (max < arr[i]) max = arr[i];
       }
       return max;
    }
     
    // comenta el codigo
    void reemplazarPorMaximo(int arr[], int tam) {
       int maxValor = max(arr, tam);
       for (int i = 0; i < tam; ++i) {
          arr[i] = maxValor;
       }
    }
     
    // comenta el codigo
    void imprimir(const int arr[], int tam) {
       cout << "{";
       for (int i = 0; i < tam; ++i) {
          cout << arr[i];
          if (i < tam - 1) cout << ",";
       }
       cout << "}" << endl;
    }

Para evitar modificaciones accidentales, puedes aplicar el calificador
``const`` al parámetro de la función. Recuerda que ``const`` informa al
compilador que el valor no debe cambiarse.

Por ejemplo, supongamos que la función ``print()`` imprime el contenido
del arreglo dado y no modifica el arreglo, podrías aplicar ``const``
tanto al nombre del arreglo como a su tamaño, ya que no se espera que se
cambien dentro de la función.

.. code:: c++

    void imprmir(const int arr[], int tam);

.. code:: c++

    #include <iostream>
    using namespace std;
     
    // ???
    int max(const int *arr, int tam);
     
    int main() {
       const int TAM = 5;
       int numeros[TAM] = {10, 20, 90, 76, 22};
       cout << max(numeros, TAM) << endl;
    }
     
    // ???
    int max(const int *arr, int tam) {
       int max = *arr;
       for (int i = 1; i < size; ++i) {
          if (max < *(arr+i)) max = *(arr+i);
       }
       return max;
    }

Paso por referencia y sizeof
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code:: c++

    #include <iostream>
    using namespace std;
     
    // ???
    void fun(const int *arr, int tam);
     
    // ???
    int main() {
       const int TAM = 5;
       int a[TAM] = {8, 4, 5, 3, 2};
       cout << "sizeof en main() es " << sizeof(a) << endl;
       cout << "direccion en main() es " << a << endl;
       fun(a, TAM);
    }
     
    //???
    void fun(const int *arr, int tam) {
       cout << "sizeof en funcion es " << sizeof(arr) << endl;
       cout << "direccion en funcion es " << arr << endl;
    }

Operando en un rango de un arreglo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code:: c++

    //???
    #include <iostream>
    using namespace std;
     
    // ??
    int suma(const int *inicio1, const int *final1);
     
    //??
    int main() {
       int a[] = {8, 4, 5, 3, 2, 1, 4, 8};
       cout << suma(a, a+8) << endl;        // ??
       cout << suma(a+2, a+5) << endl;      // ??
       cout << suma(&a[2], &a[5]) << endl;  // ??
    }
     
    //???
    int suma(const int *inicio1, const int *final1) {
       int suma = 0;
       for (const int *p = inicio1; p != final1; ++p) {
          suma += *p;
       }
       return suma;
    }

**Notas del programa:**

-  Para escribir una función que opera en un rango del arreglo dado,
   puedes pasar el puntero de inicio y el puntero de fin a la función.
   Por convención, la operación comenzará en el puntero inicial, hasta
   el puntero final, pero excluyendo el puntero final.

-  En ``const int *p"``, ``*p`` (contenido señalado) es constante, pero
   ``p`` no es constante.

C-string y punteros
~~~~~~~~~~~~~~~~~~~

.. code:: c++

    #include <iostream>
    #include <cstring>
    using namespace std;
     
    int main() {
       char msg1[] = "Hello";
       char *msg2 = "Hello";
          // ???
     
       cout << strlen(msg1) << endl;    // ???
       cout << strlen(msg2) << endl;
       cout << strlen("Hello") << endl;
     
       int tam = sizeof(msg1)/sizeof(char);
       cout << tam << endl;  // ???
       for (int i = 0; msg1[i] != '\0'; ++i) {
          cout << msg1[i];
       }
       cout << endl;
     
       for (char *p = msg1; *p != '\0'; ++p) {
              // ????
          cout << *p;
       }
       cout << endl;
    }

Ten en cuenta que para la función ``C-string`` como ``strlen()`` (en el
encabezado ``cstring``, transferido desde ``string.h`` de C), no es
necesario pasar la longitud del arreglo a la función. Esto se debe a que
las ``C-string`` terminan en ``'\0'``. La función puede iterar a través
de los caracteres del arreglo hasta ``'\0'``.

Por ejemplo:

.. code:: c++

    #include <iostream>
    #include <cstring>
    using namespace std;
     
    int count(const char *str, const char c);  //???
     
    int main() {
       char msg1[] = "Hello, world";
       char *msg2 = "Hello, world"; //???
     
       cout << count(msg1, 'l') << endl;
       cout << count(msg2, 'l') << endl;
       cout << count("Hello, world", 'l') << endl;
    }
     
    // ???
    int count(const char *str, const char c) {
       int conteo = 0;
       while (*str) {   //??? (*str != '\0')
          if (*str == c) ++conteo;
          ++str;
       }
       return conteo;
    }

Puntero de función
~~~~~~~~~~~~~~~~~~

En C/C++, las funciones, como todos los elementos de datos, tienen una
dirección. El nombre de una función es la dirección inicial donde reside
la función en la memoria y, por lo tanto, puede tratarse como un
puntero.

También podemos pasar un puntero de función a una función. La sintaxis
para declarar un puntero de función es:

::

   // Declaración de puntero de función
   tipo-retorno (* nombre-funcion-ptr) (lista-parametros)

::

   // Ejemplos
    double (*fp)(int, int) // fp apunta a una función que toma dos enteros y devuelve un double
    double *dp; // dp apunta a un double (double puntero)
    double *fun(int, int) // fun es una función que toma dos enteros y devuelve un double puntero

     double f(int, int); // f es una función que toma dos enteros y devuelve un double
     fp = f; // Asigna la función f al puntero de función fp

.. code:: c++

    #include <iostream>
    using namespace std;
     
    int aritmetica(int, int, int (*)(int, int));
        // ???
    int suma(int, int);
    int substraccion(int, int);
     
    int suma(int n1, int n2) { return n1 + n2; }
    int substraccion(int n1, int n2) { return n1 - n2; }
     
    int aritmetica(int n1, int n2, int (*operacion) (int, int)) {
       return (*operacion)(n1, n2);
    }
     
    int main() {
       int numero1 = 5, numero2 = 6;
     
       // ??
       cout << aritmetica(numero1, numero2, suma) << endl;
       // ??
       cout << aritmetica(numero1, numero2, substraccion) << endl;
    }


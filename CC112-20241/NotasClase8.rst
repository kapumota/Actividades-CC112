Clases en C++
-------------

Una clase es un tipo de datos definido por el usuario que consta de
métodos y datos agrupados como miembros (es decir, encapsulados). Una
clase usa objetos que almacenan datos, tienen un estado y comportamiento
definidos. A estos también se les conoce como una instancia de una
clase. Una clase es como una categoría amplia que abarca algunas
entidades que tienen atributos o características similares.

Por ejemplo, un gato y un tigre tienen similitudes y pertenecen a la
familia de animales Felidae. En este ejemplo, Felidae es el nombre de la
clase y los gatos y los tigres son los miembros de la clase.

El siguiente código muestra cómo declaramos y usamos clases en C++.

.. code:: c++

    #include <iostream>
    using namespace std;
    class Felidae
    {
        public:
        string gatos;
        string tigres;
        void nombreMascota()
        {
        std::cout << "\nEl nombre del gatito es: " << gatos;
        std:: cout << "\nEl nombre del tigre es: " << tigres;
        }
    };
    int main() {
        Felidae objeto1;
        objeto1.gatos = "miauHacker";
        objeto1.tigres = "Pirata";
        objeto1.nombreMascota();
        return 0;
    }

Echemos un vistazo a cómo funciona este código. 1. Aunque ``main`` es el
típico punto de entrada de ejecución en un programa C++, aquí hemos
declarado una clase fuera de ``main``. Es posible declarar una clase
fuera o dentro de ``main``.

2. La clase ``Felidae`` se define con la palabra clave ``class`` y los
   miembros ``gatos`` y ``tigres`` son cadenas con la función
   ``nombreMascota``.

3. Observamos que los especificadores de acceso en una clase están
   definidos por etiquetas, donde los miembros públicos son accesibles
   para todos y los miembros privados solo están disponibles para los
   métodos de clase.

4. En ``main``, hemos tomado un objeto y accedido a los miembros usando
   el operador punto, para luego asignarles un nombres.

5. Un objeto accede a todos los miembros de datos de la clase, por lo
   que podemos crear tantos objetos como necesitemos.

Consejos para nombrar clases
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  Comienza con una letra mayúscula y asigna a la clase un nombre que
   tenga sentido.

-  Asigna a los objetos un nombre que deje claro para qué sirven.

-  Puedes utilizar símbolos, como un guión bajo, en los nombres de las
   clases.

**Ejemplo:** Trabajando con clases.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Clase1
    {
     public:
     int x=40,y;
     void suma()
     {
        std::cout << "\nLa suma is: " <<x+y;
        }
    };
    int main() {
        Clase1 c1;
        Clase1 c2, c3;
        c1.y= 10;
        c2.y = 20;
        c1.suma();
        c2.suma();
    
        return 0;
    }

Constructores y destructores
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Una clase en C++ tiene miembros de datos, como variables de diferentes
tipos y métodos (funciones). Además de estos, hay otra función miembro
especial llamada **constructor**, cuya función principal es inicializar
un objeto de una determinada clase al mismo tiempo que se declara.

Los **destructores** implican ``romper`` o eliminar los objetos creados
por el constructor para no sobrecargar la memoria limitada de la
computadora.

Características de los constructores:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Tiene el mismo nombre que la clase.

2. Pueden hacerse accesibles a nivel público, privado o protegido.

3. No pueden ser heredados ni instanciados por ninguna otra clase.

4. Cada vez que se crea un objeto, se llama al constructor
   predeterminado.

5. En C++, los constructores no se pueden declarar como virtuales.

6. No tienen tipo de retorno.

.. code:: c++

    #include <iostream>
    using namespace std;
    class Driver
    {
        public:
        Driver()
        {
        std::cout << "\nEste es un constructor de la clase Driver\n"
    <<endl;
        }
    };
    
    int main() {
        Driver d1;
        return 0;
    }

Observa que tan pronto como se crea el objeto, se llama al constructor
de la clase ya que tiene la capacidad de sobrecargarse.

Tipos de constructores
~~~~~~~~~~~~~~~~~~~~~~

C++ nos proporciona tres tipos de constructores, cada uno un poco
diferente.

Estos son los siguientes:

1 . Constructores predeterminados
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Estos no toman argumentos y todos los objetos de la clase se inicializan
con el mismo conjunto de valores. Estos son dados por el compilador y
serán 0 o cualquier valor entero.

Si un programador se olvida de definir un constructor explícitamente en
C++, el compilador le proporciona implícitamente el constructor
predeterminado.

La sintaxis para escribir el constructor predeterminado es la siguiente:

.. code:: c++

    class nombre_clase
      { nombre_clase()
    { //....
    }
    };

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Personas
    {
      public:
      Personas()
      {
        std::cout << "\nEste es un constructor predeterminado \n" <<endl;
        }
    };
    
    int main() {
        Personas Objetos1;
        
        return 0;
    }

2 . Constructores Parametrizados
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En un constructor parametrizado podemos pasar uno o más argumentos a la
función miembro para asignar diferentes valores de inicialización a un
objeto a medida que se crea. Ten en cuenta que para llamar a este tipo
de constructor debemos usar el orden correcto y el tipo de argumentos
que se define en el prototipo del constructor.

La sintaxis de un constructor parametrizado es la siguiente:

.. code:: c++

    class nombre_clase
      { nombre_v
          clase(argumentos lista..)
    { //...
    }
    };

.. code:: c++

    #include <iostream>
    using namespace std;
    class Estudiante
    {
      public:
      Estudiante(string n)
      {
        std::cout << "\nEste es un constructor parametrizado " << endl;
        std::cout << "\nEl nombre es " <<n<<endl;
       }
    };
    int main() {
        Estudiante s1("Kapumota");
    return 0;
    }

3. Constructor de copias
^^^^^^^^^^^^^^^^^^^^^^^^

Un constructor de copias ayuda a crear una copia de otro objeto de una
clase. La copia se crea con los mismos valores para todos los miembros
de datos.

La sintaxis para un constructor de copias es la siguiente:

.. code:: c++

    class nombre_clase
    { nombre_clase(argumentos lista..)
        { //...
       }
        nombre_clase(const nombre_clase)
        { //...
        }
     };

.. code:: c++

    #include <iostream>
    using namespace std;
    class Estudiante
    
    {
        public:
        string n;
        /*Estudiante()
        {
        std::cout << "\nEste es un constructor predeterminado \n" <<endl;
        }*/
        Estudiante(string n)
         {
            std::cout << "\nEl nombre es " <<n<<endl;
        }
        Estudiante(const Estudiante& s1)
        {
            std::cout << "\nEste es un constructor copia\n" <<endl;
        }
    };
    int main() {
        //Estudiante s1;
        Estudiante s1("Kapumota");
        Estudiante s3(s1);
        
        return 0;
    }

**Ejemplo:** Escribe código donde se utilizan todos los constructores.

.. code:: c++

    #include <iostream>
    using namespace std;
    class Estudiante
    
    {
        public:
        string n;
        Estudiante()
        {
            std::cout << "\nEste es un constructor predeterminado \n" <<endl;
        }
        Estudiante(string n)
         {
            std::cout << "\nEste es un constructor parametrizado " << endl;
            std::cout << "\nEl nombre es: " <<n<<endl;
        }
        Estudiante(const Estudiante& s2)
        {
            std::cout << "\nEste es un constructor copia\n" <<endl;
        }
    };
    int main() {
        Estudiante s1;
        Estudiante s2("Kapumota");
        Estudiante s3(s2);
        
        return 0;
    }

Los destructores se llaman cuando un objeto ya no está en uso y necesita
ser borrado. Ayudan con la utilización de la memoria para que los
objetos no utilizados no ocupen espacio.

El compilador llama automáticamente a un destructor cada vez que el
objeto parece estar fuera del alcance.

Si deseas hacer la destrucción manualmente usa el operador tilde
``(~)``.

**Características de los destructores**

1. Tienen el mismo nombre que la clase.

2. Ayudan a desasignar la memoria de un objeto no utilizado

3. No toman parámetros y son de un solo tipo, por lo tanto, no se puede
   sobrecargar.

4. La destrucción ocurre en el orden opuesto a la construcción, lo que
   significa que el último objeto creado se elimina primero (LIFO, Last
   In First Out).

La sintaxis para los destructores es la siguiente:

.. code:: c++

    class nombre_clase { nombre_clase(argumentos lista..)
    { //cuerpo del constructor}
    ~nombre_clase()
    { //cuerpo del constructor}};

.. code:: c++

    #include <iostream>
    using namespace std;
    class Estudiante
    
    {
        public:
        Estudiante()
        {
        std::cout << "\nEste es un constructor predeterminado \n" <<endl;
        }
        
        Estudiante(string n)
        {
            
        std::cout << "\nEste es un constructor parametrizado" <<endl;    
        std::cout << "\nEl nombre es " <<n<<endl;
        }
        
        
        Estudiante(const Estudiante& s2)
        {
            std::cout << "\nEste es un constructor copia\n" <<endl;
        }
        
        ~Estudiante()
        {
            std::cout << "\nEste es un destructor para todos.\n" <<endl;
        }
    };
    int main() {
        Estudiante s1;
        Estudiante s2("Kapumota");
        Estudiante s3(s2);
        
        return 0;
    }

El puntero this
~~~~~~~~~~~~~~~

Cada objeto de una clase lleva consigo una copia de todos los miembros
de datos, pero estos acceden a la copia original de las funciones. Puede
ocurrir una situación en la que varios objetos acceden a la misma
función miembro. ¿Cómo se actualizarán los valores dentro de la función?

Este problema se puede resolver usando el puntero ``this``. Este puntero
almacena la dirección de un objeto para permitir que la función miembro
actualice los valores correctos.

Este puntero se puede utilizar en varios lugares y de varias maneras. A
veces, incluso se nos puede ocultar, ya que cuando el compilador se
encuentra con una función miembro, implícitamente agregará ``this`` como
un parámetro de función no estático para realizar un seguimiento de la
dirección para ``recordar`` qué objeto llamó a esta función.

El puntero ``this`` siempre apuntará hacia el objeto o la instancia en
la que se está trabajando actualmente.

Podemos hacer referencia explícita a este puntero ``this`` usándolo
dentro de un constructor o métodos y apuntar a las variables de
instancia que se actualizarán sin cambiar la dirección del puntero.

.. code:: c++

    #include<iostream>
    using namespace std;
    
    class Promedio {
        private:
        int num1;
        int num2;
        int r;
        
        public:
          Promedio (int num1, int num2) {
            this->num1 = num1;
            this->num2 = num2;
        }
        void promedioResultado() {
            cout<<"\nPromedio de num1 y num 2 = "<<(this->num1+this->num2)/2<<endl;
        }
    };
    
    int main () {
        Promedio objeto1(22, 33);
        objeto1.promedioResultado();
        return 0;
    }

Ejemplo 1
^^^^^^^^^

.. code:: c++

    #include <iostream>
    using namespace std;
    class Demo {
    private:
      int num;
      char ch;
    public:
      void colocaMisValores(int num, char ch){
        this->num =num;
        this->ch=ch;
      }
      void muestraMisValores(){
        cout<<num<<endl;
        cout<<ch;
      }
    };
    int main(){
      Demo obj;
      obj.colocaMisValores(100, 'A');
      obj.muestraMisValores();
      return 0;
    }

Aquí puedes ver que tenemos dos miembros de datos ``num`` y ``ch``. En
la función ``colocaMisValores()`` tenemos dos variables locales que
tienen el mismo nombre que el nombre de los miembros de datos. En tal
caso, si deseas asignar el valor de la variable local a los miembros de
datos, no podrás hacerlos hasta que no uses el puntero ``this``, porque
el compilador no sabrá que te estás refiriendo a los miembros de datos
del objeto a menos que se use el puntero. Este es uno de los ejemplos en
los que debes usar el puntero ``this``.

Ejemplo2
^^^^^^^^

.. code:: c++

    #include <iostream>
    using namespace std;
    class Demo {
    private:
      int num;
      char ch;
    public:
      Demo &colocaNum(int num){
        this->num =num;
        return *this;
      }
      Demo &colocaCh(char ch){
        this->num++;
        this->ch =ch;
        return *this;
      }
      void muestraMisValores(){
        cout<<num<<endl;
        cout<<ch;
      }
    };
    int main(){
      Demo obj;
      obj.colocaNum(100).colocaCh('A');
      obj.muestraMisValores();
      return 0;
    }

Otro ejemplo de uso es devolver la referencia del objeto actual para que
puedas encadenar llamadas a funciones. Otro punto importante a tener en
cuenta en este programa es que se incrementa el valor del objeto en la
segunda función y se puede ver en la salida que en realidad incrementó
el valor que establecimos en la primera llamada a la función.

Esto muestra que el encadenamiento es secuencial y los cambios
realizados en los miembros de datos del objeto se retienen para futuras
llamadas de encadenamiento.

**En resumen …**

``this`` identifica ``este`` objeto en el que está operando actualmente.

Cuando tienes una clase, puede tener funciones miembro de dos tipos:
``static`` y ``no-static``. Las funciones miembro ``no-static`` deben
operar en una instancia particular de la clase y necesitan saber dónde
está esa instancia. Para ayudar, el lenguaje define una variable
implícita (es decir, una que se declara automáticamente cuando se
necesita sin que tengas que hacer nada) que se llama ``this`` y que
automáticamente apuntará a la instancia particular de la clase en que
opera la función miembro.

.. code:: c++

    #include <iostream> //https://stackoverflow.com/questions/16492736/what-is-the-this-pointer
    
    class A
    {
    public:
        A() 
        { 
            std::cout << "A::A: construida en " << this << std::endl;
        } 
    
        void decimosHola()
        {
            std::cout << "Hola, soy una instancia de A en " << this << std::endl;
        }
    };
    
    int main(int, char **)
    {
        A a1;
        A a2;
    
        a1.decimosHola();        
        a2.decimosHola();
    
        return 0;
    }

Métodos de clase
~~~~~~~~~~~~~~~~

Hemos discutido las clases y sus miembros, así como los constructores de
funciones. Ahora, consideremos los métodos de clase.

Las funciones de clase se pueden definir dentro o fuera de la definición
de clase.

La llamada de estas funciones se realiza utilizando objetos de la clase
a través del operador punto o del de selección.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    
    class clase1
    {
      public :
      static int num1;
      int y=100,r;
      int suma(int x,int y)
    
        {
        cout << "\nLa suma es = " << x+y<<endl;
        }
        static int asignacion(int x)
        {
            cout << "\nEl valor asignado al entero= " << x<<endl;
        }
        void avg()
        {
            r= (num1+y)/2;
            cout << "\nEl promedio es = " << r<<endl;
            cout << "\nEl nombre is " << n<<endl;
        }
        private:
        string n="Kapumota";
    };
    int clase1::num1=4560;
    int main()
    {
        clase1 obj1,obj2,obj3;
        clase1::asignacion(45);
        obj2.avg();
        obj2.suma(20,27);
        cout << "\nEl valor de la variable estatica : " <<obj1.num1<<endl;
    return 0;
    }

En el código anterior, aparece un nuevo símbolo ``(::)``, que se
denomina operador de resolución de alcance (``scope resolution``) en
C++.

Su función principal es acceder o asignar valor a los miembros estáticos
de una clase.

Usos del operador de resolución de alcance
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  Acceder a variables globales para verificar si tienen nombres en
   ``conflicto`` con alguna de las variables locales

-  Para definir un cuerpo de función particular fuera de la clase

-  Para acceder a miembros de tipos de datos estáticos

-  Usado en herencia

-  Se utiliza para acceder a variables y funciones que existen dentro de
   un alcance específico.

El operador de resolución de alcance nos ayuda a comprender el alcance
de las variables y funciones.

Nos ayuda a ajustar el alcance para asegurarnos de que el código
funcione como queremos.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    int x = 5; // variable global
    
    int main() {
     int x = 10; // variable local
      cout << "Local x: " << x << endl;
      cout << "Global x: " << ::x << endl;
       return 0;
    }

En este ejemplo, hemos definido una variable global llamada ``x`` y una
variable local llamada ``x`` dentro de la función ``main()``. Cuando
usamos el operador de resolución de alcance ``(::x)`` podemos acceder a
la variable global ``x`` desde dentro de la función ``main()``. Esto nos
permite diferenciar entre las variables globales y locales que tienen el
mismo nombre.

En C++, los objetos se crean a partir de clases y el operador de
resolución de alcance se usa para acceder a funciones miembro y
variables de esos objetos. Por ejemplo:

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Clase1 {
    public:
     int x;
     void printX() {
        cout << "X es: " << x << endl;
    }
    };
    
    int main() {
        Clase1 obj;
        obj.x = 5;
        obj.printX();
        return 0;
    }


En este ejemplo, hemos definido una clase llamada ``Clase1``, que
contiene una variable entera pública llamada ``x`` y una función miembro
pública llamada ``printX()``. Luego creamos un objeto de la clase
``Clase1`` llamado ``obj`` y establecemos su valor ``x`` en 5. Luego
podemos usar el operador de resolución de alcance ``(obj.printX())``
para acceder a la función miembro ``printX()`` del objeto ``obj`` que
generará el valor de ``x``.

Incluso cuando se sobrecargan funciones, el operador de resolución de
alcance puede especificar a qué función sobrecargada llamar, en función
de los parámetros pasados a la función.

**Referencia:**
https://learn.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-170&viewFallbackFrom=vs-2017

C++ tiene una característica que habilita funciones en línea
(``inline functions``) en una clase, donde el compilador copia el código
del cuerpo de una función cada vez que se le solicita. Esto produce
resultados más rápidos, por lo que no tenemos que escribir código una y
otra vez.

La sintaxis para llamar funciones en línea es la siguiente:

.. code:: c++

    inline tipoRetorno nombre_funcion(Argumentos Lista....)
    { // cuerpo de la función}

La palabra clave static
~~~~~~~~~~~~~~~~~~~~~~~

En C++, la palabra clave ``static`` declara cualquier variable, miembro
de datos o función como un tipo de constante. Estos valores no se pueden
modificar. Se inicializa solo una vez y solo se usa una copia durante la
vida útil de un programa.

Características de la palabra clave ``static``:

1. Las variables estáticas se inicializan solo una vez en un programa
   C++.

2. Una variable estática puede definirse dentro de una función
   particular o fuera de ella.

3. El alcance de una variable estática es local al bloque donde se usa.

4. Cero es el valor predeterminado proporcionado a una variable estática
   si el programador no lo asigna.

5. La vida útil de una variable estática dura hasta que termina un
   programa y luego se libera el espacio de memoria.

6. Las funciones estáticas se llaman directamente desde el nombre de la
   clase.

La sintaxis de las funciones y variables estáticas es la siguiente:

.. code:: c++

    static DataType var = 10; // da una variable estática
    static returnType function // funcion declarada estática
     { // cuerpo de la función
      }

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class clase1
    {
        public :
        static int num1;
        static int asignacion(int x)
        {
        cout << "\nValor asignado a entero= " << x<<endl;
        }
    };
    int clase1::num1=4560;
    int main()
    {
        clase1 obj1;
        clase1::asignacion(87);
        cout << "\nEl valor de la variable estática : " <<obj1.num1<<endl;
    return 0;
    }

Ejercicios
~~~~~~~~~~

1. Escribe un programa en C++ que ilustre una declaración y definición
   de clase, así como el acceso a los miembros de la clase.

2. Escribe un programa en C++ para representar la llamada de los
   constructores de una clase.

3. Escribe un programa en C++ para representar la llamada de los
   destructores de una clase.

4. Escribe un programa en C++ para una calculadora simple con menú
   usando el concepto de clases.

5. Escribe un programa en C++ para representar las formas de usar la
   palabra clave ``static``.

6. Escribe un programa en C++ para contar y mostrar el número de veces
   que se crea un objeto usando la palabra clave ``static``.

.. code:: c++

    //Tus respuestas


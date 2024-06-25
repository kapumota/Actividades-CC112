Clases, constructores, destructores, puntero this en C++
------------------------------------------

Una clase es un tipo de datos definido por el usuario que consta de
métodos y datos agrupados como miembros (es decir, encapsulados). Una
clase se utiliza para crear objetos que almacenan datos, tienen un
estado y comportamiento definidos. Estos objetos también se conocen como
instancias de una clase. Una clase puede entenderse como una categoría
amplia que agrupa entidades con atributos o características similares.

Por ejemplo, tanto el gato como el tigre comparten similitudes y
pertenecen a la familia de animales Felidae. En este caso, Felidae sería
el nombre de la clase, y los gatos y tigres serían instancias o miembros
de esa clase.

A continuación, se muestra un ejemplo de cómo se declaran y utilizan
clases en C++.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Felidae {
    public:
        string gatos;
        string tigres;
    
        void nombreMascota() {
            std::cout << "\nEl nombre del gatito es: " << gatos;
            std::cout << "\nEl nombre del tigre es: " << tigres;
        }
    };
    
    int main() {
        Felidae objeto1;
        objeto1.gatos = "miauHacker";
        objeto1.tigres = "Pirata";
        objeto1.nombreMascota();
        return 0;
    }


Echemos un vistazo a cómo funciona este código.

Explicación del código:

1. Declaración de la clase: Hemos declarado una clase Felidae fuera de
   la función main. Es posible declarar una clase tanto dentro como
   fuera de main, pero generalmente se declara fuera para mantener el
   código organizado y reutilizable.
2. Definición de la clase: La clase Felidae se define con la palabra
   clave class. Dentro de esta clase, hemos declarado dos miembros de
   datos gatos y tigres de tipo string, y un método nombreMascota que
   imprime los nombres de las mascotas.
3. Especificadores de acceso: Los especificadores de acceso en una clase
   se definen mediante etiquetas como public y private. Los miembros
   públicos son accesibles desde cualquier parte del programa, mientras
   que los miembros privados solo son accesibles desde dentro de la
   clase. En este ejemplo, todos los miembros son públicos, lo que
   significa que pueden ser accedidos directamente desde el objeto.
4. Uso del objeto en main: En la función main, hemos creado un objeto
   objeto1 de la clase Felidae. Luego, hemos asignado nombres a los
   miembros gatos y tigres del objeto usando el operador punto (.).
5. Acceso a los miembros: Un objeto puede acceder a todos los miembros
   de datos y métodos de la clase. En este caso, hemos llamado al método
   nombreMascota del objeto objeto1 para imprimir los nombres asignados.
6. Creación de múltiples objetos: Podemos crear tantos objetos de la
   clase Felidae como necesitemos, y cada objeto tendrá su propio
   conjunto de miembros de datos independientes de otros objetos.

En resumen, este código muestra cómo declarar una clase, definir sus
miembros y métodos, crear un objeto de la clase, y acceder y modificar
sus miembros usando el operador punto.

Consejos para nombrar clases:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Comienza con una letra mayúscula y asigna a la clase un nombre que tenga
sentido y sea representativo de su propósito.

Asigna a los objetos nombres que dejen claro su propósito o uso.

En C++, evita el uso de símbolos como guiones bajos en los nombres de
las clases. En su lugar, utiliza la convención PascalCase o CamelCase
para una mayor claridad y legibilidad.

**Ejemplo:** Trabajando con clases.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Clase1
    {
     public:
     int x=40,y;
     void suma()
     {
        std::cout << "\nLa suma es: " <<x+y;
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

Declaración de la clase: la clase Clase1 se declara con dos miembros de
datos públicos x y y, y un método suma.

-  int x = 40: Inicializa x con el valor 40.
-  int y: Declara y sin inicializarlo.
-  void suma(): Define el método suma que imprime la suma de x y y.

Función main: Es el punto de entrada del programa.

-  Clase1 c1;: Declara un objeto c1 de la clase Clase1.
-  Clase1 c2, c3;: Declara dos objetos adicionales, c2 y c3, de la clase
   Clase1.
-  c1.y = 10;: Asigna el valor 10 al miembro y del objeto c1.
-  c2.y = 20;: Asigna el valor 20 al miembro y del objeto c2.
-  c1.suma();: Llama al método suma del objeto c1, que imprimirá la suma
   de x y y para c1.
-  c2.suma();: Llama al método suma del objeto c2, que imprimirá la suma
   de x y y para c2.

El programa produce el siguiente resultado en la consola:

::

   La suma es: 50
   La suma es: 60

Primera llamada a c1.suma(): \* c1.x es 40 (inicializado en la
declaración de la clase). \* c1.y es 10 (asignado en main). \* La suma
de c1.x y c1.y es 40 + 10 = 50. \* El método suma imprime: La suma es:
50.

Segunda llamada a c2.suma():

-  c2.x es 40 (inicializado en la declaración de la clase).
-  c2.y es 20 (asignado en main).
-  La suma de c2.x y c2.y es 40 + 20 = 60.
-  El método suma imprime: La suma es: 60.

Notas adicionales

-  El objeto c3 se declara pero no se utiliza en este programa.
-  Si intentaras llamar a c3.suma() sin asignar un valor a c3.y,
   obtendrías un comportamiento indefinido porque y no ha sido
   inicializado.
-  La clase Clase1 demuestra cómo los objetos de una clase pueden tener
   diferentes estados (y en este caso) mientras comparten la misma
   funcionalidad (suma).

Constructores y destructores
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Una clase en C++ tiene miembros de datos, como variables de diferentes
tipos y métodos (funciones). Además de estos, hay otra función miembro
especial llamada constructor, cuya función principal es inicializar un
objeto de una determinada clase al mismo tiempo que se declara.

Los destructores implican romper o eliminar los objetos creados por el
constructor para no sobrecargar la memoria limitada de la computadora.

**Características de los constructores**:

-  Mismo nombre que la clase: Un constructor tiene el mismo nombre que
   la clase a la que pertenece.
-  Accesibilidad: Los constructores pueden ser declarados como públicos,
   privados o protegidos, dependiendo de cómo se desee controlar el
   acceso a la creación de objetos de la clase.
-  No heredables: Los constructores no pueden ser heredados ni
   instanciados por ninguna otra clase. \*Invocación automática: Cada
   vez que se crea un objeto, se llama al constructor predeterminado
   automáticamente.
-  No virtuales: En C++, los constructores no se pueden declarar como
   virtuales.
-  Sin tipo de retorno: Los constructores no tienen tipo de retorno, ni
   siquiera void.

.. code:: ipython3

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

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        // Constructor
        Persona(string n, int e) {
            nombre = n;
            edad = e;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25); // Llama al constructor
        p1.mostrarInfo();
        return 0;
    }


En este ejemplo, la clase Persona tiene un constructor que inicializa
los miembros nombre y edad.

**Características de los destructores**:

-  Mismo nombre que la clase: Un destructor tiene el mismo nombre que la
   clase pero precedido por una virgulilla (~).
-  Invocación automática: Un destructor se llama automáticamente cuando
   un objeto sale del ámbito o se elimina.
-  Liberación de recursos: Los destructores se utilizan para liberar
   recursos que el objeto pudo haber adquirido durante su vida, como
   memoria dinámica o manejadores de archivos.
-  No tienen parámetros: Los destructores no pueden tener parámetros, lo
   que significa que no se pueden sobrecargar. \*No tienen tipo de
   retorno: Al igual que los constructores, los destructores no tienen
   tipo de retorno.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        // Constructor
        Persona(string n, int e) {
            nombre = n;
            edad = e;
        }
    
        // Destructor
        ~Persona() {
            cout << "El destructor se está llamando para " << nombre << endl;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25); // Llama al constructor
        p1.mostrarInfo();
        // Destructor se llamará automáticamente aquí al salir del ámbito de `p1`
        return 0;
    }


En este ejemplo, el destructor de la clase Persona imprime un mensaje
cuando se llama. El destructor se invoca automáticamente cuando el
objeto p1 sale del ámbito al final de main.

Tipos de constructores
~~~~~~~~~~~~~~~~~~~~~~

C++ nos proporciona tres tipos de constructores, cada uno un poco
diferente.

Estos son los siguientes:

1 . Constructores predeterminados
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Los constructores predeterminados no toman argumentos y todos los
objetos de la clase se inicializan con el mismo conjunto de valores. Si
un programador no define explícitamente un constructor en C++, el
compilador proporciona implícitamente un constructor predeterminado que
inicializa los miembros de datos a valores por defecto (por ejemplo, 0
para tipos numéricos).

La sintaxis para escribir un constructor predeterminado es la siguiente:

.. code:: ipython3

    class NombreClase {
    public:
        NombreClase() {
            // Código de inicialización predeterminado
        }
    };


.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        // Constructor predeterminado
        Persona() {
            nombre = "Sin nombre";
            edad = 0;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1; // Llama al constructor predeterminado
        p1.mostrarInfo();
        return 0;
    }


En este ejemplo, el constructor predeterminado inicializa el nombre a
“Sin nombre” y la edad a 0. Cuando se crea el objeto p1, se llama
automáticamente al constructor predeterminado.

2 . Constructores parametrizados
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En un constructor parametrizado, podemos pasar uno o más argumentos a la
función miembro para asignar diferentes valores de inicialización a un
objeto al momento de su creación. Es importante tener en cuenta que,
para llamar a este tipo de constructor, debemos usar el orden correcto y
el tipo de argumentos definidos en el prototipo del constructor.

La sintaxis de un constructor parametrizado es la siguiente:

.. code:: ipython3

    class NombreClase {
    public:
        NombreClase(tipo1 arg1, tipo2 arg2, ...) {
            // Código de inicialización
        }
    };


.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        // Constructor parametrizado
        Persona(string n, int e) {
            nombre = n;
            edad = e;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25); // Llama al constructor parametrizado
        Persona p2("Ana", 30);  // Llama al constructor parametrizado
        p1.mostrarInfo();
        p2.mostrarInfo();
        return 0;
    }


En este ejemplo, el constructor parametrizado permite inicializar los
miembros nombre y edad con valores específicos cuando se crea un objeto
de la clase Persona.

3. Constructor de copias
^^^^^^^^^^^^^^^^^^^^^^^^

Un constructor de copias se utiliza para crear una copia de otro objeto
de la misma clase. La copia se crea con los mismos valores para todos
los miembros de datos.

**Características del constructor de copias**

-  Mismo tipo de datos: Los miembros de datos del objeto copiado tienen
   los mismos valores que los del objeto original.
-  Paso por referencia: El constructor de copias toma un argumento que
   es una referencia constante al objeto de la misma clase.

.. code:: ipython3

    class NombreClase {
    public:
        NombreClase(const NombreClase &obj) {
            // Código de inicialización para copiar los miembros de datos
        }
    };


.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        // Constructor parametrizado
        Persona(string n, int e) {
            nombre = n;
            edad = e;
        }
    
        // Constructor de copias
        Persona(const Persona &p) {
            nombre = p.nombre;
            edad = p.edad;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);  // Llama al constructor parametrizado
        Persona p2 = p1;         // Llama al constructor de copias
        p1.mostrarInfo();
        p2.mostrarInfo();
        return 0;
    }


En este ejemplo, el constructor de copias Persona(const Persona &p) crea
una copia del objeto p1 y asigna los mismos valores a p2.

**Ejemplo:** Código donde se utilizan todos los constructores.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Estudiante {
    public:
        string n;
    
        // Constructor predeterminado
        Estudiante() {
            std::cout << "\nEste es un constructor predeterminado\n" << endl;
        }
    
        // Constructor parametrizado
        Estudiante(string nombre) {
            n = nombre;
            std::cout << "\nEste es un constructor parametrizado" << endl;
            std::cout << "\nEl nombre es: " << n << endl;
        }
    
        // Constructor de copias
        Estudiante(const Estudiante& s2) {
            n = s2.n;  // Copia el valor de 'n' del objeto s2
            std::cout << "\nEste es un constructor copia\n" << endl;
            std::cout << "\nEl nombre copiado es: " << n << endl;
        }
    
        // Método para mostrar la información del estudiante
        void mostrarInfo() {
            std::cout << "Nombre del estudiante: " << n << endl;
        }
    };
    
    int main() {
        // Llamada al constructor predeterminado
        Estudiante s1;
        s1.mostrarInfo();
    
        // Llamada al constructor parametrizado
        Estudiante s2("Kapumota");
        s2.mostrarInfo();
    
        // Llamada al constructor de copias
        Estudiante s3(s2);
        s3.mostrarInfo();
    
        return 0;
    }


Este ejemplo muestra cómo utilizar constructores predeterminados,
parametrizados y de copias en C++. Cada constructor tiene su propia
función y se utiliza en diferentes situaciones para inicializar objetos
de manera adecuada.

Métodos no estáticos
~~~~~~~~~~~~~~~~~~~~

En el contexto de programación orientada a objetos en C++, los métodos
no estáticos, también conocidos como métodos de instancia, son aquellos
métodos que operan sobre una instancia específica de una clase. Esto
significa que requieren una instancia del objeto para ser llamados y
pueden acceder y modificar los datos miembros de esa instancia.

**Características de los métodos no estáticos**

-  Acceso a miembros de instancia: Los métodos no estáticos pueden
   acceder a los miembros de datos (variables) y otros métodos de
   instancia de la misma clase. Esto les permite manipular el estado del
   objeto.
-  Uso del puntero this: Dentro de un método no estático, el puntero
   this está implícitamente disponible y apunta a la instancia del
   objeto que invoca el método. Esto permite acceder a los miembros de
   la instancia y llamar a otros métodos de la misma instancia.
-  No pueden rer llamados sin una instancia: A diferencia de los métodos
   estáticos, los métodos no estáticos no pueden ser llamados
   directamente desde la clase sin crear primero una instancia de la
   clase.

A continuación se presenta un ejemplo sencillo que muestra cómo se
definen y utilizan los métodos no estáticos en una clase:

.. code:: ipython3

    #include <iostream>
    #include <string>
    
    class Person {
    private:
        std::string name;
        int age;
    
    public:
        // Constructor
        Person(const std::string& name, int age) : name(name), age(age) {}
    
        // Método no estático para establecer el nombre
        void setName(const std::string& name) {
            this->name = name;
        }
    
        // Método no estático para obtener el nombre
        std::string getName() const {
            return this->name;
        }
    
        // Método no estático para establecer la edad
        void setAge(int age) {
            this->age = age;
        }
    
        // Método no estático para obtener la edad
        int getAge() const {
            return this->age;
        }
    
        // Método no estático para imprimir la información de la persona
        void printInfo() const {
            std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
        }
    };
    
    int main() {
        // Crear una instancia de la clase Person
        Person person("C J", 30);
    
        // Llamar a los métodos no estáticos utilizando la instancia
        person.printInfo();  // Output: Name: C J, Age: 30
    
        // Modificar los miembros de datos utilizando métodos no estáticos
        person.setName("E K");
        person.setAge(25);
    
        // Llamar a los métodos no estáticos nuevamente para ver los cambios
        person.printInfo();  // Output: Name: E K, Age: 25
    
        return 0;
    }


Diferencia entre métodos estáticos y no estáticos
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Métodos estáticos**:

-  No requieren una instancia de la clase para ser llamados.
-  No pueden acceder a los miembros de instancia ni al puntero this.
-  Son útiles para funciones que no dependen de los datos específicos de
   una instancia.

.. code:: ipython3

    class Example {
    public:
        static void staticMethod() {
            std::cout << "This is a static method." << std::endl;
        }
    };
    
    int main() {
        // Llamar al método estático sin crear una instancia de la clase
        Example::staticMethod();
        return 0;
    }


**Métodos no estáticos:**

-  Requieren una instancia de la clase para ser llamados.
-  Pueden acceder a los miembros de instancia y al puntero this.
-  Son útiles para funciones que operan sobre los datos de una instancia
   específica.

El puntero this
~~~~~~~~~~~~~~~

En C++, el puntero this es una característica fundamental que se utiliza
en el contexto de programación orientada a objetos. Es un puntero
implícito que está disponible en todos los métodos no estáticos (o
métodos de instancia, son aquellos métodos que operan sobre una
instancia específica de una clase. Esto significa que requieren una
instancia del objeto para ser llamados y pueden acceder y modificar los
datos miembros de esa instancia.) de una clase y apunta al objeto que
invoca el método.

El puntero this se refiere a la instancia actual de la clase en la que
se está ejecutando el método. En otras palabras, this es un puntero que
contiene la dirección del objeto que llamó al método. Esto permite que
los métodos accedan a los datos miembros del objeto y llamen a otros
métodos en el mismo objeto.

.. code:: ipython3

    class Example {
    public:
        void display() {
            std::cout << "Direccion del actual objeto: " << this << std::endl;
        }
    };
    
    int main() {
        Example obj;
        obj.display();
        return 0;
    }


En este ejemplo, el método display utiliza this para imprimir la
dirección del objeto obj.

Usos comunes del puntero this
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Acceso a miembros de la clase**:

El uso más básico de this es acceder a los miembros de la clase cuando
los nombres de los parámetros del método y los nombres de los miembros
de la clase son idénticos.

.. code:: ipython3

    class Rectangle {
    private:
        int width, height;
    
    public:
        void setDimensions(int width, int height) {
            this->width = width;
            this->height = height;
        }
    
        int area() {
            return this->width * this->height;
        }
    };
    
    int main() {
        Rectangle rect;
        rect.setDimensions(5, 10);
        std::cout << "Area: " << rect.area() << std::endl;
        return 0;
    }


En este caso, this se usa para diferenciar entre los parámetros del
método setDimensions y los miembros de la clase width y height.

**Retorno de referencia al objeto actual:**

En algunos patrones de diseño, como el patrón Builder o para permitir la
concatenación de métodos, es común que un método devuelva una referencia
al objeto actual utilizando this.

.. code:: ipython3

    class Example {
    public:
        Example& setX(int x) {
            this->x = x;
            return *this;
        }
    
        Example& setY(int y) {
            this->y = y;
            return *this;
        }
    
        void print() {
            std::cout << "x: " << x << ", y: " << y << std::endl;
        }
    
    private:
        int x, y;
    };
    
    int main() {
        Example obj;
        obj.setX(10).setY(20).print();
        return 0;
    }


Aquí, setX y setY devuelven \*this, permitiendo la concatenación de
métodos.

**Puntero this en constructores y destructores**:

El puntero this también puede ser utilizado en constructores y
destructores, aunque se debe tener cuidado con el uso en constructores
debido a la posible asignación incompleta del objeto.

.. code:: ipython3

    class MyClass {
    public:
        MyClass(int value) : value(value) {
            std::cout << "El constructor llamó al objeto en: " << this << std::endl;
        }
    
        ~MyClass() {
            std::cout << "El destructor llamó al objeto en: " << this << std::endl;
        }
    
    private:
        int value;
    };
    
    int main() {
        MyClass obj(42);
        return 0;
    }


Este ejemplo muestra cómo this se puede usar para identificar el objeto
en los constructores y destructores.

**Paso de this a funciones externas:**

A veces, es útil pasar el puntero this a funciones externas para operar
sobre el objeto actual.

.. code:: ipython3

    void externalFunction(MyClass* obj) {
        std::cout << "Función externa llamada para objeto en: " << obj << std::endl;
    }
    
    class MyClass {
    public:
        void callExternal() {
            externalFunction(this);
        }
    };
    
    int main() {
        MyClass obj;
        obj.callExternal();
        return 0;
    }


En este caso, this se pasa a la función externalFunction para operar
sobre el objeto obj.

**Uso en un constructor**

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        // Constructor parametrizado usando el puntero this
        Persona(string nombre, int edad) {
            this->nombre = nombre;
            this->edad = edad;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);
        p1.mostrarInfo();
    
        return 0;
    }


En este ejemplo, usamos el puntero this dentro del constructor para
distinguir entre los parámetros del constructor (nombre y edad) y los
miembros de datos de la clase (this->nombre y this->edad).

**Devolviendo *this  para encadenamiento de métodos**

El puntero this también se puede utilizar para devolver una referencia
al objeto actual, permitiendo el encadenamiento de métodos

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        Persona(string nombre, int edad) {
            this->nombre = nombre;
            this->edad = edad;
        }
    
        // Método para establecer el nombre usando encadenamiento
        Persona& setNombre(string nombre) {
            this->nombre = nombre;
            return *this;
        }
    
        // Método para establecer la edad usando encadenamiento
        Persona& setEdad(int edad) {
            this->edad = edad;
            return *this;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);
        p1.setNombre("Pedro").setEdad(30);
        p1.mostrarInfo();
    
        return 0;
    }

En este ejemplo, los métodos setNombre y setEdad devuelven \*this, que
es una referencia al objeto actual, permitiendo así el encadenamiento de
llamadas a métodos.

**Comparando objetos**

El puntero this puede ser útil para comparar el objeto actual con otro
objeto de la misma clase.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        Persona(string nombre, int edad) {
            this->nombre = nombre;
            this->edad = edad;
        }
    
        // Método para comparar dos objetos Persona
        bool esIgualQue(const Persona& otra) {
            return this->nombre == otra.nombre && this->edad == otra.edad;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);
        Persona p2("Juan", 25);
        Persona p3("Pedro", 30);
    
        if (p1.esIgualQue(p2)) {
            cout << "p1 y p2 son iguales" << endl;
        } else {
            cout << "p1 y p2 son diferentes" << endl;
        }
    
        if (p1.esIgualQue(p3)) {
            cout << "p1 y p3 son iguales" << endl;
        } else {
            cout << "p1 y p3 son diferentes" << endl;
        }
    
        return 0;
    }


En este ejemplo, el método esIgualQue compara el objeto actual (this)
con otro objeto Persona, devolviendo true si ambos tienen el mismo
nombre y edad.

**Consideraciones avanzadas**

-  Evitar el uso de this en constructores y destructores para métodos
   virtuales: Es una mala práctica llamar métodos virtuales desde un
   constructor o destructor, ya que el comportamiento puede ser
   inesperado debido a que el objeto puede no estar completamente
   construido o puede estar en proceso de destrucción.
-  Uso de this en sobrecarga de operadores: Al sobrecargar operadores,
   this puede ser útil para retornar referencias al objeto actual y así
   permitir la evaluación encadenada.

.. code:: ipython3

    class MyClass {
    private:
        int value;
    
    public:
        MyClass(int value) : value(value) {}
    
        MyClass& operator+=(const MyClass& other) {
            this->value += other.value;
            return *this;
        }
    
        void print() const {
            std::cout << "Value: " << value << std::endl;
        }
    };
    
    int main() {
        MyClass a(10), b(20);
        a += b;
        a.print();  // Output: Value: 30
        return 0;
    }


En este ejemplo, la sobrecarga del operador += utiliza this para acceder
y modificar el objeto actual y luego retorna \*this para permitir la
encadenación

``*this``: El puntero *this en C++ es una forma de desreferenciar el
puntero implícito this para obtener una referencia al objeto
actual.Cuando desreferencias this con*\ this, obtienes una referencia al
objeto actual en lugar de un puntero. Esto puede ser útil en varios
contextos, como en la implementación de métodos que devuelven una
referencia al objeto actual para permitir la concatenación de métodos o
en la sobrecarga de operadores.

.. code:: ipython3

    #include <iostream>
    #include <string>
    
    class Person {
    private:
        std::string name;
        int age;
    
    public:
        // Constructor
        Person(const std::string& name, int age) : name(name), age(age) {}
    
        // Método no estático para establecer el nombre
        Person& setName(const std::string& name) {
            this->name = name;
            return *this;  // Retorna una referencia al objeto actual
        }
    
        // Método no estático para establecer la edad
        Person& setAge(int age) {
            this->age = age;
            return *this;  // Retorna una referencia al objeto actual
        }
    
        // Método no estático para imprimir la información de la persona
        void printInfo() const {
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }
    };
    
    int main() {
        // Crear una instancia de la clase Person
        Person person("John Doe", 30);
    
        // Usar métodos encadenados para modificar los miembros de datos
        person.setName("Jane Doe").setAge(25);
    
        // Imprimir la información actualizada de la persona
        person.printInfo();  // Output: Name: Jane Doe, Age: 25
    
        return 0;
    }


**Ejercicio:** Explica el código anterior.

**Funciones miembro const y el puntero this**

Cuando una función miembro se declara como const, el puntero this se
convierte en un puntero a un objeto constante (const TipoClase\* const).
Esto significa que dentro de una función miembro constante, no se pueden
modificar los miembros de datos del objeto.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        Persona(string nombre, int edad) {
            this->nombre = nombre;
            this->edad = edad;
        }
    
        // Método const para mostrar la información
        void mostrarInfo() const {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    
        // Método const para comparar dos objetos Persona
        bool esIgualQue(const Persona& otra) const {
            return this->nombre == otra.nombre && this->edad == otra.edad;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);
        Persona p2("Juan", 25);
    
        p1.mostrarInfo();
        p2.mostrarInfo();
    
        if (p1.esIgualQue(p2)) {
            cout << "p1 y p2 son iguales" << endl;
        } else {
            cout << "p1 y p2 son diferentes" << endl;
        }
    
        return 0;
    }


En este ejemplo, los métodos mostrarInfo y esIgualQue son funciones
miembro constantes, lo que garantiza que no modifican el estado del
objeto.

**Ocultamiento del puntero this**

Aunque el puntero this es implícito en todas las funciones miembro no
estáticas, a veces se puede ocultar. Esto ocurre cuando se hace
referencia a los miembros de datos directamente sin utilizar this.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        Persona(string nombre, int edad) {
            // Implícitamente usa this->nombre y this->edad
            nombre = nombre;
            edad = edad;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);
        p1.mostrarInfo(); // Esto imprimirá valores incorrectos porque el constructor no utiliza `this`.
    
        return 0;
    }


En este ejemplo, el constructor no usa explícitamente el puntero this,
lo que provoca que los parámetros del constructor nombre y edad oculten
los miembros de datos de la clase. Esto puede llevar a errores difíciles
de detectar.

**Evitando la ambigüedad con el puntero this**

Para evitar ambigüedades y errores de ocultamiento, es una buena
práctica usar el puntero this explícitamente cuando los nombres de los
parámetros y los nombres de los miembros de datos son iguales.

.. code:: ipython3

    #include <iostream>
    using namespace std;
    
    class Persona {
    public:
        string nombre;
        int edad;
    
        Persona(string nombre, int edad) {
            this->nombre = nombre;
            this->edad = edad;
        }
    
        void mostrarInfo() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    int main() {
        Persona p1("Juan", 25);
        p1.mostrarInfo(); // Ahora imprimirá los valores correctos
    
        return 0;
    }


En este ejemplo, el uso explícito de this en el constructor garantiza
que los miembros de datos de la clase se inicialicen correctamente.

Ejercicios
^^^^^^^^^^

Explica los siguiente códigos.

.. code:: ipython3

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

.. code:: ipython3

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

.. code:: ipython3

    // Tu respuestas

.. code:: ipython3

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

En C++, los métodos de clase son funciones que pertenecen a una clase y
se utilizan para operar sobre los objetos de esa clase o para manipular
datos de la clase. Los métodos de clase se definen dentro de la clase y
se pueden dividir en varias categorías según su propósito y su relación
con los objetos de la clase. Aquí hay una explicación de los tipos más
comunes de métodos de clase en C++:

1 . Métodos de instancia

Estos métodos operan sobre instancias específicas de la clase. Tienen
acceso a los miembros de datos (variables de instancia) de la clase y se
invocan a través de un objeto de la clase.

.. code:: ipython3

    class Persona {
    public:
        void establecerNombre(std::string nombre) {
            this->nombre = nombre;
        }
    
        std::string obtenerNombre() const {
            return nombre;
        }
    
    private:
        std::string nombre;
    };
    
    int main() {
        Persona p;
        p.establecerNombre("Juan");
        std::cout << p.obtenerNombre() << std::endl;
        return 0;
    }


2 . Métodos estáticos

Los métodos estáticos pertenecen a la clase en sí y no a instancias
específicas de la clase. No pueden acceder a los miembros de datos no
estáticos de la clase directamente. Se utilizan para operaciones que no
requieren acceso a los datos de instancia.

.. code:: ipython3

    class Contador {
    public:
        static void incrementarContador() {
            contador++;
        }
    
        static int obtenerContador() {
            return contador;
        }
    
    private:
        static int contador;
    };
    
    int Contador::contador = 0;
    
    int main() {
        Contador::incrementarContador();
        Contador::incrementarContador();
        std::cout << Contador::obtenerContador() << std::endl;
        return 0;
    }



3 . Métodos const

Son métodos que no modifican el estado del objeto. Se declaran con la
palabra clave const al final de la declaración del método. Estos métodos
pueden ser llamados en objetos const.

.. code:: ipython3

    class Punto {
    public:
        Punto(int x, int y) : x(x), y(y) {}
    
        int obtenerX() const {
            return x;
        }
    
        int obtenerY() const {
            return y;
        }
    
    private:
        int x, y;
    };
    
    int main() {
        const Punto p(10, 20);
        std::cout << p.obtenerX() << std::endl;
        std::cout << p.obtenerY() << std::endl;
        return 0;
    }


4 . Métodos virtuales

Se utilizan en clases base para permitir que las clases derivadas
sobrescriban estos métodos. Esto es fundamental para la implementación
de polimorfismo en C++.

.. code:: ipython3

    class Animal {
    public:
        virtual void hacerSonido() const {
            std::cout << "Sonido de animal" << std::endl;
        }
    };
    
    class Perro : public Animal {
    public:
        void hacerSonido() const override {
            std::cout << "Guau" << std::endl;
        }
    };
    
    int main() {
        Animal* a = new Perro();
        a->hacerSonido(); // Llama al método hacerSonido de Perro
        delete a;
        return 0;
    }


5 . Métodos inline

Los métodos inline son aquellos cuya implementación se proporciona en el
mismo lugar donde se declara, dentro de la clase. Esto le sugiere al
compilador que intente expandir el método en el punto de llamada, en
lugar de realizar una llamada de función tradicional, lo que puede
mejorar el rendimiento.

.. code:: ipython3

    class Rectangulo {
    public:
        inline int area() const {
            return ancho * alto;
        }
    
    private:
        int ancho, alto;
    };


**Operador de resolución de alcance**

En el código siguiente, aparece un nuevo símbolo ``(::)``, que se
denomina operador de resolución de alcance (``scope resolution``) en
C++.

Su función principal es acceder o asignar valor a los miembros estáticos
de una clase.

.. code:: ipython3

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

El operador de resolución de alcance nos ayuda a comprender el alcance
de las variables y funciones.

.. code:: ipython3

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

.. code:: ipython3

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

En el contexto de la herencia, el operador :: se usa para acceder a
miembros de la clase base.

.. code:: ipython3

    class Base {
    public:
        void mostrar() {
            std::cout << "Mostrar de la clase base." << std::endl;
        }
    };
    
    class Derivada : public Base {
    public:
        void mostrar() {
            std::cout << "Mostrar de la clase derivada." << std::endl;
            Base::mostrar(); // Llamada a la función mostrar de la clase base
        }
    };
    
    int main() {
        Derivada obj;
        obj.mostrar();
        return 0;
    }


**Referencia:**
https://learn.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-170&viewFallbackFrom=vs-2017

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

.. code:: ipython3

    //Tus respuestas

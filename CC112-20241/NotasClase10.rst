Fundamentos de programación orientada a objetos
-----------------------------------------------

Herencia
~~~~~~~~

La herencia en C++ es un pilar fundamental de la programación orientada
a objetos (OOP). Permite que una clase (conocida como clase derivada)
adopte los atributos y métodos de otra clase (conocida como clase base).
Esto facilita la reutilización de código y puede hacer que la estructura
del programa sea más clara y fácil de entender.

Este concepto de establecer una relación entre clases donde se comparten
algunas de las propiedades se denomina **herencia**.

Alguna terminología adicional para estos temas:

-  Clase padre también conocida como clase base o superclase.

-  Clase hija: también conocida como clase derivada o subclase.

La sintaxis de todo esto es:

::

   class hija : especificador_acceso padre
   {
       // cuerpo de clase
   };

**Ejemplo**

.. code:: c++

    #include <iostream>
    using namespace std;
    
    // Clase base
    class Animal {
    public:
        void comer() {
            cout << "Este animal puede comer." << endl;
        }
    };
    
    // Clase derivada
    class Perro : public Animal {
    public:
        void ladrar() {
            cout << "El perro puede ladrar." << endl;
        }
    };
    
    int main() {
        Perro miPerro;
        miPerro.comer(); // Método heredado de Animal
        miPerro.ladrar(); // Método de Perro
        return 0;
    }


.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Padre {
        public:
        int p=60;
        void mostrarP()
        {
        cout<<"\nLa edad del padre es " <<p<< endl;
        }
    };
    class Hija : public Padre
    {
        public:
        int h=20;
    
       void mostrarH() {
        cout<< "\nLa edad del hijo es " <<h<< endl;
        }
    };
    int main() {
        Hija h1;
        h1.mostrarP();
        h1.mostrarH();
        return 0;
    }

**Pregunta:** Explica el código anterior y todo lo relacionado a la
herencia.

.. code:: c++

    // Tu respuesta

Especificadores de acceso
^^^^^^^^^^^^^^^^^^^^^^^^^

En la herencia, la accesibilidad que tiene una clase a los miembros de
datos de otra clase está definida por los especificadores de acceso.

Hay tres modos de acceso principales disponibles en C++.

1. Público: cualquier clase puede acceder a los miembros de datos
   declarados públicos, independientemente de la relación que tu clase
   tenga con otras clases.

2. Privado: los miembros de datos declarados privados tienen acceso
   limitado disponible solo para las clases base, amiga y derivada.

3. Protegido: los miembros de la clase base y las clases amigas pueden
   acceder a los miembros de datos declarados protegidos.

Ejemplo de uso de especificadores de acceso
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Padre {
        public:
        int p1=60;
        void mostrarP()
        {
          cout<<"\nLa edad del padre es publica " <<p1<< endl;
          cout<<"\nLa edad del padre es privada " <<p2<< endl;
          cout<<"\nLa edad del padre es protegida " <<p3<< endl;
        }
        private:
        int p2=12;
        protected:
        int p3=16;
    };
    
    class Hija : public Padre
    {
        public:
        int h1=20;
    
       void mostrarH() {
          cout<< "\nLa edad del hijo es publica " <<h1<< endl;
          cout<< "\nLa edad del hijo es privada " <<h1<< endl;
          cout<< "\nLa edad del hijo es protegida " <<h3<< endl;
        }
        private:
        int h2;
        protected:
        int h3;
        
    };
    int main() {
        Hija h;
        h.p2= 36;
        h.p3=56
        h.mostrarP();
        h.mostrarH();
        return 0;
    }

**Pregunta**: Explica el código anterior y todo lo relacionado a la
herencia y especificadores de acceso.

.. code:: c++

    // Tu respuesta

Modos de herencia
^^^^^^^^^^^^^^^^^

1. Pública: si una clase se hereda como pública, el acceso definido para
   los miembros de datos en la clase base sigue siendo el mismo en la
   clase derivada también. Es decir, el miembro público tiene acceso
   público, el miembro privado tiene acceso privado y el miembro
   protegido tiene acceso protegido. Este es un método comúnmente
   utilizado para el acceso de herencia.

2. Privado: si una clase se hereda como privada, el acceso definido para
   los miembros de datos en la clase base cambia a privado en la clase
   derivada. Es decir, todos los miembros públicos, protegidos y
   privados tienen rangos privados (inaccesibles).

3. Protegido: si una clase se hereda como protegida, el acceso definido
   para los miembros de datos en la clase base también cambia a
   protegido en la clase derivada. Es decir, los miembros protegidos
   públicos tienen rangos de acceso protegido y el acceso privado sigue
   siendo privado (inaccesible).

**Ejercicio:** Escribe un ejemplo usando todos los modos de herencia
tratados. Explica tus resultados.

Las reglas de acceso pueden parecer difíciles de entender, ya que su
combinación crea un conjunto de nueve miembros de cómo se pueden heredar
la clase y los miembros de la clase.

.. code:: c++

    // Tu respuesta

Tipos de herencia
~~~~~~~~~~~~~~~~~

La herencia en C++ se puede hacer de varias formas y combinaciones. Hay
seis tipos de herencia que se pueden implementar para definir relaciones
entre varias clases.

**1. Herencia simple**

La herencia simple es el tipo de herencia más básico, donde solo hay un
padre y una hija hereda las propiedades.

La sintaxis para la herencia simple es la siguiente:

::

   class Padre
   {
       // cuerpo de clase
   };
   class Hija : modoAcceso Padre
   {
       // cuerpo de clase
   }

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Padre {
        public:
        int p=60;
        void mostrarP()
        {
        cout<<"\nLa edad del padre es " <<p<< endl;
        }
    };
    class Hija : public Padre
    {
        public:
        int h=20;
    
       void mostrarH() {
        cout<< "\nLa edad del hijo es " <<h<< endl;
        }
    };
    int main() {
        Hija h1;
        h1.mostrarP();
        h1.mostrarH();
        return 0;
    }

Como puedes observar en el código anterior, se ha establecido una
relación entre las dos clases mediante herencia simple.

Aquí, solo la clase hija ahora podrá heredar y modificar propiedades de
todos los miembros de la clase padre, ya que su acceso se declara en la
clase base.

Los objetos de la clase hija se pueden acceder a todos los miembros
excepto a los privados de la clase base o padre.

**Herencia multinivel**

La herencia multinivel, como sugiere el nombre, tiene múltiples niveles
de propiedad compartida.

El nivel inferior no hereda directamente las propiedades, pero aún puede
acceder a todos los miembros de datos de los niveles superiores. Puedes
pensar en ello en términos de relaciones familiares.

Este tipo de herencia es similar a cómo un nieto a menudo tiene algunas
características de su abuelo. Los objetos creados solo para el nieto
podrán acceder a todas sus clases anteriores.

La sintaxis para la herencia multinivel es la siguiente:

::

   class A
   {
      // cuerpo de clase
   };
   class B : modoAcceso A
   {
       // cuerpo de clase
   };
   class C : modeoAcceso B
   {
       // cuerpo de clase
   };

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Padre {
        public:
        int p=60;
        void mostrarP()
        {
        cout<<"\nLa edad del padre es " <<p<< endl;
        }
    };
    class Hija : public Padre
    {
        public:
        int h=20;
    
       void mostrarH() {
        cout<< "\nLa edad del hijo es " <<h<< endl;
        }
    };
    
    class Nieto : public Hijo
    {
        public:
        int n=4;
        void mostrarN() {
            cout<< "\nLa edad del nieto es " <<n<< endl;
            ;
        }
    };
    
    int main() {
        Nieto n1;
        n1.mostrarP();
        n1.mostrarH();
        n1.mostrarN();
        return 0;
    }

Puedes ver en el código, hemos establecido una relación entre tres
clases usando herencia multinivel. Aquí, la clase hija ahora podrá
heredar y modificar propiedades de la clase Padre y Hija, ya que su
acceso se declara en la clase base.

Los objetos de la clase Nieto pueden acceder a todos los miembros
excepto a los privados de la clase base o padre.

**Herencia múltiple**

La herencia múltiple es cuando una clase hereda propiedades de otras dos
clases. Tiene muchos usos y los objetos creados para la clase de nivel
inferior pueden acceder a todos los miembros de las dos clases
superiores.

La sintaxis para la herencia múltiple es la siguiente:

::

   class A
   {
       // cuerpo de clase
   };
   class B
   {
       // cuerpo de clase
   };

   class C : modoAcceso A, modoAcceso B
   {
       // cuerpo de clase
   };

**Ejemplo**

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class ClaseA {
    public:
        void metodoA() {
            cout << "Método de Clase A" << endl;
        }
    };
    
    class ClaseB {
    public:
        void metodoB() {
            cout << "Método de Clase B" << endl;
        }
    };
    
    class ClaseC : public ClaseA, public ClaseB {
    };
    
    int main() {
        ClaseC obj;
        obj.metodoA();  // Heredado de ClaseA
        obj.metodoB();  // Heredado de ClaseB
        return 0;
    }


.. code:: c++

    #include <iostream>
    using namespace std;
    
    class ring1
    {
        private :
            string ss;
            float costo;
    
    public:
        void obtenerData()
        {
            cout<<"Ingresa a la seccion de Asientos & Costos: "<<endl;
            cin>>ss>>costo;
        }
        void mostraData()
        {
            cout<<"Asiento : "<<ss<<endl;
            cout<<"Costo: "<<costo<<endl;
        }
    };
    
    class ring2
    {
        private:
            float espectadores[3];
    
        public:
            void obtenerData()
            {
                int i;
                for(i=0;i<3;i++)
                {
                    cout<<"\nIngresa  "<<i+1<<" a la seccion de espectadores ";
                    cin>> espectadores[i];
                }
            }
        
            void mostrarData()
            {
                int i;
                for(i=0;i<3;i++)
                {
                    cout<<"\n"<<i+1<<"Seccion espectadores= "<<espectadores[i];
                }
            }
        };
    
        class arena:public ring1,public ring2
        {
    
            private :
            int invitado;
            
            public:
            
            ring1 r1;
            ring2 r2;
    
            void obtenerData()
            {
                r1.obtenerData();
                cout<<"Ingresa invitado";
                cin>>invitado;
                r2.obtenerData();
            }
            void mostrarData()
            {
               cout<<"\nConteo de invitados= "<<invitado<<endl;
               r2.mostrarData();
            }
        };
    int main()
    {
        arena obj1;
        obj1.obtenerData();
        obj1.obtenerData();
      
       return 0;
    }

En este código, establecimos una relación entre tres clases usando
herencia múltiple. Aquí, la clase hija podrá heredar e incluso modificar
propiedades de las dos clases padres, ya que su acceso se declara en la
clase base.

Los objetos de la clase hija pueden acceder a todos los miembros,
excepto a los privados de la clase base o padre.

**Herencia virtual**

La herencia virtual entra en juego cuando tenemos herencia múltiple,
pero las dos clases que heredan de una superclase en diferentes clases
base tienen el mismo nombre. Ahora, la hija de estas dos clases base
tendrá dos copias de los métodos de la superclase de ambos padres, lo
que se conoce como el `problema del
diamante <https://coderslegacy.com/c/diamond-problem-cpp/>`__.

La solución a este problema es usar la característica de herencia
virtual en C++, donde los dos padres heredan virtualmente de la
superclase.

La sintaxis de la herencia virtual es la siguiente:

::

   class A
   {
       // cuerpo de clase
    };
   class B : modoAcceso virtual A
   {
       // cuerpo de clase
       };
   class C : modoAcceso virtual A
   {
       // cuerpo de clase
       };
   class D : modoAcceso B, modoAcceso C
   {
       // cuerpo de clase
       };

Imagina el siguiente escenario sin herencia virtual:

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Base {
    public:
        int data;
    };
    
    class Derivada1 : public Base {};
    class Derivada2 : public Base {};
    
    class UltimaDerivada : public Derivada1, public Derivada2 {};
    
    int main() {
        UltimaDerivada obj;
        obj.Derivada1::data = 1;  // Accede a la copia de data de Derivada1
        obj.Derivada2::data = 2;  // Accede a la copia de data de Derivada2
    
        cout << "Derivada1 data: " << obj.Derivada1::data << endl;
        cout << "Derivada2 data: " << obj.Derivada2::data << endl;
    
        return 0;
    }


En este ejemplo, UltimaDerivada tiene dos copias separadas de data, una
para cada rama de herencia, lo cual puede ser confuso y propenso a
errores.

La herencia virtual asegura que sólo exista una única instancia de la
clase base, independientemente de cuántas veces sea heredada
indirectamente por otras clases. Aquí está cómo podrías implementar la
herencia virtual para resolver el problema del diamante:

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Base {
    public:
        int data;
    };
    
    class Derivada1 : virtual public Base {};
    class Derivada2 : virtual public Base {};
    
    class UltimaDerivada : public Derivada1, public Derivada2 {};
    
    int main() {
        UltimaDerivada obj;
        obj.data = 10;  // Solo una copia de 'data' es accesible y modificable
    
        cout << "Data: " << obj.data << endl;
    
        return 0;
    }


En este ejemplo, UltimaDerivada tiene solo una copia de data, y se evita
la duplicación y la ambigüedad sobre a cuál instancia de data se accede
o modifica.

**Cómo funciona**

Cuando se declara una clase como herencia virtual, C++ mantiene una
estructura más compleja para manejar cómo se accede a los miembros de la
clase base. Esto incluye un puntero adicional en cada clase derivada,
conocido como el puntero de desplazamiento de base, que se utiliza para
localizar la instancia única de la clase base.

**Consideraciones**

-  Costo de rendimiento: Debido a la complejidad adicional en el manejo
   de clases con herencia virtual, puede haber un pequeño costo de
   rendimiento asociado con su uso. Este costo proviene del manejo
   adicional necesario para resolver el acceso a la base única.
-  Diseño cuidadoso: Aunque la herencia virtual soluciona problemas
   específicos, su uso debe ser cuidadosamente considerado y
   justificado. No es recomendable usar herencia virtual
   indiscriminadamente sin una razón clara, ya que puede complicar el
   diseño de la clase y aumentar la sobrecarga de rendimiento.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class pg
    {
        public:
        int edad;
        void mostrar1()
        {
            cout<<"Ingresa tu edad "<<endl;
            cin>>edad;
        }
    };
    
    class estudiante : public virtual pg
    {
        public :
        string nombre;
        void mostrar2()
        {
            cout<<"Ingresa tu nombre"<<endl;
            cin>>nombre;
    }
    };
    
    class examen: public virtual pg
    {
        public :
    
        int ecode;
        void mostrar3()
        {
            cout<<"Ingresa el codigo del examen"<<endl;
            cin>>ecode;
        }
    };
    
    class external : public estudiante, public examen
    {
        public :
        int calificaciones;
        void mostrar4()
        {
            cout<<"Ingresa tus calificaciones de Nivel 1"<<endl;
            cin>>calificaciones;
        }
        void check()
        {
            if ((edad>17 )&&(calificaciones>65))
        {
            cout<<"\nPermitido para el examen de nivel 2\n";
        }
            else
                cout<<"Empieza a buscar copias de seguridad";
        }
    };
    
    int main()
    {
        external e;
        cout<<"Ingresa tu informacion valida"<<endl;
        e.mostrar1();
        e.mostrar2();
        e.mostrar3();
        e.mostrar4();
        e.check();
        return 0;
    }

En este código, establecimos una relación entre dos clases mediante la
herencia virtual. Esto era necesario para resolver el problema de la
herencia múltiple.

Aquí, solo la clase hija ahora podrá heredar y modificar propiedades de
la clase padre, ya que todos los miembros tienen el mismo acceso que se
declara en la clase base.

Los objetos de la clase hijo pueden acceder a todos los miembros,
excepto a los privados de la clase base o padre.

**Ejercicio:** Escribe un ejemplo de herencia híbrida que es una mezcla
de todos los tipos de herencia que hemos aprendido.

.. code:: c++

    // Tu respuesta

Llamada de constructor
~~~~~~~~~~~~~~~~~~~~~~

En una clase anterior, discutimos la creación de clases y métodos, así
como métodos especiales como constructores y sus diversos tipos. Allí
tratamos con una sola clase, pero con la herencia, siempre habrá más de
una clase. ¿Cómo funciona la llamada al constructor?

**Recuerda**:

-  El constructor de la clase base siempre se llama primero,
   independientemente del objeto creado.
-  La creación de objetos de clases derivadas da como resultado la
   inicialización de todos sus miembros, pero también tiene miembros
   heredados. Por lo tanto, primero se llama al constructor de la clase
   base para permitir que todos los miembros se inicialicen en la clase
   derivada.
-  En el caso de herencia múltiple, el orden de colocación de la clase
   base decidirá a qué constructor se llama.
-  Los destructores siempre se llaman en el orden opuesto al de los
   constructores.

La sintaxis para la llamada al constructor como:

::

   class A
   {
       //cuerpo de clase
       A();
   };
   class B : modoAcceso A
   {
       // cuerpo de clase
       B();
       };
   class C : modoAcceso B
   {
       // cuerpo de clase 
       C();
   };

   C object;

Implementando la herencia
~~~~~~~~~~~~~~~~~~~~~~~~~

La herencia es un importante concepto de programación orientada a
objetos que se utiliza con las clases.

Algunas de las ventajas de la herencia son las siguientes:

1. Reutilización del código: como la relación entre las clases padre y
   hijo permite compartir métodos, no necesitamos escribir el mismo
   cuerpo de código una y otra vez.

2. Estructura: Facilita la comprensión del código, ya que los métodos no
   se repiten y los objetos hijos pueden acceder a todos los métodos
   heredados.

3. Eficiencia: la herencia ahorra mucho tiempo y energía al obtener
   datos de una clase para obtener el resultado.

4. Extensibilidad: las clases (así como los miembros) pueden ampliar sus
   características y funcionalidades a través de clases derivadas.

El siguiente ejemplo de herencia destaca su importancia y facilidad de
uso.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class persona
    {
        public:
        int edad;
        void mostrar1()
        {
            cout<<"Ingresa tu edad "<<endl;
            cin>>edad;
        }
    };
    
    class estudiante : public persona
    {
        public :
        int ugYear;
        void mostrar2()
        {
            cout<<"Ingresa cuando fue tu aprobacion de pregrado"<<endl;
            cin>>ugYear;
        }
    };
    
    class examen: public estudiante
    {
        public :
        void check()
        {
            if ((edad>18 )&&(ugYear ==2021 || ugYear ==2022))
                cout<<"\nPuedes presentarte al CAT 2022\n";
            else
                cout<<"No puedes presentarte al CAT 2022";
        }
    };
    
    int main()
    {
        examen e;
        cout<<"Ingresa tu informacion valida"<<endl;
        e.mostrar1();
        e.mostrar2();
        e.check();
        return 0;
    }

**Ejercicios**

1. Escribe un programa en C++ para crear una clase base llamada
   ``Stack`` y una clase derivada llamada ``MiStack``. Escriba un
   programa para usar estas clases para manipular objetos.

2. Escribe un programa en C++ para representar la herencia multinivel
   usando entidades de la vida real.

3. Escribe un programa en C++ para mostrar el acceso a clases privadas,
   públicas y protegidas usando la herencia.

4. Escribe un programa en C++ para representar el propósito de un
   constructor en herencia simple.

5. Escribe un programa en C++ para representar el propósito de un
   constructor en la herencia virtual.

6. Escribe un programa en C++ para representar el propósito de un
   constructor en la herencia híbrida.

.. code:: c++

    ## Tus respuestas

Polimorfismo
~~~~~~~~~~~~

El polimorfismo nos proporciona múltiples formas de un método con
diferentes firmas pero con el mismo nombre. Los métodos pueden existir
en múltiples formas al variar los tipos de parámetros y la cantidad de
parámetros que toman en la firma de una función.

Hay dos tipos principales de polimorfismo: polimorfismo en tiempo de
compilación y polimorfismo en tiempo de ejecución.

Consideremos un ejemplo de sobrecarga de la función ``f2`` y cómo
funciona el polimorfismo.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    void f2(int i)
    {
        cout << "El entero es  " << i << endl;
    }
    
    void f2(double f)
    {
        cout << "El flotante es " << f << endl;
    }
    
    void f2(char const *c)
    {
        cout << "El caracter es " << c << endl;
    }
    int main()
    {
        f2(11);
        f2(11.11);
        f2("Eleven");
        
        return 0;
    }

Este código muestra que la función ``f2`` de la clase existe en
múltiples formas. Este tipo de polimorfismo se implementa mediante
sobrecarga de funciones.

Todas las funciones tienen el mismo nombre pero firmas diferentes. Es
decir, tienen diferentes combinaciones y números de parámetros.

Al llamar a la función ``f2``, tenga en cuenta qué firma llama a qué
función.

Enlace estático
^^^^^^^^^^^^^^^

El enlace estático o anticipado (polimorfismo en tiempo de compilación)
indica qué procedimiento se llamará en tiempo de compilación.

El código dentro del procedimiento se conoce antes de la ejecución y
ambos se unen en el momento de la ejecución, de ahí el nombre de enlace
anticipado.

Se implementa en C++ mediante llamadas a funciones normales, con
sobrecarga de funciones y sobrecarga de operadores.

La ejecución de un programa es más rápida.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class persona
    {
        public:
        int edad;
        void mostrar1()
        {
            cout<<"Ingresa tu edad "<<endl;
            cin>>edad;
        }
    };
    
    class estudiante : public persona
    {
        public :
        int ugYear;
        void mostrar2()
        {
            cout<<"Ingresa cuando fue tu aprobacion de pregrado"<<endl;
            cin>>ugYear;
        }
    };
    
    class examen: public estudiante
    {
        public :
        void check()
        {
            if ((edad>18 )&&(ugYear ==2021 || ugYear ==2022))
                cout<<"\nPuedes presentarte al CAT 2022\n";
            else
                cout<<"No puedes presentarte al CAT 2022";
        }
    };
    
    int main()
    {
        examen e;
        cout<<"Ingresa tu informacion validad"<<endl;
        e.mostrar1();
        e.mostrar2();
        e.check();
        return 0;
    }

Este código muestra que la función ``mostrar`` de la clase existe en
múltiples formas.

El enlace estático se implementa aquí mediante la sobrecarga de
funciones. Todas las funciones tienen el mismo nombre, pero firmas
diferentes. Es decir, tienen diferentes combinaciones y números de
parámetros.

Al llamar a la función de muestra, ten en cuenta qué firma llama a qué
función. Aquí, el compilador conoce el código adjunto a la llamada de
función solo en el momento de la compilación.

**Enlace dinámico**

El enlace dinámico o tardío (polimorfismo en tiempo de ejecución) indica
qué procedimiento se llamará en tiempo de ejecución. El código dentro
del procedimiento no se conoce hasta la ejecución, de ahí el nombre de
enlace tardío.

Está implementado en C++ usando funciones virtuales. La ejecución de un
programa es más lenta.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class persona
    {
        public:
        virtual void mostrar()
        {
            cout<<"Ingresa tu edad "<<endl;
        }
    };
    
    class estudiante : public persona
    {
        public :
        void mostrar() // sobreescrito
        {
            cout<<"Ingresa cuando fue tu aprobacion de pregrado"<<endl;
        }
    };
    
    
    int main()
    {
        estudiante s;
        persona e;
          cout<<"Ingresa tu informacion validad"<<endl;  
      s.mostrar();
      e.mostrar();
        return 0;
    }

**Pregunta:** Explica que hace el anterior código relacionado con el
enlace dinámico.

.. code:: c++

    // Tu respuesta

Lectura:
https://www.techiedelight.com/difference-between-static-dynamic-binding-cpp/

Interfaces e implementaciones
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

A veces, un bloque de código debe redefinirse una y otra vez debido a
las necesidades de las clases hijas.

Para esto, C++ proporciona interfaces, que no conducen a una
implementación directa y solo declaran métodos.

Veamos algunas de las características de una interfaz:

-  No se da ningún método de implementación, solo se ocupan de la parte
   de la declaración.
-  Es responsabilidad de la clase que implementa una interfaz
   implementar los métodos también.
-  No podemos definir variables dentro de nuestra interfaz.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class Interfaz1
    {
        public:
        virtual void func() = 0;
        void metodo1()
        {
        cout<<"\nMetodo de la clase padre"<<endl;
        }
    };
    
    class hijo1: public Interfaz1
    {
        public:
        void func()
        {
        cout<<"\nMetodo padre redefinido "<<endl;
        }
    };
    
    int main()
    {
        cout<<"\nInterfaces"<<endl;
        hijo1 h1;
        h1.func();
        h1.metodo1();
        
        return 0;
    }

Aquí se aplica el concepto de interfaz. El enlace estático se implementa
mediante la sobrecarga de funciones.

El método se redefine en la clase hija, ya que puede heredar y modificar
propiedades.

Los siguientes son algunos términos más y sus definiciones para aclarar
el concepto de interfaz en C++.

-  Una función virtual es un tipo de función que se declara y se define
   en la clase padre o base y se redefine en la clase hija.

-  Una función virtual pura es un tipo de función que solo se declara
   pero nunca se implementa o redefine.

-  Una clase abstracta (ABC) es un tipo de clase que tiene solo una
   función virtual pura. Esto significa que solo se declara y nunca se
   define, lo que ayuda a todas las clases hijas a heredar y redefinir
   los miembros según sea necesario.

Sobreescritura y sobrecarga de funciones
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora pasamos a un tipo de polimorfismo que usaremos con frecuencia y
que se implementa a través de funciones y sus diferentes estados.

(Debes practicar este concepto redefiniendo el estado y el tipo de
función que crea y observar cómo se lleva a cabo la llamada de estos
objetos de uso).

**Sobrecarga de funciones**

Implementación de polimorfismo en tiempo de compilación. No se requiere
herencia. Sobrecarga de funciones tiene el mismo nombre pero firmas
diferentes. El tipo de parámetro, el número y el orden se pueden
cambiar.

La sobrecarga puede ocurrir varias veces.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    void mostrar(int i)
    {
        cout << " El entero es " << i << endl;
    }
    
    void mostrar(double f)
    {
        cout << "El entero es " << f << endl;
    }
    
    void mostrar(char const *c)
    {
        cout << " El numero de caracteres es " << c << endl;
    }
    
    int main()
    {
        cout<<"Se muestra la funcion sobrecargada "<<endl;
        mostrar(11);
        mostrar(11.11);
        mostrar("Eleven");
        return 0;
    }

En este código, la función ``mostrar`` de la clase existe en múltiples
formas.

El polimorfismo se está implementando mediante la sobrecarga de
funciones. Todas las funciones tienen el mismo nombre, pero firmas
diferentes. Es decir, tienen diferentes combinaciones y números de
parámetros.

Al llamar a la función ``mostrar``, ten en cuenta qué firma llama a qué
función.

**Sobreescritura de funciones**

Implementación de polimorfismo en tiempo de ejecución. La herencia
siempre es necesaria.

Una función sobreescritura tiene el mismo nombre y firmas. No es
necesario cambiar el tipo de parámetro, el número y el orden.

La sobreescritura ocurre solo una vez en un programa C++.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class persona
    {
        public:
        int edad;
        void mostrar()
        {
            cout<<"Ingresa tu edad "<<endl;
            cin>>edad;
        }
    };
    
    class estudiante : public persona
    {
        public :
        int ugYear;
        void mostrar()
        {
            cout<<"Ingresa cuando fue tu aprobacion de pregrado"<<endl;
            cin>>ugYear;
        }
    };
    
    class examen: public estudiante
    {
        public :
        void check()
        {
            if ((edad>18 )&&(ugYear ==2021 || ugYear ==2022))
                cout<<"\nPuedes presentarte al CAT 2022\n";
            else
                cout<<"No puedes presentarte al CAT 2022";
        }
    };
    
    int main()
    {
        examen e;
        cout << "Se muestra la funcion sobreescrita" <<endl;
        cout<<"Ingresa tu informacion validad"<<endl;
        e.mostrar();
        e.check();
        return 0;
    }

**Pregunta:** Explica que hace el anterior código relacionado con la
sobreescritura de funciones.

.. code:: c++

    // Tu respuesta

Funciones friend y genéricas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

La función ``friend`` es una función no miembro de una clase que tiene
acceso como una función normal pero se declara con la palabra del
lenguaje ``friend``.

La sintaxis para una función ``friend`` es la siguiente:

::

   class nuestraClase

   { //cuerpo

       friend returnType funcion1(Paramters list...);

   };

**Características de las funciones ``friend``**

-  Es declarado con la palabra clave ``friend`` solo una vez, ya sea con
   un alcance global o en otra clase.
-  Puede tener cualquier tipo de acceso en una clase: público, privado o
   protegido.
-  Estas se invocan sin ningún objeto u operador de punto.
-  Los objetos se pueden pasar como argumentos
-  Tiene acceso a todos los miembros de datos de una clase (incluidos
   los privados), aunque no sea una función miembro.

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class claseEjemplo
    {
        friend int funcionAmiga(int a, int b);
    };
    int funcionAmiga(int a, int b)
        {
        }
            return a+b;
    int main()
    {
        int a,b;
        cout<<"Ingresa numeros para sumar"<<endl;
        cin>>a>>b;
        cout<<"La suma es "<<myfriend(a,b)<<endl;
        return 0;
    }

Este código muestra cómo se realiza la función ``friend``. Esta función
puede declararse dentro de una clase y definirse fuera de la clase.

Funciones genéricas
^^^^^^^^^^^^^^^^^^^

En una situación en la que una función normal se usa más de una vez,
necesitamos que los parámetros sobre los que actúa la función sean de
diferentes tipos de datos. Esto es posible usando funciones genéricas en
C++.

Estos actúan como una plantilla para diferentes tipos de parámetros para
dar los resultados deseados.

**Características de las funciones genéricas**

-  El código fuente sirve como plantilla y por lo tanto, el código es el
   mismo para todas las funciones, pero cuando se compilan las
   diferentes copias del código, hay resultados diferentes porque hay
   diferentes tipos de argumentos.
-  Las plantillas de clase también se pueden usar de manera similar a
   las funciones genéricas.
-  Estas funciones ayudan a disminuir la sobrecarga de funciones.
-  A los parámetros también se les puede dar un valor predeterminado, si
   es necesario.

La sintaxis para una función genérica es la siguiente:

::

   template <typename T> T mytemplate(T paramter1, T parameter2)
   {
      //codigo 
   }

**Ejemplo**

.. code:: c++

    #include <iostream>
    using namespace std;
    
    class unaClase
    {
    public:
        
        void swapR(int &a,int &b)
        {
            cout<<"Intercambio usando una llamada por referencia que cambia lo que es visible "<<endl;
            a= a+b;
            b= a-b;
            a= a-b;
        }
        void swapP(int *a,int *b)
        {
        
        cout<<"Intercambio mediante el uso de la llamada por punteros"<<endl;
            *a= *a + *b;
            *b= *a - *b;
            *a= *a - *b;
            }
        }c1;
    
    int main()
    {
        int a,b;
        cout<<"Ingresa los numeros a intercambiar"<<endl;
        cin>>a>>b;
        cout<<"Despues de intercambiar A= "<<a<<" B="<<b<<endl;
        c1.swapR(a,b);
        cout<<"Despues de intercambiar A= "<<a<<" B="<<b<<endl;
        c1.swapP(&a,&b);
        cout<<"Despues de intercambiar A= "<<a<<" B="<<b<<endl;
        
        return 0;
    }

Espacio de nombres
~~~~~~~~~~~~~~~~~~

Los espacios de nombres en C++ organizan lógicamente todos los
identificadores (variables, métodos y clases) para que se definan y
declaren bajo un nombre o un espacio. Esto crea un borde lógico entre
varios elementos y el alcance creado para acceder a los miembros del
espacio de nombres.

En el programa, podemos usar espacios de nombres ya definidos como
``std::`` o definir nuestro propio espacio usando la palabra clave
``namespace``.

**Características de los espacios de nombres**

-  Los espacios de nombres creados con el mismo nombre pero con
   diferentes estados o alcances pueden existir en C++.
-  No se requieren especificadores de acceso para las declaraciones de
   espacios de nombres.
-  Es posible anidar espacios de nombres (un espacio de nombres dentro
   de otro espacio de nombres).
-  No es una clase, por lo que no se utiliza punto y coma en la
   definición.
-  Las declaraciones de espacio de nombres realizadas solo serán
   visibles para un alcance global.

La sintaxis para el espacio de nombres es el siguiente:

::

   namespace espacio1
   {
       // codigo
   } espacio1: : identificadores;

.. code:: c++

    #include <iostream>
    using namespace std ;
    namespace espacio1
    
    {
    void nFunc()
    {
        cout << "\nFuncion de espacio1 llamada" << endl;
        }
    }
    
    namespace espacio2
    {
    void nFunc()
    {
        cout << "\nFuncion de espacio2 llamada" << endl;
        }
    }
    
    int main ()
    {
        espacio1::nFunc();
        espacio2::nFunc();
        
        return 0;
    }

En este código, se declaran los espacios de nombres. Se definen dos
funciones dentro de los espacios de nombres. Se llama a la función
``nFunc`` mediante el operador de resolución de alcance.

**Ejercicios:**

1. ¿Qué es el polimorfismo en C++? Describe la sintaxis para usarlo con
   ejemplos.
2. ¿Cuál es la diferencia entre tiempo de compilación y tiempo de
   ejecución en polimorfismo?
3. Escribe un programa en C++ para demostrar el uso del polimorfismo en
   tiempo de ejecución.
4. Escribe un programa en C++ que ilustre el uso de funciones virtuales
   puras.
5. Escribe un programa en C++ para representar el uso de una clase base
   abstracta.
6. Escribe un programa en C++ para mostrar una base de datos de
   estudiantes usando varios aspectos del polimorfismo.

.. code:: c++

    // Tus respuestas

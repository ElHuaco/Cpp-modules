- [Documentación](https://cplusplus.com/reference/)
  1. [STL vs standard library](https://stackoverflow.com/questions/5205491/whats-the-difference-between-stl-and-c-standard-library)
  2. [¿Qué es la STL?](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
- Teoría
  1. M00:
  	**¿Por qué public/private?** -> Private data members exist so that the class can have access to them while everything else can't. For instance, a vector has a private data member that stores the size of the vector. If you let this be public, the client could just change this to whatever it wanted, and any functionality that relied on knowing the size would be greatly hindered.
	In general, you want most of your data members to be private, and if you want to give the client access to them, you define get/set functions that can test for valid input before changing the value.
  2. M01:
 	**¿Por qué references en ex05?** -> Porque nos ahorramos problemas de Lifetime así, que podrían surgir con los punteros a atributos de instancias terminadas de la clase. _"Lifetime Safety: When you don't dereference a possible invalid pointer"_
	**¿Por qué references en HumanA pero pointers en HumanB?** -> la weapon no se crea con el constructor en HumanB, así que no puede ser reference. La weapon sí lo hace en HumanA, así que puede ser reference, que es mejor en este caso por ser constante y tener la misma lifetime (el atributo) que la instancia.
	**¿Por qué sólo un "if" en ex08?** -> para usar [arrays de punteros a funciones miembro](https://www.cs.technion.ac.il/users/yechiel/c++-faq/array-memfnptrs.html)
  3. M02:
  	**operator=** -> in the copy assignment operator we need to check that the address we’re giving by parameter is not our own address. If we don’t do it, we’d be leaking memory or destroying our own object.
  	[Reglas de operator overloads](https://stackoverflow.com/a/4421708/12320117)
  	**¿Por qué no hay class overload del operator<< ?** -> You can overload operator<< as a member function. But you can't write a member operator<< that takes an ostream on the left side, and your class on the right side. [Uso overloads operator<<](https://stackoverflow.com/a/9814453/12320117)
	**Uso istringstreams para parseo aritmetico** -> [idea](https://codereview.stackexchange.com/questions/32155/arithmetic-expression-parsing-and-converting-infix-to-postfix-notation)
  4. M03:
	**Niveles de encapsulación del inheritance** -> This access specifier limits the most accessible level for the members inherited from the base class: The members with a more accessible level are inherited with this level instead, while the members with an equal or more restrictive access level keep their restrictive level in the derived class. Por ej., class Animal : protected Pony haría heredar a Pony todos los miembros públicos de Animal como protected.
	**Herencia de constructores** -> Los constructores de la clase base se llaman cuando se usan los constructores de la clase derivada. Puede configurarse qué constructor de la base se llama usando la misma sintáxis que las listas de inicialización:
	derived_constructor_name (parameters) : base_constructor_name (parameters) {...}.
	**Inheritance Múltiple** -> Tiene el problema del diamante del [destino.](https://en.wikipedia.org/wiki/Virtual_inheritance)
  5. M04:
  	**Link dinámico de métodos con clases abstractas** -> Failure to override a pure virtual function in a derived class, then attempting to instantiate objects of that class, is a compilation error.
	**Necesidad de destructores virtuales en clases derivadas** -> [Link](https://stackoverflow.com/a/461224/12320117), To sum up, always make base classes' destructors virtual when they're meant to be manipulated polymorphically.
	**Deep copy vs Shallow copy** -> When designing classes that handle dynamically allocated memory, memberwise (shallow) copying can get us in a lot of trouble! This is because shallow copies of a pointer just copy the address of the pointer -- it does not allocate any memory or copy the contents being pointed to!  A deep copy allocates memory for the copy and then copies the actual value, so that the copy lives in distinct memory from the source.
  6. M05:
 	**Clases nested** -> [Link](https://en.cppreference.com/w/cpp/language/nested_types)
	**Throw termina la función** -> [Link](https://stackoverflow.com/a/16854349/12320117)
	**¿Qué significa throw() en la declaración de una función?** -> Que no va a tirar ella misma exceptions. Esto se usa en las funciones que tratan exceptions, para que no tiren ellas mismas otra.
	**Exceptions en constructores** -> [Link](http://www.gotw.ca/publications/mill13.htm)
  7. M06:
  	**Casts en C** -> Teníamos Type Conversions (Cast), Type Reinterpretations (Identity Cast), Type Qualifier Reinterpretations (Identity Cast + qualifier cast).
	**Casts según Inheritance** -> La inheritance en C++ introduce una nueva jerarquía. Los Type Reinterpretations sobre ésta se llaman Upcast (hacia más concreto) y Downcast (hacia la base).
	**C++ Type conversions** -> static_cast < type > (var)
	**C++ Upcast, Downcast** -> static_cast < type * > (ptr). No admite clases sin relación.
	**C++ abstract Downcasts** -> dynamic_cast < type &/* > (var). Para downcasts de clases con polimorfismo. Comprobado al ejecutar.
	**C++ reinterpret_cast** -> hace Type Reinterpretation, Upcast y Downcast.

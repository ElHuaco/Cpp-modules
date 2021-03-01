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
  	[Reglas de operator overloads](https://stackoverflow.com/a/4421708/12320117)
  	**¿Por qué no hay class overload del operator<< ?** -> You can overload operator<< as a member function. But you can't write a member operator<< that takes an ostream on the left side, and your class on the right side. [Uso overloads operator<<](https://stackoverflow.com/a/9814453/12320117)
	**Uso istringstreams para parseo aritmetico** -> [idea](https://codereview.stackexchange.com/questions/32155/arithmetic-expression-parsing-and-converting-infix-to-postfix-notation)

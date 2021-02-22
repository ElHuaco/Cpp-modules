- [Documentación](https://cplusplus.com/reference/)
  1. [STL vs standard library](https://stackoverflow.com/questions/5205491/whats-the-difference-between-stl-and-c-standard-library)
  2. [¿Qué es la STL?](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
- Teoría
  1. M00:
    i. ¿Por qué public/private? -> Private data members exist so that the class can have access to them while everything else can't. For instance, a vector has a private data member that stores the size of the vector. If you let this be public, the client could just change this to whatever it wanted, and any functionality that relied on knowing the size would be greatly hindered.

In general, you want most of your data members to be private, and if you want to give the client access to them, you define get/set functions that can test for valid input before changing the value.

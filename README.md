# kalman_filtering

Implementation of kalman filter in C++

#### Libraries
- Eigen3. Check it using ```pkg-config --modversion eigen3```

#### Notes

##### cmake

```cmake_minimum_required``` - Sets the required version of the cmake for the project.\
```project()``` - Sets the name of the project, and stores it in the variable PROJECT_NAME. When called from the top-level CMakeLists.txt also stores the project name in the variable CMAKE_PROJECT_NAME.\
```set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")``` Set the compiler option to C++11\

```
set(SOURCE_FILES kalman.cpp kalman-test.cpp)
add_executable(kalman-test ${SOURCE_FILES})
```
Setting multiple source files for compilation.

##### C++

- ```#include <Eigen/Dense>``` - The Eigen/Dense header file defines all member functions for the MatrixXd type and related types (see also the table of header files). All classes and functions defined in this header file (and other Eigen header files) are in the Eigen namespace.

- ```#pragma once``` - The use of #pragma once can reduce build times, as the compiler won't open and read the file again after the first #include of the file in the translation unit. It's called the multiple-include optimization.

- Constructor: A constructor of a class can be defined as a container which is automatically called whenever a new object of this class is created, allowing the class to initialize member variables or allocate storage. This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void. 

- Constructor Overloading: In general instead of using different members with different arguments but providing the same functionality you can define a constructor of that class to use it again and again with different arguments. Like any other function, a constructor can also be overloaded with different versions taking different parameters: with a different number of parameters and/or parameters of different types. The compiler will automatically call the one whose parameters match the arguments

- Default Constructor: The default constructor is the constructor that takes no parameters, and it is special because it is called when an object is declared but is not initialized with any arguments.

- Function Overloading (Overloaded Functions): In C++, two different functions can have the same name if their parameters are different; either because they have a different number of parameters, or because any of their parameters are of a different type. Note that a function cannot be overloaded only by its return type. At least one of its parameters must have a different type.

- There is also a concept of function template which we will look at later.

- Member Initialization: When a constructor is used to initialize other members, these other members can be initialized directly, without resorting to statements in its body. This is done by inserting, before the constructor's body, a colon (:) and a list of initializations for class members.\
Example: ```Rectangle::Rectangle (int x, int y) : width(x), height(y) { }```


- ```::``` Scope Operator: The scope operator (::) specifies the class to which the member being defined belongs, granting exactly the same scope properties as if this function definition was directly included within the class definition. 

- ```this```: The this pointer is a pointer accessible only within the nonstatic member functions of a class, struct, or union type. It points to the object for which the member function is called. Static member functions don't have a this pointer.

- Different constructors are overloaded to initialize different values. For this code I have not included all the constructors in the source file.


#### References
1. http://www.cplusplus.com/doc/tutorial/classes/
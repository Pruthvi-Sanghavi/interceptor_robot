# kalman_filtering

Implementation of kalman filter in C++

#### Libraries
- Eigen3. Check it using ```pkg-config --modversion eigen3```

#### cmake file
```cmake_minimum_required``` - Sets the required version of the cmake for the project.\
```project()``` - Sets the name of the project, and stores it in the variable PROJECT_NAME. When called from the top-level CMakeLists.txt also stores the project name in the variable CMAKE_PROJECT_NAME.\
```set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")``` Set the compiler option to C++11\

#### Notes

```#include <Eigen/Dense>``` - The Eigen/Dense header file defines all member functions for the MatrixXd type and related types (see also the table of header files). All classes and functions defined in this header file (and other Eigen header files) are in the Eigen namespace.

```#pragma once``` - The use of #pragma once can reduce build times, as the compiler won't open and read the file again after the first #include of the file in the translation unit. It's called the multiple-include optimization.

- Constructor: A constructor of a class can be defined as a container which is automatically called whenever a new object of this class is created, allowing the class to initialize member variables or allocate storage. This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void. 

- Constructor Overloading: In general instead of using different members with different arguments but providing the same functionality you can define a constructor of that class to use it again and again with different arguments. Like any other function, a constructor can also be overloaded with different versions taking different parameters: with a different number of parameters and/or parameters of different types. The compiler will automatically call the one whose parameters match the arguments

- Default Constructor: The default constructor is the constructor that takes no parameters, and it is special because it is called when an object is declared but is not initialized with any arguments.





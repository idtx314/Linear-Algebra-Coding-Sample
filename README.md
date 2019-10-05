## Introduction
This is a C++ code sample containing a simple header library that provides  Matrix Multiplication and Transposition functions in a portable C++ package.

The sample includes 3 files, which are located in the "Davis-Ian" directory:

* [Deployment Manual][Manual]: A more detailed set of instructions in plaintext for compiling against the library and including it in code.  
* [linalg.h][Header]: A header library containing the linear algebra functions and related objects.  
* [main_example.cpp][Demonsrator]: A script that performs unit testing and demonstrates the functionality in the library.  



## Basic Compiling and Validation
"main_example.cpp" is intended to both demonstrate the functionality of the library and validate the functions with terminal output.

When compiling main_example.cpp, keep it in the same directory as linalg.h and use the C++11 standard. Any compiler that complies with the standard should work. For detailed instructions reference the [Deployment Manual][Manual-Compiling] included in the sample.

If using g++, you can navigate your command line interface to the directory containing the source files and enter the command:
    "g++ main_example.cpp -std=c++11"


## Advanced Usage
Refer to the [Deployment Manual][Manual] included in the package for detailed information on functions, compilation instructions, and integration of the package into an application.



[Manual]:https://github.com/idtx314/Linear-Algebra-Coding-Sample/blob/master/Davis-Ian/Deployment%20Manual.txt
[Manual-Compiling]:https://github.com/idtx314/Linear-Algebra-Coding-Sample/blob/master/Davis-Ian/Deployment%20Manual.txt#L66
[Header]:https://github.com/idtx314/Linear-Algebra-Coding-Sample/blob/master/Davis-Ian/linalg.h
[Demonstrator]:https://github.com/idtx314/Linear-Algebra-Coding-Sample/blob/master/Davis-Ian/main_example.cpp

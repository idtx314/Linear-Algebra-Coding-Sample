/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Copyright and Licensing
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
<This section intentionally left blank>

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Introduction
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This program demonstrates the usage of the linalg.h library.

To compile with g++, place this source file and the linalg.h source file in the same directory, navigate to that directory with a command line interface, and enter the command:
    g++ main_example.cpp -std=c++11

For more detailed instructions, refer to the Deployment Manual.
*/

// Includes
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include"linalg.h"


// Prototypes
void matrix_print(linalg::matrix);


// Demonstrator Function
int main(void){

    // Variable Initializations
    int height1 = 3;
    int height2 = 2;
    int height3 = 4;
    int width1 = 5;
    int width2 = 4;
    int width3 = 3;
    int unit_test_error_count;
    std::vector<double> values1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<double> values2{1, 1, 1, 1, 2, 2, 2, 2};
    std::vector<double> values3{1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};


    // Run Unit Tests and Print Error Count
    unit_test_error_count = linalg::unit_tests();
    std::cout << "Unit Test Errors: " << unit_test_error_count << std::endl;


    // Matrix initialization and matrix operations will throw std::string exceptions in the event of an error.
    // The application programmer is expected to handle these.
    try{
        // Initialize Some Matrices
        linalg::matrix m1(values1, height1, width1);
        linalg::matrix m2(values2, height2, width2);
        linalg::matrix m3(values3, height3, width3);

        // Initialize a Default Matrix
        linalg::matrix m4;

        // Perform Matrix Operations
        linalg::matrix prod = linalg::matrix_multiply(m2,m3);
        linalg::matrix m1t = linalg::matrix_transpose(m1);


        // Print Input and Results
        // Multiplication
        std::cout << std::endl << "Matrix Multiplication" << std::endl;
        std::cout << "First Multiple:" << std::endl;
        matrix_print(m2);
        std::cout << "Second Multiple:" << std::endl;
        matrix_print(m3);
        std::cout << "Product:" << std::endl;
        matrix_print(prod);
        std::cout << std::endl << std::endl;

        // Transposition
        std::cout << "Matrix Transposition" << std::endl;
        std::cout << "Original Matrix:" << std::endl;
        matrix_print(m1);
        std::cout << "Transpose:" << std::endl;
        matrix_print(m1t);

    }
    catch (std::string e){
        std::cout << e << std::endl;
        return 1;
    }

    return 0;
}


// This function prints the properties of a matrix to the standard output
void matrix_print(linalg::matrix input_matrix){

    // Variable Initialization
    int i, j;

    // Iterate Through the Input Matrix
    for (i=0; i<input_matrix.height(); i++){
        for (j=0; j<input_matrix.width(); j++)

            // Print Values
            std::cout << std::setw(5) << input_matrix.values()[i*input_matrix.width()+j];

        std::cout << std::endl;
    }

    // Print Height and Width
    std::cout<< "Rows:" << std::setw(3) << input_matrix.height() << std::endl << "Columns:" << std::setw(3) << input_matrix.width() << std::endl << std::endl;
}

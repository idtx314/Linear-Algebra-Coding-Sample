/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Copyright and Licensing
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
<This section intentionally left blank>

This program demonstrates the usage of the linalg.h library.

Compile from the command line using g++ with the command:
    `$ g++ main_example.cpp -std=c++11`
*/

// Includes
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include"linalg.h"


// Prototypes
void matrix_print(matrix);
int unit_tests(void);


// Demonstrator function
int main(void){

    // Matrix Data
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

    unit_test_error_count = unit_tests();
    std::cout << "Unit Test Errors: " << unit_test_error_count << std::endl;

    // Matrix Initializations and Matrix Multiplication will throw std::string exceptions in the event that input fails sanity checking.
    try{
        matrix m1(values1, height1, width1);
        matrix m2(values2, height2, width2);
        matrix m3(values3, height3, width3);


        // Matrix Multiplication
        matrix prod = matrix_multiply(m2,m3);

        // Matrix Transposition
        matrix m1t = matrix_transpose(m1);


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
    // Complete error handling
    catch (std::string e){
        std::cout << e << std::endl;
        return 1;
    }
    return 0;
}


void matrix_print(matrix input_matrix){
    // This function prints the values of a matrix to the standard output
    int i, j;
    for (i=0; i<input_matrix.height(); i++){
        for (j=0; j<input_matrix.width(); j++)
            std::cout << std::setw(5) << input_matrix.values()[i*input_matrix.width()+j];
        std::cout << std::endl;
    }
    std::cout<< "Rows:" << std::setw(3) << input_matrix.height() << std::endl << "Columns:" << std::setw(3) << input_matrix.width() << std::endl << std::endl;
}

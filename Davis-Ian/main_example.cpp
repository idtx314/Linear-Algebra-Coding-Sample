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
    std::vector<double> values1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<double> values2{1, 1, 1, 1, 2, 2, 2, 2};
    std::vector<double> values3{1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};

    unit_tests();

    // Matrix Initializations and Matrix Multiplication will throw std::string exceptions in the event that input fails sanity checking.
    try{
        matrix m1( values1, height1, width1);
        matrix m2( values2, height2, width2);
        matrix m3( values3, height3, width3);


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


int unit_tests(){
    // This function performs a series of checks to make sure that the library is working properly.
    // for each error print a message to std out and add to error count

    // Initialize variables
    bool pass = false;
    int error_count = 0;
    int height1 = 3;
    int height2 = 2;
    int height3 = 4;
    int width1 = 5;
    int width2 = 4;
    int width3 = 3;
    std::vector<double> values1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<double> values2{1,1,1,1,2,2,2,2};
    std::vector<double> values3{1,2,3,1,2,3,1,2,3,1,2,3};


    // Test Matrix Initialization
    // Initialize Undersize Matrix
    try{
        matrix m1(values3, height2, width2);
        pass = false;
    }
    catch(std::string e){
        if(e == "Error: Vector size does not match given matrix dimensions. Aborting variable creation"){
            pass = true;
        }
        else{
            pass = false;
        }
    }
    if(pass){
        std::cout << "Unit Test Passed: Initialize Undersize Matrix" << std::endl;
    }
    else{
        std::cout << "Unit Test Failed: Initialize Undersize Matrix" << std::endl;
        error_count += 1;
    }
    pass = false;

    // Initialize Oversize Matrix
    try{
        matrix m2(values1, height2, width2);
        pass = false;
    }
    // Initialize Null Matrix
    // Initialize Default Matrix
    // Initialize matrix properly

    // Test Matrix Multiplication
        // Test Mismatched Input
        // Test Null Input
        // Test Normal Input

    // Test Matrix Transposition
        // Test Normal Input

    // Return Number of Errors
    return error_count;
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

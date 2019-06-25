/*
Usage
    This library defines several functions that perform matrix operations and a struct for accessing them.
    When initializing a new struct, use a vector from the C++ standard libraries to input the contents of your matrix. The vector should contain all values from the rows of the matrix reading from left to right and top to bottom. Usage examples are provided in the file "main_example.cpp" included in the library zip file.
    This library will sanity check input and throw exceptions as a string from the c++ standard libraries. Handling these exceptions gracefully is left to the user.
    Member variables in the struct should be modified only through the Constructor function and accessed using the member functions values(), height(), and width().

Compilation
    This library requires the usage of the C++11 standard or later when compiling. To compile with g++ or MinGW:
        1. Place "linalg.h" in a directory on the default path or in the same directory as the source code in which it is being included.
        2. Navigate a command line interface to the source directory and compile using the flag `-std=c++11`. For example:
        `$ g++ main.cpp -std=c++11`
*/


// Include Guard
#ifndef LALG_H
#define LALG_H


// Includes
#include<iostream>
#include<string>
#include<vector>


// Global Variables
struct matrix {
    private:
        // Member variables cannot be modified directly
        std::vector<double> _values;
        int _height;
        int _width;


    public:
        inline matrix(std::vector<double> input_values = std::vector<double>(), int input_height=0, int input_width=0){
            // This function initializes the member variables. An empty matrix is created by default.

            // Sanity check input
            if (input_values.size() != input_height*input_width){
                throw std::string("Vector size does not match given matrix dimensions. Object will be invalid");
            }

            // Set member variables
            _values   = input_values;
            _height = input_height;
            _width  = input_width;
        }


        // These functions should be used to retrieve information about the matrix
        inline std::vector<double> values() const{
            return _values;
        }
        inline int height() const{
            return _height;
        }
        inline int width() const{
            return _width;
        }
};


// Functions
inline matrix matrix_multiply(matrix multiplicand, matrix multiplier){
    // This function performs matrix multiplication of the first input by the second input.

    // Initialize Variables
    int output_height = multiplicand.height();
    int output_width  = multiplier.width();
    std::vector<double> output_data;

    // Sanity check input matrix dimensions
    if (multiplicand.width() != multiplier.height()){
        throw std::string("Width of input matrix 1 does not match height of input matrix 2. Multiplication is not defined!");
    }

    double sum = 0;
    int i, j, k;
    // Iterate across the rows of the output matrix
    for (i=0; i<output_height; i++){
        for (j=0; j<output_width; j++){
            // Calculate the result of matrix multiplication
            for (k=0; k<multiplier.height(); k++){
                sum = sum + multiplicand.values()[i*multiplicand.width()+k]*multiplier.values()[k*multiplier.width()+j];
            }
            // Then append the result to the output data vector.
            output_data.push_back(sum);
            sum = 0;
        }
    }

    // Initialize the output matrix and return it
    try{
        matrix output_matrix(output_data, output_height, output_width);
        return output_matrix;
    } catch (std::string e){
        throw e;
    }
}



inline matrix matrix_transpose(matrix input){
    // This function takes the transpose of the input matrix and returns it as a new matrix. The input matrix is unchanged.

    // Initialize variables
    int output_height = input.width();
    int output_width = input.height();
    std::vector<double> output_data;

    // Iterate down the columns of the input matrix
    int i, j;
    for (j=0; j<input.width(); j++){
        for (i=0; i<input.height(); i++){
            // Append the values to the output data vector
            output_data.push_back(input.values()[i*input.width() + j]);
        }
    }

    // Initialize the output matrix and return it
    try{
        matrix output_matrix(output_data, output_height, output_width);
        return output_matrix;
    } catch (std::string e){
        throw e;
    }
}


#endif /* LALG_H */

/*
Instructions and license go in here
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
    std::vector<double> data;
    int height;
    int width;

    matrix(double* input_data = NULL, int input_height=0, int input_width=0){
        height = input_height;
        width  = input_width;
        for (int i=0; i<(width*height); i++)
            data.push_back(input_data[i]);
    }
};




// Functions
inline matrix matrix_multiply(matrix multiplicand, matrix multiplier){
    // This function performs matrix multiplication of the first input by the second input.

    // Initialize variables
    int output_height = multiplicand.height;
    int output_width  = multiplier.width;
    double output_data[output_height * output_width];

    // Sanity check input matrix dimensions
    if (multiplicand.width != multiplier.height){
        throw std::string("Width of input matrix 1 does not match height of input matrix 2. Multiplication is not defined!");
    }

    double sum = 0;
    // Iterate across the rows of the output matrix
    for (int i=0; i<output_height; i++){
        for (int j=0; j<output_width; j++){
            // Calculate the result of matrix multiplication
            for (int k=0; k<multiplier.height; k++){
                sum = sum + multiplicand.data[i*multiplicand.width + k]*multiplier.data[k*multiplier.width+j];
            }
            // Then append the result to the output data vector.
            output_data[i*output_height + j] = sum;
            sum = 0;
        }
    }

    // Initialize the output matrix and return it
    matrix output_matrix(output_data, output_height, output_width);
    return output_matrix;
}



inline matrix matrix_transpose(matrix input){
    // This function takes the transpose of the input matrix and returns it as a new matrix. The input matrix is unchanged.

    // Initialize variables
    int output_height = input.width;
    int output_width = input.height;
    double output_data[output_height*output_width];

    // Iterate down the columns of input matrix
    for (int j=0; j<input.width; j++){
        for (int i=0; i<input.height; i++){
            // Append values to output data vector
            output_data[i + j*output_height] = input.data[i*input.width + j];
        }
    }

    // Initialize the output matrix and return it
    matrix output_matrix(output_data, output_height, output_width);
    return output_matrix;
}


#endif /* LALG_H */

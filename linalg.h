/*
Instructions and license go in here
*/


// Include guard
#ifndef LALG_H
#define LALG_H


// Includes
#include<iostream>
#include<string>
#include <vector>


// Typedefs
// public and private library variables, intern, extern, structs, etc
// Be sure that global variables are limited in scope to being used in the library if they aren't meant for outside use.
struct matrix {
    std::vector<double> data;
    int height;
    int width;

    matrix(std::vector<double> input_data = std::vector<double>(), int input_height=0, int input_width=0){
        data   = input_data;
        height = input_height;
        width  = input_width;
    }


    //use this -> to reference member functions, but not member data?
    // inline transpose (matrix multiplier)
};




// Functions
// need to use inlining so the compiler can discard extra definitions, because header library may be included in multiple translation units in the project. Include guards only work within a single translation unit!
// Member functions defined within a class(?) are implicitly inline. If they are defined outside the class definition, they must be marked explicitly. Declaring them as inline within the class will apply the label to all external definitions.
inline matrix matrix_multiply(matrix multiplicand, matrix multiplier){
    // This function performs matrix multiplication of the first input by the second input.

    // Initialize variables
    int output_height = multiplicand.height;
    int output_width  = multiplier.width;
    //output length is height*width
    std::vector<double> output_data;

    // Sanity check input matrix dimensions
    if (multiplicand.width != multiplier.height){
        throw std::string("Width of input matrix 1 does not match height of input matrix 2. Multiplication is not defined!");
    }

    double sum = 0;
    // For each position in the output matrix
    for (int i=0; i<output_height; i++){
        for (int j=0; j<output_width; j++){
            // Calculate the result of matrix multiplication
            for (int k=0; k<multiplier.height; k++){
                sum = sum + multiplicand.data[i*multiplicand.width+k]*multiplier.data[k*multiplier.width+j];
            }
            // Then append the result to the output data vector.
            output_data.push_back(sum);
            sum = 0;
        }
    }

    // Initialize the output matrix and return it
    matrix output_matrix(output_data, output_height, output_width);
    return output_matrix;
}



// inline void matrix_transpose(double* array1, int height_1, int width_1){
//     // I could alter the data in the original array via reference
//     // Might actually be easier to do the OO approach
// }










#endif /* LALG_H */

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

    matrix(std::vector<double> input_data, int input_height, int input_width){
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

    //Sanity check matrix dimensions
    if (multiplicand.width != multiplier.height){
        throw std::string("Width of input matrix 1 does not match height of input matrix 2. Multiplication is not defined!");
    }

    double sum = 0;

    // For each  output matrix row
    for (int i=0; i<output_height; i++){
        // And column
        for (int j=0; j<output_width; j++){
            // Cycle through products and keep a rolling sum
            for (int k=0; k<multiplier.height; k++){
                sum = sum + multiplicand.data[i*multiplicand.width+k]*multiplier.data[k*multiplier.width+j];
            }
            // Then add the total value to the output data vector.
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

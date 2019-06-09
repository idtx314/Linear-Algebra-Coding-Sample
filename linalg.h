/*
Instructions and license go in here
*/


// Include guard
#ifndef LALG_H
#define LALG_H


// Includes
#include <vector>


// Typedefs
// public and private library variables, intern, extern, structs, etc
// Be sure that global variables are limited in scope to being used in the library if they aren't meant for outside use.
struct matrix {
    std::vector<double> data;
    int height;
    int width;

    matrix(std::vector<double> input_data, int input_height, int input_width)
    {
        data   = input_data;
        height = input_height;
        width  = input_width;
    }


    //use this -> to reference member functions, but not member data?
    // inline transpose (matrix multiplier)
};




// Functions
// need to use inlining so the compiler can discard extra definitions, because header may be included in multiple translation units in the project. Include guards only work within a single translation unit!
// Member functions defined within a class are implicitly inline. If they are defined outside the class definition, they must be marked explicitly. Declaring them as inline within the class will apply the label to all external definitions.
// inline void matrix_multiply(double* array1, int height_1, int width_1, double* array2, int height_2, int width_2, double* array3, int height_3, int width_3)
// {
//     // Result array will have to be precisely correct dimension. This is foolish, I'm going for the OO approach.
// }



// inline void matrix_transpose(double* array1, int height_1, int width_1)
// {
//     // I could alter the data in the original array via reference
//     // Might actually be easier to do the OO approach
// }










#endif /* LALG_H */

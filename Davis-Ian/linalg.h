/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Copyright and Licensing
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
<This section intentionally left blank>

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Introduction
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This library defines the class "matrix" and several functions that perform matrix operations.
class member variables can be changed only during initialization or when calling the initialization function. The values of these variables can be accessed using the member functions values(), height(), and width().
This library will sanity check input and throw exceptions as a std::string. Handling these exceptions gracefully is left to the application programmer.
For detailed instructions on library usage, refer to the Deployment Manual.
All library resources are contained in the namespace "linalg".

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Requirements
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This library requires the usage of the C++11 standard when compiling.
*/


// Include Guard
#ifndef LALG_H
#define LALG_H


// Includes
#include<iostream>
#include<string>
#include<vector>


namespace linalg{

    class matrix {
        private:
            std::vector<double> _values;
            int _height;
            int _width;


        public:
            // This function initializes the member variables. An empty matrix is created by default.
            inline matrix(const std::vector<double>& input_values = std::vector<double>(), const int input_height=0, const int input_width=0){

                // Sanity check input
                if (input_values.size() != input_height*input_width){
                    throw std::string("Error: Vector size does not match given matrix dimensions. Aborting variable creation");
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


    // Library Functions

    // This function performs matrix multiplication of the first input by the second input.
    inline matrix matrix_multiply(const matrix& multiplicand, const matrix& multiplier){

        // Initialize Variables
        int output_height = multiplicand.height();
        int output_width  = multiplier.width();
        int i, j, k;
        double sum = 0;
        std::vector<double> output_data(output_height*output_width);

        // Sanity check input matrix dimensions
        if (multiplicand.width() != multiplier.height()){
            throw std::string("Error: Width of input matrix 1 does not match height of input matrix 2. Multiplication is not defined!");
        }

        // Iterate across the rows of the output matrix
        for (i=0; i<output_height; i++){
            for (j=0; j<output_width; j++){

                // Calculate the result of matrix multiplication
                for (k=0; k<multiplier.height(); k++){
                    sum = sum + multiplicand.values()[i*multiplicand.width()+k]*multiplier.values()[k*multiplier.width()+j];
                }

                // Append the result to the output data vector.
                output_data[i*output_width + j] = sum;
                sum = 0;
            }
        }

        // Initialize the output matrix and return it
        try{
            matrix output_matrix(output_data, output_height, output_width);
            return output_matrix;
        }
        catch (std::string e){
            throw;
        }
    }


    // This function takes the transpose of the input matrix and returns it as a new matrix.
    inline matrix matrix_transpose(const matrix& input){

        // Initialize variables
        int output_height = input.width();
        int output_width = input.height();
        std::vector<double> output_data (output_height*output_width);
        int i, j;

        // Iterate down the columns of the input matrix
        for (j=0; j<input.width(); j++){
            for (i=0; i<input.height(); i++){

                // Append the values to the output data vector
                output_data[j*output_width + i] = input.values()[i*input.width() + j];
            }
        }

        // Initialize the output matrix and return it
        try{
            matrix output_matrix(output_data, output_height, output_width);
            return output_matrix;
        }
        catch (std::string e){
            throw;
        }
    }


    // This function performs a series of checks to make sure that the library is working properly. The results of specific tests are printed to standard out. The return value is the number of tests failed.
    inline int unit_tests(){

        // Initialize variables
        bool pass;
        int error_count = 0;
        int height1 = 3;
        int height2 = 2;
        int height3 = 4;
        int height_2x3 = 2;
        int width1 = 5;
        int width2 = 4;
        int width3 = 3;
        int width_2x3 = 3;
        std::vector<double> values1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        std::vector<double> values2{1,1,1,1,2,2,2,2};
        std::vector<double> values3{1,2,3,1,2,3,1,2,3,1,2,3};
        std::vector<double> values_2x3{4,8,12,8,16,24};
        std::vector<double> values1t{1,6,11,2,7,12,3,8,13,4,9,14,5,10,15};


        // Test Matrix Initialization
        // Initialize Undersize Matrix
        pass = false;
        try{
            matrix m1(values3, height2, width2);
        }
        catch(std::string e){
            if(e == "Error: Vector size does not match given matrix dimensions. Aborting variable creation"){pass = true;}
        }

        if(pass){
            std::cout << "Unit Test Passed: Initialize Undersize Matrix" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Initialize Undersize Matrix" << std::endl;
            error_count += 1;
        }

        // Initialize Oversize Matrix
        pass = false;
        try{
            matrix m2(values1, height2, width2);
        }
        catch(std::string e){
            if(e == "Error: Vector size does not match given matrix dimensions. Aborting variable creation"){pass = true;}
        }
        if(pass){
            std::cout << "Unit Test Passed: Initialize Oversize Matrix" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Initialize Oversize Matrix" << std::endl;
            error_count += 1;
        }

        // Initialize Null And Empty Matrix
        pass = false;
        try{
            matrix m3(std::vector<double>(),0,0);
            matrix m4;

            if (m3.values()==m4.values() && m3.height()==m4.height() && m3.width()==m4.width()){pass = true;}
        }
        catch(std::string e){}
        if(pass){
            std::cout << "Unit Test Passed: Initialize NULL And Empty Matrix" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Initialize NULL And Empty Matrix" << std::endl;
            error_count += 1;
        }

        // Initialize Valid Matrix
        pass = false;
        try{
            matrix m5(values1,height1,width1);
            if (m5.values()==values1 && m5.height() == height1 && m5.width() == width1){pass = true;}
        }
        catch(std::string e){}
        if(pass){
            std::cout << "Unit Test Passed: Initialize Valid Matrix" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Initialize Valid Matrix" << std::endl;
            error_count += 1;
        }

        // Test Matrix Multiplication
        // Test Mismatched Dimension Input
        pass = false;
        try{
            matrix m6(values1, height1, width1);
            matrix m7(values2, height2, width2);
            matrix m8 = matrix_multiply(m6,m7);
        }
        catch(std::string e){
            if(e == "Error: Width of input matrix 1 does not match height of input matrix 2. Multiplication is not defined!"){pass = true;}
        }
        if(pass){
            std::cout << "Unit Test Passed: Multiply Mismatched Dimension Input" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Multiply Mismatched Dimesnion Input" << std::endl;
            error_count += 1;
        }

        // Test Null Input
        pass = false;
        try{
            matrix m9;
            matrix m10;
            matrix m11 = matrix_multiply(m9,m10);
            if(m11.values() == std::vector<double>() && m11.height() == 0 && m11.width() == 0){pass = true;}
        }
        catch(std::string e){}
        if(pass){
            std::cout << "Unit Test Passed: Multiply NULL Input" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Multiply NULL Input" << std::endl;
            error_count += 1;
        }

        // Test Valid Input
        pass = false;
        try{
            matrix m12(values2, height2, width2);
            matrix m13(values3, height3, width3);
            matrix m14 = matrix_multiply(m12,m13);
            if(m14.values() == values_2x3 && m14.height() == height_2x3 && m14.width() == width_2x3){pass = true;}
        }
        catch(std::string e){}
        if(pass){
            std::cout << "Unit Test Passed: Multiply Valid Input" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Multiply Valid Input" << std::endl;
            error_count += 1;
        }

        // Test Matrix Transposition
        // Test NULL Input
        pass = false;
        try{
            matrix m15;
            matrix m16 = matrix_transpose(m15);
            if(m16.values() == std::vector<double>() && m16.height() == 0 && m16.width() == 0){pass = true;}
        }
        catch(std::string e){}
        if(pass){
            std::cout << "Unit Test Passed: Transpose NULL Input" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Transpose NULL Input" << std::endl;
            error_count += 1;
        }

        // Test Normal Input
        pass = false;
        try{
            matrix m17(values1, height1, width1);
            matrix m18 = matrix_transpose(m17);
            if(m18.values() == values1t && m18.height() == width1 && m18.width() == height1){pass = true;}
        }
        catch(std::string e){}
        if(pass){
            std::cout << "Unit Test Passed: Transpose Normal Input" << std::endl;
        }
        else{
            std::cout << "Unit Test Failed: Transpose Normal Input" << std::endl;
            error_count += 1;
        }


        return error_count;
    }

// End Namespace
}

#endif /* LALG_H */

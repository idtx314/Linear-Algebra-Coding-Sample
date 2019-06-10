/*
Program introduction, this just demonstrates the usage of linalg.h
license
compile with g++
*/

// Includes
#include <iostream>
#include "linalg.h"


// Global Variables


// Demonstrator function
int main(void)
{
    // Local Variables
    int height = 3;
    int height2 = 2;
    int height3 = 4;
    int width = 5;
    int width2 = 4;
    int width3 = 3;
    double initlist[height*width] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    double initlist2[height2*width2] = {1, 1, 1, 1, 2, 2, 2, 2};
    double initlist3[height3*width3] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    std::vector<double> data;
    std::vector<double> data2;
    std::vector<double> data3;

    for (int i=0; i<height*width; i++)
        data.push_back(initlist[i]);
    for (int i=0; i<height2*width2; i++)
        data2.push_back(initlist2[i]);
    for (int i=0; i<height3*width3; i++)
        data3.push_back(initlist3[i]);


    // Matrix Initializations
    matrix m1(initlist, height, width);
    matrix m2(initlist2, height2, width2);
    matrix m3(initlist3, height3, width3);
    // matrix prod;


    // Header Demonstration
    // Matrix Multiplication
    try{
        matrix prod = matrix_multiply(m2,m3);

        for (int i=0; i<prod.height; i++){
            for (int j=0; j<prod.width; j++)
                std::cout << prod.data[i*prod.width+j] << " ";
            std::cout << std::endl;
        }
        std::cout << prod.height << " " << prod.width << std::endl;
    } catch (std::string e){
        std::cout << e << std::endl;
    }

    // Matrix Transposition
    for (int i=0; i<m1.height; i++){
        for (int j=0; j<m1.width; j++)
            std::cout << m1.data[i*m1.width+j] << " ";
        std::cout << std::endl;
    }
        std::cout << m1.height << " " << m1.width << std::endl;

    matrix m1t = matrix_transpose(m1);

    for (int i=0; i<m1t.height; i++){
        for (int j=0; j<m1t.width; j++)
            std::cout << m1t.data[i*m1t.width+j] << " ";
        std::cout << std::endl;
    }
        std::cout << m1t.height << " " << m1t.width << std::endl;



    return 0;
}

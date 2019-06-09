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
    int width = 5;
    double initlist[height*width] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<double> data;

    for (int i=0; i<height*width; i++)
        data.push_back(initlist[i]);

    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++)
            std::cout << initlist[i*width+j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;


    // Matrix Initialization
    matrix m(data,height,width);





    // Header Demonstration
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++)
            std::cout << data[i*width+j] << " ";
        std::cout << std::endl;
    }
    std::cout << m.height << " " << m.width << std::endl;


    return 0;
}

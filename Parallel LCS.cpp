#include <iostream>
#include <string>
#include "LCS.h"

Matrix<int> LcsLength(char array1[], char array2[]);

int main()
{
    char letters[] = "abcd";
    
    char array1[1024];
    char array2[1024];
    for (int i = 0; i < 1024; i++) {
        array1[i] = letters[rand() % 4];
        array2[i] = letters[rand() % 4];
    }
    Matrix<int> returned = LcsLength(array1, array2);
    std::cout << returned(0, 1);


    //T(12, 54) = 3; Set the entry in row 13 and column 55 to 3

    //Now we need to code LCS from chapter 15
    //This will make an LCS from array1/array2 and print it out
    //Then we will have to make a new program, the parallel one
    //Compare runtimes with a timer
}

Matrix<int>* LcsLength(char array1[], char array2[]) {
    Matrix<int> T(1024, 1024);
    Matrix<int> B(1024, 1024); 
        // 1 = up
        // 2 = left
        // 3 = up, left
    

    for (int i = 1; i < 1024; i++) {
        T(i, 0) = 0;
        for (int j = 1; j < 1024; j++) {
            T(0, j) = 0;
            if (array1[i] == array2[j]) {
                T(i, j) = T(i - 1, j - 1) + 1;
                B(i, j) = 3;
            }
            else if (T(i - 1, j) >= T(i, j - 1)) {
                T(i, j) = T(i - 1, j);
                B(i, j) = 1;
            }
            else {
                T(i, j) = T(i, j - 1);
                B(i, j) = 0;
            }
        }
    }
    return T,B;
}
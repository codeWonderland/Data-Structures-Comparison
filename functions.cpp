//
// Created by me on 10/25/2017.
//
#include "functions.h"


void fillArray(int *arr, std::ifstream &inputFile) {

    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        inputFile >> arr[i];
    }

}


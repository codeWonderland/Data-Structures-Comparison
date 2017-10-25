//
// Created by me on 10/25/2017.
//

#ifndef PA5_FUNCTIONS_H
#define PA5_FUNCTIONS_H

#include <cstdlib>
#include <fstream>
#include <string>

const int MAX_SIZE = 1000000;
const std::string INPUT_FILE = "data.txt";
enum TIMES_DATA { NUM_TESTS = 3, DATA_STRUCTURE = 3, WHICH_TEST = 3};
enum TESTS { ARRAY = 0, LINKED_LIST =  1, DOUBLY_LL = 2};
enum TO_BE_TIMED { CREATE = 0, SEARCH = 1, DELETION = 2};

void fillArray(int *arr, std::ifstream &inputFile);

#endif //PA5_FUNCTIONS_H

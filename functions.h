/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  October 18, 2017
     *        Class:  CSI-281
     *     Filename:  functions.h
     *
     *  Description:
     *      Stub driver for testing
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/

#ifndef PA5_FUNCTIONS_H
#define PA5_FUNCTIONS_H

#include <cstdlib>
#include <fstream>
#include <string>
#include "linkedList.h"
#include "DoublyLinkedList.h"

const int MAX_SIZE = 1000000;
const std::string INPUT_FILE = "data.txt";
const std::string OUTPUT_FILE = "output.txt";
enum TIMES_DATA { NUM_TESTS = 3, DATA_STRUCTURE = 3, WHICH_TEST = 3};
enum TESTS { ARRAY_T = 0, LINKED_LIST_T = 1, DOUBLY_LL_T = 2};
enum TO_BE_TIMED { FILL = 0, SEARCH = 1, DELETION = 2};

void arrayRemove(int *arr, const int &toBeDeleted);
void displayTests(double times[NUM_TESTS][DATA_STRUCTURE][WHICH_TEST]);
void fillArray(int *arr, std::ifstream &inputFile);
void fillDoublyLinkedList(DoublyLinkedList<int> doublyLinkedList, std::ifstream &inputFile);
void fillLinkedList(LinkedList<int> &linkedList, std::ifstream &inputFile);
void searchArray(int *arr, const int &searchKey);
void quickSort(int list[], int lowerBound, int upperBound);

#endif //PA5_FUNCTIONS_H

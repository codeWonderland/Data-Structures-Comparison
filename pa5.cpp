/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  October 18, 2017
     *        Class:  CSI-281
     *     Filename:  pa5.cpp
     *
     *  Description:
     *      Stub driver for testing
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "timerSystem.h"
#include "functions.h"
#include "linkedList.h"
#include "DoublyLinkedList.h"

int main()
{
	int *arr;
    std::ifstream inputFile;
	arr = new int[MAX_SIZE];
	LinkedList<int> linkedList = LinkedList<int>();
	DoublyLinkedList<int> doublyLinkedList = DoublyLinkedList<int>();
    TimerSystem timer;
    double times[NUM_TESTS][DATA_STRUCTURE][WHICH_TEST];          //ARRAY TO HOLD ALL OF THE TIMES
    int i;

    // CONDUCTS THE ARRAY TESTS
    inputFile.open(INPUT_FILE);
    for (i = 0; i < NUM_TESTS; i++)
    {
        //Times filling the array
        timer.startClock();
        fillArray(arr, inputFile);
        times[i][ARRAY][CREATE] = timer.getTime();




        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);
    }

	return 0;
}

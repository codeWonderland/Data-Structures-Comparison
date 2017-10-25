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
#include <iomanip>
#include "timerSystem.h"
#include "functions.h"

int main()
{
	int *arr;
    std::ifstream inputFile;
	arr = new int[MAX_SIZE];
	LinkedList<int> linkedList = LinkedList<int>();
	DoublyLinkedList<int> doublyLinkedList = DoublyLinkedList<int>();
    TimerSystem timer;
    double times[NUM_TESTS][DATA_STRUCTURE][WHICH_TEST];                    //ARRAY TO HOLD ALL OF THE TIMES
    int i;
    inputFile.open(INPUT_FILE);

    /* * * * * * * * * * * * * * * * * * * * *
     *  CONDUCTS THE ARRAY TESTS
     * * * * * * * * * * * * * * * * * * * * */
    for (i = 0; i < NUM_TESTS; i++)
    {
        //TIMES FILLING THE ARRAY
        timer.startClock();
        fillArray(arr, inputFile);
        times[i][ARRAY_T][FILL] = timer.getTime();

        //TIMES SEARCHING THE ARRAY
        timer.startClock();
        searchArray(arr, 0); // FIGURE OUT HOW WE WANT TO SEARCH THE ARRAY AND FOR WHAT
        times[i][ARRAY_T][SEARCH] = timer.getTime();

        //TIMES DELETING AN ELEMENT
        timer.startClock();
        arrayRemove(arr, 0); // FIGURE OUT HOW WE WANT TO DELETE AN ELEMENT IN THE ARRAY AND WHAT ELEMENT TO REMOVE
        times[i][ARRAY_T][DELETION] = timer.getTime();


        // CLEARS THE ifstream AND SETS IT BACK TO THE BEGINNING OF THE FILE
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);
    }

    /* * * * * * * * * * * * * * * * * * * * *
     *  CONDUCTS THE LinkedList TESTS
     * * * * * * * * * * * * * * * * * * * * */
    for (i = 0; i < NUM_TESTS; i++)
    {
        //TIMES FILLING THE LinkedList
        timer.startClock();
        fillLinkedList(linkedList, inputFile);
        times[i][LINKED_LIST_T][FILL] = timer.getTime();

        //TIMES SEARCHING THE LinkedList
        timer.startClock();
        linkedList.isExist(0); // FIGURE OUT WHAT WE WANT TO SEARCH
        times[i][LINKED_LIST_T][SEARCH] = timer.getTime();

        //TIMES DELETING AN ELEMENT FROM THE LinkedList
        timer.startClock();
        linkedList.remove(0); // FIGURE OUT WHAT WE WANT TO REMOVE
        times[i][LINKED_LIST_T][DELETION] = timer.getTime();

        // CLEARS THE ifstream AND SETS IT BACK TO THE BEGINNING OF THE FILE
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        linkedList.clear(); // RESETS THE LinkedList SO IT CAN BE USED FOR THE NEXT TESTS
    }

    /* * * * * * * * * * * * * * * * * * * * *
     *  CONDUCTS THE DoublyLinkedList TESTS
     * * * * * * * * * * * * * * * * * * * * */
    for (i = 0; i < NUM_TESTS; i++)
    {
        //TIMES FILLING THE DoublyLinkedList
        timer.startClock();
        fillDoublyLinkedList(doublyLinkedList, inputFile);
        times[i][DOUBLY_LL_T][FILL] = timer.getTime();

        //TIMES SEARCHING THE DoublyLinkedList
        timer.startClock();
        doublyLinkedList.isExist(0); // FIGURE OUT WHAT WE WANT TO SEARCH
        times[i][DOUBLY_LL_T][SEARCH] = timer.getTime();

        //TIMES DELETING AN ELEMENT FROM THE DoublyLinkedList
        timer.startClock();
        doublyLinkedList.remove(0); // FIGURE OUT WHAT WE WANT TO REMOVE
        times[i][DOUBLY_LL_T][DELETION] = timer.getTime();

        // CLEARS THE ifstream AND SETS IT BACK TO THE BEGINNING OF THE FILE
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        doublyLinkedList.clear(); // RESETS THE DoublyLinkedList SO IT CAN BE USED FOR THE NEXT TESTS
    }

    inputFile.close();
	return 0;
}

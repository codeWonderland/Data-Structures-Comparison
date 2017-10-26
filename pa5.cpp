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

const int SEARCH_KEY = 1000001; //Search key that cannot be in the list

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
        std::cout << "Array Fill: " << times[i][ARRAY_T][FILL] << "\n";

        //TIMES SEARCHING THE ARRAY
        timer.startClock();
        searchArray(arr, SEARCH_KEY);
        times[i][ARRAY_T][SEARCH] = timer.getTime();
        std::cout << "Array Search: " << times[i][ARRAY_T][SEARCH] << "\n";

        //TIMES DELETING AN ELEMENT
        timer.startClock();
        arrayRemove(arr, MAX_SIZE / 2);
        times[i][ARRAY_T][DELETION] = timer.getTime();
        std::cout << "Array Delete: " << times[i][ARRAY_T][DELETION] << "\n";


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
        std::cout << "Linked List Fill: " << times[i][LINKED_LIST_T][FILL] << "\n";

        //TIMES SEARCHING THE LinkedList
        timer.startClock();
        linkedList.isExist(SEARCH_KEY);
        times[i][LINKED_LIST_T][SEARCH] = timer.getTime();
        std::cout << "Linked List Search: " << times[i][LINKED_LIST_T][SEARCH] << "\n";

        //TIMES DELETING AN ELEMENT FROM THE LinkedList
        timer.startClock();
        linkedList.removeAt(MAX_SIZE / 2);
        times[i][LINKED_LIST_T][DELETION] = timer.getTime();
        std::cout << "Linked List Delete: " << times[i][LINKED_LIST_T][DELETION] << "\n";

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
        std::cout << "Doubly Linked List Fill: " << times[i][DOUBLY_LL_T][FILL] << "\n";


        //TIMES SEARCHING THE DoublyLinkedList
        timer.startClock();
        doublyLinkedList.isExist(SEARCH_KEY);
        times[i][DOUBLY_LL_T][SEARCH] = timer.getTime();
        std::cout << "Doubly Linked List Search: " << times[i][DOUBLY_LL_T][SEARCH] << "\n";

        //TIMES DELETING AN ELEMENT FROM THE DoublyLinkedList
        timer.startClock();
        doublyLinkedList.removeAt(MAX_SIZE / 2);
        times[i][DOUBLY_LL_T][DELETION] = timer.getTime();
        std::cout << "Doubly Linked List Delete: " << times[i][DOUBLY_LL_T][DELETION] << "\n";

        // CLEARS THE ifstream AND SETS IT BACK TO THE BEGINNING OF THE FILE
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        doublyLinkedList.clear(); // RESETS THE DoublyLinkedList SO IT CAN BE USED FOR THE NEXT TESTS
    }

    inputFile.close();

    displayTests(times);

	return 0;
}

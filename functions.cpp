/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  October 18, 2017
     *        Class:  CSI-281
     *     Filename:  functions.cpp
     *
     *  Description:
     *      Stub driver for testing
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/
#include "functions.h"

/*      Pre:  An array of size MAX_SIZE and an opened inputFile
 *     Post:  None
 *  Purpose:  To fill the array of size MAX_SIZE from the inputFile
 ********************************************************************/
void fillArray(int *arr, std::ifstream &inputFile)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        inputFile >> arr[i];
    }
}

/*      Pre:  An empty DoublyLinkedList and an opened inputFile
 *     Post:  None
 *  Purpose:  To fill the DoublyLinkedList with MAX_SIZE elements from the inputFile
 ********************************************************************/
void fillDoublyLinkedList(DoublyLinkedList<int> doublyLinkedList, std::ifstream &inputFile)
{
    int tmp;
    while (!inputFile.eof())
    {
        inputFile >> tmp;
        doublyLinkedList.insert(tmp);
    }
}

/*      Pre:  An empty LinkedList and an opened inputFile
 *     Post:  None
 *  Purpose:  To fill the LinkedList with MAX_SIZE elements from the inputFile
 ********************************************************************/
void fillLinkedList(LinkedList<int> &linkedList, std::ifstream &inputFile)
{
    int tmp;
    while (!inputFile.eof())
    {
        inputFile >> tmp;
        linkedList.insert(tmp);
    }
}

/*      Pre:  A filled array and an int to be searched for
 *     Post:  None
 *  Purpose:  To search the array to find the specified searchKey
 ********************************************************************/
void searchArray(int *arr, const int &searchKey)
{
    // SEARCHES THE ARRAY

}

/*      Pre:  A filled array and an int to be deleted
 *     Post:  None
 *  Purpose:  To delete an element in the array
 ********************************************************************/
void arrayRemove(int *arr, const int &toBeDeleted)
{
    // DELETES toBeDeleted IN THE ARRAY
}

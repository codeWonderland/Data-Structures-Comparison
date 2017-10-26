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

/*      Pre:  A filled array and an int to be deleted
 *     Post:  None
 *  Purpose:  To delete an element in the array
 ********************************************************************/
void arrayRemove(int *arr, const int &toBeDeleted)
{
    int i;
    for (i = toBeDeleted; i < MAX_SIZE - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[MAX_SIZE - 1] = 0;
}

void displayTests(double times[NUM_TESTS][DATA_STRUCTURE][WHICH_TEST])
{
    std::ofstream out;
    out.open(OUTPUT_FILE);

    out.setf(ios::scientific | ios::showpoint);
    out.precision(5);

    int i, j, k;
    for (i = 0; i < NUM_TESTS; i++)
    {
        out << "\n\nTEST: " << i << "\n\n";
        for (j = 0; j < DATA_STRUCTURE; j++)
        {
            switch(j)
            {
                case ARRAY_T:
                    for (k = 0; k < WHICH_TEST; k++)
                    {
                        switch(k)
                        {
                            case FILL:
                                out << "ARRAY FILL: " << times[i][j][k] << endl;
                                break;
                            case SEARCH:
                                out << "ARRAY SEARCH: " << times[i][j][k] << endl;
                                break;
                            case DELETION:
                                out << "ARRAY DELETION: " << times[i][j][k] << endl;
                                break;
                        }
                    }
                    break;
                case LINKED_LIST_T:
                    for (k = 0; k < WHICH_TEST; k++)
                    {
                        switch(k)
                        {
                            case FILL:
                                out << "LINKED LIST FILL: " << times[i][j][k] << endl;
                                break;
                            case SEARCH:
                                out << "LINKED LIST SEARCH: " << times[i][j][k] << endl;
                                break;
                            case DELETION:
                                out << "LINKED LIST DELETION: " << times[i][j][k] << endl;
                                break;
                        }
                    }
                    break;
                case DOUBLY_LL_T:
                    for (k = 0; k < WHICH_TEST; k++)
                    {
                        switch(k)
                        {
                            case FILL:
                                out << "DOUBLY LINKED LIST FILL: " << times[i][j][k] << endl;
                                break;
                            case SEARCH:
                                out << "DOUBLY LINKED LIST SEARCH: " << times[i][j][k] << endl;
                                break;
                            case DELETION:
                                out << "DOUBLY LINKED LIST DELETION: " << times[i][j][k] << endl;
                                break;
                        }
                    }
                    break;
            }
        }
    }

    out.close();
}

/*      Pre:  An array of size MAX_SIZE and an opened inputFile
 *     Post:  None
 *  Purpose:  To fill the array of size MAX_SIZE from the inputFile
 ********************************************************************/
void fillArray(int *arr, std::ifstream &inputFile)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        inputFile >> arr[i];;
    }

    quickSort(arr, 0, MAX_SIZE - 1);
}

/*      Pre:  An empty DoublyLinkedList and an opened inputFile
 *     Post:  None
 *  Purpose:  To fill the DoublyLinkedList with MAX_SIZE elements from the inputFile
 ********************************************************************/
void fillDoublyLinkedList(DoublyLinkedList<int> doublyLinkedList, std::ifstream &inputFile)
{
    int tmp, i = 0;
    while (!inputFile.eof() && i < MAX_SIZE)
    {
        inputFile >> tmp;
        doublyLinkedList.insert(tmp);
        i++;
    }
}

/*      Pre:  An empty LinkedList and an opened inputFile
 *     Post:  None
 *  Purpose:  To fill the LinkedList with MAX_SIZE elements from the inputFile
 ********************************************************************/
void fillLinkedList(LinkedList<int> &linkedList, std::ifstream &inputFile)
{
    int tmp, i = 0;
    while (!inputFile.eof() && i < MAX_SIZE)
    {
        inputFile >> tmp;
        linkedList.insert(tmp);
        i++;
    }
}

/*      Pre:  A filled array and an int to be searched for
 *     Post:  None
 *  Purpose:  To search the array to find the specified searchKey
 ********************************************************************/
void searchArray(int *arr, const int &searchKey)
{
    // SEARCHES THE ARRAY
    int mid, lb = 0, ub = MAX_SIZE;
    bool found = false;

    while (lb <= ub)
    {
        mid = (lb + ub) / 2;

        if (arr[mid] == searchKey)
        {
            found = true;
            break;
        }
        else if (searchKey > arr[mid])
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
}

/*
*     Pre: An array to be sorted and the lowest index used in the array and the highest index used in the array
*    Post: None
* Purpose: Performs a quickSort to sort the array in ascending order.
*/
void quickSort(int list[], int lowerBound, int upperBound)
{
    int i = lowerBound;
    int j = upperBound;
    int pivot = list[(lowerBound + upperBound) / 2];
    int temp;

    while (i < j)
    {
        while (list[i] < pivot)
            i++;

        while (list[j] > pivot)
            j--;

        if (i <= j)
        {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            i++;
            j--;
        }
    }

    if (lowerBound < j)
        quickSort(list, lowerBound, j);

    if (i < upperBound)
        quickSort(list, i, upperBound);
}

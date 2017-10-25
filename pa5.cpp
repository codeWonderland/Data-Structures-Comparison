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
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <string>
#include "timerSystem.h"
#include "linkedList.h"
#include "DoublyLinkedList.h"

const int SIZE = 1000000;

int main()
{
	std::ifstream inputFile;
	std::string line;
	int *arr;
	arr = new int[SIZE];
	LinkedList<int> linkedList = LinkedList<int>();
	DoublyLinkedList<int> doublyLinkedList = DoublyLinkedList<int>();

	
	int i = 0;

	inputFile.open("output.txt");

	while (!inputFile.eof())
	{
		getline(inputFile, line);
		arr[i] = std::stoi(line);
		i++;
	}



	inputFile.close();
	return 0;
}

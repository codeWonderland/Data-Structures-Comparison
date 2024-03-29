/* ***       Author:  Wei Kian Chen
     *  Last Update:  Oct 4, 2017 by Alice Easter
     *        Class:  CSI-281
     *     Filename:  DoublyLinkedList.h
     *
     *  Description:
     *      This is the template linked list definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/

#ifndef PA4_DOUBLYLINKEDLIST_H
#define PA4_DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList
{
		template <typename R>
		struct Node
		{
			R       mData;
			Node<R> *mNext;
			Node<R> *mPrev;

			/*      Pre:  None
			 *     Post:  This object is initialized using default values
			 *  Purpose:  To initialize date object
			 ********************************************************************/
			Node()
			{
				mData = R();
				mNext = NULL;
				mPrev = NULL;
			}


			/*      Pre:  None
			 *     Post:  This object is initialized using specified data
			 *  Purpose:  To intialize date object
			 ********************************************************************/
			Node(R data)
			{
				mData = data;
				mNext = NULL;
				mPrev = NULL;
			}
		};


	private:
		Node<T> *mHead, *mTail;
		int     mCount;

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		int  getCount();
		T    getData(int index);
		void setData(int index, T data);

		void clear();
		void display();
		void displayReverse();
		bool insert(T data);
		bool isEmpty();
		bool isExist(T searchKey);
		bool remove(T searchKey);
		T    removeAt(int index);

		T operator[](int index);
};


/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize date object
 ************************************************************************/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list
 ************************************************************************/
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	// remove all nodes
	clear();

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;

	// reinitialize count
	mCount = 0;
}


/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to
 *            the caller
 *  Purpose:  To retrieve the number of nodes in the list
 ************************************************************************/
template <typename T>
int DoublyLinkedList<T>::getCount()
{
	return mCount;
}


/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 ************************************************************************/
template <typename T>
T DoublyLinkedList<T>::getData(int index)
{
	int     i;
	Node<T> *tmp;

	if (index < 0 || index >= mCount)
		return T();

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	return tmp->mData;
}


/*      Pre:  The list is instantiated, the index is valid and the
 *            data is available
 *     Post:  The data in the specified index is updated with the
 *            specified data
 *  Purpose:  To update the specified nodes in the list
 ************************************************************************/
template <typename T>
void DoublyLinkedList<T>::setData(int index, T data)
{
	int     i;
	Node<T> *tmp;

	if (index < 0 || index >= mCount)
		return;

	tmp = mHead;
	for (i = 0; i < index; i++)
		tmp = tmp->mNext;

	tmp->mData = data;
}



/*      Pre:  The list is initiated
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list
 ************************************************************************/
template <typename T>
void DoublyLinkedList<T>::clear()
{
	Node<T> *tmp, *toBeDeleted;

	tmp = mHead;

	// removing node by node
	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}



/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 ************************************************************************/
template <typename T>
void DoublyLinkedList<T>::display()
{
	Node<T> *tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mHead;
	while (tmp != NULL)
	{
		cout << tmp->mData << " ";
		tmp = tmp->mNext;
	}
	cout << endl;
}

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 ************************************************************************/
template <typename T>
void DoublyLinkedList<T>::displayReverse()
{
	Node<T> *tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mTail;
	while (tmp != NULL)
	{
		cout << tmp->mData << " ";
		tmp = tmp->mPrev;
	}
	cout << endl;
}


/*      Pre:  The list is instantiated and the data is available
 *     Post:  The data is inserted in ascending order
 *  Purpose:  To insert a data into the list in ascending order.
 *            However, if the data already existed in the list, it will
 *            not be added again
 ************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::insert(T data)
{
	Node<T> *tmp, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		if (data <= mHead->mData)
		{
			newNode->mNext = mHead;
			mHead->mPrev = newNode;
			mHead = newNode;
		}
		else if (data >= mTail->mData)
		{
			mTail->mNext = newNode;
			newNode->mPrev = mTail;
			mTail = newNode;
		}
		else
		{
			tmp = mHead;
			while (tmp->mData < data)
			{
				tmp = tmp->mNext;
			}

			newNode->mNext = tmp;
			tmp->mPrev->mNext = newNode;
			newNode->mPrev = tmp->mPrev;
			tmp->mPrev = newNode;
		}
	}

	mCount++;

	return true;
}


/*      Pre:  The list is instantiated
 *     Post:  The function returns true is the list is empty; false
 *            otherwise
 *  Purpose:  To determine if the list is empty
 ************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
	return mHead == NULL;
}


/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns true if the search key exists in the
 *            list; otherwise false
 *  Purpose:  To determine if a specific value exists in the list or not
 ************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::isExist(T searchKey)
{
	bool    found = false;
	Node<T> *tmp;

	tmp = mHead;
	while (tmp != NULL && !found)
	{
		if (tmp->mData == searchKey)
			found = true;
		else if (tmp->mData > searchKey)
			tmp = NULL;
		else
			tmp = tmp->mNext;
	}

	return found;
}


/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  If the searchKey exists, removes it from the list and the
 *            function returns true; otherwise the function does nothing
 *            and returns false
 *  Purpose:  To remove a specific value from the list
 ************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::remove(T searchKey)
{
	Node<T> *tmp, *toBeDeleted;
	T       data = T();
	bool    found = false;

	if (mHead != NULL)
	{
		tmp = mHead;
		while (tmp != NULL && !found)
		{
			if (tmp->mData == searchKey)
				found = true;
			else if (tmp->mData > searchKey)
				tmp = NULL;
			else
			{
				tmp = tmp->mNext;
			}
		}

		if (found)
		{
			toBeDeleted = tmp;
			data = toBeDeleted->mData;

			if (tmp == mHead)
			{
				if (mHead == mTail)
				{
					mHead = NULL;
					mTail = NULL;
				}
				else
				{
					mHead = tmp->mNext;
				}
			}
			else if (tmp == mTail)
			{
				mTail = mTail->mPrev;
				mTail->mNext = NULL;
			}
			else
			{
				tmp->mPrev->mNext = tmp->mNext;
			}

			toBeDeleted->mNext = NULL;
			delete toBeDeleted;

			mCount--;
		}
	}

	return found;
}


/*      Pre:  The list is instantiated and the index is valid
 *     Post:  Remove the element in the specified index location and
 *            returns its content to the caller.  If the index location
 *            is invalid, the function returns the default value
 *  Purpose:  To remove an item in the specified index location
 ************************************************************************/
template <typename T>
T DoublyLinkedList<T>::removeAt(int index)
{
    Node<T> *tmp, *oneBefore;
    T       data = T();
    int     i;

    if (index < 0 || index >= mCount);
    else if (mHead != NULL)
    {
        tmp = mHead;
        oneBefore = mHead;
        for (i = 0; i < index; i++)
        {
            tmp = tmp->mNext;
        }

        data = tmp->mData;

        if (index == 0)
        {
            mHead = tmp->mNext;
        }
        else
        {
            tmp->mPrev->mNext = tmp->mNext;
            tmp->mNext->mPrev = tmp->mPrev;
        }

        delete tmp;

        mCount--;
    }

    return data;
}


/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the
 *            caller
 *  Purpose:  To retrieve the specified nodes in the list using []
 *            operator
 ************************************************************************/
template <typename T>
T DoublyLinkedList<T>::operator[](int index)
{
	return getData(index);
}


#endif //PA4_DOUBLYLINKEDLIST_H

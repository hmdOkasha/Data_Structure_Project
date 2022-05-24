#pragma once
#include <iostream>
#include "PrioQNode.h"

template <typename T>
class PrioQ
{
private:

	PrioQNode<T>* Head;
	int count;

public:
	//Constructor
	PrioQ()
	{
		Head = NULL;
		count = 0;
	}

	//Function that enqueues the elements sorted ASCENDING ORDER according to the key(small->big)
	template <typename T>
	bool enqueueAscending(T newEntry, const double& newKey)//removed astricks before newentry
	{
		//Creating the new node to be inserted 
		PrioQNode<T>* temp = new PrioQNode<T>(newEntry, newKey);
		PrioQNode<T>* ptr;

		//If the entry is in the first place or the list is empty
		if (Head == NULL || (temp->getKey() < Head->getKey()))
		{
			temp->setNext(Head);
			Head = temp;
		}
		//General Case
		else
		{
			ptr = Head;
			while (ptr->getNext() != NULL && ptr->getNext()->getKey() <= temp->getKey())
				ptr = ptr->getNext();

			temp->setNext(ptr->getNext());
			ptr->setNext(temp);
		}
		count++;
		return true;
	}

	//Function that enqueues the elements sorted DESCENDING ORDER according to the key(BIG->SMALL)
	template <typename T>
	bool enqueueDescending(T newEntry, const double& newKey)//removed astricks before newentry
	{
		//Creating the new node to be inserted 
		PrioQNode<T>* temp = new PrioQNode<T>(newEntry, newKey);
		PrioQNode<T>* ptr;

		//If the entry is in the first place or the list is empty
		if (Head == NULL || (temp->getKey() > Head->getKey()))
		{
			temp->setNext(Head);
			Head = temp;
		}
		//General Case
		else
		{
			ptr = Head;
			while (ptr->getNext() != NULL && ptr->getNext()->getKey() >= temp->getKey())
				ptr = ptr->getNext();

			temp->setNext(ptr->getNext());
			ptr->setNext(temp);
		}
		count++;
		return true;
	}

	bool dequeue(T value)
	{
		if (isEmpty())
			return false;

		PrioQNode<T>* temp = Head;
		value = temp->getItem();

		Head = Head->getNext();
		delete temp;
		count--;
		return true;
	}

	//Function the checks the first element.and copies the front of this queue to the passed param.
	bool peek(PrioQNode<T>& temp)
	{
		if (isEmpty())
			return false;

		temp = *Head;
		return true;
	}

	//Function that checks whether the queue is empty or not
	bool isEmpty()
	{
		return (Head == NULL);
	}
	int getCount()
	{
		return count;
	}

	void printList()
	{
		PrioQNode<T>* curr = Head;
		while (curr != nullptr)
		{

			if (curr->getNext() == NULL)
			{
				cout << curr->getItem();

			}
			else
			{
				cout << curr->getItem() << "," << " ";


			}
			curr = curr->getNext();
		}
	}
	T getLastNode()
	{
		PrioQNode<T>* prev = NULL;
		PrioQNode<T>* curr = Head;
		while (curr->getNext() != nullptr)
		{
			prev = curr;
			curr = curr->getNext();
		}
		T LastNode = curr->getItem();
		return LastNode;
	}
	bool dequeue(PrioQNode<T>& temp)
	{
		if (isEmpty())
			return false;

		temp = *Head;
		Head = Head->getNext();
		count--;
		return true;
	}

};
#pragma once
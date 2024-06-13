#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template<class T>
class Queue : public Node<T>
{
public:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue() :front(nullptr), rear(nullptr) {}

	~Queue()
	{
		while (front != nullptr)
		{
			Node<T>* ptr = front;
			front = front->getNext();
			delete ptr;
		}
		rear = nullptr;
	}
	bool isEmpty()
	{
		return (front == nullptr);
	}

	bool enqueue(T& newEntry)
	{
		Node<T>* newNode = new Node<T>();
		newNode->setItem(newEntry);
		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
			return true;
		}
		rear->setNext(newNode);
		rear = newNode;
		return true;
	}

	bool dequeue(T& anEntry)
	{
		if (front == nullptr)
		{
			return false;
		}
		anEntry = front->getItem();
		Node<T>* curptr = front;
		if (front == rear)
		{
			front = nullptr;
			rear = nullptr;
			return true;
		}
		else
		{
			front = front->getNext();
		}
		delete curptr;
		return true;
	}

	T peekfront()
	{
		if (front != nullptr)
		{
			return front->getItem();
		}
		else
		{
			cout << "Queue is empty" << endl;
		}
	}

	void Print()
	{
		if (isEmpty())
		{
			cout << "[ Empty ]\n";
			return;
		}
		Node<T>* Temp = front;
		cout << "[ " << Temp->getItem();
		Temp = Temp->getNext();
		while (Temp != nullptr)
		{
			cout << ", " << Temp->getItem();
			Temp = Temp->getNext();
		}
		cout << " ]\n";
	}

	void Print2()
	{
		if (isEmpty())
		{
			cout << "[ Empty ]";
			return;
		}
		Node<T>* Temp = front;
		cout << "[ " << Temp->getItem();
		Temp = Temp->getNext();
		while (Temp != nullptr)
		{
			cout << ", " << Temp->getItem();
			Temp = Temp->getNext();
		}
		cout << " ]";
	}
};


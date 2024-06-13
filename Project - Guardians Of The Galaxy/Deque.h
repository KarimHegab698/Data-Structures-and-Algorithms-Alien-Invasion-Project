#pragma once
#include "Denode.h"

template<class T>
class Deque
{
public:
	Denode<T>* front;
	Denode<T>* rear;
public:
		Deque():front(nullptr),rear(nullptr){}
		bool isEmpty()
		{
			if (front == nullptr && rear == nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool enqueuefront(T& newEntry)
		{
			Denode<T>* newNode = new Denode<T>();
			newNode->setItem(newEntry);
			if (isEmpty())
			{
				front = newNode;
				rear = newNode;
				newNode->setNext(nullptr);
				newNode->setPrev(nullptr);
				return true;
			}
			else
			{
				newNode->setNext(front);
				front->setPrev(newNode);
				front = newNode;
				return true;
			}
			return false;
		}
		bool dequeuefront(T& anEntry)
		{
			if (isEmpty())
			{
				return false;
			}
			else if (front == rear)
			{
				anEntry = front->getItem();
				delete front;
				front = nullptr;
				rear = nullptr;
				return true;
			}
			else
			{
				Denode<T>* ptr = front;
				front = front->getNext();
				front->setPrev(nullptr);
				ptr->setNext(nullptr);
				anEntry = ptr->getItem();
				delete ptr;
				ptr = nullptr;
				return true;
			}
		}
		bool enqueueback(T& newEntry)
		{
			Denode<T>* newNode = new Denode<T>();
			newNode->setItem(newEntry);
			if (isEmpty())
			{
				front = newNode;
				rear = newNode;
				newNode->setNext(nullptr);
				newNode->setPrev(nullptr);
				return true;
			}
			else
			{
				rear->setNext(newNode);
				newNode->setPrev(rear);
				rear = newNode;
				return true;
			}
			return false;
		}
		bool dequeueback(T& anEntry)
		{
			if (isEmpty())
			{
				return false;
			}
			else if (front == rear)
			{
				anEntry = front->getItem();
				delete front;
				front = nullptr;
				rear = nullptr;
				return true;
			}
			else
			{
				Denode<T>* ptr = rear;
				rear = rear->getPrev();
				anEntry = ptr->getItem();
				rear->setNext(nullptr);
				ptr->setPrev(nullptr);
				delete ptr;
				return true;
			}
			return false;
		}
		bool peekfront(T& frntEntry)
		{
			if (isEmpty())
			{
				return false;
			}
			frntEntry = front->getItem();
			return true;
		}
		bool peekback(T& bckEntry)
		{
			if (isEmpty())
			{
				return false;
			}
			bckEntry = rear->getItem();
			return true;
		}
		void PrintD()
		{
			if (isEmpty())
			{
				cout << "[ Empty ]\n";
				return;
			}
			Denode<T>* Temp = front;
			cout << "[ " << Temp->getItem();
			Temp = Temp->getNext();
			while (Temp != NULL)
			{
				cout << ", " << Temp->getItem();
				Temp = Temp->getNext();
			}
			cout << " ]\n";
		}
		~Deque()
		{
			T temp;
			while (dequeuefront(temp));
		}
};


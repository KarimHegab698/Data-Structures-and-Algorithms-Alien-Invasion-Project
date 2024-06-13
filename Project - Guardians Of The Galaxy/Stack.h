#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template<class T>
class Stack : Node<T>
{
public:
	Node<T>* Top;
	Stack() :Top(NULL) {};
	bool push(T& it)
	{
		Node<T>* NewNode = new Node<T>();
		NewNode->setItem(it);
		NewNode->setNext(Top);
		Top = NewNode;
		return true;
	}
	bool pop(T &Entry)
	{
		if (IsEmpty())
		{
			return false;
		}
		Entry = Top->getItem();
		Node<T>* DeletePtr = Top;
		Top = Top->getNext();
		DeletePtr->setNext(NULL);
		delete DeletePtr;
		return true;
	}
	bool peek(T &it)
	{
		it = Top->getItem();
	}
	bool IsEmpty()
	{
		if (Top == NULL)
		{
			return true;
		}
		return false;
	}
	void Print()
	{
		if (IsEmpty())
		{
			cout << "[ Empty ]\n";
			return;
		}
		Node<T>* Temp = Top;
		cout << "[ " << Temp->getItem();
		Temp = Temp->getNext();
		while (Temp != NULL)
		{
			cout << ", " << Temp->getItem();
			Temp = Temp->getNext();
		}
		cout << " ]\n";
	}
};




#pragma once
#include <iostream>
#include "ArmyUnit.h"

template<class T>
class Node
{
public:
	T item;
	Node<T>* next;
public:
	Node()
	{
		item = T();
		next = nullptr;
	}
	Node(const T& it)
	{
		item = it;
		next = nullptr;
	}
	Node(const T& it, Node<T>* ptr)
	{
		item = it;
		next = ptr;
	}
	Node<T>* getNext() const
	{
		return next;
	}
	T getItem() const
	{
		return item;
	}
	void setNext(Node<T>* ptr)
	{
		next = ptr;
	}
	void setItem(const T& it)
	{
		item = it;
	}
};



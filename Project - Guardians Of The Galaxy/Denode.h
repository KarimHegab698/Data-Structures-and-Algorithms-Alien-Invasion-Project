#pragma once
#include <iostream>
using namespace std;

template<class T>
class Denode
{
private:
	T item;
	Denode<T>* next;
	Denode<T>* prev;
public:
	Denode() :item(NULL), next(nullptr), prev(nullptr) {}
	Denode(T& it)
	{
		item = it;
	}
	Denode(T& it, Denode<T>* nx)
	{
		item = it;
		next = nx;
	}
	Denode(T& it, Denode<T>* nx, Denode<T>* pv)
	{
		item = it;
		next = nx;
		prev = pv;
	}
	Denode<T>* getNext()
	{
		return next;
	}
	Denode<T>* getPrev()
	{
		return prev;
	}
	T getItem()
	{
		return item;
	}
	void setNext(Denode<T>* nx)
	{
		next = nx;
	}
	void setPrev(Denode<T>* pv)
	{
		prev = pv;
	}
	void setItem(T& it)
	{
		item = it;
	}
	~Denode() {}

};


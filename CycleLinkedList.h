#pragma once


//Ñ­»·Ë«Ö¸ÕëÁ´±í


template <class T>
struct Node {
	T value;
	Node *left;
	Node *right;
};


template <class T>
class CycleLinkedList {
private:
	Node<T> *head;
public:
	CycleLinkedList();
	bool addAtHead(T value);
	bool addAtTail(T value);
	bool isEmpty();
	bool deleteHead();
	bool deleteTail();
	T getHead();
	T getTail();
	T getByIndex(int index);
	T getByValue(T value);
};
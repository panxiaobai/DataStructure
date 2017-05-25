#pragma once

//只有头指针的单链表


template <class T>
struct Node {
	T value;
	Node *next;
};

template <class T> 
class SingleLinkedList {
private:
	Node<T> *head;
public:
	SingleLinkedList();
	bool deleteByIndex(int index);
	bool insertByIndex(int index, T value);
	bool add(T value);
	T getValueByIndex(int index);
	Node<T>* getNodeByIndex(int index);
	Node<T>* getNodeByValue(T value);
	bool replaceByIndex(int index, T value);
};
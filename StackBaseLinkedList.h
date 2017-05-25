#pragma once

//���������ջ

template <class T>
struct Node {
	T value;
	Node *next;
};

template <class T>
class StackBaseLinkedList {
private:
	Node<T> *head;
public:
	StackBaseLinkedList();
	bool push(T value);
	T pop();
	T peek();
	bool clear();
	bool isEmpty();
};
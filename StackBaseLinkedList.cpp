#include"StackBaseLinkedList.h"

template <class T> StackBaseLinkedList<T>::StackBaseLinkedList() {
	head = NULL;
}

template <class T> bool StackBaseLinkedList<T>::push(T value) {
	if (head == NULL) {
		head = new Node<T>;
		head->value = value;
		head->next = NULL;
	}
	else {
		Node<T> *n = new Node<T>;
		n->value = value;
		n->next = head;
		head = n;
	}
	return true;
}

template <class T> T StackBaseLinkedList<T>::pop() {
	if (head == NULL) {
		return NULL;
	}
	else {
		T value = head->value;
		head = head->next;
		return value;
	}
}

template <class T> T StackBaseLinkedList<T>::peek() {
	if (head == NULL) {
		return NULL;
	}
	else {
		return head->value;
	}
}


template <class T> bool StackBaseLinkedList<T>::clear() {
	head = NULL;
	return true;
}

template <class T> bool StackBaseLinkedList<T>::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}
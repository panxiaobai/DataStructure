#include"CycleLinkedList.h"

template <class T> CycleLinkedList<T>::CycleLinkedList() {
	head = NULL;
}

template <class T> bool CycleLinkedList<T>::addAtHead(T value) {
	if (isEmpty()) {
		head = new Node<T>;
		head->value = value;
		head->right = head;
		head->left = head;
	}
	else {
		Node<T> *tail = head->left;
		Node<T> *n = new Node<T>;
		n->value = value;
		n->right = head;
		head->left = n;
		tail->right = n;
		n->left = tail;
		head = n;
	}
	return true;
}

template <class T> bool CycleLinkedList<T>::addAtTail(T value) {
	if (isEmpty()) {
		head = new Node<T>;
		head->value = value;
		head->right = head;
		head->left = head;
	}
	else {
		Node<T> *tail = head->left;
		Node<T> *n = new Node<T>;
		n->value = value;
		n->right = head;
		head->left = n;
		tail->right = n;
		n->left = tail;
	}
	return true;
}

template <class T> bool CycleLinkedList<T>::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> bool CycleLinkedList<T>::deleteHead() {
	if (isEmpty()) {
		return false;
	}
	else {
		if (head->right == head) {
			head = NULL;
		}
		else {
			Node<T> *tail = head->left;
			head = head->right;
			head->left = tail;
			tail->right = head;
		}
		return true;
	}
}

template <class T> bool CycleLinkedList<T>::deleteTail() {
	if (isEmpty()) {
		return false;
	}
	else {
		if (head->right == head) {
			head = NULL;
		}
		else {
			Node<T> *tail = head->left;
			tail = tail->left;
			tail->right = head;
			head->left = tail;
		}
		return true;
	}
}

template <class T> T CycleLinkedList<T>::getHead() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		return head->value;
	}
}

template <class T> T CycleLinkedList<T>::getTail() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		return head->left->value;
	}
}

template <class T> T CycleLinkedList<T>::getByIndex(int index) {
	if (isEmpty()) {
		return NULL;
	}
	Node<T> p = head;
	int i = 0;
	while (p != head) {
		if (i == index) {
			return p;
		}
		i++;
		p = p->right;
	}
	return NULL;
}

template <class T> T CycleLinkedList<T>::getByValue(T value) {
	if (isEmpty()) {
		return NULL;
	}
	Node<T> p = head;
	while (p != head) {
		if (p->value == value) {
			return p->value;
		}
		p = p->right;
	}
	return NULL;
}
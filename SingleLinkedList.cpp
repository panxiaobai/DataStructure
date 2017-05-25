#include"SingleLinkedList.h"

template <class T> SingleLinkedList<T>::SingleLinkedList() {
	head = NULL;
}

template <class T> bool SingleLinkedList<T>::deleteByIndex(int index) {
	if (index == 0) {
		head = head->next;
		return true;
	}
	else {
		Node<T> *p = head, *q = NULL;
		int i = 0;
		while (i != index - 1 && p != NULL) {
			p = p->next;
			i++;
		}
		if (p == NULL) {
			return false;
		}
		q = p->next;
		if (q == NULL) {
			return false;
		}
		p->next = q->next;
		return true;
	}
	
}

template <class T> bool SingleLinkedList<T>::insertByIndex(int index,T value) {
	if (index == 0) {
		Node<T> *n = new Node<T>;
		n->value = value;
		n->next = head;
		head = n;
		return true;
	}
	else {
		Node<T> *p = head;
		int i = 0;
		while (i != index - 1 && p != NULL) {
			p = p->next;
			i++;
		}
		if (p == NULL) {
			return false;
		}
		Node<T> *n = new Node<T>;
		n->value = value;
		n->next = p->next;
		p->next = n;
		return true;
	}
	}
	

template <class T> bool SingleLinkedList<T>::add(T value) {
	if (head == NULL) {
		head = new Node<T>;
		head->value = value;
		head->next = NULL;
	}
	else {
		Node<T> *p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		Node<T> *n = new Node<T>;
		n->value = value;
		n->next = NULL;
		p->next = n;
	}
	return true;
}

template <class T> T SingleLinkedList<T>::getValueByIndex(int index) {
	Node<T> *p = head;
	int i = 0;
	while (i!=index&&p != NULL) {
		p = p->next;
		i++;
	}
	return p->Value;
}

template <class T> Node<T>* SingleLinkedList<T>::getNodeByIndex(int index) {
	Node<T> *p = head;
	int i = 0;
	while (i != index&&p != NULL) {
		p = p->next;
		i++;
	}
	return p;
}

template <class T> Node<T>* SingleLinkedList<T>::getNodeByValue(T value) {
	Node<T> *p = head;
	int i = 0;
	while (p != NULL&&p->value!=value) {
		p = p->next;
	}
	return p;
}

template <class T> bool SingleLinkedList<T>::replaceByIndex(int index,T value) {
	Node<T> *p = head;
	int i = 0;
	while (i != index&&p != NULL) {
		p = p->next;
	}
	if (p == NULL){
		return false;
	}else {
		p->value = value;
		return true;
	}
}
#include"CycleQueueBaseCycleLinkedList.h"

template <class T> CycleQueueBaseCycleLinkedList<T>::CycleQueueBaseCycleLinkedList() {

}

template <class T> bool CycleQueueBaseCycleLinkedList<T>::offer(T value) {
	return list.addAtTail(value);
}

template <class T> T CycleQueueBaseCycleLinkedList<T>::poll() {
	if (isEmpty()) {
		return NULL;
	}
	T value = list.getHead();
	list.deleteHead();
	return value;
}

template <class T> T CycleQueueBaseCycleLinkedList<T>::peek() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		return list.getHead();
	}
}

template <class T> bool CycleQueueBaseCycleLinkedList<T>::isEmpty() {
	return list.isEmpty();
}
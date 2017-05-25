#include"CycleQueueBaseArray.h"

template <class T> CycleQueueBaseArray<T>::CycleQueueBaseArray() {
	array = new T[64];
	maxLength = 64;
	head = 0;
	tail = 0;
}

template <class T> CycleQueueBaseArray<T>::CycleQueueBaseArray(int length) {
	array = new T[length];
	maxLength = length;
	head = 0;
	tail = 0;
}

template <class T> bool CycleQueueBaseArray<T>::offer(T value) {
	if (!isFull()) {
		array[tail] = value;
		tail = (tail + 1) % maxLength;
		return true;
	}
	else {
		return false;
	}
}

template <class T> T CycleQueueBaseArray<T>::poll() {
	if (!isEmpty()) {
		head = (head + 1) % maxLength;
		return array[(head-1)%maxLength];
	}
	else {
		return NULL;
	}
}

template <class T> T CycleQueueBaseArray<T>::peek() {
	if (!isEmpty()) {
		return array[head];
	}
	else {
		return NULL;
	}
}

template <class T> bool CycleQueueBaseArray<T>::isEmpty() {
	if (head == tail) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> bool CycleQueueBaseArray<T>::isFull() {
	if (head == (tail + 1) % maxLength) {
		return true;
	}
	else {
		return false;
	}
}

#include"StackBaseArray.h"

template <class T> StackBaseArray<T>::StackBaseArray() {
	maxLength = 64;
	array = new T[64];
	top = -1;
}

template <class T> StackBaseArray<T>::StackBaseArray(int maxLength) {
	this->maxLength = maxLength;
	array = new T[maxLength];
	top = -1;
}

template <class T> bool StackBaseArray<T>::push(T value) {
	if (top == maxLength - 1) {
		return false;
	}
	top++;
	array[top] = value;
	return true;
}

template <class T> T StackBaseArray<T>::pop() {
	if (top == -1) {
		return NULL;
	}
	top--;
	return array[top + 1];
}

template <class T> T StackBaseArray<T>::peek() {
	if (top == -1) {
		return NULL;
	}
	return array[top];
}

template <class T> bool StackBaseArray<T>::clear() {
	top = -1;
	return true;
}

template <class T> bool StackBaseArray<T>::isEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}
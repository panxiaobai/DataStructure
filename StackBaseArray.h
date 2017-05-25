#pragma once

//���������ջ


template <class T>
class StackBaseArray {
private:
	T *array;
	int maxLength=1;
	int top;
public:
	StackBaseArray();
	StackBaseArray(int maxLength);
	bool push(T value);
	T pop();
	T peek();
	bool clear();
	bool isEmpty();
};
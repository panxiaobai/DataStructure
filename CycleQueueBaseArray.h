#pragma once


//���������ѭ������


template <class T>
class CycleQueueBaseArray {
private:
	T *array;
	int maxLength;
	int head;
	int tail;
public:
	CycleQueueBaseArray();
	CycleQueueBaseArray(int length);
	bool offer(T value);
	T poll();
	T peek();
	bool isEmpty();
	bool isFull();
};
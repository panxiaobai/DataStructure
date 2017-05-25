#pragma once
#include"CycleLinkedList.h"

//基于循环双指针链表的循环队列



template <class T>
class CycleQueueBaseCycleLinkedList {
private:
	CycleLinkedList<T> list;
public:
	CycleQueueBaseCycleLinkedList();
	bool offer(T value);
	T poll();
	T peek();
	bool isEmpty();
};
#pragma once
#include"CycleLinkedList.h"

//����ѭ��˫ָ�������ѭ������



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
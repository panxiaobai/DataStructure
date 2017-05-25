#pragma once
#include<iostream>
using namespace std;


//基于数组的顺序表

template <class T> class SequenceTable {
private:
	T *array;
	int length;
	int maxLength;
public:
	SequenceTable();							//默认构造函数
	SequenceTable(int maxlength);				//带最大长度参数的构造函数
	bool deleteByIndex(int index);				//通过下标删除元素
	bool addByIndex(T t, int index);			//通过下标增加元素
	bool add(T t);								//在表尾增加元素
	T getByIndex(int index);					//通过下标得到元素
	int getLength();							//得到当前表的长度
	int getMaxLength();							//得到当前表的最大长度
	void showAll();								//显示所有元素
	bool replaceByIndex(T t, int index);		//通过下表替换元素
};
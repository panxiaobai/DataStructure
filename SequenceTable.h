#pragma once
#include<iostream>
using namespace std;


//���������˳���

template <class T> class SequenceTable {
private:
	T *array;
	int length;
	int maxLength;
public:
	SequenceTable();							//Ĭ�Ϲ��캯��
	SequenceTable(int maxlength);				//����󳤶Ȳ����Ĺ��캯��
	bool deleteByIndex(int index);				//ͨ���±�ɾ��Ԫ��
	bool addByIndex(T t, int index);			//ͨ���±�����Ԫ��
	bool add(T t);								//�ڱ�β����Ԫ��
	T getByIndex(int index);					//ͨ���±�õ�Ԫ��
	int getLength();							//�õ���ǰ��ĳ���
	int getMaxLength();							//�õ���ǰ�����󳤶�
	void showAll();								//��ʾ����Ԫ��
	bool replaceByIndex(T t, int index);		//ͨ���±��滻Ԫ��
};
#include"SequenceTable.h"

template <class T> SequenceTable<T>::SequenceTable() {

}

template <class T> SequenceTable<T>::SequenceTable(int maxlength) {
	array = new T[maxlength];
	this->length = 0;
	this->maxLength = maxlength;
}

template <class T> bool SequenceTable<T>::deleteByIndex(int index) {
	if (index<0 || index>length - 1) {
		return false;
	}
	for (int i = index + 1; i < length; i++) {
		array[i - 1] = array[i];
	}
	length--;
	return true;
}

template <class T> bool SequenceTable<T>::addByIndex(T t, int index) {
	if (index<0 || index>length) {
		return false;
	}
	length++;
	for (int i = length - 1; i > index; i--) {
		array[i] = array[i - 1];
	}
	array[index] = t;
	return true;
}

template <class T> bool SequenceTable<T>::add(T t) {
	array[length] = t;
	length++;
	return true;
}

template <class T> T SequenceTable<T>::getByIndex(int index) {
	return array[index];
}

template <class T> int SequenceTable<T>::getLength() {
	return length;
}

template <class T> int SequenceTable<T>::getMaxLength() {
	return maxLength;
}

template <class T> void SequenceTable<T>::showAll() {
	for (int i = 0; i < length; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
}

template <class T> bool SequenceTable<T>::replaceByIndex(T t, int index) {
	if (index<0 || index>=length) {
		return false;
	}
	array[index] = t;
	return true;
}

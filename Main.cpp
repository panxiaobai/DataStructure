#include<iostream>
#include"ExpressionCalcuate.h"
using namespace std;

void main() {
	ExpressionCalcuate ec;
	ec.setInfix("(3+4-4/2)*5-6");
	ec.infixToPrefix();
	ec.infixToSuffix();
	cout <<"��׺:"<< ec.getInfix() << endl;
	cout << "ǰ׺:" << ec.getPrefix() << endl;
	cout << "��׺:" << ec.getSuffix() << endl;
	cout << "��׺����:" << ec.calcuateInfix() << endl;
	cout << "ǰ׺����:" << ec.calcuatePrefix() << endl;
	cout << "��׺����:" << ec.calcuateSuffix() << endl;
}
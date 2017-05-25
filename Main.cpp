#include<iostream>
#include"ExpressionCalcuate.h"
using namespace std;

void main() {
	ExpressionCalcuate ec;
	ec.setInfix("(3+4-4/2)*5-6");
	ec.infixToPrefix();
	ec.infixToSuffix();
	cout <<"中缀:"<< ec.getInfix() << endl;
	cout << "前缀:" << ec.getPrefix() << endl;
	cout << "后缀:" << ec.getSuffix() << endl;
	cout << "中缀计算:" << ec.calcuateInfix() << endl;
	cout << "前缀计算:" << ec.calcuatePrefix() << endl;
	cout << "后缀计算:" << ec.calcuateSuffix() << endl;
}
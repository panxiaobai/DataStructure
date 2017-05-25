#pragma once
#include<string>
#include<iostream>
#include <stack> 
using namespace std;

class ExpressionCalcuate {
private:
	string prefix;	//ǰ׺
	string suffix;	//��׺
	string infix;	//��׺
public:
	void setPrefix(string prefix);
	void setSuffix(string suffix);
	void setInfix(string infix);
	string getPrefix();
	string getSuffix();
	string getInfix();
	bool infixToPrefix();				//��׺תǰ׺
	bool infixToSuffix();				//��׺ת��׺
	bool prefixToSuffix();				//ǰ׺ת��׺
	bool suffixToPrefix();				//��׺תǰ׺
	bool prefixToInfix();				//ǰ׺ת��׺
	bool suffixToInfix();				//��׺ת��׺
	int calcuatePrefix();				//ǰ׺����
	int calcuateSuffix();				//��׺����
	int calcuateInfix();				//��׺����
	bool calcuateOnce(stack<int> &numStack, stack<char> &signStack);
};
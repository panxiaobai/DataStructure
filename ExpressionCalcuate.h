#pragma once
#include<string>
#include<iostream>
#include <stack> 
using namespace std;

class ExpressionCalcuate {
private:
	string prefix;	//前缀
	string suffix;	//后缀
	string infix;	//中缀
public:
	void setPrefix(string prefix);
	void setSuffix(string suffix);
	void setInfix(string infix);
	string getPrefix();
	string getSuffix();
	string getInfix();
	bool infixToPrefix();				//中缀转前缀
	bool infixToSuffix();				//中缀转后缀
	bool prefixToSuffix();				//前缀转后缀
	bool suffixToPrefix();				//后缀转前缀
	bool prefixToInfix();				//前缀转中缀
	bool suffixToInfix();				//后缀转中缀
	int calcuatePrefix();				//前缀计算
	int calcuateSuffix();				//后缀计算
	int calcuateInfix();				//中缀计算
	bool calcuateOnce(stack<int> &numStack, stack<char> &signStack);
};
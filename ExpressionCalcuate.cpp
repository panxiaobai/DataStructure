#include"ExpressionCalcuate.h"

void ExpressionCalcuate::setPrefix(string prefix) {
	this->prefix = prefix;
}

void ExpressionCalcuate::setSuffix(string suffix) {
	this->suffix = suffix;
}

void ExpressionCalcuate::setInfix(string infix) {
	this->infix = infix;
}

string ExpressionCalcuate::getPrefix(){
	return this->prefix;
}

string ExpressionCalcuate::getSuffix() {
	return this->suffix;
}

string ExpressionCalcuate::getInfix() {
	return this->infix;
}

bool ExpressionCalcuate::infixToPrefix() {
	stack<char> signStack;
	stack<char> res;
	string result = "";
	for (int i = infix.size()-1; i >-1; i--) {
		char c = infix[i];
		if (c >= '0'&&c <= '9') {
			res.push(c);
		}
		else if (c == '+' || c == '-') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == ')'||
					signStack.top() == '+' || signStack.top() == '-') {
					signStack.push(c);
					flag = false;
				}
				else {
					res.push(signStack.top());
					signStack.pop();
				}
			}
		}
		else if (c == '*' || c == '/') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == ')' ||
					signStack.top() == '+' || signStack.top() == '-'||
					signStack.top() == '/' || signStack.top() == '*') {
					signStack.push(c);
					flag = false;
				}
				else {
					res.push(signStack.top());
					signStack.pop();
				}
			}
		}
		else if (c == ')') {
			signStack.push(c);
		}
		else if (c == '(') {
			while (signStack.top() != ')') {
				res.push(signStack.top());
				signStack.pop();
			}
			signStack.pop();
		}
		
	}
	while (!signStack.empty()) {
		res.push(signStack.top());
		signStack.pop();
	}
	while (!res.empty()) {
		result += res.top();
		res.pop();
	}
	this->prefix = result;
	return true;
}

bool ExpressionCalcuate::infixToSuffix() {
	stack<char> signStack;
	string result="";
	for (int i = 0; i < infix.size(); i++) {
		char c = infix[i];
		if (c >= '0'&&c <= '9') {
			result += c;
		}
		else if (c == '+'||c=='-') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == '(') {
					signStack.push(c);
					flag = false;
				}
				else {
					result += signStack.top();
					signStack.pop();
				}
			}
		}
		else if (c == '*'||c == '/') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == '('||
					signStack.top()=='+'||signStack.top()=='-') {
					signStack.push(c);
					flag = false;
				}
				else {
					result += signStack.top();
					signStack.pop();
				}
			}
		}
		else if (c == '(') {
			signStack.push(c);
		}
		else if (c == ')') {
			while (signStack.top() != '(') {
				result += signStack.top();
				signStack.pop();
			}
			signStack.pop();
		}
	}
	while (!signStack.empty()) {
		result += signStack.top();
		signStack.pop();
	}
	this->suffix = result;
	return true;
}


bool ExpressionCalcuate::prefixToSuffix() {
	return true;
}

bool ExpressionCalcuate::suffixToPrefix() {
	return true;
}

bool ExpressionCalcuate::prefixToInfix() {
	return true;
}

bool ExpressionCalcuate::suffixToInfix() {
	return true;
}



int ExpressionCalcuate::calcuatePrefix() {
	stack<int> numStack;
	for (int i = prefix.size()-1; i>-1; i--) {
		char c = prefix[i];
		if (c >= '0'&&c <= '9') {
			int num = c - '0';
			numStack.push(num);
		}
		else {
			int a = numStack.top();
			numStack.pop();
			int b = numStack.top();
			numStack.pop();
			if (c == '+') {
				numStack.push(a + b);
			}
			else if (c == '-') {
				numStack.push(a - b);
			}
			else if (c == '*') {
				numStack.push(a * b);
			}
			else if (c == '/') {
				numStack.push(a / b);
			}
		}

	}
	return numStack.top();
}

int ExpressionCalcuate::calcuateSuffix() {
	stack<int> numStack;
	for (int i = 0; i < suffix.size(); i++) {
		char c = suffix[i];
		if (c >= '0'&&c <= '9') {
			int num = c - '0';
			numStack.push(num);
		}
		else {
			int b = numStack.top();
			numStack.pop();
			int a = numStack.top();
			numStack.pop();
			if (c == '+') {
				numStack.push(a + b);
			}
			else if (c == '-') {
				numStack.push(a - b);
			}
			else if (c == '*') {
				numStack.push(a * b);
			}
			else if (c == '/') {
				numStack.push(a / b);
			}
		}

	}
	return numStack.top();
}

int ExpressionCalcuate::calcuateInfix() {
	stack<int> numStack;
	stack<char> signStack;
	for (int i = 0; i < infix.size(); i++) {
		char c = infix[i];
		if (c >= '0'&&c <= '9') {
			int num = c - '0';
			numStack.push(num);
		}
		else if (c == '+') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == '(') {
					signStack.push(c);
					flag = false;
				}
				else {
					calcuateOnce(numStack, signStack);
				}
			}
		}
		else if (c == '-') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == '(' || signStack.top() == '+') {
					signStack.push(c);
					flag = false;
				}
				else {
					calcuateOnce(numStack, signStack);
				}
			}
		}
		else if (c == '*') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == '(' ||
					signStack.top() == '+' || signStack.top() == '-') {
					signStack.push(c);
					flag = false;
				}
				else {
					calcuateOnce(numStack, signStack);
				}
			}
		}
		else if (c == '/') {
			bool flag = true;
			while (flag) {
				if (signStack.empty() || signStack.top() == '(' ||
					signStack.top() == '+' || signStack.top() == '-' || signStack.top() == '*') {
					signStack.push(c);
					flag = false;
				}
				else {
					calcuateOnce(numStack, signStack);
				}
			}
		}
		else if (c == '(') {
			signStack.push(c);
		}
		else if (c == ')') {
			while (signStack.top() != '(') {
				calcuateOnce(numStack, signStack);
			}
			signStack.pop();
		}
	}
	while (!signStack.empty()) {
		calcuateOnce(numStack, signStack);
	}
	return numStack.top();
}


bool ExpressionCalcuate::calcuateOnce(stack<int> &numStack, stack<char> &signStack) {
	int b = numStack.top();
	numStack.pop();
	int a = numStack.top();
	numStack.pop();
	char c = signStack.top();
	signStack.pop();
	if (c == '+') {
		numStack.push(a + b);
	}
	else if (c == '-') {
		numStack.push(a - b);
	}
	else if (c == '*') {
		numStack.push(a * b);
	}
	else if (c == '/') {
		numStack.push(a / b);
	}
	return true;
}

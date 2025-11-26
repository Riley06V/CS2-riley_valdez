#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "stack.h"

using namespace std;

int evaluateRPN(const string&);
void test();

int main(int argc, char *argv[]) {
	test();
	return 0;
}

int evaluateRPN(const string& expr) {
	stack<int> stack;
	std::stringstream ss(expr);
	std::string token;

	while (ss >> token) {
		// If token is a number
		if (isdigit(token[0]) ||
			(token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
			stack.push(std::stoi(token));
			} else {
				// Must be operator
				if (stack.size() < 2) {
					throw std::runtime_error("Invalid RPN expression: not enough operands");
				}
				int b = stack.pop();  // second operand
				int a = stack.pop();  // first operand
				int result;

				if (token == "+") result = a + b;
				else if (token == "-") result = a - b;
				else if (token == "*") result = a * b;
				else if (token == "/") {
					if (b == 0) throw std::runtime_error("Division by zero");
					result = a / b;
				} else {
					throw std::runtime_error("Invalid operator: " + token);
				}
				stack.push(result);
			}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Invalid RPN expression: leftover operands");
	}
	return stack.pop();

}

void test() {
	cout << "3 4 + 5 6 - * = " << evaluateRPN("3 4 + 5 6 - * = ") << endl;
	cout << "7 5 + 1 42 / + = " << evaluateRPN("7 5 + 1 42 / +") << endl;
	cout << "2 5 + 2 - 8 9 + + = " << evaluateRPN("2 5 + 2 - 8 9 + +") << endl;
}
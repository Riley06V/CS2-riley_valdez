#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include "stack.h"

using namespace std;

double evaluateRPN(const string&);
void test();
int main(int argc, char *argv[]) {

	//command line using argc and argv
	try {
		if (argc == 3 && string(argv[1]) == "-p") {
			string expr = argv[2];
			double result = evaluateRPN(expr);
			cout << expr << " = " << result << std::endl;
		} else {
			string expr;
			cout << "Enter an RPN expression: ";
			getline(cin, expr);
			double result = evaluateRPN(expr);
			cout << fixed << setprecision(5);
			cout << expr << " = " << result << endl;
		}
	} catch (const std::exception &e) {
		cerr << e.what() << endl;
	}
	return 0;
}

double evaluateRPN(const string& expr) {
	stack<double> operandStack;
	stringstream ss(expr);
	string token;

	while (ss >> token) {
		// If token is a number
		if (isdigit(token[0]) ||
			(token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
			operandStack.push(stod(token));
			} else {
				// Must be operator
				if (operandStack.size() < 2) {
					throw runtime_error("Invalid RPN expression: not enough operands");
				}
				double b = operandStack.pop();  // second operand
				double a = operandStack.pop();  // first operand
				double result;

				if (token == "+") result = a + b;
				else if (token == "-") result = a - b;
				else if (token == "*") result = a * b;
				else if (token == "/") {
					if (b == 0) throw runtime_error("Division by zero");
					result = a / b;
				} else {
					throw runtime_error("Invalid operator: " + token);
				}
				operandStack.push(result);
			}
	}

	if (operandStack.size() != 1) {
		throw runtime_error("Invalid RPN expression: leftover operands");
	}
	return operandStack.pop();

}

void test() {
	cout << "3 4 + = " << evaluateRPN("3 4 +") << endl;   // should be 7
	cout << "3 4 + 5 6 - * = " << evaluateRPN("3 4 + 5 6 - *") << endl; // should be -7
	cout << "7 5 + 1 42 / + = " << evaluateRPN("7 5 + 1 42 / +") << endl; //12
	cout << "2 5 + 2 - 8 9 + + = " << evaluateRPN("2 5 + 2 - 8 9 + +") << endl; //22
}

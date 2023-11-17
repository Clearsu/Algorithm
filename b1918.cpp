#include <iostream>
#include <stack>
#include <string>

int main() {
	std::string str;
	std::cin >> str;
	std::stack<char> operators;

	int len = str.length();
	char c;
	for (int i = 0; i < len; i++) {
		c = str[i];
		if (c >= 'A' && c <= 'Z') {
			std::cout << c;
		} else {
			if (c == '(') {
				operators.push(c);
			} else if (c == '*' || c == '/') {
				while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
					std::cout << operators.top();
					operators.pop();
				}
				operators.push(c);
			} else if (c == '+' || c == '-') {
				while (!operators.empty() && (operators.top() != '(')) {
					std::cout << operators.top();
					operators.pop();
				}
				operators.push(c);
			} else if (c == ')') {
				while (operators.top() != '(') {
					std::cout << operators.top();
					operators.pop();
				}
				operators.pop();
			}
		}
	}
	while (!operators.empty()) {
		std::cout << operators.top();
		operators.pop();
	}
	std::cout << '\n';
}
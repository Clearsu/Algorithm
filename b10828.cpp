#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main() {
	int n;
	std::cin >> n;
	std::cin.ignore();

	std::stack<int> stack;

	std::string line;
	std::string tempStr;
	for (int i = 0; i < n; i++) {
		std::getline(std::cin, line);
		std::stringstream ss(line);
		int temp;
		ss >> tempStr >> temp;
		if (tempStr == "push") {
			stack.push(temp);
		} else if (tempStr == "pop") {
			if (stack.empty()) {
				std::cout << "-1\n";
				continue ;
			}
			std::cout << stack.top() << '\n';
			stack.pop();
		} else if (tempStr == "size") {
			std::cout << stack.size() << '\n';
		} else if (tempStr == "empty") {
			std::cout << stack.empty() << '\n';
		} else if (tempStr == "top") {
			if (stack.empty()) {
				std::cout << "-1\n";
				continue ;
			}
			std::cout << stack.top() << '\n';
		}
		line.clear();
	}
	
	return 0;
}
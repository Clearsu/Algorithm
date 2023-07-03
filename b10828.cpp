/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b10828.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:16:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/07/03 13:01:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>

int main(void) {
	int n;
	std::cin >> n;
	std::cin.ignore();
	if (n < 1 || n > 100000) return 1;
	
	std::vector<std::string> inputLines;
	std::string input;
	for (int i = 0; i < n; i++) {
		std::getline(std::cin, input);
		inputLines.push_back(input);
		input.clear();
	}

	std::string instruction;
	std::stack<int> stack;
	int element;
	for (int j = 0; j < n; j++) {
		std::stringstream sstream(inputLines[j]);
		sstream >> instruction;

		if (instruction == "push") {
			sstream >> element;
			stack.push(element);
		} else if (instruction == "top") {
			if (stack.size() == 0) {
				std::cout << "-1\n";
			} else {
				std::cout << stack.top() << '\n';
			}
		} else if (instruction == "pop") {
			if (stack.size() == 0) {
				std::cout << "-1\n";
			} else {
				std::cout << stack.top() << '\n';
				stack.pop();
			}
		} else if (instruction == "size") {
			std::cout << stack.size() << '\n';
		} else if (instruction == "empty") {
			std::cout << stack.empty() << '\n';
		}
		input.clear();
	}

	return 0;
}

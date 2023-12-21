#include <iostream>
#include <string>

int main() {
	std::string temp;

	while (std::getline(std::cin, temp)) {
		std::cout << temp << '\n';
	};

	return 0;
}
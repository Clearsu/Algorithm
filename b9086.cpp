#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::cin.ignore();
	std::string str;
	for (int i = 0; i < n; i++) {
		std::cin >> str;
		std::cout << str[0] << *(str.end() - 1) << '\n';
		std::cin.ignore();
	}
}
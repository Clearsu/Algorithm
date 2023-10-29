#include <iostream>

int main() {
	int n;
	std::cin >> n;

	n /= 4;
	for (int i = 0; i < n; i++) {
		std::cout << "long ";
	}
	std::cout << "int\n";
}
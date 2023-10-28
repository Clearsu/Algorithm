#include <iostream>

int main() {
	int x, n, a, b;

	std::cin >> x;
	std::cin.ignore();
	std::cin >> n;
	std::cin.ignore();
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b;	
		std::cin.ignore();
		total += a * b;
	}

	if (total == x) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}

	return 0;
}
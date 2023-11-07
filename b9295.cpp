#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::cin.ignore();

	int a, b;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b;
		std::cout << "Case " << i + 1 << ": " << a + b << '\n';
		std::cin.ignore();
	}
}
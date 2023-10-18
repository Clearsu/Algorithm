#include <iostream>

int getFibonacci(int n, int n1, int n2) {
	if (n == 0) {
		return n1;
	}
	return getFibonacci(n - 1, n2, n1 + n2);
}

int main() {
	int n;

	std::cin >> n;
	
	if (n == 1) {
		std::cout << "1\n";
		return 0;
	}

	std::cout << getFibonacci(n, 0, 1) << '\n';

	return 0;
}
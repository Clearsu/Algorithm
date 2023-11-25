#include <iostream>

int basket[101] = {0, };

int main() {
	int n, m;
	std::cin >> n >> m;
	std::cin.ignore();

	for (int x = 0; x < m; x++) {
		int i, j, k;
		std::cin >> i >> j >> k;
		std::cin.ignore();
		for (int l = i; l <= j; l++) {
			basket[l] = k;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << basket[i] << ' ';
	}
	std::cout << '\n';
#include <iostream>

void hanoi(short n, short from, short via, short to) {
	if (n == 1) {
		std::cout << from << ' ' << to << '\n';
		return ;
	}
	hanoi(n - 1, from, to, via);
	std::cout << from << ' ' << to << '\n';
	hanoi(n - 1, via, from, to);
}

int main() {
	uint32_t n;
	std::cin >> n;

	int cases = 1;
	for (int i = 0; i < n; i++) {
		cases *= 2;
	}

	std::cout << cases - 1 << '\n';

	hanoi(n, 1, 2, 3);
}
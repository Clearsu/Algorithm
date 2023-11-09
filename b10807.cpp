#include <iostream>

int main(void) {
	int n;
	std::cin >> n;
	std::cin.ignore();

	int arr[100];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::cin.ignore();

	int v;
	std::cin >> v;

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) {
			res++;
		}
	}

	std::cout << res << '\n';

	return 0;
}
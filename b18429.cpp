#include <iostream>

void dfs(int& cases, const int& n, const int& k, int const kit[8],
			bool check[8], int day, int currWeight) {
	if (day == n - 1) {
		if (currWeight >= 500) {
			cases++;
			return ;
		} else {
			return ;
		}
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == false && currWeight - k + kit[i] >= 500) {
			check[i] = true;	
			dfs(cases, n, k, kit, check, day + 1, currWeight - k + kit[i]);
			check[i] = false;
		}
	}
}

int main() {
	int n, k;
	int kit[8];
	bool check[8] = {false,};

	std::cin >> n >> k;
	std::cin.ignore();

	for (int i = 0; i < n; i++) {
		std::cin >> kit[i];
	}	

	int cases = 0;

	dfs(cases, n, k, kit, check, 0, 500);

	std::cout << cases << '\n';

	return 0;
}
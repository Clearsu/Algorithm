#include <iostream>
#include <utility>
#include <algorithm>

int n, k;
std::pair<int, int> stuffs[101];
int values[101][100001] = {};

int main() {
	std::cin >> n >> k;
	std::cin.ignore();
	for (int i = 1; i <= n; i++) {
		std::cin >> stuffs[i].first >> stuffs[i].second;
		std::cin.ignore();
	}

	for (int i = 1; i <= n; i++) {
		int weight = stuffs[i].first;
		int value = stuffs[i].second;
		for (int j = 1; j <= k; j++) {

			if (j < weight) {
				values[i][j] = values[i - 1][j];
			} else {
				values[i][j] = std::max(values[i - 1][j], values[i - 1][j - weight] + value);
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= k; j++) {
	// 		std::cout << values[i][j] << ' ';
	// 	}
	// 	std::cout << '\n'; 
	// }

	std::cout << values[n][k] << '\n';
	
	return 0;
}
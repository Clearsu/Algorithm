#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int n;

	std::cin >> n;
	std::cin.ignore();

	std::vector<int> hills(n);
	for (int i = 0; i < n; i++) {
		std::cin >> hills[i];
		std::cin.ignore();
	}

	std::sort(hills.begin(), hills.end());

	int minCost, tempCost, idx, diff, maxInRange;
	minCost = 2147483647;
	for (int minInRange = hills[0]; minInRange <= hills[n - 1] - 17; minInRange++) {
		tempCost = 0;
		idx = 0;
		while (hills[idx] < minInRange) {
			diff = minInRange - hills[idx];
			tempCost += diff * diff;
			idx++;
		}
		idx = n - 1;
		maxInRange = minInRange + 17;
		while (hills[idx] > maxInRange) {
			diff = maxInRange - hills[idx];
			tempCost += diff * diff;
			idx--;
		}
		if (tempCost < minCost) {
			minCost = tempCost;
		}
	}

	std::cout << minCost << '\n';

	return 0;
}
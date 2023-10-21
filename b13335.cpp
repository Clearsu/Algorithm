#include <iostream>
#include <queue>

int main() {
	int n, w, l;
	int trucks[1000];

	std::cin >> n >> w >> l;
	std::cin.ignore();

	for (int i = 0; i < n; i++) {
		std::cin >> trucks[i];
	}	

	std::queue<int> bridge;
	int sumOfTrucksOnBridge = 0;
	int time = 0;

	for (int i = 0; i < n; i++) {
		while (true) {
			if (bridge.size() == w) {
				sumOfTrucksOnBridge -= bridge.front();
				bridge.pop();
			}
			if (sumOfTrucksOnBridge + trucks[i] <= l) {
				break ;
			}
			bridge.push(0);
			time++;
		}
		bridge.push(trucks[i]);
		sumOfTrucksOnBridge += trucks[i];
		time++;
	}

	std::cout << time + w << '\n';

	return 0;
}
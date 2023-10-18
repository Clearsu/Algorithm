#include <iostream>
#include <queue>
#include <vector>

void moveTrucks(std::vector<int>& bridge, int w, int& truckPassed, int& totalWeightOfTrucks) {
	if (bridge[w - 1] != 0) {
		totalWeightOfTrucks -= bridge[w - 1];
		bridge[w - 1] = 0;
		truckPassed++;
	}
	if (w == 1) {
		return ;
	}
	for (int i = w - 2; i >= 0; i--) {
		if (bridge[i] != 0) {
			bridge[i + 1] = bridge[i];
			bridge[i] = 0;
		}
	}
}

int getTrucksWeightOnBridge(std::vector<int>& bridge, int w) {
	int sum = 0;

	for (int i = 0; i < w; i++) {
		sum += bridge[i];	
	}
	return sum;
}

void printBridge(std::vector<int>& bridge, int w) {
	std::cout << "bridge: ";
	for (int i = 0; i < w; i++) {
		std::cout << bridge[i] << ' ';
	}
	std::cout << '\n';
}

int main(void) {
	// w : 다리 길이
	// l : 최대 하중
	int n, w, l;

	std::cin >> n >> w >> l;
	std::cin.ignore();

	std::queue<int> queue;
	int truck;
	for (int i = 0; i < n; i++) {
		std::cin >> truck;
		queue.push(truck);
	}

	std::vector<int> bridge(w);
	int time = 0;
	int trucksPassed = 0;
	int trucksOnBridge = 0;
	int totalWeightOfTrucks = 0;

	while (!queue.empty()) {
		while (totalWeightOfTrucks + queue.front() <= l
				&& !queue.empty() && trucksOnBridge < w) {
			if (trucksOnBridge != 0) {
				moveTrucks(bridge, w, trucksPassed, totalWeightOfTrucks);
			}
			bridge[0] = queue.front();
			totalWeightOfTrucks += bridge[0];
			trucksOnBridge++;
			queue.pop();
			time++;
			printBridge(bridge, w);
		}
		int initialWeightSumOnBridge = totalWeightOfTrucks;
		while (totalWeightOfTrucks == initialWeightSumOnBridge) {
			moveTrucks(bridge, w, trucksPassed, totalWeightOfTrucks);
			if (totalWeightOfTrucks + queue.front() <= l) {
				break ;
			}
			time++;
			// printBridge(bridge, w);
		}
	}
	while (totalWeightOfTrucks > 0) {
		moveTrucks(bridge, w, trucksPassed, totalWeightOfTrucks);
		time++;
	}
	time++;

	std::cout << time << '\n';
	
	return 0;
}
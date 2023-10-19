#include <deque>
#include <queue>
#include <iostream>

void moveTrucks(std::deque<int>& bridge, int& time, int& trucksPassed) {
	if (bridge. != 0) {
		trucksPassed++;
	}	
	bridge.pop_front();
}

int main() {
	int n, w, l;

	std::cin >> n >> w >> l;
	std::cin.ignore();

	std::queue<int> trucks;
	int truckWeight;
	for (int i = 0; i < n; i++) {
		std::cin >> truckWeight;
		trucks.push(truckWeight);
	}

	std::deque<int> bridge(w);	
	int trucksPassed = 0;
	int totalWeightOnBridge = 0;

	bridge[0] = trucks.front();
	totalWeightOnBridge += trucks.front();
	trucks.pop();
	int time = 1;
	while (trucksPassed != n) {
		while (totalWeightOnBridge + trucks.front() < l) {
			moveTrucks(bridge, time, trucksPassed);
			bridge[0] = trucks.front();
			totalWeightOnBridge += trucks.front();
			trucks.pop();
		}
	}

	return 0;
}
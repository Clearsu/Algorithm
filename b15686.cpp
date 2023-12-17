#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int minDist = 2147483647;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
vector<pair<int, int> > chosenChicken;

int getDistance() {
	int distSum = 0;
	int min;
	int dist;
	
	for (int i = 0; i < house.size(); i++) {
		min = 2147483647;
		for (int j = 0; j < chosenChicken.size(); j++) {
			dist = abs(house[i].first - chosenChicken[j].first) \
				+ abs(house[i].second - chosenChicken[j].second);
			if (dist < min) {
				min = dist;
			}
		}
		distSum += min;
	}
	return distSum;
}

void bruteForce(int curr, int depth) {
	if (depth == m) {
		int dist = getDistance();
		if (dist < minDist) {
			minDist = dist;
		}
		return ;
	}
	for (int i = curr; i < chicken.size(); i++) {
		chosenChicken.push_back(chicken[i]);
		bruteForce(i + 1, depth + 1);
		chosenChicken.pop_back();
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 2) {
				chicken.push_back(pair<int, int>(i, j));
			} else if (temp == 1) {
				house.push_back(pair<int, int>(i, j));
			}
		}
	}

	bruteForce(0, 0);

	cout << minDist << '\n';

	return 0;
}
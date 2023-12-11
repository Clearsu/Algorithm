#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int cities[100][100];

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				cities[i][j] = 0;
			} else {
				cities[i][j] = 10000000;
			}
		}
	}


	int cityA, cityB, cost;
	for (int i = 0; i < m; i++) {
		cin >> cityA >> cityB >> cost;
		cityA--;
		cityB--;
		if (cost < cities[cityA][cityB]) {
			cities[cityA][cityB] = cost;
		}
	}

	for (int via = 0; via < n; via++) {
		for (int departure = 0; departure < n; departure++) {
			for (int arrival = 0; arrival < n; arrival++) {
				cities[departure][arrival] = min(cities[departure][arrival] \
												,cities[departure][via] + cities[via][arrival]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cities[i][j] == 10000000) {
				cout << 0 << ' ';
			} else {
				cout << cities[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
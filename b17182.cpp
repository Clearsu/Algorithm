#include <iostream>
#include <limits>

int n, k;
int travelTime[10][10];
int minTime = std::numeric_limits<int>::max();
bool visited[10] = {false, };

void readInput(void) {
	std::cin >> n >> k;
	std::cin.ignore();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> travelTime[i][j];
		}
		std::cin.ignore();
	}
}

void calculateShortest(void) {
	int distIK;
	int distIKJ;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i == k) {
				continue ;
			}
			distIK = travelTime[i][k];
			for (int j = 0; j < n; j++) {
				if (j == i) {
					continue ;
				}
				distIKJ = distIK + travelTime[k][j];
				int& distIJ = travelTime[i][j];
				if (distIKJ < distIJ) {
					distIJ = distIKJ;
				}
			}
		}
	}
}

bool isAllVisited(void) {
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			return false;
		}
	}
	return true;
}

void dfs(int from, int currTime) {
	if (currTime >= minTime) {
		return ;
	}
	if (isAllVisited() && currTime < minTime) {
		minTime = currTime;
		return ;
	}
	for (int to = 0; to < n; to++) {
		if (visited[to] == true) {
			continue ;
		}
		visited[to] = true;
		dfs(to, currTime + travelTime[from][to]);
		visited[to] = false;
	}
}

int main(void) {
	readInput();
	calculateShortest();
	visited[k] = true;
	dfs(k, 0);

	std::cout << minTime << '\n';

	return 0;
}
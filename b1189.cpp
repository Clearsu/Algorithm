#include <iostream>

int r, c, k;
int cases = 0;
char map[5][5];

void dfs(int currR, int currC, int dist) {
	if (map[currR][currC] != '.' || dist > k) {
		return ;
	}
	if (currR == 0 && currC == c - 1) {
		if (dist < k) {
			return ;
		}
		cases++;
		return ;
	}
	map[currR][currC] = 'V';
	if (currR > 0) {
		dfs(currR - 1, currC, dist + 1);
	}
	if (currR < r - 1) {
		dfs(currR + 1, currC, dist + 1);
	}
	if (currC > 0) {
		dfs(currR, currC - 1, dist + 1);
	}
	if (currC < c - 1) {
		dfs(currR, currC + 1, dist + 1);
	}
	map[currR][currC] = '.';
}

int main() {
	std::cin >> r >> c >> k;
	std::cin.ignore();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> map[i][j];
		}
		std::cin.ignore();
	}

	dfs(r - 1, 0, 1);

	std::cout << cases << '\n';
}
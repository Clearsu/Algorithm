#include <iostream>
#include <deque>

bool grid[101][101] = {};
int n;
int x, y, d, g;

void drawDragonCurve() {
	std::deque<short> dir;
	dir.push_back(d);
	while (g-- > 0) {
		for (int i = dir.size() - 1; i >= 0; i--) {
			if (dir[i] == 3) {
				dir.push_back(0);
			} else {
				dir.push_back(dir[i] + 1);
			}
		}
	}
	grid[y][x] = 1;
	int len = dir.size();
	for (int i = 0; i < len; i++) {
		switch (dir[i]) {
			case 0:
				x++;
				break ;
			case 1:
				y--;
				break ;
			case 2:
				x--;
				break ;
			case 3:
				y++;
		}
		grid[y][x] = 1;
	}
}

int countSquares() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (grid[i][j] == 1 && grid[i + 1][j] == 1
				&& grid[i][j + 1] == 1 && grid[i + 1][j + 1] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	std::cin >> n;
	std::cin.ignore();

	for (int i = 0; i < n; i++) {
		std::cin >> x >> y >> d >> g;
		std::cin.ignore();
		drawDragonCurve();
	}

	std::cout << countSquares() << '\n';
}
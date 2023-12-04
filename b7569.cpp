#include <iostream>
#include <queue>

struct Coord {
	Coord(int initZ, int initY, int initX, int initDay)
		: z(initZ), y(initY), x(initX), day(initDay) {}
	int x, y, z, day;
};

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int boxes[101][101][101] = {0, };
	std::queue<Coord> queue;

	int dz[6] = {1, -1, 0, 0, 0, 0};
	int dy[6] = {0, 0, 1, -1, 0, 0};
	int dx[6] = {0, 0, 0, 0, 1, -1};

	int n, m, h;
	std::cin >> m >> n >> h;

	int tomatosLeft = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				std::cin >> boxes[i][j][k];
				if (boxes[i][j][k] == 1) {
					queue.push(Coord(i, j, k, 0));
				} else if (boxes[i][j][k] == 0) {
					tomatosLeft++;
				}
			}
		}
	}

	int maxDay = 0;

	while (!queue.empty()) {
		Coord curr = queue.front();	
		queue.pop();
		int newX, newY, newZ;
		int currDay = curr.day;
		if (currDay > maxDay) {
			maxDay = currDay;
		}
		for (int i = 0; i < 6; i++) {
			newZ = curr.z + dz[i];
			newY = curr.y + dy[i];
			newX = curr.x + dx[i];
			if (newZ < 0 || newY < 0 || newX < 0 || newZ >= h || newY >= n || newX >= m
				|| boxes[newZ][newY][newX] == -1 || boxes[newZ][newY][newX] == 1) {
				continue ;
			}
			boxes[newZ][newY][newX] = 1;
			tomatosLeft--;
			queue.push(Coord(newZ, newY, newX, currDay + 1));
		}
	}

	if (tomatosLeft != 0) {
		std::cout << "-1\n";
	} else {
		std::cout << maxDay << '\n';
	}

	return 0;
}
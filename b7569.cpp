#include <iostream>
#include <queue>

struct Coord {
	int z, y, x, day;
	Coord(int initZ, int initY, int initX, int initDay)
		: z(initZ), y(initY), x(initX), day(initDay) {}
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
				int& tomato = boxes[i][j][k];
				std::cin >> tomato;
				if (tomato == 1) {
					queue.push(Coord(i, j, k, 0));
					continue ;
				}
				if (tomato == 0) {
					tomatosLeft++;
				}
			}
		}
	}

	if (tomatosLeft == 0) {
		std::cout << "0\n";
		return 0;
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
			if (newZ < 0 || newZ >= h) {
				continue ;
			}
			newY = curr.y + dy[i];
			if (newY < 0 || newY >= n) {
				continue ;
			}
			newX = curr.x + dx[i];
			if (newX < 0 || newX >= m) {
				continue ;
			}
			int& tomato = boxes[newZ][newY][newX];
			if (tomato == -1 || tomato == 1) {
				continue ;
			}
			tomato = 1;
			tomatosLeft--;
			queue.push(Coord(newZ, newY, newX, currDay + 1));
		}
	}

	std::cout << (tomatosLeft == 0 ? maxDay : -1) << '\n';

	return 0;
}
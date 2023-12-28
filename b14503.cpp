#include <iostream>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int map[50][50];
int n, m;
pair<int, int> pos;
int dir;
int clearCount = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void readInput(void) {
	cin >> n >> m;
	cin >> pos.first >> pos.second >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void cleanCurrPos(void) {
	if (map[pos.first][pos.second] == 0) {
		map[pos.first][pos.second] = -1;
		clearCount++;
	}
}

bool isAllCleaned(void) {
	int x, y;
	for (int i = 0; i < 4; i++) {
		y = pos.first + dy[i];
		x = pos.second + dx[i];
		if (x >= 0 && x < m && y >= 0 && y < n && map[y][x] == 0) {
			return false;
		}
	}
	return true;
}

bool canMoveBackward(void) {
	if (dir == NORTH) {
		if (pos.first + 1 < n && map[pos.first + 1][pos.second] != 1) {
			return true;
		}
		return false;
	}
	if (dir == SOUTH) {
		if (pos.first - 1 >= 0 && map[pos.first - 1][pos.second] != 1) {
			return true;
		}
		return false;
	}
	if (dir == EAST) {
		if (pos.second - 1 >= 0 && map[pos.first][pos.second - 1] != 1) {
			return true;
		}
		return false;
	}
	// WEST
	if (pos.second + 1 < m && map[pos.first][pos.second + 1] != 1) {
		return true;
	}
	return false;
}

void moveBackward(void) {
	if (dir == NORTH) {
		pos.first++;
	} else if (dir == SOUTH) {
		pos.first--;
	} else if (dir == EAST) {
		pos.second--;
	} else if (dir == WEST) {
		pos.second++;
	}
}

void rotateCounterClockwise(void) {
	if (dir == 0) {
		dir = 3;
	} else {
		dir--;
	}
}

bool isForwardNotCleaned(void) {
	if (dir == SOUTH) {
		if (pos.first + 1 < n && map[pos.first + 1][pos.second] == 0) {
			return true;
		}
		return false;
	}
	if (dir == NORTH) {
		if (pos.first - 1 >= 0 && map[pos.first - 1][pos.second] == 0) {
			return true;
		}
		return false;
	}
	if (dir == EAST) {
		if (pos.second + 1 < m && map[pos.first][pos.second + 1] == 0) {
			return true;
		}
		return false;
	}
	// WEST
	if (pos.second - 1 >= 0 && map[pos.first][pos.second - 1] == 0) {
		return true;
	}
	return false;
}

void moveForward(void) {
	if (dir == NORTH) {
		pos.first--;
	} else if (dir == SOUTH) {
		pos.first++;
	} else if (dir == EAST) {
		pos.second++;
	} else if (dir == WEST) {
		pos.second--;
	}
}

int main() {
	readInput();

	while (true) {
		cleanCurrPos();
		if (isAllCleaned()) {
			if (!canMoveBackward()) {
				break ;
			}
			moveBackward();
		} else {
			rotateCounterClockwise();
			if (isForwardNotCleaned()) {
				moveForward();
			}
		}
	}

	cout << clearCount << '\n';

	return 0;
}
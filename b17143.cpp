#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

struct Shark {
	int x, y, s, d, z;
	int dummy;
};

void initBoard(Shark board[100][100], int r, int c) {
	for (int i = 0; i < r; i++) {
		memset(board[i], 0, sizeof(Shark) * c);
	}
}

void initSharks(Shark board[100][100], int m) {
	int y, x, s, d, z;

	for (int i = 0; i < m; i++) {
		cin >> y >> x >> s >> d >> z;
		Shark& temp = board[y - 1][x - 1];
		temp.s = s;
		temp.d = d;
		temp.z = z;
	}
}

void initGrid(Shark& shark) {
	shark.s = 0;
	shark.d = 0;
	shark.z = 0;
}

int catchShark(Shark board[100][100], int x, int r) {
	int i = 0;
	int res;

	while (i < r && board[i][x].z == 0) {
		i++;
	}
	if (i == r) {
		return 0;
	}
	res = board[i][x].z;
	initGrid(board[i][x]);

	return res;
}

void moveSharks(Shark board[100][100], int r, int c) {
	int toGo, currY, currX;
	queue<Shark> toMove;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			Shark& currShark = board[i][j];
			if (currShark.z > 0 && currShark.s > 0) {
				toGo = currShark.s;
				currY = i;
				currX = j;
				while (toGo > 0) {
					switch (currShark.d) {
						case UP :
							if (toGo > currY) {
								toGo -= currY;
								currY = 0;
								currShark.d = DOWN;
							} else {
								currY -= toGo;
								toGo = 0;
							}
							break ;
						case DOWN :
							if (currY + toGo >= r) {
								toGo -= (r - currY - 1);
								currY = r - 1;
								currShark.d = UP;
							} else {
								currY += toGo;
								toGo = 0;
							}
							break ;
						case LEFT :
							if (toGo > currX) {
								toGo -= currX;
								currX = 0;
								currShark.d = RIGHT;
							} else {
								currX -= toGo;
								toGo = 0;
							}
							break ;
						case RIGHT :
							if (currX + toGo >= c) {
								toGo -= (c - currX - 1);
								currX = c - 1;
								currShark.d = LEFT;
							} else {
								currX += toGo;
								toGo = 0;
							}
							break ;
					}
				}
				if (currY == i && currX == j) {
					continue ;
				}
				currShark.y = currY;
				currShark.x = currX;
				toMove.push(currShark);
				initGrid(currShark);
			}
		}
	}
	while (!toMove.empty()) {
		Shark& temp = toMove.front();
		if (temp.z > board[temp.y][temp.x].z) {
			board[temp.y][temp.x] = temp;
		}
		toMove.pop();
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int r, c, m;

	cin >> r >> c >> m;

	Shark board[100][100];

	initBoard(board, r, c);
	initSharks(board, m);

	int sharkSizeSum = 0;

	for (int i = 0; i < c; i++) {
		sharkSizeSum += catchShark(board, i, r);	
		moveSharks(board, r, c);
	}

	cout << sharkSizeSum << '\n';
}
#include <iostream>
#include <vector>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int initialBoard[20][20];
int n;
vector<int> instructions;
int instruction[4] = {UP, DOWN, LEFT, RIGHT};
int maxVal = 0;

void printBoard(int board[20][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void moveLineUp(int board[20][20], int x) {
	int y = 0;
	int zeroPos;
	while (true) {
		while (y < n && board[y][x] != 0) {
			y++;
		}
		zeroPos = y;
		while (y < n && board[y][x] == 0) {
			y++;
		}
		if (y == n) {
			break ;
		}
		board[zeroPos][x] = board[y][x];
		board[y][x] = 0;
		y = zeroPos + 1;
	}
}

void moveLineDown(int board[20][20], int x) {
	int y = n - 1;
	int zeroPos;
	while (true) {
		while (y >= 0 && board[y][x] != 0) {
			y--;
		}
		zeroPos = y;
		while (y >= 0 && board[y][x] == 0) {
			y--;
		}
		if (y == -1) {
			break ;
		}
		board[zeroPos][x] = board[y][x];
		board[y][x] = 0;
		y = zeroPos - 1;
	}
}

void moveLineLeft(int board[20][20], int y) {
	int x = 0;
	int zeroPos;
	while (true) {
		while (x < n && board[y][x] != 0) {
			x++;
		}
		zeroPos = x;
		while (x < n && board[y][x] == 0) {
			x++;
		}
		if (x == n) {
			break ;
		}
		board[y][zeroPos] = board[y][x];
		board[y][x] = 0;
		x = zeroPos + 1;
	}
}

void moveLineRight(int board[20][20], int y) {
	int x = n - 1;
	int zeroPos;
	while (true) {
		while (x >= 0 && board[y][x] != 0) {
			x--;
		}
		zeroPos = x;
		while (x >= 0 && board[y][x] == 0) {
			x--;
		}
		if (x == -1) {
			break ;
		}
		board[y][zeroPos] = board[y][x];
		board[y][x] = 0;
		x = zeroPos - 1;
	}
}

void moveBlocks(void) {
	int board[20][20];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = initialBoard[i][j];		
		}
	}

	for (int i = 0; i < 5; i++) {
		switch (instructions[i]) {
			case UP :
				for (int x = 0; x < n; x++) {
					moveLineUp(board, x);
					for (int y = 0; y < n - 1; y++)  {
						if (board[y][x] == board[y + 1][x]) {
							board[y][x] *= 2;
							board[y + 1][x] = 0;
						}
					}
					moveLineUp(board, x);
				}
				break ;
			case DOWN :
				for (int x = 0; x < n; x++) {
					moveLineDown(board, x);
					for (int y = n - 1; y > 0; y--)  {
						if (board[y][x] == board[y - 1][x]) {
							board[y][x] *= 2;
							board[y - 1][x] = 0;
						}
					}
					moveLineDown(board, x);
				}
				break ;
			case LEFT :
				for (int y = 0; y < n; y++) {
					moveLineLeft(board, y);
					for (int x = 0; x < n - 1; x++) {
						if (board[y][x] == board[y][x + 1]) {
							board[y][x] *= 2;
							board[y][x + 1] = 0;
						}
					}
					moveLineLeft(board, y);
				}
				break ;
			case RIGHT :
				for (int y = 0; y < n; y++) {
					moveLineRight(board, y);
					for (int x = n - 1; x > 0; x--) {
						if (board[y][x] == board[y][x - 1]) {
							board[y][x] *= 2;
							board[y][x - 1] = 0;
						}
					}
					moveLineRight(board, y);
				}
				break ;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > maxVal) {
				maxVal = board[i][j];
			}
		}
	}
}

void dfs(int count) {
	if (count == 5) {
		moveBlocks();
		return ;
	}
	for (int i = 0; i < 4; i++) {
		instructions.push_back(instruction[i]);
		dfs(count + 1);
		instructions.pop_back();
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> initialBoard[i][j];
		}
	}

	dfs(0);

	cout << maxVal << '\n';
}
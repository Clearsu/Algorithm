#include <iostream>
#include <deque>
#include <utility>

using namespace std;

#define EMPTY 0
#define APPLE 1
#define BODY 2
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int board[101][101];
int dir = RIGHT;
deque<pair<int, int> > snakeBodyPos;
int n, t = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void initBoard(void) {
		int k;
		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
						board[i][j] = EMPTY;
				}
		}

		board[1][1] = BODY;
		snakeBodyPos.push_front(pair<int, int>(1, 1));

		int applePosX, applePosY;
		for (int i = 0; i < k; i++) {
				cin >> applePosY >> applePosX;
				board[applePosY][applePosX] = APPLE;
		}
}

void changeHeadDirection(char dirChange) {
		if (dirChange == 'L') {
				if (dir == UP) {
						dir = LEFT;
				} else {
						dir--;
				}
		} else {
				if (dir == LEFT) {
						dir = UP;
				} else {
						dir++;
				}
		}
}

bool move(void) {
		int nextX, nextY;

		const pair<int, int>& head = snakeBodyPos.front();
		nextX = head.second + dx[dir];
		nextY = head.first + dy[dir];


		if (nextX < 1 || nextX > n || nextY < 1 || nextY > n
						|| board[nextY][nextX] == BODY) {
				return false;
		}
		snakeBodyPos.push_front(pair<int, int>(nextY, nextX));
		if (board[nextY][nextX] == EMPTY) {
				const pair<int, int>& tail = snakeBodyPos.back();
				board[tail.first][tail.second] = EMPTY;
				snakeBodyPos.pop_back();
		}
		board[nextY][nextX] = BODY;
		return true;
}

void printBoard(void) {
		for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
						cout << board[i][j] << ' ';
				}
				cout << '\n';
		}
		cout << '\n';
}

void simulate(void) {
		int moveReps, sec, prevSec = 0;
		char dirChange;

		cin >> moveReps;
		for (int i = 0; i < moveReps; i++) {
				cin >> sec >> dirChange;
				sec -= prevSec;
				prevSec += sec;
				while (sec-- > 0) {
						t++;
						if (!move()) {
								return ;
						}
				}
				changeHeadDirection(dirChange);
		}
		while (move()) {
				t++;
		};
		t++;
}

int main(void) {
		cin.tie(0);
		ios_base::sync_with_stdio(0);

		initBoard();
		simulate();

		cout << t << '\n';

		return 0;
}
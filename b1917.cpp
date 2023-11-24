#include <iostream>
#include <queue>
#include <utility>

// sides of dice
#define BOTTOM 0
#define TOP 1
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define BACK 5

void rollDown(std::vector<int>& dice) {
	int temp = dice[BOTTOM];
	dice[BOTTOM] = dice[FRONT];
	dice[FRONT] = dice[TOP];
	dice[TOP] = dice[BACK];
	dice[BACK] = temp;
}

void rollRight(std::vector<int>& dice) {
	int temp = dice[BOTTOM];
	dice[BOTTOM] = dice[RIGHT];
	dice[RIGHT] = dice[TOP];
	dice[TOP] = dice[LEFT];
	dice[LEFT] = temp;
}

void rollLeft(std::vector<int>& dice) {
	int temp = dice[BOTTOM];
	dice[BOTTOM] = dice[LEFT];
	dice[LEFT] = dice[TOP];
	dice[TOP] = dice[RIGHT];
	dice[RIGHT] = temp;
}

void rollUp(std::vector<int>& dice) {
	int temp = dice[BOTTOM];
	dice[BOTTOM] = dice[BACK];
	dice[BACK] = dice[TOP];
	dice[TOP] = dice[FRONT];
	dice[FRONT] = temp;
}

struct DiceInfo {
	DiceInfo(const std::vector<int>& initDice, int initY, int initX)
		: dice(initDice), y(initY), x(initX) {}
	std::vector<int> dice;
	int y;
	int x;
};

void findFirstOne(int arr[6][6], int& i, int& j) {
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (arr[i][j] == 1) {
				return ;
			}
		}
	}
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void bfs(int arr[6][6]) {
	bool visited[6] = { false, };

	std::vector<int> initialDice;
	for (int i = 0; i < 6; i++) {
		initialDice.push_back(i);
	}
	
	int y = 0, x = 0;
	findFirstOne(arr, y, x);
	arr[y][x] = 0;

	std::queue<DiceInfo> queue;
	queue.push(DiceInfo(initialDice, y, x));

	while (!queue.empty()) {
		const DiceInfo& diceInfo = queue.front();
		std::vector<int> dice = diceInfo.dice;
		int currY = diceInfo.y;
		int currX = diceInfo.x;
		queue.pop();
		visited[dice[BOTTOM]] = true;
		for (int i = 0; i < 4; i++) {
			int togoY = currY + dy[i];
			int togoX = currX + dx[i];
			if (togoY < 0 || togoY >= 6 || togoX < 0 || togoX >= 6) {
				continue ;
			}
			if (arr[togoY][togoX] == 1) {
				arr[togoY][togoX] = 0;
				std::vector<int> rolledDice = dice;
				if (dy[i] == 1) {
					rollDown(rolledDice);
				} else if (dy[i] == -1) {
					rollUp(rolledDice);
				} else if (dx[i] == 1) {
					rollRight(rolledDice);
				} else if (dx[i] == -1) {
					rollLeft(rolledDice);
				}
				queue.push(DiceInfo(rolledDice, togoY, togoX));
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		if (visited[i] == false) {
			std::cout << "no\n";
			return;
		}
	}
	std::cout << "yes\n";
}

int main() {
	int cases[3][6][6];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				std::cin >> cases[i][j][k];
			}
			std::cin.ignore();
		}
	}
	for (int i = 0; i < 3; i++) {
		bfs(cases[i]);
	}
}
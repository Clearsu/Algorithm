#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int> > blankVec;

void initBoard(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				blankVec.push_back(pair<int, int>(i, j));
			}
		}
	}
}

void putCommonMissingNumber(int y, int x, vector<int>& nums) {
	bool missingNums[9];

	for (int i = 0; i < 9; i++) {
		missingNums[i] = true;
	}

	for (int i = 0; i < 9; i++) {
		if (board[y][i] != 0) {
			missingNums[board[y][i] - 1] = false;
		}
		if (board[i][x] != 0) {
			missingNums[board[i][x] - 1] = false;
		}
	}
	for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++) {
		for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
			if (board[i][j] != 0) {
				missingNums[board[i][j] - 1] = false;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (missingNums[i] == true) {
			nums.push_back(i + 1);
		}
	}
}

void printBoard(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int stopFlag = false;

void dfs(int blankIdx) {
	if (stopFlag) {
		return ;
	}
	if (blankIdx == blankVec.size()) {
		printBoard();
		stopFlag = true;
		return ;
	}
	const pair<int, int>& blank = blankVec[blankIdx];
	vector<int> nums;
	putCommonMissingNumber(blank.first, blank.second, nums);

	int size = nums.size();
	for(int i = 0; i < size; i++) {
		board[blank.first][blank.second] = nums[i];
		dfs(blankIdx + 1);
	}
	board[blank.first][blank.second] = 0;
}

int main() {
	initBoard();
	dfs(0);
}
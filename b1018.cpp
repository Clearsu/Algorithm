#include <iostream>

int main() {
	int n, m;
	char board[50][50];

	std::cin >> n >> m;
	std::cin.ignore();

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> c;
			board[i][j] = c;
		}
		std::cin.ignore();
	}

	int min = 50 * 50 / 2;
	int resWb, resBw;

	char bw[8][8];
	char wb[8][8];

	char first, second;

	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			first = 'B';
			second = 'W';
		} else {
			first = 'W';
			second = 'B';
		}
		for (int j = 0; j < 8; j++) {
			bw[i][j] = j % 2 == 0 ? first : second;
			wb[i][j] = j % 2 == 1 ? first : second;
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			resWb = 0;
			resBw = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (board[k][l] != bw[k - i][l - j]) {
						resBw++;
					}
					if (board[k][l] != wb[k - i][l - j]) {
						resWb++;
					}
				}
			}
			if (resBw < min) {
				min = resBw;
			}
			if (resWb < min) {
				min = resWb;
			}
		}
	}

	std::cout << min << '\n';
}
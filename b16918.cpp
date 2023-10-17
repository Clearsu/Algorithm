#include <iostream>
#include <vector>
#include <utility>

void	printBoard(char board[200][200], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cout << board[i][j];
		}
		std::cout << '\n';
	}
}

void	getBombCoordinates(std::vector<std::pair<int, int> > &bomb,
							 char board[200][200], int r, int c)
{
	std::pair<int, int> temp;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'O') {
				temp.first = i;
				temp.second = j;
				bomb.push_back(temp);
			}
		}
	}
}

void	explodeBomb(std::vector<std::pair<int, int> > &bomb,
						 char board[200][200], int r, int c)
{
	std::vector<std::pair<int, int> >::iterator it = bomb.begin();
	std::vector<std::pair<int, int> >::iterator end = bomb.end();

	while (it != end) {
		int i = (*it).first;
		int j = (*it).second;
		board[i][j] = '.';
		if (i > 0) {
			board[i - 1][j] = '.';
		}
		if (i < r - 1) {
			board[i + 1][j] = '.';
		}
		if (j > 0) {
			board[i][j - 1] = '.';
		}
		if (j < c - 1) {
			board[i][j + 1] = '.';
		}
		++it;
	}
}

void	setBomb(char board[200][200], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] = 'O';
		}
	}
}

int main(void) {
	int r, c, n;		
	char board[200][200];

	std::cin >> r >> c >> n;
	std::cin.ignore();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> board[i][j];
		}
		std::cin.ignore();
	}	

	if (n == 1) {
		printBoard(board, r, c);
		return 0;
	}

	if (n % 2 == 0) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				std::cout << 'O';
			}
			std::cout << '\n';
		}
		return 0;
	}

	std::vector<std::pair<int, int> > bombA;
	std::vector<std::pair<int, int> > bombB;

	for (int i = 2; i <= 5; i++) {
		if (i % 2 == 0) {
			setBomb(board, r, c);
		} else if (i % 4 == 1) {
			explodeBomb(bombB, board, r, c);
			if (n % 4 == 1) {
				break ;
			}
			bombB.clear();
			getBombCoordinates(bombA, board, r, c);
		} else if (i % 4 == 3) {
			explodeBomb(bombA, board, r, c);
			if (n % 4 == 3) {
				break ;
			}
			bombA.clear();
			getBombCoordinates(bombB, board, r, c);
		}
	}

	printBoard(board, r, c);
	
	return 0;
}
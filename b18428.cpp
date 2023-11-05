#include <iostream>
#include <utility>
#include <vector>

int n;
char space[6][6];
std::vector<std::pair<int, int> >teachers;
int isYes = false;

int getStudentsExposed() {
	std::vector<std::pair<int, int> >::const_iterator it = teachers.begin();
	std::vector<std::pair<int, int> >::const_iterator end = teachers.end();

	int res = 0;
	while (it != end) {
		const int& row = (*it).first;
		const int& col = (*it).second;
		for (int x = col; x >= 0; x--) {
			if (space[row][x] == 'O') {
				break ;
			}
			if (space[row][x] == 'S') {
				res++;
				break ;
			}
		}
		for (int x = col; x < n; x++) {
			if (space[row][x] == 'O') {
				break ;
			}
			if (space[row][x] == 'S') {
				res++;
				break ;
			}
		}
		for (int y = row; y >= 0; y--) {
			if (space[y][col] == 'O') {
				break ;
			}
			if (space[y][col] == 'S') {
				res++;
				break ;
			}
		}
		for (int y = row; y < n; y++) {
			if (space[y][col] == 'O') {
				break ;
			}
			if (space[y][col] == 'S') {
				res++;
				break ;
			}
		}
		++it;
	}

	return res;
}

void dfs(int currObs, int prevStudentsExposed) {
	if (prevStudentsExposed == 0) {
		isYes = true;
		return ;
	}
	if (isYes || currObs == 3) {
		return ;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (space[i][j] == 'X') {
				space[i][j] = 'O';
				int currStudentsExposed = getStudentsExposed();
				if (currStudentsExposed < prevStudentsExposed) {
					dfs(currObs + 1, currStudentsExposed);
				}
				space[i][j] = 'X';
			}
		}
	}
}

int main() {
	std::cin >> n;
	std::cin.ignore();

	std::pair<int, int> temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> space[i][j];
			if (space[i][j] == 'T') {
				temp.first = i;
				temp.second = j;
				teachers.push_back(temp);
			}
		}
		std::cin.ignore();
	}


	dfs(0, getStudentsExposed());

	std::cout << (isYes ? "YES" : "NO") << '\n';

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

char map[1000][1000];
int dist[1000][1000];
int t = 0;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init(queue<pair<int, int> >& fire, queue<pair<int, int> >& pos,
			int col, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char& temp = map[i][j];
			cin >> temp;
			if (temp == '*') {
				fire.push(pair<int, int>(i, j));
			} else if (temp == '@') {
				pos.push(pair<int, int>(i, j));
				temp = '.';
			}
			dist[i][j] = 0;
		}
	}
}

void moveSanggueon(queue<pair<int, int> >& pos, int col, int row) {
	int size = pos.size();
	int currX, currY, nextX, nextY;

	while (size-- > 0) {
		currY = pos.front().first;
		currX = pos.front().second;
		pos.pop();
		for (int i = 0; i < 4; i++) {
			nextY = currY + dy[i];
			nextX = currX + dx[i];
			if (map[currY][currX] == '.'
				&& (nextY >= row || nextY < 0 || nextX >= col || nextX < 0)) {
				t = dist[currY][currX] + 1;		
				return ;
			}
			if (map[nextY][nextX] == '.' && dist[nextY][nextX] == 0 && map[nextY][nextX] != '@') {
				dist[nextY][nextX] = dist[currY][currX] + 1;
				pos.push(pair<int, int>(nextY, nextX));
			}
		}
	}
}

void expandFire(queue<pair<int, int> >& fire, int col, int row) {
	int size = fire.size();
	int currY, currX, nextY, nextX;

	while (size-- > 0) {
		currY = fire.front().first;
		currX = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			nextY = currY + dy[i];
			nextX = currX + dx[i];
			if (nextY >= row || nextY < 0 || nextX >= col || nextX < 0
				|| map[nextY][nextX] == '#' || map[nextY][nextX] == '*') {
				continue ;
			}
			map[nextY][nextX] = '*';
			fire.push(pair<int, int>(nextY, nextX));
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	int col, row;
	for (int i = 0; i < n; i++) {
		cin >> col >> row;
		queue<pair<int, int> > fire;
		queue<pair<int, int> > pos;
		init(fire, pos, col, row);
		while (true) {
			moveSanggueon(pos, col, row);
			if (t > 0) {
				cout << t << '\n';
				t = 0;
				break ;
			}
			if (pos.empty()) {
				cout << "IMPOSSIBLE\n";
				break ;
			}
			expandFire(fire, col, row);
		}
	}
}
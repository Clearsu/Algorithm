#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class Solution {
public:
		void bfs(vector<vector<char>>& grid, int startY, int startX, int col, int row) {
      queue<pair<int, int> > q;
			int currY, currX, nextY, nextX;

			q.push(pair<int, int>(startY, startX));
			grid[startY][startX] = '0';

			while (!q.empty()) {
				pair<int, int>& curr = q.front();
				currY = curr.first;
				currX = curr.second;
				for (int i = 0; i < 4; i++) {
					nextY = currY + dy[i];
					nextX = currX + dx[i];
					if (nextY >= 0 && nextY < col && nextX >= 0 && nextX < row 
						&& grid[nextY][nextX] == '1') {
						grid[nextY][nextX] = '0';
						q.push(pair<int, int>(nextY, nextX));
					}
				}
				q.pop();
			}
		}

    int numIslands(vector<vector<char>>& grid) {
			int col, row;
			int count = 0;

			col = grid.size();
			row = grid[0].size();

			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
					if (grid[i][j] == '1') {
						count++;
						bfs(grid, i, j, col, row);
					}
				}
			}

			return count;
    }
};

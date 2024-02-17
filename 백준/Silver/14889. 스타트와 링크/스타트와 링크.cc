#include <iostream>

using namespace std;

int n;
int stat[20][20];
int minValue = 2147483647;
bool visited[20] = { false, };

int calculateDiff(void) {
	int teamStart = 0;
	int teamLink = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && visited[i] == visited[j]) {
				if (visited[i] == true) {
					teamStart += stat[i][j];
				} else {
					teamLink += stat[i][j];
				}
			}
		}
	}
  
  return abs(teamStart - teamLink);
}

void dfs(int currIndex, int playerCount) {
	if (playerCount == n / 2) {
		int diff = calculateDiff();
    if (diff < minValue) {
      minValue = diff;
    }
	}
	for (int i = currIndex; i < n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			dfs(i + 1, playerCount + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> stat[i][j];
		}
	}

	dfs(0, 0);

  cout << minValue << '\n';
	
	return 0;
}
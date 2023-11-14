#include <iostream>
#include <vector>

int n, m;
bool visited[9] = {};

void dfs(int curr, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == true) {
				std::cout << i << ' ';
			}
		}
		std::cout << '\n';
		return ;
	}
	for (int i = curr + 1; i <= n; i++) {
		visited[i] = true;
		dfs(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	std::cin >> n >> m;
	dfs(0, 0);
	return 0;
}
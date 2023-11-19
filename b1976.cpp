#include <iostream>

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int n, m;
	char graph[201][201];
	int plan[1001];

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> plan[i];
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((graph[k][i] == '1' && graph[k][j] == '1')) {
					graph[i][j] = '1';
					graph[j][i] = '1';
				}
			}
		}
	}

	for (int i = 1; i < m; i++) {
		if (plan[i] != plan[i + 1] && graph[plan[i]][plan[i + 1]] == '0') {
			std::cout << "NO\n";
			return 0;
		}
	}

	std::cout << "YES\n";

	return 0;
}
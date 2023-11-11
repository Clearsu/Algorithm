#include <iostream>
#include <cstring>

int main() {
	int n;
	bool graph[101][101];

	for (int i = 0; i < 101; i++) {
		std::memset(graph[i], false, sizeof(graph[i]));
		graph[i][i] = true;
	}

	std::cin >> n;
	std::cin.ignore();
	int a, b;
	for (int i = 1; i < n; i++) {
		std::cin >> a >> b;
		graph[a][b] = true;
		std::cin.ignore();
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] == true && graph[k][j] == true) {
					graph[i][j] = true;
				}
			}
		}
	}

	int res = -1;

	for (int i = 1; i <= n; i++) {
		int j = 1;
		while (j <= n && graph[j][i] == true) {
			j++;
		}
		if (j == n + 1) {
			res = i;
			break ;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << graph[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	std::cout << res << '\n';

	return 0;
}
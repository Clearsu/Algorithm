#include <iostream>
#include <vector>
#include <string>

int main() {
	int n;

	std::cin >> n;
	std::cin.ignore();
	std::vector<std::string> arr;
	std::string temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		arr.push_back(temp);
		std::cin.ignore();
	}

	int len = arr[0].length();
	std::string res = arr[0];
	char c;
	for (int i = 0; i < len; i++) {
		c = arr[0][i];
		for (int j = 1; j < n; j++) {
			if (arr[j][i] != c) {
				res[i] = '?';
				break ;
			}
		}
	}

	std::cout << res << '\n';
}
#include <iostream>
#include <deque>
#include <utility>

int main() {
	int n;

	std::cin >> n;
	std::cin.ignore();

	std::deque<std::pair<int, int> > deque;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		deque.push_back(std::pair<int, int>(i, temp));
	}
	std::cin.ignore();

	int time[1000] = {0, };
	int currTime = 0;

	while (!deque.empty()) {
		--deque[0].second;
		time[deque[0].first] = ++currTime;
		if (deque[0].second > 0) {
			deque.push_back(deque[0]);
		}
		deque.pop_front();
	}

	for (int i = 0; i < n; i++) {
		std::cout << time[i] << ' ';
	}
	std::cout << '\n';
}
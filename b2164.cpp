#include <iostream>
#include <deque>

int main() {
	int n;

	std::cin >> n;

	if (n == 1) {
		std::cout << "1\n";
		return 0;
	}

	std::deque<int> cards(n);

	for (int i = 0; i < n; i++) {
		cards[i] = i + 1;
	}

	while (cards.size() > 1) {
		cards.pop_front();
		cards.push_back(cards.front());
		cards.pop_front();
	}

	std::cout << cards.front() << '\n';

	return 0;
}
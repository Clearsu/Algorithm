#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		cout << vec[i] << '\n';
	}
}
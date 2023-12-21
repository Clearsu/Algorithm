#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

bool compare(const string& a, const string& b) {
	if (a.length() < b.length()
		|| (a.length() == b.length() && strcmp(a.c_str(), b.c_str()) < 0)) {
		return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<string> vec;

	map<string, bool> check;

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (check[temp]) {
			continue ;
		}
		check[temp] = true;
		vec.push_back(temp);
		temp.clear();
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}

	return 0;
}
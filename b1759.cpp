#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int l, c;
bool visit[15] = {false, };
vector<string> vec;

void bruteForce(const string& str, string temp) {
	if (temp.size() == l) {
		int vowelCount = 0;
		int consonantCount = 0;
		for (int i = 0; i < l; i++) {
			if (temp[i] == 'a' || temp[i] == 'i'
				|| temp[i] == 'e' || temp[i] == 'o' || temp[i] == 'u') {
				vowelCount++;
			} else {
				consonantCount++;
			}
		}
		if (vowelCount >= 1 && consonantCount >= 2) {
			vec.push_back(temp);
		}
		return ;
	}
	for (int i = 0; i < c; i++) {
		if (visit[i] == false && (temp.size() == 0 || *(temp.end() - 1) < str[i])) {
			visit[i] = true;
			bruteForce(str, temp + str[i]);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> l >> c;

	string str;
	char temp;

	for (int i = 0; i < c; i++) {
		cin >> temp;
		str += temp;
	}

	bruteForce(str, "");
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}

	return 0;
}
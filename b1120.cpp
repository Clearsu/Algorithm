#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;

	cin >> a >> b;

	int minDiff = 50;

	for (int i = 0; i <= b.length() - a.length(); i++) {
		int j = i;
		int k = 0; 
		int diffCount = 0;
		while (k < a.length() && j < b.length()) {
			if (a[k] != b[j]) {
				diffCount++;
			}
			k++;
			j++;
		}
		if (diffCount < minDiff) {
			minDiff = diffCount;
		}
	}

	cout << minDiff << '\n';
	
	return 0;
}
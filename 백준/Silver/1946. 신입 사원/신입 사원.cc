#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> scores[100000];

void readScores(int n) {
	for (int i = 0; i < n; i++) {
		pair<int, int>& score = scores[i];
		cin >> score.first;
		cin >> score.second;
	}
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
	int t, n, res;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		readScores(n);
		sort(scores, scores + n);
		// cout << "--- scores sorted ---\n";
		// for (int j = 0; j < n; j++) {
		// 	cout << scores[j].first << ' ' << scores[j].second << '\n';
		// }
		// cout << "---------------------\n";
		res = 1;
		int lastPickedInterviewScore = scores[0].second;
		for (int j = 1; j < n; j++) {
			if (scores[j].second < lastPickedInterviewScore) {
				lastPickedInterviewScore = scores[j].second;
				res++;
			}
		}
		cout << res << '\n';
	}
}
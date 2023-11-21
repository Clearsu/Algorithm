#include <iostream>
#include <deque>
#include <utility>
#include <cmath>
#include <algorithm>
#include <limits>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	long long l, n;
	std::pair<long long, char> moveInfo[1001];
	std::deque<std::pair<std::pair<long long, long long>, long long> > colLines; // {fromY, toY}, X == same
	std::deque<std::pair<std::pair<long long, long long>, long long> > rowLines; // {fromX, toX}, Y == same
	long long dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	long long dirIdx = RIGHT;

	std::cin >> l >> n;
	for (long long i = 0; i < n; i++) {
		std::cin >> moveInfo[i].first >> moveInfo[i].second;
	}

	long long border = l * 2 + 1;
	unsigned long long time = 0;
	std::pair<long long, long long> currPos(l, l);
	std::vector<long long> collisionTime;

	long long i = 0;
	while (true) {
		const long long & moveDist = i < n ? moveInfo[i].first : std::numeric_limits<int>::max(); // 회전 모두 했을 경우 맵 벗어날때까지 움직일 수 있도록
		long long toX, toY;
		if (dirIdx == LEFT || dirIdx == RIGHT) { // 가로 방향으로 이동 시
			toX = currPos.first + dir[dirIdx][0] * moveDist;
			if (colLines.size() > 1) {
				for (long long i = colLines.size() - 2; i >= 0; i--) { // 세로 몸통에 부딪히는지 확인
					long long smallY, bigY, commonX;
					smallY = colLines[i].first.first;
					bigY = colLines[i].first.second;
					commonX = colLines[i].second;
					if (commonX >= l && currPos.second == l 
						&& dirIdx == RIGHT && currPos.first < l && toX >= l) { // 꼬리에 부딪힘
						// std::cout << "here\n";
						collisionTime.push_back(time + l - currPos.first);
					}
					if (currPos.second >= smallY && currPos.second <= bigY) {
						if (dirIdx == RIGHT && commonX >= currPos.first && commonX <= toX) {
							collisionTime.push_back(time + commonX - currPos.first);
						} else if (dirIdx == LEFT && commonX <= currPos.first && commonX >= toX) {
							collisionTime.push_back(time + currPos.first - commonX);
						}
					}
				}
			}

			// 벽에 부딪히는 경우
			if (toX < 0) {
				collisionTime.push_back(time + currPos.first + 1);
			} else if (toX >= border) {
				collisionTime.push_back(time + border - currPos.first);
			}

			long long temp1 = currPos.first, temp2 = toX;
			if (temp1 > temp2) { // 작은 값, 큰 값 순으로 들어가도록
				std::swap(temp1, temp2);
			}
			rowLines.push_back(std::pair<std::pair<long long, long long>, long long>(std::pair<long long, long long>(temp1, temp2)
										, currPos.second));
			currPos.first = toX;
		} else if (dirIdx == UP || dirIdx == DOWN) {
			toY = currPos.second + dir[dirIdx][1] * moveDist;

			if (rowLines.size() > 1) {
				for (long long i = rowLines.size() - 2; i >= 0; i--) { // 가로 몸통에 부딪히는지 최근 경로부터 확인
					long long smallX, bigX, commonY;
					smallX = rowLines[i].first.first;
					bigX = rowLines[i].first.second;
					commonY = rowLines[i].second;
					if (currPos.first >= smallX && currPos.first <= bigX) {
						if (dirIdx == DOWN && commonY >= currPos.second && commonY <= toY) {
							collisionTime.push_back(time + commonY - currPos.second);
						} else if (dirIdx == UP && commonY <= currPos.second && commonY >= toY) {
							collisionTime.push_back(time + currPos.second - commonY);
						}
					}
				}
			}

			if (toY < 0) {
				collisionTime.push_back(time + currPos.second + 1);
			}
			if (toY >= border) {
				collisionTime.push_back(time + border - currPos.second);
			}

			long long temp1 = currPos.second, temp2 = toY;
			if (temp1 > temp2) {
				std::swap(temp1, temp2);
			}
			colLines.push_back(std::pair<std::pair<long long, long long>, long long>(std::pair<long long, long long>(temp1, temp2), currPos.first));
			currPos.second = toY;
		}

		if (!collisionTime.empty()) {
			std::sort(collisionTime.begin(), collisionTime.end());
			std::cout << collisionTime[0] << '\n';
			return 0;
		}

		time += moveDist;
		if (i < n) {
			if (moveInfo[i].second == 'L') {
				dirIdx = dirIdx == 0 ? 3 : dirIdx - 1;
			} else {
				dirIdx = dirIdx == 3 ? 0 : dirIdx + 1;
			}
		}
		i++;
	}
}
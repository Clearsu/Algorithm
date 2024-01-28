#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int map[100][100];
int dist[100][100];
vector<pair<int, int> > toCheck;
const short dx[4] = {0, 0, 1, -1};
const short dy[4] = {1, -1, 0, 0};

struct DistInfo {
  int y, x, dist;
};

void fillContinent(int startY, int startX, int val, int n) {
  queue<pair<int, int> > queue;
  
  map[startY][startX] = val;
  queue.push(pair<int, int>(startY, startX));

  int currY, currX, nextY, nextX;
  while (!queue.empty()) {
    currY = queue.front().first;
    currX = queue.front().second;
    queue.pop();
    for (int i = 0; i < 4; i++) {
      nextY = currY + dy[i];
      nextX = currX + dx[i];
      if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0
        || map[nextY][nextX] != 1) {
        continue ;
      }
      map[nextY][nextX] = val;
      queue.push(pair<int, int>(nextY, nextX));
    }
  }
}

void initMap(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  int val = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1) {
        fillContinent(i, j, val++, n);
      }
    }
  }
}

void pushLocationsToCheck(int n) {
  int toCheckY, toCheckX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 0) {
        continue ;
      }
      for (int k = 0; k < 4; k++) {
        toCheckY = i + dy[k];
        toCheckX = j + dx[k];
        if (toCheckY < 0 || toCheckY >= n || toCheckX < 0 || toCheckY >= n) {
          continue ;
        }
        if (map[toCheckY][toCheckX] == 0) {
          toCheck.push_back(pair<int, int>(i, j));
          break ;
        }
      }
    }
  }
}

void initDist(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = 0;
    }
  }
}

int getBridgeLength(int startY, int startX, int n) {
  queue<pair<int, int> > queue;
  int startVal = map[startY][startX];
  queue.push(pair<int, int>(startY, startX));

  initDist(n);

  int currY, currX, nextY, nextX;
  while (!queue.empty()) {
    currY = queue.front().first;
    currX = queue.front().second;
    queue.pop();
    
    for (int i = 0; i < 4; i++) {
      nextY = currY + dy[i];
      nextX = currX + dx[i];
      if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n
      || dist[nextY][nextX] != 0 || map[nextY][nextX] == startVal) {
        continue ;
      }
      if (map[nextY][nextX] == 0) {
        queue.push(pair<int, int>(nextY, nextX));
        dist[nextY][nextX] = dist[currY][currX] + 1;
      } else if (map[nextY][nextX] != startVal) {
        return dist[currY][currX];
      }
    }
  }
  return 2147483647;
}

int getMinBridgeLength(int n) {
  int tempDist, minDist = 2147483647;
  queue<pair<int, int> > queue;

  for (int i = 0; i < toCheck.size(); i++) {
    tempDist = getBridgeLength(toCheck[i].first, toCheck[i].second, n);
    if (tempDist < minDist) {
      minDist = tempDist;
    }
  }
  
  return minDist;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  initMap(n);
  pushLocationsToCheck(n);
  cout << getMinBridgeLength(n) << '\n';

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
int n, m;
bool visit[1001] = {false, };

void bfs(int start) {
    queue<int> queue;
    queue.push(start);
    visit[start] = true;

    int curr, next, size;
    while (!queue.empty()) {
        curr = queue.front();
        queue.pop();
        size = graph[curr].size();
        for (int i = 0; i < size; i++) {
            next = graph[curr][i];
            if (visit[next] == false) {
                queue.push(next);
                visit[next] = true;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt << '\n';
    
    return 0;
}
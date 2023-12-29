#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

vector<pair<int, int> > graph[1001];
int prevNode[1001];
int minCost[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >,
        greater<pair<int, int> > > pqueue;
    
    pqueue.push(pair<int, int>(0, start));

    int currNode, nextNode, currCost, nextCost, size;
    while (!pqueue.empty()) {
        currNode = pqueue.top().second;
        currCost = pqueue.top().first;
        pqueue.pop();
        if (currCost > minCost[currNode]) {
            continue ;
        }
        size = graph[currNode].size();
        for (int i = 0; i < size; i++) {
            nextNode = graph[currNode][i].second;
            nextCost = currCost + graph[currNode][i].first;
            if (nextCost < minCost[nextNode]) {
                minCost[nextNode] = nextCost;
                prevNode[nextNode] = currNode;
                pqueue.push(pair<int, int>(nextCost, nextNode));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;   

    int a, b, cost;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cost;
        graph[a].push_back(pair<int, int>(cost, b));
    }

    int start, dest;
    cin >> start >> dest;

    for (int i = 1; i <= n; i++) {
        minCost[i] = 2147483647;
    }

    dijkstra(start);

    cout << minCost[dest] << '\n';

    stack<int> path;
    int i = dest;
    while (i != start) {
        path.push(i);   
        i = prevNode[i];
    }
    cout << path.size() + 1 << '\n';
    cout << start << ' ';
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';

    return 0;
}
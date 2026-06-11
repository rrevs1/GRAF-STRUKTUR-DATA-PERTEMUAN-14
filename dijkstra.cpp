#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;
vector<pair<int, int>> graph[100];

void dijkstra(int start, int V) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "Jarak Terpendek dari node " << start << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : ";
        if (dist[i] == INF) {
            cout << "Tidak dapat dijangkau" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    int V = 5;

    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({2, 6});
    graph[3].push_back({0, 7});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    dijkstra(0, V);

    return 0;
}
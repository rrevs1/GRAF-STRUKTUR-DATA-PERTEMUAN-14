#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<string> nama;

public:
    Graph(int vertices, vector<string> names) {
        V = vertices;
        adj.resize(V);
        nama = names;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << nama[i] << " berteman dengan : ";
            for (int teman : adj[i]) {
                cout << nama[teman] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<string> user = {"Andi", "Budi", "Citra", "Dina", "Eko"};
    int n = 5;

    Graph g(n, user);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "===== SISTEM PERTEMANAN MEDIA SOSIAL =====\n\n";
    cout << "Daftar Relasi Pertemanan:\n";
    g.display();

    return 0;
}
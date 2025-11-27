#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;


void BFS(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}


void DFSUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!visited[neigh])
            DFSUtil(neigh, adj, visited);
    }
}

void DFS(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);

    cout << "DFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}


struct Edge {
    int u, v, w;
};


vector<int> parent, Rank;

int findSet(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (Rank[a] < Rank[b]) swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b]) Rank[a]++;
    }
}

void Kruskal(int n, vector<Edge>& edges) {
    parent.resize(n);
    Rank.resize(n, 0);

    for (int i = 0; i < n; i++) parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
        });

    cout << "\nKruskal's MST:\n";
    int mstCost = 0;

    for (auto& e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            cout << e.u << " -- " << e.v << "  weight = " << e.w << endl;
            mstCost += e.w;
            unionSet(e.u, e.v);
        }
    }
    cout << "Total MST Cost = " << mstCost << "\n";
}


void Prim(int start, int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });
    key[start] = 0;

    int cost = 0;
    cout << "\nPrim's MST:\n";

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        cost += w;

        cout << "Node " << u << " included with edge weight = " << w << endl;

        for (auto& p : adj[u]) {
            int v = p.first;
            int weight = p.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({ weight, v });
            }
        }
    }

    cout << "Total MST Cost = " << cost << endl;
}


void Dijkstra(int start, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    cout << "\nDijkstra Shortest Distances from " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> Distance = " << dist[i] << endl;
    }
}


int main() {
    int n = 6;

    
    vector<vector<int>> adjSimple = {
        {1,2},    // 0
        {0,3},    // 1
        {0,3},    // 2
        {1,2,4},  // 3
        {3,5},    // 4
        {4}       // 5
    };

    BFS(0, adjSimple);
    DFS(0, adjSimple);

    // Graph for Kruskal 
    vector<Edge> edges = {
        {0,1,4}, {0,2,3}, {1,2,1}, {1,3,2}, {2,3,4}, {3,4,2}, {4,5,6}
    };
    Kruskal(6, edges);

    // Graph for Prim & Dijkstra 
    vector<vector<pair<int, int>>> adjWeighted(6);

    auto addEdge = [&](int u, int v, int w) {
        adjWeighted[u].push_back({ v,w });
        adjWeighted[v].push_back({ u,w });
        };

    addEdge(0, 1, 4);
    addEdge(0, 2, 3);
    addEdge(1, 2, 1);
    addEdge(1, 3, 2);
    addEdge(2, 3, 4);
    addEdge(3, 4, 2);
    addEdge(4, 5, 6);

    Prim(0, 6, adjWeighted);
    Dijkstra(0, adjWeighted);

    return 0;
}

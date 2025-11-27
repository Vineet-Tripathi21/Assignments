#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int shortestPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Min-heap: (distance, (x, y))
    priority_queue< pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>> > pq;

    
    dist[0][0] = grid[0][0];
    pq.push({ grid[0][0], {0, 0} });

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int x = top.second.first;
        int y = top.second.second;

        if (x == m - 1 && y == n - 1) return cost;

        // Explore neighbors
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Check boundaries
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newCost = cost + grid[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({ newCost, {nx, ny} });
                }
            }
        }
    }

    return dist[m - 1][n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input grid costs
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << shortestPath(grid);

    return 0;
}

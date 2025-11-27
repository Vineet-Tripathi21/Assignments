#include <iostream>
#include <vector>
using namespace std;

// Directions: up, down, left, right
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int m = grid.size();
    int n = grid[0].size();

    visited[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            grid[nx][ny] == 1 && !visited[nx][ny])
        {
            dfs(nx, ny, grid, visited);
        }
    }
}

int numberOfIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                islands++;
                dfs(i, j, grid, visited);
            }
        }
    }
    return islands;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input the grid
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << numberOfIslands(grid);

    return 0;
}

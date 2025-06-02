#include <bits/stdc++.h>
using namespace std;
int minimumObstacles(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!pq.empty())
    {
        auto [obstacles, pos] = pq.top();
        pq.pop();

        int x = pos.first;
        int y = pos.second;

        if (x == m - 1 && y == n - 1)
        {
            return obstacles;
        }

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                int new_obstacles = obstacles + grid[nx][ny];
                if (new_obstacles < dist[nx][ny])
                {
                    dist[nx][ny] = new_obstacles;
                    pq.push({new_obstacles, {nx, ny}});
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    cout << minimumObstacles(grid);
}
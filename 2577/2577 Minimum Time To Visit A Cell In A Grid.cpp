#include <bits/stdc++.h>
using namespace std;

int minimumTime(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if ((m > 1 && grid[1][0] > 1) && (n > 1 && grid[0][1] > 1))
        return -1;

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!pq.empty())
    {
        auto [time, pos] = pq.top();
        pq.pop();
        int x = pos.first;
        int y = pos.second;

        if (x == m - 1 && y == n - 1)
        {
            return time;
        }

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                int wait_time = (grid[nx][ny] - time) % 2 == 0 ? 0 : 1;
                int new_time = max(time + 1, grid[nx][ny] + wait_time);

                if (new_time < dist[nx][ny])
                {
                    dist[nx][ny] = new_time;
                    pq.push({new_time, {nx, ny}});
                }
            }
        }
    }

    return -1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    cout << minimumTime(grid) << endl;
    return 0;
}

// 2025/10/05 23:47:29

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool is_valid(int row, int col, const vector<vector<int>> &heights)
{
    return row >= 0 && col >= 0 && row < (int)heights.size() && col < (int)heights[0].size();
}

// Bu fonksiyonu "bitmask" mantığına göre düzelttim
bool is_visited(int row, int col, int from_ocean, const vector<vector<int>> &visited)
{
    return (visited[row][col] & from_ocean) != 0;
}

vector<vector<int>> pacificAtlantic1(vector<vector<int>> &heights)
{
    int col_len = heights.size();    // satır sayısı (m)
    int row_len = heights[0].size(); // sütun sayısı (n)
    vector<pair<int, int>> all_directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<tuple<int, int, int>> next_cell;                         // (r, c, ocean) 1=Pacific, 2=Atlantic
    vector<vector<int>> visited(col_len, vector<int>(row_len, 0)); // bitmask: 1|2

    auto enqueue_if_new = [&](int r, int c, int ocean)
    {
        if ((visited[r][c] & ocean) == 0)
        { // bu okyanat için henüz işaretlenmemişse
            visited[r][c] |= ocean;
            next_cell.emplace(r, c, ocean);
        }
    };

    // Top (Pacific)
    for (int c = 0; c < row_len; ++c)
        enqueue_if_new(0, c, 1);
    // Left (Pacific)
    for (int r = 0; r < col_len; ++r)
        enqueue_if_new(r, 0, 1);

    // Right (Atlantic)
    for (int r = 0; r < col_len; ++r)
        enqueue_if_new(r, row_len - 1, 2);

    // Bottom (Atlantic)  <-- burası sendeki hataydı
    for (int c = 0; c < row_len; ++c)
        enqueue_if_new(col_len - 1, c, 2);

    while (!next_cell.empty())
    {
        auto [row, col, ocean_from] = next_cell.front();
        next_cell.pop();

        for (auto [dx, dy] : all_directions)
        {
            int nr = row + dx, nc = col + dy;
            if (!is_valid(nr, nc, heights))
                continue;

            // Okyanattan içeri doğru "tırmanıyoruz": komşu >= mevcut olmalı
            if (heights[nr][nc] >= heights[row][col])
            {
                if (!is_visited(nr, nc, ocean_from, visited))
                {                                  // bu okyanat için ziyaret edilmemişse
                    visited[nr][nc] |= ocean_from; // <-- komşuyu işaretle
                    next_cell.emplace(nr, nc, ocean_from);
                }
            }
        }
    }

    vector<vector<int>> result;
    for (int r = 0; r < col_len; ++r)
        for (int c = 0; c < row_len; ++c)
            if (visited[r][c] == 3)
                result.push_back({r, c});

    return result;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    if (heights.empty() || heights[0].empty())
        return {};
    int m = heights.size(), n = heights[0].size();
    vector<vector<char>> pac(m, vector<char>(n, 0));
    vector<vector<char>> atl(m, vector<char>(n, 0));
    queue<pair<int, int>> q;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
        q.pop();
    for (int j = 0; j < n; ++j)
    {
        pac[0][j] = 1;
        q.push({0, j});
    }
    for (int i = 0; i < m; ++i)
    {
        pac[i][0] = 1;
        q.push({i, 0});
    }

    while (!q.empty())
    {
        // auto [r, c] = q.front();
        pair<int, int> p = q.front();
        int r = p.first;
        int c = p.second;
        q.pop();
        for (auto &d : dirs)
        {
            int nr = r + d.first, nc = c + d.second;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (pac[nr][nc])
                continue;

            if (heights[nr][nc] >= heights[r][c])
            {
                pac[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    while (!q.empty())
        q.pop();
    for (int j = 0; j < n; ++j)
    {
        atl[m - 1][j] = 1;
        q.push({m - 1, j});
    }
    for (int i = 0; i < m; ++i)
    {
        atl[i][n - 1] = 1;
        q.push({i, n - 1});
    }

    while (!q.empty())
    {
        // auto [r, c] = q.front();
        pair<int, int> p = q.front();
        int r = p.first;
        int c = p.second;
        q.pop();
        for (auto &d : dirs)
        {
            int nr = r + d.first, nc = c + d.second;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (atl[nr][nc])
                continue;
            if (heights[nr][nc] >= heights[r][c])
            {
                atl[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> res;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (pac[i][j] && atl[i][j])
                res.push_back({i, j});
    return res;
}
void soln()
{
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};
    auto ans = pacificAtlantic(heights);
    sort(ans.begin(), ans.end());
    cout << "DFS result size: " << ans.size() << "\n";
    for (auto &p : ans)
        cout << "[" << p[0] << "," << p[1] << "] ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
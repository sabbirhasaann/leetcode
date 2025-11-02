// 2025/11/02 22:50:40

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void check(vector<vector<int>> &visited, int n, int m, int i, int j)
{
    // right
    for (int k = j + 1; k < m; k++)
    {
        if (visited[i][k] == 1 || visited[i][k] == 2)
            break;
        visited[i][k] = 3;
    }
    // left
    for (int k = j - 1; k >= 0; k--)
    {
        if (visited[i][k] == 1 || visited[i][k] == 2)
            break;
        visited[i][k] = 3;
    }
    // down
    for (int k = i + 1; k < n; k++)
    {
        if (visited[k][j] == 1 || visited[k][j] == 2)
            break;
        visited[k][j] = 3;
    }
    // up
    for (int k = i - 1; k >= 0; k--)
    {
        if (visited[k][j] == 1 || visited[k][j] == 2)
            break;
        visited[k][j] = 3;
    }
}

int countUnguarded3(int n, int m, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    /*
        empty = 0
        wall = 1
        guard = 2
        guarded = 3
    */
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (auto &vec : walls)
    {
        int x = vec[0];
        int y = vec[1];
        visited[x][y] = 1;
    }
    for (auto &vec : guards)
    {
        int x = vec[0];
        int y = vec[1];
        visited[x][y] = 2;
    }
    for (auto &vec : guards)
    {
        int x = vec[0];
        int y = vec[1];
        check(visited, n, m, x, y);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
                count++;
        }
    }
    return count;
}

int countUnguarded2(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<int> g(m * n);
    for (auto &pos : walls)
        g[pos[0] * n + pos[1]] = 2;
    for (auto &pos : guards)
        g[pos[0] * n + pos[1]] = 2;
    for (auto &pos : guards)
        for (int i = 0, d[] = {1, 0, -1, 0, 0, 1, 0, -1}; i < 7; i += 2)
            for (int y = pos[0] + d[i], x = pos[1] + d[i + 1];
                 y >= 0 && y < m && x >= 0 && x < n && g[y * n + x] < 2;)
                g[y * n + x] = 1, y += d[i], x += d[i + 1];
    return count_if(g.begin(), g.end(), [](int v)
                    { return v < 1; });
}
int countUnguarded1(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (auto &guard : guards)
        grid[guard[0]][guard[1]] = 1;

    for (auto &wall : walls)
        grid[wall[0]][wall[1]] = 2;

    for (auto &guard : guards)
    {
        int r = guard[0], c = guard[1];

        for (int i = r - 1; i >= 0; i--)
        {
            if (grid[i][c] == 1 || grid[i][c] == 2)
                break;
            grid[i][c] = 3;
        }

        for (int i = r + 1; i < m; i++)
        {
            if (grid[i][c] == 1 || grid[i][c] == 2)
                break;
            grid[i][c] = 3;
        }

        for (int j = c - 1; j >= 0; j--)
        {
            if (grid[r][j] == 1 || grid[r][j] == 2)
                break;
            grid[r][j] = 3;
        }

        for (int j = c + 1; j < n; j++)
        {
            if (grid[r][j] == 1 || grid[r][j] == 2)
                break;
            grid[r][j] = 3;
        }
    }

    int unguarded = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                unguarded++;
        }
    }

    return unguarded;
}

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<bool>> mat(m, vector<bool>(n, false));
    vector<vector<bool>> block(m, vector<bool>(n, false));
    vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int res = 0;

    for (vector<int> v : walls)
    {
        mat[v[0]][v[1]] = true;
        block[v[0]][v[1]] = true;
    }

    for (vector<int> g : guards)
    {
        mat[g[0]][g[1]] = true;
        block[g[0]][g[1]] = true;
    }

    for (int i = 0; i < guards.size(); i++)
    {
        for (pair<int, int> dir : direction)
        {
            int x = dir.first + guards[i][0];
            int y = dir.second + guards[i][1];

            while (x >= 0 && x < m && y >= 0 && y < n && !block[x][y])
            {
                mat[x][y] = true;
                x += dir.first;
                y += dir.second;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!mat[i][j])
                res++;
        }
    }

    return res;
}
int countUnguarded_tried(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<bool>> mat(m, vector<bool>(n, false));
    vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int res = 0;
    for (vector<int> v : walls)
        mat[v[0]][v[1]] = true;

    for (int i = 0; i < guards.size(); i++)
    {
        mat[guards[i][0]][guards[i][1]] = true;
        for (pair<int, int> dir : direction)
        {
            int x = dir.first + guards[i][0];
            int y = dir.second + guards[i][1];
            while (x >= 0 && x < m && y >= 0 && y < n && !mat[x][y])
            {
                mat[x][y] = true;
                x += dir.first;
                y += dir.second;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
            if (!mat[i][j])
                res++;
        }
        cout << endl;
    }
    return res;
}
void soln()
{
    int m, n;
    vector<vector<int>> guards, walls;
    m = 4, n = 6;
    guards = {{0, 0}, {1, 1}, {2, 3}};
    walls = {{0, 1},
             {2, 2},
             {1, 4}};
    cout << countUnguarded(m, n, guards, walls) << endl;

    m = 3, n = 3, guards = {{1, 1}}, walls = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    cout << countUnguarded(m, n, guards, walls) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
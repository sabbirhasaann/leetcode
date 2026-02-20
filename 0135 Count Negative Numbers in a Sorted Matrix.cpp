// 2026/01/02 20:15:04

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int countNegatives(vector<vector<int>> &grid)
{
    int count = 0, n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        int l = m - 1, h = 0, res = m;
        while (l >= h)
        {
            int mid = h + (l - h) / 2;
            if (grid[i][mid] <= -1)
            {
                res = mid;
                l = mid - 1;
            }

            else
                h = mid + 1;
        }
        count += (m - res);
    }

    return count;
}
int countNegatives1(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int row = 0;
    int col = n - 1;
    int count = 0;

    // Start from top-right corner
    while (row < m && col >= 0)
    {
        if (grid[row][col] < 0)
        {
            // All elements below in this column are also negative
            count += (m - row);
            col--; // move left
        }
        else
        {
            row++; // move down
        }
    }
    return count;
}
void soln()
{
    vector<vector<int>> grid = {
        {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << countNegatives(grid) << endl;

    grid = {
        {3, 2},
        {1, 0}};
    cout << countNegatives(grid)
         << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
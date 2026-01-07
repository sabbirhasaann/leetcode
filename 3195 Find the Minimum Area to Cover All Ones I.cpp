// 2025/08/22 21:53:53

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minimumArea(vector<vector<int>> &grid)
{
    int mina = 0;
    int n = grid.size();
    int m = grid[0].size();

    return mina;
}
vector<vector<int>> input_matrix(int n, int m)
{
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    return arr;
}
void soln()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr = input_matrix(n, m);
    cout << minimumArea(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
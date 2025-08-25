// 2025/08/25 22:36:09

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> findDiagonalOrderOptimized(vector<vector<int>> &mat)
{

    int row = mat.size();
    int col = mat[0].size();
    vector<int> ans;

    int i = 0;
    int j = 0;

    bool upward = true;

    while (ans.size() < row * col)
    {
        ans.push_back(mat[i][j]);

        if (upward)
        {

            if (j == col - 1)
            {
                i++;
                upward = false;
            }
            else if (i == 0)
            {
                j++;
                upward = false;
            }
            else
            {
                i--;
                j++;
            }
        }
        else
        {

            if (i == row - 1)
            {
                j++;
                upward = true;
            }
            else if (j == 0)
            {
                i++;
                upward = true;
            }
            else
            {
                i++;
                j--;
            }
        }
    }

    return ans;
}
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> adj(n + m - 1);
    vector<int> arr;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            adj[i + j].push_back(mat[i][j]);

    for (int i = 0; i < n + m - 1; i++)
        if (!(i % 2))
            for (int j = 0, k = adj[i].size() - 1; j <= k; j++, k--)
                swap(adj[i][j], adj[i][k]);

    for (int i = 0; i < m + n - 1; i++)
        for (int j = 0; j < adj[i].size(); j++)
            arr.push_back(adj[i][j]);

    return arr;
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
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat = input_matrix(m, n);
    // vector<int> arr = findDiagonalOrder(mat);
    vector<int> arr = findDiagonalOrderOptimized(mat);
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
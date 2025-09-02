// 2025/08/28 23:00:22

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<int>> sortMatrixEfficient(vector<vector<int>> &grid)
{
    map<int, vector<int>> mpp;
    int n = grid.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mpp[i - j].push_back(grid[i][j]);

    for (auto &it : mpp)
    {
        if (it.first < 0)
            sort(begin(it.second), end(it.second));

        else
            sort(begin(it.second), end(it.second), greater<int>());
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            grid[i][j] = mpp[i - j].back();
            mpp[i - j].pop_back();
        }
    }

    return grid;
}
vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int j = 1; j < m; j++)
    {
        int i = 0, k = j;
        vector<int> arr;
        while (k < m)
        {
            arr.push_back(grid[i][k]);
            i++;
            k++;
        }
        sort(arr.begin(), arr.end());
        i = 0;
        k = j;
        int l = 0;
        while (k < m)
        {
            grid[i][k] = arr[l];
            i++;
            k++;
            l++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int j = 0, k = i;
        vector<int> arr;
        while (k < n)
        {
            arr.push_back(grid[k][j]);
            j++;
            k++;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        j = 0;
        k = i;
        int l = 0;
        while (k < n)
        {
            grid[k][j] = arr[l];
            j++;
            k++;
            l++;
        }
    }
    return grid;
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
    vector<vector<int>> mat = input_matrix(n, m);
    vector<vector<int>> resMat = sortMatrix(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << resMat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
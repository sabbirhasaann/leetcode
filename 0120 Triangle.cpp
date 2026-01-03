// 2025/09/25 08:32:53

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minimumTotal(vector<vector<int>> &triangle)
{
    int minT = 0;

    return minT;
}
int minimumTotal_not(vector<vector<int>> &triangle)
{
    int minT = 0;
    int n = triangle.size();
    for (int i = 0; i < n; i++)
    {
        sort(triangle[i].begin(), triangle[i].end());
        minT += triangle[i][0];
    }
    return minT;
}
void print_matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void soln()
{
    vector<vector<int>> adj = {{2},
                               {3, 4},
                               {6, 5, 7},
                               {4, 1, 8, 3}};
    cout << minimumTotal(adj) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
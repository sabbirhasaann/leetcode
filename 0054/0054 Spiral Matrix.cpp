#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> spiralMat;

    int n = matrix.size();
    int m = matrix[0].size();
    int noOfValue = n * m;

    int count = 0;

    return spiralMat;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    vector<int> spiralMat = spiralOrder(matrix);
}
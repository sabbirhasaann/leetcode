#include <bits/stdc++.h>
using namespace std;
bool isTeoplitz_Matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        int j = i;
        int k = 0;

        int temp = matrix[j][k];
        j++;
        k++;

        while (j != n && k != m)
        {
            if (matrix[j][k] != temp)
                return false;
            j++;
            k++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int j = i;
        int k = 0;

        int temp = matrix[k][j];
        j++;
        k++;

        while (j != m && k != n)
        {
            if (matrix[k][j] != temp)
                return false;
            j++;
            k++;
        }
    }
    return true;
}
int main()
{
    int m, n; // m -> row n -> column
    cin >> m >> n;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << isTeoplitz_Matrix(matrix) << endl;
}
// 2025/12/17 22:39:03

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool binary_search(vector<vector<int>> &matrix, int row, int m, int search_key)
{
    int i = 0;
    int j = m - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (matrix[row][mid] == search_key)
            return true;
        else if (matrix[row][mid] > search_key)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        if (binary_search(matrix, i, m, target))
            return true;
    }
    return false;
}
void soln()
{
    vector<vector<int>> matrix;
    int target;

    matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    target = 3;

    if (searchMatrix(matrix, target))
        cout << "Found\n";
    else
        cout << "Not Found!\n";

    matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    target = 13;

    if (searchMatrix(matrix, target))
        cout << "Found\n";
    else
        cout << "Not Found!\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
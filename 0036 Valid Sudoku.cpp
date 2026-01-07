// 2025/08/30 19:39:10

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isValidSudoku(vector<vector<char>> &board)
{
}
vector<vector<int>> input_matrix(int n, int m)
{
    vector<vector<int>> arr(n, vector<int>(m));w
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    return arr;
}
void soln()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board = input_matrix(n, m);
    cout << isValidSudoku(board);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
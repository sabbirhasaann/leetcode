// 2025/08/01 22:47:43

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascal(numRows);

    for (int i = 0; i < numRows; i++)
        pascal[i].push_back(1);

    for (int i = 1; i < numRows; i++)
    {
        if (i == 1)
            pascal[i].push_back(1);
        else
        {
            for (int j = 0; j < pascal[i - 1].size() - 1; j++)
                pascal[i].push_back(pascal[i - 1][j] + pascal[i - 1][j + 1]);
            pascal[i].push_back(1);
        }
    }

    return pascal;
}
void soln()
{
    int n;
    cin >> n;
    vector<vector<int>> pascal = generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int x : pascal[i])
            cout << x << " ";
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
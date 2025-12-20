// 2025/12/20 22:35:08

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minDeletionSize(vector<string> &strs)
{
    int delCol = 0;

    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 0; j < strs.size() - 1; j++)
        {
            if (strs[j][i] > strs[j + 1][i])
            {
                delCol++;
                break;
            }
        }
    }

    return delCol;
}
void soln()
{
    vector<string> strs;
    strs = {"cba", "daf", "ghi"};
    cout << minDeletionSize(strs) << endl;

    strs = {"a", "b"};
    cout << minDeletionSize(strs) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
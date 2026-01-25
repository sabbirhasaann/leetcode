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
int minDeletionSize1(vector<string> &strs)
{
    int n = strs.size();
    int count = 0;

    int k = strs[0].length();

    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (strs[j][i] < strs[j - 1][i])
            {
                count++;
                break;
            }
        }
    }
    return count;
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
// 2025/12/22 00:00:55

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minDeletionSize(vector<string> &strs)
{
    int n = strs.size();
    int count = 0;

    int k = strs[0].length();

    for (int i = 0; i < k; i++)
    {
        bool flag = true;
        for (int j = 1; j < n; j++)
        {
            if (strs[j][i] < strs[j - 1][i])
            {
                count++;
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    return count;
}
void soln()
{
    vector<string> strs = {"ca", "bb", "ac"};

    strs = {"xga", "xfb", "yfa"};
    cout << minDeletionSize(strs) << endl;

    strs = {"xc", "yb", "za"};
    cout << minDeletionSize(strs) << endl;

    strs = {"zyx", "wvu", "tsr"};
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
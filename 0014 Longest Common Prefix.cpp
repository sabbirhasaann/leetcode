// 2025/09/11 15:58:02

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    int m = INT_MAX, cnt = 0;
    string s;
    for (string x : strs)
    {
        int len = x.size();
        if (len < m)
            m = len;
    }

    for (int j = 0; j < m; j++)
    {
        char ch = strs[0][j];
        bool flag = 0;
        for (int i = 1; i < n; i++)
            if (strs[i][j] != ch)
            {
                flag = !flag;
                break;
            }
        if (flag)
            break;
        s += ch;
    }
    return s;
}
void soln()
{
    vector<string> strs = {"flower", "flow", "flight"};
    // vector<string> strs = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
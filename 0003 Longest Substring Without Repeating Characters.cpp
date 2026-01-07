// 2025/09/07 20:08:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int lengthOfLongestSubstring(string s)
{
    int max_len = 1, len = 1;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] != s[i - 1])
        {
            cout << s[i - 1] << " " << s[i] << endl;
            len++;
        }
        else
            len = 1;

        if (len > max_len)
            max_len = len;
    }
    return max_len;
}
void soln()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
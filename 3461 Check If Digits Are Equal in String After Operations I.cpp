// 2025/10/23 12:01:00

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool hasSameDigits(string s)
{
    int n = s.size();
    for (int j = 0; j < n - 2; j++)
    {
        for (int i = 1; i < n - j; i++)
        {
            int f = s[i - 1] - '0';
            int l = s[i] - '0';
            int val = (f + l) % 10;
            s[i - 1] = (char)val + '0';
        }
    }
    return s[0] == s[1];
}
void soln()
{
    cout << hasSameDigits("3902") << endl;
    cout << hasSameDigits("34789") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/12/18 00:54:55

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int len = log10(x);

    while (x && len > 0)
    {
        int tenth = pow(10, len);
        int l = x / tenth;
        x = x % tenth;
        int r = x % 10;
        x = x / 10;
        len -= 2;
        if (l != r)
            return false;
    }

    return true;
}
void soln()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
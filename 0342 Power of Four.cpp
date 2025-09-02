// 2025/08/15 21:22:29

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    if ((n & (n - 1)) != 0)
        return false;

    return (n & 0x55555555) != 0;
}
void soln()
{
    int n;
    cin >> n;
    cout << isPowerOfFour(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
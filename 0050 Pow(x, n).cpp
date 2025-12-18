// 2025/12/18 16:27:32

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double myPow(double x, int n)
{
    double ans = 1;
    long long p = n;

    if (n < 0)
        p = ~p + 1;

    while (p > 0)
    {
        if (p & 1)
            ans *= x;
        x *= x;
        p >>= 1;
    }
    if (n < 0)
        return 1 / ans;
    return ans;
}
void soln()
{
    double x;
    int n;

    x = 2.00000;
    n = 10;
    cout << myPow(x, n) << endl;

    x = 2.00000, n = 10;
    cout << myPow(x, n) << endl;

    x = 2.00000, n = -2;
    cout << myPow(x, n) << endl;

    x = 1.0000, n = -2147483648;
    cout << myPow(x, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
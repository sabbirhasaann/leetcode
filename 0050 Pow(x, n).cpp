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

double myPow2(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    if (n > 0)
    {
        return 1.0 / myPow(x, -n);
    }
    if (n % 2)
    {
        return myPow(x, n + 1) / x;
    }
    double tmp = myPow(x, n / 2);
    return tmp * tmp;
}

double power(double x, long long p)
{
    if (p == 0)
        return 1;

    double half = power(x, p / 2);

    if (p % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

double myPow1(double x, int n)
{
    long long p = n; // handle INT_MIN safely

    if (p < 0)
    {
        x = 1 / x;
        p = -p;
    }

    return power(x, p);
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
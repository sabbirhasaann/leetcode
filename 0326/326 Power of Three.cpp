// 2025/08/13 22:41:34

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isPowerOfThree(int n)
{
    if (n < 1)
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}
void soln()
{
    int n;
    cin >> n;
    cout << isPowerOfThree(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
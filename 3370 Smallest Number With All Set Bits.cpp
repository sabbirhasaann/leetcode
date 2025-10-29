// 2025/10/29 12:19:13

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int smallestNumber(int n)
{
    int digit = log2(n) + 1;
    return (1 << digit) - 1;
}
void soln()
{
    cout << smallestNumber(5) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
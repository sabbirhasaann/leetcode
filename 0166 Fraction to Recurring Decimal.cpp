// 2025/09/24 22:40:17

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string fractionToDecimal(int numerator, int denominator)
{
    double ans = (double)numerator / denominator;
    return to_string(ans);
}
void soln()
{
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(2, 1) << endl;
    cout << fractionToDecimal(4, 333) << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    soln();
    return 0;
}
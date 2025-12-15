// 2025/12/15 18:58:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
long long getDescentPeriods(vector<int> &prices)
{
    int n = prices.size();
    int start = 0, end = 0;
    long long periods = 0;
    while (start < n && end < n - 1)
    {
        if (prices[end] - prices[end + 1] == 1)
            end++;
        else
        {
            long long len = end - start + 1;
            periods += len * (len + 1) / 2;
            end++;
            start = end;
        }
    }

    long long len = end - start + 1;
    periods += len * (len + 1) / 2;

    return periods;
}
void soln()
{
    vector<int> prices;
    prices = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 4, 3, 10, 9, 8, 7};
    cout << getDescentPeriods(prices) << endl;
    prices = {8, 6, 7, 7};
    cout << getDescentPeriods(prices) << endl;
    prices = {3, 2, 1, 4};
    cout << getDescentPeriods(prices) << endl;
    prices = {1};
    cout << getDescentPeriods(prices) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
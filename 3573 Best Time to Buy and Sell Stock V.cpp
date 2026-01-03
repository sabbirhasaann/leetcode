// 2025/12/17 07:51:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

long long maximumProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    int maxProfit = 0;

    vector<int> maxPrices(n, 0);

    maxPrices[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxPrices[i] = max(maxPrices[i + 1], prices[i]);

    for (int i = 0; i < n; i++)
        maxProfit = max(maxProfit, maxPrices[i] - prices[i]);

    return maxProfit;
}

void soln()
{
    vector<int> prices;
    int k;

    prices = {1, 7, 9, 8, 2};
    k = 2;
    cout << maximumProfit(prices, k) << endl;

    prices = {12, 16, 19, 19, 8, 1, 19, 13, 9};
    k = 3;
    cout << maximumProfit(prices, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/12/17 08:39:36

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maxProfitNaive(vector<int> &prices)
{
    int n = prices.size();
    int profit = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int prof = prices[j] - prices[i];
            if (prof > profit)
                profit = prof;
        }
    }
    return profit;
}

int maxProfit(vector<int> &prices)
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
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;

    prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/12/18 12:49:52

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
{
    long long mxProfit = 0;
    int n = prices.size();
    vector<long long> preSumPrices(n, 0), preSumProfits(n, 0);
    preSumPrices[0] = prices[0];
    preSumProfits[0] = strategy[0] * prices[0];

    for (int i = 1; i < n; i++)
        preSumPrices[i] = preSumPrices[i - 1] + prices[i];

    for (int i = 1; i < n; i++)
        preSumProfits[i] = preSumProfits[i - 1] + strategy[i] * prices[i];

    mxProfit = preSumProfits[n - 1];

    for (int i = 0; i < n - k + 1; i++)
    {
        int leftIdx = i - 1, rightIdx = i + k;
        long long leftSum = 0, rightSum = 0, profits = 0;
        if (leftIdx != -1)
            leftSum = preSumProfits[leftIdx];
        if (rightIdx != n)
            rightSum = preSumProfits[n - 1] - preSumProfits[rightIdx - 1];

        long long windowSum = preSumPrices[i + k - 1] - preSumPrices[i + k / 2 - 1];
        profits = leftSum + windowSum + rightSum;
        mxProfit = max(mxProfit, profits);
    }
    return mxProfit;
}
void soln()
{
    vector<int> prices, strategy;
    int k;

    prices = {5, 8};
    strategy = {-1, -1};
    k = 2;
    cout << maxProfit(prices, strategy, k) << endl;

    prices = {4, 2, 8};
    strategy = {-1, 0, 1};
    k = 2;
    cout << maxProfit(prices, strategy, k) << endl;

    prices = {5, 4, 3};
    strategy = {1, 1, 0};
    k = 2;
    cout << maxProfit(prices, strategy, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
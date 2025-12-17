// 2025/12/17 08:39:36

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maxProfit(vector<int> &prices)
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
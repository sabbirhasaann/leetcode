// 2025/08/02 19:46:34

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minCost(vector<int> &basket1, vector<int> &basket2)
{
    map<int, int> count;
    for (int x : basket1)
        count[x]++;
    for (int x : basket2)
        count[x]--;

    vector<int> toSwap;
    int minVal = min(*min_element(basket1.begin(), basket1.end()),
                     *min_element(basket2.begin(), basket2.end()));

    for (auto &[val, freq] : count)
    {
        if (freq % 2 != 0)
            return -1;
        for (int i = 0; i < abs(freq) / 2; i++)
        {
            toSwap.push_back(val);
        }
    }

    sort(toSwap.begin(), toSwap.end());

    long long cost = 0;
    int m = toSwap.size();
    for (int i = 0; i < m / 2; i++)
    {
        cost += min(toSwap[i], 2 * minVal);
    }

    return cost;
}

void soln()
{
    int n;
    cin >> n;

    vector<int> basket1(n), basket2(n);
    for (int i = 0; i < n; i++)
        cin >> basket1[i];
    for (int i = 0; i < n; i++)
        cin >> basket2[i];

    cout << minCost(basket1, basket2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
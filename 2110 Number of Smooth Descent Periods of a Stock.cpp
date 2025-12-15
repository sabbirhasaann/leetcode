// 2025/12/15 18:58:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

long long getDescentPeriods8(vector<int> &prices)
{
    long long res = 1, cnt = 1;
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i - 1] == prices[i] + 1)
            ++cnt;
        else
            cnt = 1;
        res += cnt;
    }
    return res;
}

long long getDescentPeriods7(vector<int> &prices)
{
    long ans = 1; // prices[0]
    int dp = 1;

    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] == prices[i - 1] - 1)
            ++dp;
        else
            dp = 1;
        ans += dp;
    }

    return ans;
}

long long getDescentPeriods6(vector<int> &prices)
{
    long long res = 0, L = 0, R = 0, n = prices.size();
    while (L < n)
    {
        while (R < n - 1 and prices[R] == prices[R + 1] + 1)
            R++;
        long long sz = R - L + 1;
        res += (sz * (sz + 1)) / 2;
        L = R = R + 1;
    }
    return res;
}

long long getDescentPeriods5(vector<int> &prices)
{
    if (prices.size() == 1)
    {
        return 1;
    }
    long long res = 0;
    long long segStart = 0;
    long long segEnd = 1;
    bool flag = false;
    while (segEnd < prices.size())
    {
        // cout<<"left is "<<segStart<<" right is "<<segEnd;
        if (prices[segEnd] + 1 == prices[segEnd - 1])
        {
            segEnd++;
            flag = true;
        }
        else
        {
            if (flag)
            {
                flag = false;
                long long slen = segEnd - segStart;
                res += ((slen * (slen + 1))) / 2;
                segStart = segEnd;
                segEnd++;
            }
            else
            {
                segStart++;
                segEnd++;
                res++;
            }
        }
        // cout<<" res is "<<res<<endl;
    }
    if (flag)
    {
        cout << segEnd << " " << segStart << " " << prices.size() << endl;
        long long slen = segEnd - segStart;
        res += (slen * (slen + 1)) / 2;
    }
    else
    {
        res++;
    }

    return res;
}

long long getDescentPeriods4(vector<int> &prices)
{
    long long res = 0;
    int len = 1;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i - 1] - prices[i] == 1)
            len++;
        else
        {
            res += 1LL * (len) * (len + 1) / 2;
            len = 1;
        }
    }
    res += 1LL * (len) * (len + 1) / 2;
    return res;
}
long long getDescentPeriods3(vector<int> &prices)
{

    long long ans = 0;
    long long len = 1; // each element itself is a descent period

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] == prices[i - 1] - 1)
        {
            len++; // continue descent
        }
        else
        {
            ans += (len * (len + 1)) / 2;
            len = 1; // reset
        }
    }

    ans += (len * (len + 1)) / 2; // last segment

    return ans;
}

long long getDescentPeriods2(vector<int> &prices)
{
    long long ans = 1, dp = 1;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] == prices[i - 1] - 1)
        {
            dp++;
        }
        else
        {
            dp = 1;
        }

        ans += dp;
    }

    return ans;
}

long long getDescentPeriods1(vector<int> &prices)
{

    long long cnt = 0;
    long long currStreak = 1;
    long long prevPrice = -1;
    for (int price : prices)
    {
        if (price > 0 && (prevPrice - price) == 1)
        {
            currStreak++;
            cnt += currStreak;
        }
        else
        {
            currStreak = 1;
            cnt++;
        }

        // std::cout << prevPrice << " " << price << std::endl;
        prevPrice = price;
    }

    return cnt;
}

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
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

long long maxProfit14(vector<int> &prices, vector<int> &strategy, int k)
{
    long long res = 0;
    int n = prices.size();
    vector<long long> prefix_sum(n + 1);
    vector<long long> prefix_sum_st(n + 1);
    prefix_sum[0] = 0;
    prefix_sum_st[0] = 0;
    int c = k / 2;

    for (int i = 0; i < n; ++i)
    {
        // res += prices[i] * strategy[i];
        prefix_sum[i + 1] = prices[i] + prefix_sum[i];
        prefix_sum_st[i + 1] = prices[i] * strategy[i] + prefix_sum_st[i];
    }

    res = prefix_sum_st[n];

    if (k == 0)
        return res;

    for (int i = k - 1; i < n; ++i)
    {
        // total length = i+1
        // left_st = 0, i-k
        // right_st = i+1, n-1
        // prefix_no_st = i-c+1, i
        long long new_sum = prefix_sum_st[i - k + 1] + prefix_sum_st[n] - prefix_sum_st[i + 1] + prefix_sum[i + 1] - prefix_sum[i - c + 1];
        res = max(res, new_sum);
    }

    return res;
}

long long maxProfit13(vector<int> &prices, vector<int> &strategy, int k)
{

    int n = prices.size();

    ll original = 0;

    for (int i = 0; i < n; i++)
    {
        original += prices[i] * strategy[i];
    }

    int half = k / 2;

    // Will hold the profit *difference* produced by modifying the current k-window
    ll change = 0;

    // First half (see TC)
    // (newS * newP) - (oldS * oldP)  // p is same, newS = 0
    for (int i = 0; i < half; i++)
    {
        change += (0 * prices[i]) - (prices[i] * strategy[i]);
    }

    // Second half (see TC)
    // (newS * newP) - (oldS * oldP)  // p is same, newS = 1
    for (int i = half; i < k; i++)
    {
        change += (1 * prices[i]) - (prices[i] * strategy[i]);
    }

    ll maxChange = change;

    // Slide the window: consider windows starting at i = 1 .. n-k (inclusive)
    // For each shift we update `change` in O(1) by accounting for three positions:
    //  - the index that left the window's first half (idx_left),
    //  - the index that moved from second-half -> first-half (idx_mid),
    //  - the new index that entered the window's second-half (idx_right).
    for (int i = 1; i <= n - k; i++)
    {
        // idx_left = i-1 : it was part of the previous window's first half.
        // Remove its contribution
        // (newS * newP) - (oldS * oldP)
        // first half = (0 * prices[i - 1]) - (prices[i - 1] * strategy[i - 1])
        // no half = 0
        // change = no half - first half = prices[i - 1] * strategy[i - 1]
        ll leftI = (prices[i - 1] * strategy[i - 1]);

        // idx_mid = i + half - 1 : this element was in the previous window's second half,
        // but after shifting the window right by 1 it becomes part of the first half.
        // Compute the net delta for this index: new - old
        // (newS * newP) - (oldS * oldP)
        // second half (1 * prices[idx_mid]) - (strategy[idx_mid] * prices[idx_mid])
        // first half (0 * prices[idx_mid]) - (strategy[idx_mid] * prices[idx_mid])
        // change = new - old = first half - second half = -(prices[idx_mid])
        ll midI = -prices[i + half - 1];

        // idx_right = i + k - 1 : the new element entering the window at the rightmost position (second half).
        // Its contribution in the new window is (1 * prices[idx_right]) - (strategy[idx_right] * prices[idx_right]).
        ll rightI = (1 * prices[i + k - 1]) - (prices[i + k - 1] * strategy[i + k - 1]);

        // Just add all changes - signs were taken care of earlier
        change = change + leftI + midI + rightI;

        maxChange = max(maxChange, change);
    }

    // We are allowed to do at most one modification. If the best change is negative,
    // it's better to not modify at all -> take max(0, maxi).
    return original + max(0LL, maxChange);
}

long long maxProfit12(vector<int> &prices, vector<int> &strategy, int k)
{

    // first, we will create the vector whcih will house the result of the multiplication across all time.
    int n = prices.size();

    long long original_sum = 0;
    for (int i = 0; i < n; i += 1)
    {
        original_sum += prices[i] * strategy[i];
    }

    long long original_window = 0;
    long long modified_window = 0;
    int left = 0;

    long long res = original_sum;

    // instantiate modified window sum:
    for (int i = k / 2; i < k; i += 1)
    {
        modified_window += prices[i];
    }

    for (int i = 0; i < k; i += 1)
    {
        original_window += prices[i] * strategy[i];
    }

    // literal sliding window.
    for (int right = k; right < n; right += 1)
    {

        res = max(res, original_sum + modified_window - original_window);

        // now we also have to shift left up one.
        original_window -= prices[left] * strategy[left];

        // in the modified window, we have to ensure that we shift the middle
        modified_window -= prices[left + k / 2];

        // add the right to the modified window
        original_window += prices[right] * strategy[right];
        modified_window += prices[right];

        left += 1;
    }
    res = max(res, original_sum + modified_window - original_window);
    return res;
}

long long maxProfit11(vector<int> &p, vector<int> &s, int k)
{
    int n = p.size();
    vector<ll> pp(n), pc(n); // pref price nd cost
    pp[0] = p[0];
    pc[0] = s[0] * p[0];

    for (int i = 1; i < n; i++)
    {
        pp[i] = pp[i - 1] + p[i];
        pc[i] = pc[i - 1] + s[i] * p[i];
    }

    ll ans = pc[n - 1];
    for (int i = k - 1; i < n; i++)
    {
        ll t = pc[n - 1] - pc[i];
        if (i - k >= 0)
            t += pc[i - k];

        t += (pp[i] - pp[i - k / 2]);
        ans = max(ans, t);
    }
    return ans;
}

long long maxProfit10(vector<int> &prices, vector<int> &strategy, int k)
{
    long long sum = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i)
        sum += prices[i] * strategy[i];
    long long ans = sum;
    for (int i = 0; i < k; ++i)
    {
        sum -= prices[i] * strategy[i];
        sum += (i < k / 2 ? prices[i] * 0 : prices[i] * 1);
    }
    for (int i = k; i <= n; ++i)
    {
        // [i-k, i)
        ans = max(ans, sum);
        if (i == n)
            break;
        // update to [i-k+1, i+1)
        sum += prices[i - k] * strategy[i - k];
        sum -= prices[i - k] * 0;

        // i-k/2
        sum -= prices[i - k / 2] * 1;
        sum += prices[i - k / 2] * 0;
        //
        sum -= prices[i] * strategy[i];
        sum += prices[i] * 1;
    }
    return ans;
}

long long maxProfit9(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += strategy[i] * prices[i];
    }

    long long ans = sum;
    for (int i = 0; i < k / 2; ++i)
    {
        sum += -strategy[i] * prices[i];
    }
    for (int i = k / 2; i < k; ++i)
    {
        sum += (1 - strategy[i]) * prices[i];
    }
    ans = max(ans, sum);

    for (int i = k; i < n; ++i)
    {
        sum += strategy[i - k] * prices[i - k];
        sum += (1 - strategy[i]) * prices[i];
        sum -= prices[i - k / 2];

        ans = max(ans, sum);
    }
    return ans;
}

long long maxProfit8(vector<int> &prices, vector<int> &strategy, int k)
{
    int s1 = prices.size();
    long long r = 0;
    int p = k / 2;
    for (int i = 0; i < s1; i++)
    {
        r += 1LL * strategy[i] * prices[i];
    }
    vector<long long> v1(s1 + 1, 0);
    vector<long long> v2(s1 + 1, 0);
    for (int i = 0; i < s1; i++)
    {
        v1[i + 1] = v1[i] + 1LL * strategy[i] * prices[i];
        v2[i + 1] = v2[i] + prices[i];
    }
    long long s = 0;
    for (int i = 0; i + k <= s1; i++)
    {
        long long t = v1[i + k] - v1[i];
        long long u = v2[i + k] - v2[i + p];
        s = max(s, u - t);
    }
    return r + s;
}

long long maxProfit7(vector<int> &prices, vector<int> &strategy, int k)
{
    int64_t result = 0, curr = 0;
    for (int i = 0; i < size(prices); ++i)
    {
        curr += (i < k) ? prices[i] * (i < k / 2 ? 0 : 1) : prices[i] * strategy[i];
        result += prices[i] * strategy[i];
    }
    result = max(result, curr);
    for (int i = k; i < size(prices); ++i)
    {
        curr += (prices[i - k] * strategy[i - k]) + (prices[i] - prices[i - k / 2]) - (prices[i] * strategy[i]);
        result = max(result, curr);
    }
    return result;
}

long long maxProfit6(vector<int> &prices, vector<int> &strategy, int k)
{

    int n = prices.size();

    long long initial = 0;

    for (int i = 0; i < n; i++)
    {
        initial += (prices[i] * strategy[i]);
    }
    long long updated = 0;
    for (int i = 0; i < k; i++)
    {
        updated -= (prices[i] * strategy[i]);
        if (i >= k / 2)
        {
            updated += prices[i];
        }
    }
    long long ans = max(initial, initial + updated);

    for (int i = 0; i < n - k; i++)
    {
        updated += (prices[i] * strategy[i]);
        updated -= (prices[i + k] * strategy[i + k]);
        updated += prices[i + k];
        updated -= prices[i + k / 2];
        ans = max(ans, initial + updated);
    }
    return ans;
}

long long maxProfit5(vector<int> &prices, vector<int> &strategy, int k)
{
    int size = prices.size();
    long long lSum = 0, mSum = 0, rSum = 0;
    for (int i = k; i < size; i++)
    {
        rSum += prices[i] * strategy[i];
    }
    int l = 0, m = k / 2;
    for (int i = m; i < k; i++)
    {
        mSum += prices[i];
    }
    long long res = 0;
    for (int i = 0; i < size; i++)
    {
        res += prices[i] * strategy[i];
    }
    res = max(res, mSum + rSum);
    for (int r = k; r < size; l++, m++, r++)
    {
        rSum -= prices[r] * strategy[r];
        mSum += prices[r] - prices[m];
        lSum += prices[l] * strategy[l];
        res = max(res, lSum + mSum + rSum);
    }
    return res;
}

long long maxProfit4(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();
    vector<long long> sum(n + 1, 0), profit(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + 1ll * prices[i] * strategy[i];
        profit[i + 1] = profit[i] + prices[i];
    }
    long long ans = sum[n];
    for (int i = k; i <= n; i++)
    {
        long long cnt = sum[i - k] + sum[n] - sum[i] + profit[i] - profit[i - k / 2];
        ans = max(ans, cnt);
    }
    return ans;
}

long long maxProfit3(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();
    int h = k / 2;
    long long ans = 0;
    long long maxi = -1;
    for (int i = 0; i < n; i++)
    {
        ans += prices[i] * strategy[i];
    }
    maxi = ans;
    int initial = 0;
    for (int i = 0; i < k; i++)
    {
        initial += prices[i] * strategy[i];
        if (i >= h)
        {
            ans += prices[i];
        }
    }
    int left = 0;
    int right = k;
    ans -= initial;
    maxi = max(ans, maxi);
    while (right < n)
    {
        int mid = (left + right + 1) / 2;
        ans -= prices[right] * strategy[right];
        ans += prices[right];
        ans += prices[left] * strategy[left];
        ans -= prices[mid];
        maxi = max(ans, maxi);
        right++;
        left++;
    }
    return maxi;
}

long long maxProfit2(vector<int> &prices, vector<int> &strategy, int k)
{
    int N = prices.size();
    // No modification
    long long profit_0 = 0;

    for (int i = 0; i < N; i++)
    {
        profit_0 += prices[i] * strategy[i];
    }

    // Modification at the start
    long long profit_1 = profit_0;

    for (int i = 0; i < k; i++)
    {
        profit_1 -= prices[i] * strategy[i];
        if (i >= int(k / 2))
            profit_1 += prices[i];
    }

    long long ans = max(profit_0, profit_1);

    for (int i = k; i < N; i++)
    {
        profit_1 -= prices[i] * strategy[i];
        profit_1 += prices[i];
        profit_1 -= prices[i - int(k / 2)];
        profit_1 += prices[i - k] * strategy[i - k];

        if (profit_1 > ans)
            ans = profit_1;
    }

    return ans;
}

static long long maxProfit1(vector<int> &prices, vector<int> &strategy, int k)
{
    const int n = prices.size(), k2 = k / 2;
    memset(sum, 0, sizeof(long long) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + 1LL * strategy[i] * prices[i];
    }

    long long modify = reduce(prices.begin() + k / 2, prices.begin() + k, 0LL);
    long long profit = max(sum[n], modify + sum[n] - sum[k]);

    for (int i = 1; i + k <= n; i++)
    {
        modify += prices[i + k - 1] - prices[i + k2 - 1];
        profit = max(profit, modify + sum[n] - sum[i + k] + sum[i]);
    }
    return profit;
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
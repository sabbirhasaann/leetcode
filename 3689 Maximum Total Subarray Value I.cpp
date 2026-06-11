// 2026/06/11 06:09:04
// https://leetcode.com/problems/maximum-total-subarray-value-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

long long maxTotalValue(vector<int> &nums, int k)
{
    if (nums.size() == 1)
        return 0;

    int m = INT_MIN, n = INT_MAX;

    for (int i = 0; i < nums.size(); ++i)
    {
        m = max(m, nums[i]);
        n = min(n, nums[i]);
    }

    return 1LL * k * (m - n);
}

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{1, 3, 2}, 2},
        {{4, 2, 5, 1}, 3},
        {{1}, 5},
        {{100000, 1}, 100000},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << maxTotalValue(testSet[i].first, testSet[i].second) << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
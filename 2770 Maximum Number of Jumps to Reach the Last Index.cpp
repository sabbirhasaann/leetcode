// 2026/05/11 05:17:24
// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int maximumJumps(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> jumps(n, -1);
    jumps[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (jumps[j] != -1 && abs((long long)nums[i] - nums[j]) <= target)
                jumps[i] = max(jumps[i], jumps[j] + 1);
        }
    }

    return jumps[n - 1];
}

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{1, 3, 6, 4, 1, 2}, 2},
        {{1, 3, 6, 4, 1, 2}, 3},
        {{1, 3, 6, 4, 1, 2}, 0},
        {{1, 0, 2}, 1},
        {{1, 0, 2, 3}, 1},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << maximumJumps(testSet[i].first, testSet[i].second) << endl;
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
// 2025/10/23 09:10:06

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 1;
    int l = 0;

    for (int r = 0; r < n; ++r)
    {
        while (nums[r] - nums[l] > 2 * k)
            ++l;

        int window_size = r - l + 1;

        int possible_freq = min(window_size, numOperations + 1);
        ans = max(ans, possible_freq);
    }

    return ans;
}

void soln()
{
    vector<int> num;
    int k, op;
    vector<int> nums1 = {1, 4, 5};
    int k1 = 1, ops1 = 2;
    cout << maxFrequency(nums1, k1, ops1) << "\n"; // Output: 2

    vector<int> nums2 = {5, 11, 20, 20};
    int k2 = 5, ops2 = 1;
    cout << maxFrequency(nums2, k2, ops2) << "\n"; // Output: 2

    k = 76, op = 1;
    num = {1, 90};
    cout << maxFrequency(num, k, op) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
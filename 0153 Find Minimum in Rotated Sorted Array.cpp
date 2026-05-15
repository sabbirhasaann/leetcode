// 2026/05/15 20:49:38
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int findMin(vector<int> &nums)
{
    int l = 0, h = nums.size() - 1;
    while (l <= h)
    {
        if (nums[l] <= nums[h])
            break;
        int mid = l + (h - l) / 2;

        if (nums[mid] > nums[h])
            l = mid + 1;
        else
            h = mid;
    }
    return nums[l];
}

int findMin1(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

void soln()
{
    vector<vector<int>> testSet{
        {3, 4, 5, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {11, 13, 15, 17},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << findMin(testSet[i]) << endl;
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
// 2026/06/06 09:01:48
// https://leetcode.com/problems/left-and-right-sum-differences/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

vector<int> leftRightDifference(vector<int> &nums)
{
    int n = nums.size();
    vector<int> leftSum(n), rightSum(n);
    leftSum[0] = 0;
    rightSum[n - 1] = 0;
    for (int i = 1; i < n; ++i)
        leftSum[i] = nums[i - 1] + leftSum[i - 1];

    for (int j = n - 2; j >= 0; --j)
        rightSum[j] = nums[j + 1] + rightSum[j + 1];

    for (int i = 0; i < n; ++i)
        nums[i] = abs(leftSum[i] - rightSum[i]);
    return nums;
}

void soln()
{
    vector<vector<int>> testSet{
        {10, 4, 8, 3},
        {1}};
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        vector<int> a = leftRightDifference(testSet[i]);
        for (int x : a)
            cout << x << " ";
        cout << endl;
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
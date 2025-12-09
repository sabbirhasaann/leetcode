// 2025/12/07 09:44:42

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN, currentSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        if (currentSum > maxSum)
            maxSum = currentSum;
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}
void soln()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;

    nums = {5, 4, -1, 7, 8};
    cout << maxSubArray(nums) << endl;

    nums = {-1};
    cout << maxSubArray(nums) << endl;

    nums = {-0};
    cout << maxSubArray(nums) << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
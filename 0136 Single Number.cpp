// 2025/12/18 00:15:09

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int singleNumber(vector<int> &nums)
{
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
        ans ^= nums[i];
    return ans;
}
void soln()
{
    vector<int> nums;
    nums = {2, 2, 1};
    cout << singleNumber(nums) << endl;
    nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
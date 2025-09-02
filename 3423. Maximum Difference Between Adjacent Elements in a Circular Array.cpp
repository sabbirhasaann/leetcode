// 2025/06/12 17:00:58

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maxAdjacentDistance(vector<int> &nums)
{
    int n = nums.size();
    int diff = abs(nums[n - 1] - nums[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int diff_a = abs(nums[i + 1] - nums[i]);
        if (diff_a > diff)
            diff = diff_a;
    }
    return diff;
}
void soln()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maxAdjacentDistance(nums);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
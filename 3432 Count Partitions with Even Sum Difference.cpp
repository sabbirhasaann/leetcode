// 2025/12/06 06:33:45

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int countPartitions(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int currSum = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        currSum += nums[i];
        sum -= nums[i];
        int diff = abs(currSum - sum);
        if (!(diff & 1))
            cnt++;
    }
    return cnt;
}
void soln()
{
    vector<int> nums = {10, 10, 3, 7, 6};
    cout << countPartitions(nums) << endl;

    nums = {1, 2, 2};
    cout << countPartitions(nums) << endl;

    nums = {2, 4, 6, 8};
    cout << countPartitions(nums) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
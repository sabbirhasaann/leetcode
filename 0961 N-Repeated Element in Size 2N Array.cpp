// 2026/01/02 14:41:52

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int repeatedNTimes(vector<int> &nums)
{
    int n = nums.size() / 2, num;
    map<int, int> mp;

    for (int x : nums)
        mp[x]++;
    for (auto x : mp)
        if (x.second == n)
        {
            num = x.first;
            break;
        }

    return num;
}
int repeatedNTimes3(vector<int> &nums)
{
    unordered_set<int> s;
    for (int x : nums)
    {
        if (s.count(x))
            return x;
        s.insert(x);
    }
    return -1;
}
int repeatedNTimes2(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;

        if (mp[nums[i]] > 1)
        {
            return nums[i];
        }
    }
    return -1;
}
int repeatedNTimes1(vector<int> &nums)
{

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
        {
            return nums[i];
        }
    }

    return nums[nums.size() - 1];
}
void soln()
{
    vector<int> nums;

    nums = {1, 2, 3, 3};
    cout << repeatedNTimes(nums) << "\n";

    nums = {2, 1, 2, 5, 3, 2};
    cout << repeatedNTimes(nums) << "\n";

    nums = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << repeatedNTimes(nums) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
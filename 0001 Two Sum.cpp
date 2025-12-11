// 2025/09/07 19:56:54

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> twoSum1(vector<int> &nums, int target)
{
    unordered_map<int, int> p;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int need = target - nums[i];

        if (p.count(need))
        {
            return {p[need], i};
        }

        p[x] = i;
    }
    return {}; // missing in your code
}

vector<int> twoSum2(vector<int> &nums, int target)
{
    unordered_map<int, int> mp; // value → index

    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];

        // Check if the complement exists
        if (mp.count(need))
        {
            return {mp[need], i};
        }

        // Store current number with its index
        mp[nums[i]] = i;
    }

    return {}; // Not needed (guaranteed one solution), but syntactically safe
}

vector<int> twoSum3(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mpp.find(target - nums[i]) != mpp.end())
        {
            return {mpp[target - nums[i]], i};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

vector<int> twoSum4(vector<int> &nums, int target)
{
    vector<int> res(2);
    unordered_map<int, size_t> dict;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (dict.find(target - nums[i]) != dict.end())
        {
            res[0] = i;
            res[1] = dict[target - nums[i]];
        }
        dict[nums[i]] = i;
    }
    return res;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> um;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int inv = target - nums[i];
        if (um.find(inv) != um.end()) // means we've find the element
        {
            res.push_back(um[inv]);
            res.push_back(i);
            break;
        }
        else
            um[nums[i]] = i;
    }
    return res;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = twoSum(nums, target);
    printArray(res);

    nums = {3, 2, 4};
    target = 6;
    printArray(twoSum(nums, target));

    nums = {3, 3};
    target = 6;
    printArray(twoSum(nums, target));

    nums = {-3, 4, 3, 90};
    target = 0;
    printArray(twoSum(nums, target));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
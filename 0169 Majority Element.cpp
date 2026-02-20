// 2025/09/21 23:11:35

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int majorityElement4(vector<int> &nums)
{
    int f = 0, ans = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (f == 0)
        {
            ans = nums[i];
        }
        if (nums[i] == ans)
        {
            f++;
        }
        else
        {
            f--;
        }
    }
    return ans;
}
int majorityElement3(vector<int> &nums)
{
    int cnt = 0;
    int can;
    for (int num : nums)
    {
        if (cnt == 0)
            can = num;

        if (can == num)
            cnt++;

        else
            cnt--;
    }
    return can;
}
int majorityElement2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int c = 1;
    int last = nums[0];
    int mc = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (last == nums[i])
        {
            mc++;
            c = max(c, mc);
            if (mc > nums.size() / 2)
                return nums[i];
        }
        else
        {
            last = nums[i];
            mc++;
        }
    }
    return nums[0];
}
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int majority;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[nums[i]]++;
    for (pair<int, int> p : mp)
        if (p.second > n / 2)
        {
            majority = p.first;
            break;
        }
    return majority;
}
void soln()
{
    vector<int> v = {3, 2, 3};
    // cout << majorityElement(v) << endl;
    cout << majorityElement3(v) << endl;

    v = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(v) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
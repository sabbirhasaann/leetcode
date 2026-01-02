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
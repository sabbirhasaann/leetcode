// 2025/11/05 12:44:01
// Q1. Find Missing Elements
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> findMissingElements(vector<int> &nums)
{
    unordered_map<int, int> um;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        um[nums[i]]++;
    int maxim = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());

    for (int i = min; i <= maxim; i++)
        if (um.find(i) == um.end())
            res.push_back(i);
    return res;
}
void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums;
    nums = {1,4,2,5};
    vector<int> res = findMissingElements(nums);
    printArray(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
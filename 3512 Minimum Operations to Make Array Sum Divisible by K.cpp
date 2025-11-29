// 2025/11/29 19:19:04

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minOperations(vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum % k;
}
void soln()
{
    vector<int> nums = {3, 9, 7};
    int k = 5;
    cout << minOperations(nums, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
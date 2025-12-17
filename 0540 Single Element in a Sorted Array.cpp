// 2025/12/18 01:10:14

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int singleNonDuplicate(vector<int> &nums)
{
    int i = 0, j = 1;
    int n = nums.size();

    while (i < n && j < n)
    {
        if (nums[i] != nums[j])
            return nums[i];

        i += 2;
        j += 2;
    }
    return nums[i];
}
void soln()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << endl;

    nums = {3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(nums) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
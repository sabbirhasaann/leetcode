// 2026/01/03 10:06:09

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        vector<int> v;
        int x = nums[i];
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum3 = x + nums[j] + nums[k];
            if (sum3 == 0)
            {
                v.push_back(x);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                break;
            }
            else if (sum3 > 0)
                k--;
            else if (sum3 < 0)
                j++;
        }
        if (!(v.empty()))
            res.push_back(v);
    }
    return res;
}
void print_matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void soln()
{
    vector<int> nums;
    vector<vector<int>> res;

    nums = {-1, 0, 1, 2, -1, -4};
    res = threeSum(nums);
    print_matrix(res);

    nums = {0, 1, 1};
    res = threeSum(nums);
    print_matrix(res);

    nums = {0, 0, 0};
    res = threeSum(nums);
    print_matrix(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
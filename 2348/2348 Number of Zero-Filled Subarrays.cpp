// 2025/08/19 14:36:15

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
long long zeroFilledSubarray1(vector<int> &nums)
{
    long long res = 0, count = 0;

    for (int x : nums)
    {
        if (x == 0)
        {
            count++;
            res += count;
        }
        else
            count = 0;
    }

    return res;
}

long long zeroFilledSubarray(vector<int> &nums)
{
    ll res = 0;
    int n = nums.size(), i = 0;

    while (i < n)
    {
        if (nums[i] == 0)
        {
            int prev = i;
            while (i < n && (nums[i] == 0))
                i++;
            int len = i - prev;
            res += (1LL * len * (len + 1)) / 2;
        }

        i++;
    }

    return res;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // cout << zeroFilledSubarray(arr);
    cout << zeroFilledSubarray1(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
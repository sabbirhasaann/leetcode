// 2025/07/30 20:11:47

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int longestSubarray(vector<int> &nums)
{
    int max_val = *max_element(nums.begin(), nums.end());
    int max_len = 0, curr_len = 0;

    for (int num : nums)
    {
        if (num == max_val)
        {
            curr_len++;
            max_len = max(max_len, curr_len);
        }
        else
        {
            curr_len = 0;
        }
    }

    return max_len;
}

void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestSubarray(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
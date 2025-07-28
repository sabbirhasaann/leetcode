// 2025/07/28 21:15:41

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int countMaxOrSubsets(vector<int> &nums)
{
    int n = nums.size();
    int max_or = 0;
    for (int x : nums)
        max_or |= x;

    int count = 0;

    for (int i = 1; i < (1 << n); i++)
    {
        int track_or = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                track_or |= nums[j];
            }
        }
        if (track_or == max_or)
            count++;
    }
    return count;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countMaxOrSubsets(arr) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}
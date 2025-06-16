// 2025/06/16 11:15:40

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maximumDifference(vector<int> &nums)
{
    int n = nums.size();
    int diff = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                int df = nums[j] - nums[i];
                if (df > diff)
                    diff = df;
            }
        }
    }
    return diff;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maximumDifference(a);
    return;
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
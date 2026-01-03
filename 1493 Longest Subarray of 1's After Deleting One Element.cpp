// 2025/08/24 23:03:40

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
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
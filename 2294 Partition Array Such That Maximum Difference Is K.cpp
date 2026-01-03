// 2025/06/19 09:28:44

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int partitionArray(vector<int> &nums, int k)
{
    int n = nums.size();
}
void soln()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    partitionArray(arr, k);
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
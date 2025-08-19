// 2025/08/19 15:09:13

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int findLucky(vector<int> &arr)
{
    int maxx = -1;
    unordered_map<int, int> mp;
    for (int x : arr)
        mp[x]++;
    for (pair<int, int> x : mp)
        if (x.first == x.second)
            if (x.first > maxx)
                maxx = x.first;
    return maxx;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findLucky(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
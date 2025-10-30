// 2025/10/30 21:13:18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minNumberOperations4(vector<int> &diff)
{
    int n = diff.size();
    using ll = long long;
    ll res = 0;

    int curr = 0, prev = 0;

    for (int i = 0; i < n; i++)
    {
        curr = diff[i];

        if (abs(curr) > abs(prev))
            res += abs(curr - prev);

        prev = curr;
    }
    return res;
}
int minNumberOperations3(vector<int> &target)
{
    int size = target.size();
    int res = 0;
    int prev = 0;
    for (int i = 0; i < size; i++)
    {
        int curr = target[i];
        res += max(curr - prev, 0);
        prev = curr;
    }
    return res;
}

int minNumberOperations2(vector<int> &target)
{
    int prev = target[0];
    int ans = target[0];
    for (int i = 1; i < target.size(); i++)
    {
        int curr = target[i];
        if (curr <= prev)
        {
            prev = curr;
        }
        else
        {
            ans += curr - prev;
            prev = curr;
        }
    }
    return ans;
}
int minNumberOperations(vector<int> &target)
{
    int n = target.size();
    long long ans = target[0];

    for (int i = 1; i < n; i++)
        if (target[i] > target[i - 1])
            ans += target[i] - target[i - 1];

    return (int)ans;
}
void soln()
{
    vector<int> target;
    target = {1, 2, 3, 2, 1};
    cout << minNumberOperations(target) << endl;
    target = {3, 1, 1, 2};
    cout << minNumberOperations(target) << endl;
    target = {3, 1, 5, 4, 2};
    cout << minNumberOperations(target) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
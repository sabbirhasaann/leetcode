// 2025/07/31 15:02:36

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int subarrayBitwiseORs(vector<int> &arr)
{
    unordered_set<int> result;
    unordered_set<int> prev;

    for (int num : arr)
    {
        unordered_set<int> curr;
        curr.insert(num);

        for (int val : prev)
            curr.insert(val | num);

        prev = curr;

        for (int val : curr)
            result.insert(val);
    }

    return result.size();
}

void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subarrayBitwiseORs(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
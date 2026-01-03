// 2025/09/02 20:26:18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxSubarraySumIndex(vector<int> &arr, int k)
{
    int maxSoFar = INT_MIN, maxEndingHere = 0;
    int start, end, s;
    start = end = s = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        maxEndingHere += arr[i];
        if (maxSoFar < maxEndingHere && (end - start + 1) % k == 0)
        {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
        if (maxEndingHere < 0)
        {
            maxEndingHere = 0;
            s = i + 1;
        }
    }
    return maxSoFar;
}

void soln()
{
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    // arr = {1, 2};
    arr = {-1, -2, -3, -4, -5};
    // cout << maxSubarraySumNaive(arr) << endl;
    cout << maxSubarraySumIndex(arr, 4) << endl;
    // cout << maxSubarraySum(arr) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
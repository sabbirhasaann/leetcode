// 2025/08/19 15:56:13

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        for (int i = n - 1, j = 0; i >= j; i--, j++)
            swap(nums[i], nums[j]);
    }

    else
    {
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        for (int i = n - 1, j = pivot + 1; i >= j; i--, j++)
            swap(nums[i], nums[j]);
    }
}
void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    nextPermutation(arr);
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
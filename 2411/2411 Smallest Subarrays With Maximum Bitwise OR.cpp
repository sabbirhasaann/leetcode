// 2025/07/29 19:24:32

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> smallestSubarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n);
    vector<int> lastSeen(32, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int bit = 0; bit < 32; bit++)
        {
            if ((nums[i] >> bit) & 1)
            {
                lastSeen[bit] = i;
            }
        }

        int maxReach = i;
        for (int bit = 0; bit < 32; bit++)
        {
            if (lastSeen[bit] != -1)
            {
                maxReach = max(maxReach, lastSeen[bit]);
            }
        }

        answer[i] = maxReach - i + 1;
    }

    return answer;
}

void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> subarrays = smallestSubarrays(arr);
    for (int x : subarrays)
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
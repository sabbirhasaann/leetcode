// 2025/08/03 22:13:29

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
{
    int n = fruits.size();
    int maxFruits = 0;
    int windowSum = 0;

    int left = 0;

    for (int right = 0; right < n; ++right)
    {
        windowSum += fruits[right][1];

        while (left <= right)
        {
            int l = fruits[left][0];
            int r = fruits[right][0];

            int goLeftFirst = abs(startPos - l) + (r - l);
            int goRightFirst = abs(startPos - r) + (r - l);

            if (min(goLeftFirst, goRightFirst) <= k)
                break;

            windowSum -= fruits[left][1];
            left++;
        }

        maxFruits = max(maxFruits, windowSum);
    }

    return maxFruits;
}

void soln()
{
    int n, startPos, k;
    cin >> n;
    vector<vector<int>> fruits(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
        cin >> fruits[i][0] >> fruits[i][1];

    cin >> startPos >> k;
    cout << maxTotalFruits(fruits, startPos, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/08/03 22:13:29

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int getFruitAmount(vector<vector<int>> &fruits, int pos)
{
    int low = 0, high = fruits.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (fruits[mid][0] == pos)
            return fruits[mid][1];
        else if (fruits[mid][0] < pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
{
    int maxFruits = 0;

    // 1. Walk right only
    int rightSum = 0;
    for (int i = startPos; i <= startPos + k; i++)
    {
        rightSum += getFruitAmount(fruits, i);
    }
    maxFruits = max(maxFruits, rightSum);

    // 2. Walk left only
    int leftSum = 0;
    for (int i = startPos; i >= startPos - k; i--)
    {
        leftSum += getFruitAmount(fruits, i);
    }
    maxFruits = max(maxFruits, leftSum);

    // 3. Left then right (go left L steps, then right R steps)
    for (int leftSteps = 0; leftSteps <= k; leftSteps++)
    {
        int leftPos = startPos - leftSteps;
        int remaining = k - 2 * leftSteps;
        if (remaining < 0)
            continue;

        int rightLimit = startPos + remaining;
        int total = 0;
        for (int i = leftPos; i <= rightLimit; i++)
        {
            total += getFruitAmount(fruits, i);
        }
        maxFruits = max(maxFruits, total);
    }

    // 4. Right then left (go right R steps, then left L steps)
    for (int rightSteps = 0; rightSteps <= k; rightSteps++)
    {
        int rightPos = startPos + rightSteps;
        int remaining = k - 2 * rightSteps;
        if (remaining < 0)
            continue;

        int leftLimit = startPos - remaining;
        int total = 0;
        for (int i = leftLimit; i <= rightPos; i++)
        {
            total += getFruitAmount(fruits, i);
        }
        maxFruits = max(maxFruits, total);
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
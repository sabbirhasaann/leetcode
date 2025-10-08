// 2025/10/08 23:32:07

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> successfulPairs2(vector<int> &spells, vector<int> &potions, long long success)
{

    sort(potions.begin(), potions.end());
    vector<int> ans;

    int m = potions.size();

    for (int spell : spells)
    {

        long long minPotion = (success + spell - 1) / spell;

        int low = 0;
        int high = m - 1;
        int firstValid = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if ((long long)potions[mid] >= minPotion)
            {
                firstValid = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        int count = m - firstValid;
        ans.push_back(count);
    }

    return ans;
}
int lowerBound(vector<int> &arr, long long target, int val)
{
    int low = 0, high = arr.size() - 1;
    int res = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((long long)(arr[mid] * val) >= target)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{

    int n = spells.size(), m = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int idx = lowerBound(potions, success, spells[i]);
        if (idx != m)
            res.push_back(m - idx);
        else
            res.push_back(0);
    }
    return res;
}
void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5};
    long long success = 7;
    vector<int> res = successfulPairs(spells, potions, success);
    printArray(res);

    spells = {3, 1, 2}, potions = {8, 5, 8}, success = 16;
    res = successfulPairs(spells, potions, success);
    printArray(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/08/06 23:28:22

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int binary_search(vector<pair<int, int>> &arr, int search_key)
{
    int i = 0, j = arr.size() - 1;
    int ans = -1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid].first >= search_key)
        {
            ans = mid;
            j = mid - 1;
        }
        else
            i = mid + 1;
    }
    return ans;
}

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = fruits.size();
    vector<pair<int, int>> bs(n);
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++)
    {
        bs[i].first = baskets[i];
        bs[i].second = i;
    }

    sort(bs.begin(), bs.end());

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int index = binary_search(bs, fruits[i]);

        while (index != -1 && index < n && used[bs[index].second])
            index++;

        if (index < n && bs[index].first >= fruits[i])
        {
            cnt++;
            used[bs[index].second] = true;
        }
    }

    return n - cnt;
}

void soln()
{

    int n;
    cin >> n;
    vector<int> fruits(n), baskets(n);
    for (int i = 0; i < n; i++)
        cin >> fruits[i];

    for (int i = 0; i < n; i++)
        cin >> baskets[i];

    cout << numOfUnplacedFruits(fruits, baskets);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
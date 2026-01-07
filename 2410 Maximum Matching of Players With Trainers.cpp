// 2025/07/13 11:30:28

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    int n = players.size();
    int m = players.size();
    int count = 0;

    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    for (int i = 0, j = 0;;)
    {
        if (players[i] <= trainers[j])
        {
            count++;
            j++;
            i++;
        }
        else if (players[i] > trainers[j])
            j++;
        if (i == n || j == m)
            break;
    }
    return count;
}

void soln()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr_p(n), arr_t(m);
    for (int i = 0; i < n; i++)
        cin >> arr_p[i];

    for (int i = 0; i < m; i++)
        cin >> arr_t[i];
    cout << matchPlayersAndTrainers(arr_p, arr_t);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}
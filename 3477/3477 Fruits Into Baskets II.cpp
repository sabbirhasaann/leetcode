// 2025/08/05 23:33:33

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = fruits.size();
    vector<bool> fill_basket(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!fill_basket[j] && fruits[i] <= baskets[j])
            {
                fill_basket[j] = true;
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!fill_basket[i])
            cnt++;
    return cnt;
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
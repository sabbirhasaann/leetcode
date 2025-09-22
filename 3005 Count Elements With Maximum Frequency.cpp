// 2025/09/22 10:38:32

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxFrequencyElements2(vector<int> &nums)
{
    vector<int> count(101);
    int maxfreq = 0;
    int c = 0;
    int ans = 0;
    for (int num : nums)
    {
        count[num]++;
        maxfreq = max(maxfreq, count[num]);
    }
    for (int i = 0; i < 101; i++)
    {
        if (count[i] == maxfreq)
        {
            c++;
        }
        ans = maxfreq * c;
    }
    return ans;
}
int maxFrequencyElements(vector<int> &nums)
{
    int sum = 0, maxx = 1;
    unordered_map<int, int> mp;
    for (int x : nums)
    {
        mp[x]++;
        if (mp[x] > maxx)
            maxx = mp[x];
    }
    for (pair<int, int> p : mp)
        if (p.second == maxx)
            sum += p.second;
    return sum;
}
void soln()
{
    vector<int> v = {1, 2, 2, 3, 1, 4};
    cout << maxFrequencyElements(v);
    v = {1, 2, 3, 4, 5};
    cout << endl
         << maxFrequencyElements(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
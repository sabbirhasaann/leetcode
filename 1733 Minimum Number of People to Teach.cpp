// 2025/09/11 11:13:24

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
#define ll long long
#define endl '\n'
int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
{
    // for (vector<int> v : languages)
    //     sort(v.begin(), v.end());
    int cnt = 0;
    for (vector<int> v : friendships)
    {
        vector<int> res;
        vector<int> v1 = languages[v[0] - 1];
        vector<int> v2 = languages[v[1] - 1];
        set_intersection(v1.begin(), v1.end(),
                         v2.begin(), v2.end(), back_inserter(res));
        if (res.empty())
            cnt++;
    }
    return cnt;
}
void soln()
{
    int n = 2;
    vector<vector<int>> languages;
    vector<vector<int>> friendship;
    // languages = {{1},
    //              {2},
    //              {1, 2}};
    languages = {
        {2},
        {1, 3},
        {1, 2},
        {3}};
    // friendship = {{1, 2},
    //               {1, 3},
    //               {2, 3}};
    friendship = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    cout << minimumTeachings(n, languages, friendship);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
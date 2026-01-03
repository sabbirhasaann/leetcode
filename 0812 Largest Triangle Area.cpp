// 2025/09/27 21:55:19

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double area(vector<pair<int, int>> points)
{
    int x1, y1, x2, y2, x3, y3;
    x1 = points[0].first;
    y1 = points[0].second;

    x2 = points[1].first;
    y2 = points[1].second;

    x3 = points[2].first;
    y3 = points[2].second;
    double ar = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    return ar / 2;
}

double largestTriangleArea(vector<vector<int>> &points)
{
    int n = points.size();
    double maxim = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        if (__builtin_popcount(i) == 3)
        {
            vector<pair<int, int>> p;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    p.push_back({points[j][0], points[j][1]});
                }
            }
            maxim = max(maxim, area(p));
        }
    }
    return maxim;
}
void soln()
{
    vector<vector<int>> points = {{0, 0},
                                  {0, 1},
                                  {1, 0},
                                  {0, 2},
                                  {2, 0}};
    cout << largestTriangleArea(points) << endl;
    points = {{1, 0},
              {0, 0},
              {0, 1}};
    cout << largestTriangleArea(points);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
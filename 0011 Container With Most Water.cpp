// 2025/10/04 19:25:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int maximAr = 0;
    while (l < r)
    {
        int area = (r - l) * min(height[l], height[r]);
        maximAr = max(area, maximAr);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return maximAr;
}
void soln()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    height = {1, 1};
    cout << maxArea(height) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
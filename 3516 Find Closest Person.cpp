// 2025/09/04 13:42:56

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int findClosest(int x, int y, int z)
{
    int first = abs(x - z);
    int sec = abs(y - z);

    if (first == sec)
        return 0;
    else if (first < sec)
        return 1;
    else
        return 2;
}
void soln()
{
    int x, y, z;
    cin >> x >> y >> z;
    cout << findClosest(x, y, z);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
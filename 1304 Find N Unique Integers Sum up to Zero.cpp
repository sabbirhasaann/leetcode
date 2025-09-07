// 2025/09/07 19:49:01

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> sumZero2(const int n)
{
    vector<int> ret(n);
    for (int i = 0; i < n / 2; ++i)
    {
        ret[i * 2] = i + 1;
        ret[i * 2 + 1] = -i - 1;
    }
    return ret;
}
vector<int> sumZero(int n)
{
    vector<int> arr;
    if (n % 2)
    {
        for (int i = 0; i < n; i++)
        {
            int val = -(n / 2) + i;
            arr.push_back(val);
        }
    }

    else
    {
        for (int i = 0; i <= n; i++)
        {
            int val = -(n / 2) + i;
            if (val == 0)
                continue;
            arr.push_back(val);
        }
    }
    return arr;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> arr = sumZero(n);
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
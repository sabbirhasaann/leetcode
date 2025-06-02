#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    int flag = 0;
    while (!flag)
    {
        auto it = find_if(s.begin(), s.end(), ::isdigit);
        if (it != s.end())
        {
            int index = distance(s.begin(), it);
            if (index != 0)
                s.erase(index - 1, 2);
            else
                s.erase(index, 1);
        }
        else
            flag = !flag;
    }
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
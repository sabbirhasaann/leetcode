#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
    string s, part;
    cin >> s >> part;
    int flag = 0, m = part.size();

    while (!flag)
    {
        size_t pos = s.find(part);
        if (pos != string::npos)
            s.erase(pos, m);
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
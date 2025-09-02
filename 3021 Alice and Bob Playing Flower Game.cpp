// 2025/08/29 22:38:51

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
long long flowerGame(int n, int m)
{
    int n_odd = (n + 1) / 2;
    int n_eve = n / 2;
    int m_odd = (m + 1) / 2;
    int m_eve = m / 2;
    return (long long)n_odd * (long long)m_eve + (long long)n_eve * (long long)m_odd;
}
void soln()
{
    int n, m;
    cin >> n >> m;
    cout << flowerGame(n, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
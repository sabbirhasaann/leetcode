// 2025/08/14 20:17:18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string largestGoodInteger(string num)
{
    string result;
    int n = num.size();
    int maxx = -1;

    for (int i = 0; i < n - 2; i++)
    {
        string sb_str = num.substr(i, 3);
        if (sb_str[0] == sb_str[1] && sb_str[1] == sb_str[2])
        {
            if ((sb_str[0] - '0') > maxx)
            {
                maxx = sb_str[0] - '0';
                result = sb_str;
            }
        }
    }
    return result;
}
void soln()
{
    string num;
    cin >> num;
    cout << largestGoodInteger(num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
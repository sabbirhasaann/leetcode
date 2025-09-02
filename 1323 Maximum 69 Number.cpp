// 2025/08/16 20:06:07

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maximum69Number(int num)
{
    string str = to_string(num);
    for (int i = 0; i < str.size(); i++)
        if (str[i] == '6')
        {
            str[i] = '9';
            break;
        }
    return stoi(str);
}
void soln()
{

    int num;
    cin >> num;
    cout << maximum69Number(num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
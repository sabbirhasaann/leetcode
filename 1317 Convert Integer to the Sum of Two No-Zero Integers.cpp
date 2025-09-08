// 2025/09/08 23:29:15

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> getNoZeroIntegers(int n)
{
    vector<int> arr;
    for (int i = 1, j = n - 1; i <= j; i++, j--)
    {
        string s1 = to_string(i);
        string s2 = to_string(n - i);

        bool b1 = (s1.find('0') != string::npos);
        bool b2 = (s2.find('0') != string::npos);

        if (!b1 && !b2)
        {
            arr.push_back(i);
            arr.push_back(n - i);
            break;
        }
    }
    return arr;
}

void soln()
{
    int n;
    cin >> n;
    vector<int> arr = getNoZeroIntegers(n);
    cout << arr[0] << " " << arr[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
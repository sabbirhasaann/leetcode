// 2025/08/20 22:43:20

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int compress(vector<char> &chars)
{
    int write = 0, read = 0;
    while (read < chars.size())
    {
        char ch = chars[read];
        int count = 0;
        while (read < chars.size() && chars[read] == ch)
        {
            ++read;
            ++count;
        }
        chars[write++] = ch;
        if (count > 1)
        {
            for (char c : to_string(count))
            {
                chars[write++] = c;
            }
        }
    }
    return write;
}
void soln()
{
    int n;
    cin >> n;
    vector<char> chars(n);

    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << compress(chars);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
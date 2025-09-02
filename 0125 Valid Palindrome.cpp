// 2025/08/20 22:03:24

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isPalindrome(string s)
{
    string str;
    for (char c : s)
    {
        char ch = static_cast<unsigned char>(tolower(c));
        if (isalnum(static_cast<unsigned char>(ch)))
            str += ch;
    }

    for (int i = 0, j = str.size() - 1; i <= j; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}
void soln()
{
    string s;
    getline(cin, s);
    cout << isPalindrome(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
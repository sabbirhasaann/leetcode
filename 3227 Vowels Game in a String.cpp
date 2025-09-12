// 2025/09/12 17:12:55

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool doesAliceWin4(string s)
{
    int numVowels = 0;

    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            numVowels++;

    return numVowels != 0;
}
bool doesAliceWin3(string s)
{
    string t = "aeiouAEIOU";
    for (int i = 0; i < s.size(); i++)
    {
        if (t.find(s[i]) != string::npos)
            return true;
    }
    return false;
}
static bool doesAliceWin2(string &s)
{
    return any_of(s.begin(), s.end(), [](char c)
                  { return ((0x208222 >> (c & 0x1f)) & 1); })
               ? 1
               : 0;
}
bool doesAliceWin(string s)
{
    int cnt = 0;
    for (char ch : s)
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cnt++;
    if (cnt == 0)
        return false;
    return true;
}
void soln()
{
    cout << doesAliceWin("leetcode") << endl;
    cout << doesAliceWin("bbdc");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
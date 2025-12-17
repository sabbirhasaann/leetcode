// 2025/12/17 23:01:22

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isAnagram(string s, string t)
{
    unordered_map<char, int> um;
    for (char ch : s)
        um[ch]++;
    for (char ch : t)
        um[ch]--;
    for (pair<char, int> p : um)
        if (p.second != 0)
            return false;
    return true;
}
void soln()
{
    string s, t;
    s = "anagram";
    t = "nagaram";

    cout << isAnagram(s, t) << endl;
    s = "rat", t = "car";
    cout << isAnagram(s, t) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/12/17 23:01:22

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isAnagram3(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    unordered_map<char, int> freq;
    for (int i = 0; i < s.size(); i++)
    {
        if (freq.count(s[i]))
        {
            freq[s[i]]++;
        }
        else
        {
            freq[s[i]] = 1;
        }
    }
    // 2nd to look for t's chars in freq
    for (int i = 0; i < t.size(); i++)
    {
        if (freq.count(t[i]))
        {
            freq[t[i]]--;
            if (freq[t[i]] == 0)
            {
                freq.erase(t[i]);
            }
        }
        else
        {
            return false;
        }
    }
    return freq.size() == 0;
}

bool isAnagram2(string s, string t)
{
    map<char, int> ma;
    map<char, int> mb;

    for (const auto &el : s)
        ma[el]++;

    for (const auto &el : t)
        mb[el]++;

    return ma == mb;
}

bool isAnagram1(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }

    unordered_map<char, int> counter;

    for (char ch : s)
    {
        counter[ch]++;
    }
    for (char ch : t)
    {
        if (counter.find(ch) == counter.end() || counter[ch] == 0)
        {
            return false;
        }
        counter[ch]--;
    }
    return true;
}

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
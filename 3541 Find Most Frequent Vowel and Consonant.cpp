// 2025/09/13 08:47:42

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int maxFreqSum4(string s)
{
    unordered_map<char, int> mp;
    for (auto ch : s)
    {
        mp[ch]++;
    }
    int vowel = 0, consonant = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (is_vowel(ch))
        {
            vowel = max(vowel, mp[ch]);
        }
        else
        {
            consonant = max(consonant, mp[ch]);
        }
    }
    return vowel + consonant;
}
int maxFreqSum3(string s)
{
    vector<int> arr(26, 0);
    int mxVowel = 0;
    int mxConst = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 'a']++;

        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            mxVowel = max(mxVowel, arr[s[i] - 'a']);
        }
        else
        {
            mxConst = max(mxConst, arr[s[i] - 'a']);
        }
    }
    return mxConst + mxVowel;
}
int maxFreqSum2(string s)
{
    int count_v = 0;
    int count_c = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            mp[s[i]]++;
            count_v = max(count_v, mp[s[i]]);
        }
        else
        {
            mp[s[i]]++;
            count_c = max(count_c, mp[s[i]]);
        }
    }
    return count_v + count_c;
}
int maxFreqSum(string s)
{
    unordered_map<char, int> letters;
    int vfreq = 0, cfreq = 0;
    for (char x : s)
        letters[x]++;

    // for (pair<char, int> x : letters)
    //     cout << x.first << " " << x.second << endl;
    for (pair<char, int> x : letters)
    {
        if (x.first == 'a' || x.first == 'e' || x.first == 'i' || x.first == 'o' || x.first == 'u')
        {
            if (x.second > vfreq)
                vfreq = x.second;
        }
        else
        {
            if (x.second > cfreq)
                cfreq = x.second;
        }
    }
    return vfreq + cfreq;
}
void soln()
{
    cout << maxFreqSum("successes") << endl;
    cout << maxFreqSum("aeiaeia");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
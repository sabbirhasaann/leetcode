// 2026/02/17 23:20:51
// https://leetcode.com/problems/find-the-difference/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        char c;
        for(int i=0;i<t.length();++i)
            ++freq[t[i]-'a'];
        for(int i=0;i<s.length();++i)
            --freq[s[i]-'a'];
        for(int i=0;i<26;++i)
        {
            if(freq[i])
            {
                c = i + 'a';
                break;
            }
        }
        return c;

    }

    char findTheDifference1(string s, string t) {
    char res = 0;
    for (char c : s) res ^= c;
    for (char c : t) res ^= c;
    return res;
}

char findTheDifference2(string s, string t) {
    int sum = 0;
    for (char c : t) sum += c;
    for (char c : s) sum -= c;
    return (char)sum;
}
void soln()
{
    cout << findTheDifference("abcd", "abcde") << endl;;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
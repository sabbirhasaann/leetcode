// 2026/02/07 21:43:47

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char repeatedCharacter(string s) {
    map<char,int> mp;
    char ch;
    int n  = s.size();
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i]) != mp.end())
        {
            ch = s[i];
            break;
        }
        ++mp[s[i]];
    }
    return ch;
}

void soln()
{
    string s = "abccbaacz";
    cout << repeatedCharacter(s) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
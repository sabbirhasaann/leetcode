// 2026/02/07 21:21:28

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isAcronym(vector<string>& words, string s) {
    string str;
    for(string x: words)
        str += x[0];
    if(s != str)
        return false;
    return true;
}
void soln()
{
    vector<string> words = {"alice","bob","charlie"};
    string s = "abc";
    
    isAcronym(words,s) ? cout << "Yes\n" : cout <<  "No\n"; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
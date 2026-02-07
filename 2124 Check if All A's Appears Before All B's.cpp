// 2026/02/07 18:58:18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool checkString(string s) {
    
    for(int i=0;i<s.length()-1;i++)
        if(s[i]=='b' && s[i+1] =='a')
            return false;
    return true;
}

void soln()
{
    string s = "aaabbb";
    cout << checkString(s) << endl;
    
    s = "bbaaaaabb";    
    cout << checkString(s) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
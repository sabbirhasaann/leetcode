// 2025/11/16 18:43:17

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;

int numSub(string s) {
    long long cnt = 0;
    long long cnt_sbstr=0;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '0')
        {
            cnt_sbstr = (cnt_sbstr + cnt * (cnt + 1) / 2) % mod;
            cnt = 0;
        }
        else
            cnt++;
    }
    cnt_sbstr = (cnt_sbstr + cnt * (cnt + 1) / 2) % mod;
    return cnt_sbstr  % mod;
}

void soln()
{
    string s;
    s = "0110111";
    cout << numSub(s)<< endl;
    s = "101";
    cout << numSub(s)<< endl;
    s = "111111";
    cout << numSub(s)<< endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2026/02/16 08:44:07
// https://leetcode.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int reverseBits(int n){
    int rev = 0;
    for (int i = 0; i < 32; i++) {
        rev <<= 1;
        if (n & 1) {
            rev |= 1;
        }
        n >>= 1;
    }
    return rev;
}

int reverseBitsNaive(int n) {

    int rev = 0;
    string s;
    for(int i=0;i<32;++i){
        if(n & (1<<i))
            s += '1';
        else
            s += '0';       
    }

    for(int i=0;i<32;i++)
        if(s[i]=='1')
            rev += (1<<(31-i));

    return rev;
}

void soln()
{
    int n = 2147483644;
    cout << reverseBits(n) << endl;
    n = 43261596;
    cout << reverseBits(n) << endl;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
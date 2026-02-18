// 2026/02/18 21:59:15
// https://leetcode.com/problems/binary-number-with-alternating-bits/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'
bool hasAlternatingBits(int n) {
        string s;
        while(n){
            if(n&1)
                s+='1';
            else
                s+='0';
            n>>=1;
        }
        reverse(s.begin(), s.end());

        for(int i=0;i<s.length()-1;++i){
            if(s[i]==s[i+1])
                return false;
        }
        return true;
    }


bool hasAlternatingBits(int n) {
    int l=log2(n);
    // cout<<l<<endl;
    l++;
    int prev=(n>>l)&1;
    for(int i=l-1;i>=0;i--){
        int bit=(n>>i)&1;
        if(prev==bit) return false;
        prev=bit;
    }
    return true;
}
void soln()
{
    auto start = high_resolution_clock::now();

    int n=5;
    hasAlternatingBits(n)? cout << "True\n" : cout << "False\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();

    n = 7;
    hasAlternatingBits(n)? cout << "True\n" : cout << "False\n";

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop-start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();

    n = 11;
    hasAlternatingBits(n)? cout << "True\n" : cout << "False\n";

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop-start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

}




int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
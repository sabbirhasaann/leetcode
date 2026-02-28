// 2026/02/28 07:58:45
// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long ans = 0;
        for(int i=1;i<=n;++i)
        {
            int l = log2(i)+1;
            ans = (ans << l | i);
            ans %= mod;
        }   
        return ans;
    }

int concatenatedBinary1(int n) 
    {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bits = 0;
        for (int i = 1; i <= n; i++) 
        {
            if ((i & (i - 1)) == 0) bits++;   
            ans = ((ans << bits) % MOD + i) % MOD;
        }
        return ans;
    }

int concatenatedBinary2(int n) {
        long long modulo = 1e9 + 7;
        long long output = 0;
        int len = 0;

        for(int i = 1; i <=n; i++){
            if((i & (i -1)) == 0 ) len++;

            output <<= len;
            output += i;
            output %= modulo;
        }

        return output %= modulo;
        
    }

int concatenatedBinary3(int n) {
        long long ans = 0, len = 0, MOD = 1e9+7;
        for(int i = 1; i <= n; i++){
            if((i & (i-1)) == 0)len++;
            ans = ((ans << len) | i) % MOD;
        }
        return ans;
    }

const int mod = 1e9 + 7;
int concatenatedBinary4(int n) {
    long result = 0;
    for (int i = 1; i <= n; ++i) {
        result = ((result << (std::bit_width((unsigned)i))) | i) % mod;
    }
    return result;
}

void soln()
{
    vector<int> testSet{
        1,3,12,100000
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << concatenatedBinary(testSet[i])<< endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
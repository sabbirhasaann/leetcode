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
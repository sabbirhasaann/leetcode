// 2026/03/17 21:55:21
// https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int hammingWeight(int n) {
        int ans = 0;
        while(n){
            if(n&1)
                ++ans;
            n>>=1;
        }
        return ans;
    }

void soln()
{
    vector<int> testSet{
        11, 128, 2147483645,
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << hammingWeight(testSet[i])<< endl;
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
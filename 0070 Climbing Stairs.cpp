// 2026/02/27 22:07:53
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int climbStairs(int n) {
        vector<int> dp(n,0);
        if(n==1)
            return 1;
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<n;++i)
            dp[i] = dp[i-2] + dp[i-1];
        return dp[n-1];
    }
int climbStairs1(int n) {

        int steps = 0;
        int minus_1 = 1;
        int minus_2 = 0;
        for(int i = 1; i <= n; i++){
            steps =  minus_1 + minus_2;

            minus_2 = minus_1;
            minus_1 = steps;
        }
        return steps;
    }
void soln()
{
    vector<int> testSet{
        2,3
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << climbStairs(testSet[i])<< endl;
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
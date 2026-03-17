// 2026/03/17 22:01:44
// https://leetcode.com/problems/hamming-distance/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int hammingDistance(int x, int y) {
        int n = x^y, ans = 0;
        while(n){
            if(n&1)
                ++ans;
            n>>=1;
        }

        return ans;
    }

void soln()
{
    vector<pair<int,int>> testSet{
        {1,4},
        {3,1},

    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << hammingDistance(testSet[i].first, testSet[i].second)<< endl;
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
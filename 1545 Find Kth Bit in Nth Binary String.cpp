// 2026/03/03 21:12:51
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1;i<n;++i){
            string rev = s;

            for(int j=0;j<rev.size();++j)
                rev[j] = (rev[j] == '0') ? '1' : '0';

            for(int j=0,k=rev.size()-1; j<k; ++j, --k){
                swap(rev[j], rev[k]);
            }
            s += '1';
            s += rev;
        }
        
        return s[k-1];
    }

void soln()
{
    vector<pair<int,int>> testSet{
        {2,1},
        {3,1},
        {4,11},
        {20, 112345},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << findKthBit(testSet[i].first, testSet[i].second)<< endl;
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
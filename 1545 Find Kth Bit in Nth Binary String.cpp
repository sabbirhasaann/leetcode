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
char findKthBit1(int n, int k) {
        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
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
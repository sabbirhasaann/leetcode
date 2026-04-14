// 2026/04/14 23:53:19
// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> um;
        for(int i=0;i<nums.size();++i)
            um[nums[i]].push_back(i);
        int minD = INT_MAX;
        for(auto p: um){
            int f = p.first;
            vector<int> s = p.second;
            if(s.size()>=3){
                for(int l=0;l<=s.size()-3;++l){
                    int i = s[l];
                    int j = s[l+1];
                    int k = s[l+2];
                    minD = min(minD, (abs(i - j) + abs(j - k) + abs(k - i)));
                }
            }
        }
        if(minD == INT_MAX)
            return -1;
        return minD;
    }

void soln()
{
    vector<vector<int>> testSet{
        {1,2,1,1,3},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << minimumDistance(testSet[i])<< endl;
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
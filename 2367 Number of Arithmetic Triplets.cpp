// 2026/03/08 08:05:33
// https://leetcode.com/problems/number-of-arithmetic-triplets/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,bool> exists;
        int ans = 0;
        for(int i=0;i<nums.size();++i)
            exists[nums[i]] = true;
        for(int i=0;i<nums.size()-2;++i)
            if(exists.find(nums[i]+diff) != exists.end() && exists.find(nums[i]+2*diff) != exists.end())
                ++ans;
        return ans;
        
    }

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{0,1,4,6,7,10}, 3},
        {{4,5,6,7,8,9}, 2},
        
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << arithmeticTriplets(testSet[i].first, testSet[i].second)<< endl;
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
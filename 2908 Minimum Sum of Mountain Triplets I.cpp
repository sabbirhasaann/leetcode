// 2026/03/08 07:20:07
// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int minimumSum(vector<int>& nums) {
        int ans = INT_MAX;

        for(int i=0;i<nums.size()-2;++i){
            for(int j=i+1;j<nums.size()-1;++j){
                for(int k=j+1;k<nums.size();++k)
                    if(nums[i]<nums[j] && nums[j]>nums[k])
                        ans = min(ans, nums[i]+nums[j]+nums[k]);
            }
        }

        if(ans == INT_MAX)
            ans = -1;
        return ans;
    }

void soln()
{
    vector<vector<int>> testSet{
        {8,6,1,5,3},
        {5,4,8,7,10,2},
        {6,5,4,3,4,5},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << minimumSum(testSet[i])<< endl;
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
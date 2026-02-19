// 2026/02/19 15:46:40
// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int missing = n * (n+1)/2;
        for(int i=0;i<n;i++)
            missing -= nums[i];
        return missing;
}

int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=1; i<=n; i++)
            ans ^= i;

        for(int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }

        return ans;
    }

void soln()
{
    vector<vector<int>> testSet{
        {3,0,1},
        {0,1},
        {9,6,4,2,3,5,7,0,1}
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << missingNumber(testSet[i])<< endl;
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
// 2026/03/08 08:24:48
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0;
        
        for(int j = 1; j < n - 1; j++){
            
            int leftMax = INT_MIN;
            int rightMax = INT_MIN;
            
            for(int i = 0; i < j; i++)
                leftMax = max(leftMax, nums[i]);
            
            
            for(int k = j + 1; k < n; k++)
                rightMax = max(rightMax, nums[k]);

            ans = max(ans, (long long)(leftMax - nums[j]) * rightMax);
        }
        
        return ans;
    }


long long maximumTripletValue1(vector<int>& nums) {
        long long ans = 0;

        for(int i=0;i<nums.size()-2;++i){
            for(int j=i+1;j<nums.size()-1;++j){
                for(int k=j+1;k<nums.size();++k)
                        ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
            }
        }

        return ans;
    }


long long maximumTripletValue2(vector<int>& nums) { // use prefix and suffix max
    int n = nums.size();
    if (n < 3) return 0;

    // 1. Precompute Prefix Max (The best nums[i] for any j)
    vector<int> prefixMax(n);
    prefixMax[0] = nums[0];
    for (int i = 1; i < n; i++) 
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);

    // 2. Precompute Suffix Max (The best nums[k] for any j)
    vector<int> suffixMax(n);
    suffixMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) 
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);

    long long maxVal = 0;
    
    // 3. Iterate through j (the middle element)
    for (int j = 1; j < n - 1; j++) {
        long long current = (long long)(prefixMax[j - 1] - nums[j]) * suffixMax[j + 1];
        maxVal = max(maxVal, current);
    }

    return maxVal;
}


long long maximumTripletValue3(vector<int>& nums) { // most efficient
    long long max_val = 0;
    int max_i = 0;       // Stores the maximum nums[i] found so far
    int max_diff = 0;    // Stores the maximum (nums[i] - nums[j]) found so far

    for (int x : nums) {
        // 1. Update the overall answer using the best (i - j) we've seen and current k
        // We do this first because the current 'x' acts as nums[k]
        max_val = max(max_val, (long long)max_diff * x);

        // 2. Update the best difference using the best i we've seen and current j
        // Here, the current 'x' acts as nums[j]
        max_diff = max(max_diff, max_i - x);

        // 3. Update the best i seen so far
        // Here, the current 'x' acts as nums[i]
        max_i = max(max_i, x);
    }

    return max_val;
}

void soln()
{
    vector<vector<int>> testSet{
        {12,6,1,2,7},
        {1,10,3,4,19},
        {1,2,3},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << maximumTripletValue(testSet[i])<< endl;
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
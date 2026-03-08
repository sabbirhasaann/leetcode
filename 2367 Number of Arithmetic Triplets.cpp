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

int arithmeticTriplets1(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((nums[j]-nums[i]== diff)&& (nums[k]-nums[j]==diff)) cnt++;
                }
            }
        }
        return cnt;
    }

int arithmeticTriplets2(vector<int>& nums, int diff) {
    int  arr[201]   ={0};
    for(auto it:nums){
        arr[it]++;
    }
    int ans=0;
    for(auto it:nums){
        if(it-diff>=0 &&it+diff<=200    &&arr[it-diff]&&arr[it+diff]){
            ans++;
        }
    }
    return  ans;
}

int arithmeticTriplets3(vector<int>& nums, int diff) {
    unordered_set s(nums.begin(),nums.end());
    int count=0;
    for(int x:nums){
        if(s.count(x-diff) && s.count(x+diff)){
            count++;
        }
    }
    return count;     
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


int arithmeticTriplets4(vector<int>& nums, int diff) {
    set <int> s(nums.begin(),nums.end());
    int length=size(s);
    int count=0;
    for(int i=0;i<length;i++){
        int j=diff+nums[i];
        if(s.count(j)==1){
            int k=diff+j;
            if(s.count(k)==1){
                count++;
            }
        }
        else{
            continue;
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
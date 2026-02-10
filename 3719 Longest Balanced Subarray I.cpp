// 2026/02/10 13:27:40
// https://leetcode.com/problems/longest-balanced-subarray-i/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int longestBalancedBase(vector<int>& nums) {

    int n= nums.size(),maxLen=0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int,int> odd, even;
        for (int j = i; j < n; j++)
        {
            if(nums[j]%2 && odd.find(nums[j]) == odd.end())
                ++odd[nums[j]];
                
            else if(even.find(nums[j]) == even.end())
                ++even[nums[j]];

            if(odd.size() == even.size())
                maxLen = max(maxLen, j-i+1);
        }
    }

    return maxLen;
}

int longestBalanced(vector<int>& nums) {

    int n= nums.size(),maxLen=0;
    vector<int> lastSeen(1e5+1, -1);
    for (int i = 0; i < n; i++)
    {
        int odd = 0, even = 0;
        for (int j = i; j < n; j++)
        {
            if(nums[j]%2 && lastSeen[nums[j]]<i)
            {
                ++odd;
                lastSeen[nums[j]] = i;

            }
                
            else if(lastSeen[nums[j]]<i){
                ++even;
                lastSeen[nums[j]] = i;

            }

            if(odd == even)
                maxLen = max(maxLen, j-i+1);
        }
    }

    return maxLen;
}


void soln()
{
    vector<int> nums = {2, 5, 4, 3};
    cout << longestBalanced(nums) << endl;
    
    nums = {3,2,2,5,4};
    cout << longestBalanced(nums) << endl;
    
    nums = {1,2,3,2};
    cout << longestBalanced(nums) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
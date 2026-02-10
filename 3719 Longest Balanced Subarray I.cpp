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

int longestBalanced1(vector<int>& a) {
    int n=a.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        vector<bool>seen(100005,false);
        int even=0;
        int odd=0;
        for(int j=i;j<n;j++){
            if(seen[a[j]]==false){
                seen[a[j]]=true;
                if(a[j]%2==0) even++;
                else odd++;
            }
            if(even==odd) maxi=max(maxi,j-i+1);
        }
    }
    return maxi;
}


int longestBalanced(vector<int>& a) {
    unordered_map<int, int> even, odd;
    int max_ans = 0;
    int n = a.size() ;
    for (int i = 0; i < n - 1; i++) {
        even.clear();
        odd.clear();
        if (a[i] % 2 == 0) {
            even[a[i]] = 1;
        } else {
            odd[a[i]] = 1;
        }

        for (int j = i + 1; j < n; j++) {

            if (a[j] % 2 == 0) {
                even[a[j]] = 1;
            } 
            else {
                odd[a[j]] = 1;
            }

            if(even.size() == odd.size()){
                max_ans = max(max_ans , j - i + 1) ;

            }
        }

    }
    return max_ans ;

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
// 2026/02/13 21:43:50
// https://leetcode.com/problems/contains-duplicate/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool containsDuplicate(vector<int>& nums) {
    map<int,int> hash;
    for(int x: nums)
    {
        if(hash.find(x) != hash.end())
            return true;
        hash[x]++;
    }
    return false;
}

bool containsDuplicate1(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    if(mpp.size()==n)return false;
    return true; 
}
void soln()
{
    vector<int> nums = {1,2,3,1};
    containsDuplicate(nums) ? cout << "YES\n" : cout << "NO\n";

    nums = {1,2,3,4};
    containsDuplicate(nums) ? cout << "YES\n" : cout << "NO\n";


    nums = {1,1,1,3,3,4,3,2,4,2};
    containsDuplicate(nums) ? cout << "YES\n" : cout << "NO\n";

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2026/01/27 15:49:31

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, right = 0, avg = n / 3;
    vector<int> v;

    while(right != n + 1){
        
        if(right < n && nums[left]==nums[right])
            right++;
        else{
            if(right - left > avg)
                v.push_back(nums[left]);
            left = right;
            right ++;
        }
    }
    
    return v;

}


vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    
    int candidate1 = 0, candidate2 = 1;
    int count1 = 0, count2 = 0;
    
    // Phase 1: Find candidates
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } 
        else if (num == candidate2) {
            count2++;
        } 
        else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } 
        else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } 
        else {
            count1--;
            count2--;
        }
    }
    
    // Phase 2: Verify candidates
    count1 = 0;
    count2 = 0;
    
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }
    
    vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);
    
    return result;
}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void soln()
{
    vector<int> nums = {3,2,3};
    vector<int> res = majorityElement(nums);
    printArray(res);

    nums = {1};
    res = majorityElement(nums);
    printArray(res);


    nums = {1,2};
    res = majorityElement(nums);
    printArray(res);

    nums = {1,2,3};
    res = majorityElement(nums);
    printArray(res);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2026/02/03 20:53:08

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isTrionic(vector<int>& nums) {
    int n = nums.size(), i = 1,p=-1,q=-1;

    while(i < n && nums[i-1] < nums[i])
        p = i++;
    while(i < n && nums[i-1] > nums[i])
        q = i++;
    while(i<n && nums[i-1] < nums[i])
        i++;

    return i == n && p != -1 && q != -1 && q != n - 1;
}
void soln()
{
    vector<int> nums = {1,3,5,4,2,6};
    cout << isTrionic(nums) << endl;
    
    nums = {2,1,3};
    cout << isTrionic(nums) << endl;   
    
    nums ={3,7,1};
    cout << isTrionic(nums) << endl;  
    
    
    nums = {6,7,5,1};
    cout << isTrionic(nums) << endl;  


    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
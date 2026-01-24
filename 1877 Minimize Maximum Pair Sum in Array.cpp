// 2026/01/24 15:53:57

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minPairSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int maxSum = 0;
    
    for(int i=0, j=n-1;i<j;i++, j--)
        maxSum = max(maxSum, nums[i]+nums[j]);

    return maxSum;

}
void soln()
{
    vector<int> arr = {3,5,2,3};
    cout << minPairSum(arr) << endl; 
    
    arr = {3,5,4,2,4,6};
    cout << minPairSum(arr) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
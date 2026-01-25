// 2026/01/25 15:11:59

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minimumDifference(vector<int>& nums, int k) {
    int n = nums.size(), minD = INT_MAX;

    sort(nums.begin(), nums.end());
    for(int i=0;i<n-k+1;i++)
        minD = min(minD, nums[i+k-1] - nums[i]);
    
    if(minD == INT_MAX)
        return 0;
    return minD;
}
void soln()
{
    int k = 2;
    vector<int> nums = {9,4,1,7};
    cout << minimumDifference(nums,k)<<endl;

    k = 1;
    nums = {90};
    cout << minimumDifference(nums,k)<<endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
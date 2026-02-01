// 2026/02/01 12:54:16

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minimumCost(vector<int>& nums) {
    sort(nums.begin()+1, nums.end());
    return nums[0]+nums[1]+nums[2];
}

void soln()
{
    vector<int> nums = {1,2,3,4,5};
    cout << minimumCost(nums) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
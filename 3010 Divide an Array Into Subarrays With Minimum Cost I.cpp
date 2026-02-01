// 2026/02/01 12:54:16

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minimumCost(vector<int>& nums) {
    sort(nums.begin()+1, nums.end());
    return nums[0]+nums[1]+nums[2];
}

int minimumCost2(vector<int>& nums) {
    int a = 51, b = 51, n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] < b){
            b = nums[i];
            if(b < a) swap(a, b);
        }
    }
    return a + b + nums[0];
}

int minimumCost1(vector<int>& nums) {
    int m1 = INT_MAX, m2 = INT_MAX;
    for (int i = 1;i < nums.size();++i) {
        int x = nums[i];
        if (x < m1) {
            m2 = m1;
            m1 = x;
        }
        else if (x < m2) {
            m2 = x;
        }
    }
    return nums[0] + m1 + m2;
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
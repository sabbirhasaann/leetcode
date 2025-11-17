// 2025/11/17 18:32:57

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool kLengthApart1(vector<int>& nums, int k) {
    int currentDist = k;
    for(const auto& num : nums)
    {
        if (num == 1)
        {
            if (currentDist < k)
            {
                return false;
            }
            currentDist = 0;
        }
        else
        {
            currentDist++;
        }
    }
    return true;
}
bool kLengthApart(vector<int>& nums, int k) {
    int prev_pos = -1;

    for(int i=0;i<nums.size();i++)
    {
        // cout << prev_pos << " ";
        if(nums[i]==1)
        {
            if(prev_pos != -1)
            {
                if(i - prev_pos - 1 < k )
                    return false;
                else
                    prev_pos = i;
            }
            else
                prev_pos = i;
        }

    }
    return true;
}
void soln()
{
    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;
    cout << kLengthApart(nums, k) << endl;

    nums = {1,0,0,1,0,1}, k = 2;
    cout << kLengthApart(nums, k) << endl;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    soln();

    return 0;
}
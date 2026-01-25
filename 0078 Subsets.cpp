#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    
    for(int i=0;i< (1LL << n);i++){
        vector<int> sb;
        for(int j=0;j<n;j++)
        {
            if(i & (1LL<<j))
                sb.push_back(nums[j]);
        }
        res.push_back(sb);
    }
    
    return res;
}

int main(){
    vector<vector<int>> res;
    vector<int> nums = {1,2,3};
    res = subsets(nums);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    
}
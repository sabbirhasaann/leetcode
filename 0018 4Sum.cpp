// 2026/03/10 06:42:54
// https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0;i<n-3;++i){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1; j<n-2;++j){
                if(j-1>i && nums[j] == nums[j-1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l<r)
                {
                    long long sum = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum == target){
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l<r && nums[l] == nums[l+1])
                            ++l;
                        while (l<r && nums[r] == nums[r-1])
                            --r;
                        ++l;
                        --r;
                    }
                    else if(sum<target)
                        ++l;
                    else
                        --r;
                }

            }
        }
        return res;
    }

void print_matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " " ;
        cout << endl;
    }
}
void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{-2,-1,-1,1,1,2,2},0},
        {{1,0,-1,0,-2,2}, 0},
        {{2,2,2,2,2}, 8},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        vector<vector<int>> res = fourSum(testSet[i].first, testSet[i].second);
        print_matrix(res);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
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


    vector<vector<int>> twoSum(vector<int>& nums, int left, int right, long target) {
        vector<vector<int>> ret {};
        while (left < right) {                      
            long sum = nums[left] + nums[right];
            if (sum == target) {
                ret.push_back(vector{nums[left], nums[right]});
                while (nums[left] == nums[left+1] && left < right-1)
                    ++left;
                ++left;
                while (nums[right] == nums[right-1] && right > left)
                    --right;
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return ret;
    }


      vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        vector<vector<int>> ans{};
        std::sort(nums.begin(), nums.end());

        if (nums.size() < 4) return ans;
        
        for (int i = 0; i < nums.size()-3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                long newTarget = (long)target - (nums[i] + nums[j]);
                vector<vector<int>> rets = twoSum(nums, j + 1, nums.size() - 1, newTarget);
                for(auto ret: rets) {
                    vector<int> vec{nums[i], nums[j], ret[0], ret[1]};
                    ans.push_back(vec);
                }
                if (nums[j+1] == nums[nums.size()-1])
                    break;
                
                while (nums[j] == nums[j+1] && j < nums.size()-2)
                    ++j;
            }
            while (nums[i] == nums[i+1] && i < nums.size()-3)
                    ++i;
        }
        return ans;
    }

    

    struct fourElements{
        int one;
        int two;
        int three;
        int four;
    };
    vector<vector<int>> fourSum3(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }
            int first = nums[i];
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int second = nums[j];
                int k = j+1;
                int l = n-1;
                while(k < l){
                    int third = nums[k];
                    int fourth = nums[l];
                    long long sum = (long long)first + second + third + fourth;
                    if(sum == target){
                        vector<int> temp {first, second, third, fourth};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k-1 > 0 && k < n && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(l+1 < n && l >=0 && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum < target){
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
            
        }
        return ans;
    }

    vector<vector<int>> fourSum4(vector<int>& nums, int target) {
        if (nums.size() < 4)  return {};
        sort(nums.begin(), nums.end());
        if ((nums[0] > 0 && nums[0] > target) || (long long)nums[0] + nums[1] + nums[2] + nums[3] > target ||
            (long long)nums[nums.size() - 4] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
            return {};
    
        vector<vector<int>> result; 
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long long)nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) 
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else
                        --right;
                }
            }
        }
        return result;
    }


    vector<vector<int>> fourSum5(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // Sort to handle duplicates and use two pointers
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Optimization: Smallest sum in this iteration is too big
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // Optimization: Largest sum in this iteration is too small
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Optimization for the second loop
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for left and right pointers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
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
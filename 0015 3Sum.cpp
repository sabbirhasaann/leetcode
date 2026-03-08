// 2026/01/03 10:06:09

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 3) return res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int j = i + 1, k = n - 1;
        
        while (j < k) {
            int sum = nums[j] + nums[k];
            
            if (sum == target) {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);

                res.push_back(v);
                
                while (j < k && nums[j] == nums[j + 1]) j++;
                
                while (j < k && nums[k] == nums[k - 1]) k--;
                
                
                j++;
                k--;
            } 
            else if (sum > target) {
                k--;
            } 
            else {
                j++;
            }
        }
    }
    return res;
}

// vector<vector<int>> threeSum1(vector<int> &nums) {
//     vector<vector<int>> res;
//     int n = nums.size();
//     if (n < 3) return res; // Basic edge case

//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < n - 2; i++) {
//         // Skip duplicate values for the first element
//         if (i > 0 && nums[i] == nums[i - 1]) continue;

//         int target = -nums[i];
//         int j = i + 1, k = n - 1;
        
//         while (j < k) {
//             int sum = nums[j] + nums[k];
            
//             if (sum == target) {
//                 res.insert({nums[i], nums[j], nums[k]});
                
//                 // Skip duplicate values for the second element
//                 while (j < k && nums[j] == nums[j + 1]) j++;
//                 // Skip duplicate values for the third element
//                 while (j < k && nums[k] == nums[k - 1]) k--;
                
//                 // Move both pointers after finding a valid triplet
//                 j++;
//                 k--;
//             } 
//             else if (sum > target) {
//                 k--;
//             } 
//             else {
//                 j++;
//             }
//         }
//     }
//     return res;
// }

void print_matrix(vector<vector<int>> &matrix)
{
    if (matrix.empty()) {
        cout << "No triplets found." << endl;
        return;
    }
    
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void soln()
{
    vector<int> nums;
    vector<vector<int>> res;

    nums = {-1, 0, 1, 2, -1, -4};
    res = threeSum(nums);
    print_matrix(res);

    nums = {0, 1, 1};
    res = threeSum(nums);
    print_matrix(res);

    nums = {0, 0, 0};
    res = threeSum(nums);
    print_matrix(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
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


vector<vector<int>> threeSum1(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) break;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                long long curSum = (long long)nums[i] + nums[left] + nums[right];
                if (curSum == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else if (curSum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ret;
        
    }


    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> res;
        const int n = (int)nums.size();
        if (n < 3) return res;

        int mn = nums[0], mx = nums[0];
        for (int x : nums) {
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        long rangeL = (long)mx - (long)mn + 1;
        if (rangeL <= 0) return res;

        const long MAX_RANGE = 2000000L;
        if (rangeL > MAX_RANGE) return res;

        const int range = (int)rangeL;

        // u16 statt int: 4x weniger Memory + bessere Cache-Dichte
        vector<uint16_t> freq(range, 0);
        for (int x : nums) {
            int off = x - mn;
            if (freq[off] < UINT16_MAX)  // safety, sollte praktisch nie overflowen
                ++freq[off];
        }

        // Unique values extrahieren
        vector<int> vals;
        vals.reserve(range);
        for (int off = 0; off < range; ++off) {
            if (freq[off] > 0) vals.push_back(mn + off);
        }
        const int U = (int)vals.size();
        if (U == 0) return res;

        // Hauptloop wie in deiner 17ms-Version, nur mit u16
        for (int i = 0; i < U; ++i) {
            int a = vals[i];
            if (a > 0) break; // alle weiteren >0 → keine 0-Summe mehr
            int off_a = a - mn;
            uint16_t fa = freq[off_a];

            for (int j = i; j < U; ++j) {
                int b = vals[j];
                int off_b = b - mn;
                uint16_t fb = freq[off_b];

                long c_long = -((long)a + (long)b);
                if (c_long < INT_MIN || c_long > INT_MAX) continue;
                int c = (int)c_long;

                if (c < b) break;               // ab hier wird c nur noch kleiner
                if (c < mn || c > mx) continue; 

                int off_c = c - mn;
                uint16_t fc = freq[off_c];
                if (fc == 0) continue;

                if (a == b && b == c) {
                    if (fa >= 3) res.push_back({a, b, c});
                } else if (a == b) {
                    if (fa >= 2 && fc >= 1) res.push_back({a, b, c});
                } else if (b == c) {
                    if (fb >= 2 && fa >= 1) res.push_back({a, b, c});
                } else {
                    res.push_back({a, b, c});
                }
            }
        }

        return res;
    }


    vector<vector<int>> threeSum3(vector<int>& nums) {
        int n = nums.size();

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end()); // to arrange duplicates and give array an order

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0)
            {
                ans.push_back({nums[i], nums[l], nums[r]});

                 // to avoid duplicates

         while(l<r && nums[l] == nums[l+1]){
            l++;
         }

         while ( l < r && nums[r] == nums[r-1]){
            r--;
         }

         l++;
         r--;
            }

            else if (sum < 0)
            {
                l++;
            }

            else
            {
                r--;
            }
        }

        
    }

    return ans ;
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
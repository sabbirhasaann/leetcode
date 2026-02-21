// 2026/02/21 15:08:46
// https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'


int searchInsert(vector<int>& nums, int target) {
        int l = 0,h = nums.size() - 1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<target)
                l = mid + 1;
            else 
                h = mid - 1;
        }
    
        return l;
    }

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{1,3,5,6}, 5},
        {{1,3,5,6}, 2},
        {{1,3,5,6}, 7},
        {{5,6,8,9}, 10},
        {{-3,-1, -1, 1, 5}, 0},
        {{5,6,8,9}, 10}
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << searchInsert(testSet[i].first, testSet[i].second)<< endl;
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
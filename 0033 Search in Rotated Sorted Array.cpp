// 2026/02/26 22:47:30
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int findPivot(vector<int> &a){
    int l = 0, h = a.size() - 1;
    while (l<=h)
    {
        if(a[l]<=a[h])
            return l;
        int mid = l + (h-l) / 2;
        
        if(a[mid]>a[h])
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}

int binary_search(vector<int> &arr, int i, int j, int search_key)
{
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid] == search_key)
            return mid;
        else if (arr[mid] > search_key)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int n = nums.size();
        if(nums[pivot] == target)
            return pivot;
        if(pivot == 0)
            return binary_search(nums, 0, n-1, target);
        if(nums[0] <= target)
            return binary_search(nums, 0, pivot - 1, target);
        return binary_search(nums, pivot + 1, n - 1, target);
    }

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{4,5,6,7,0,1,2}, 0},
        {{4,5,6,7,0,1,2}, 3},
        {{1}, 0}
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << search(testSet[i].first, testSet[i].second)<< endl;
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
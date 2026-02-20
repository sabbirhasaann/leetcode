// 2026/02/20 17:19:51
// https://leetcode.com/problems/remove-element/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int removeElement(vector<int>& nums, int val) {
        int n = nums.size(),k=0;
        for(int i=0;i<n;++i)
            if(nums[i] != val)
                swap(nums[k++],nums[i]);
        return k;
    }

void soln()
{
    vector<pair<vector<int>,int>> testSet{
        {{3,2,2,3}, 3}, 
        {{0,1,2,2,3,0,4,2}, 2}
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << removeElement(testSet[i].first, testSet[i].second)<< endl;
        printArray(testSet[i].first);
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
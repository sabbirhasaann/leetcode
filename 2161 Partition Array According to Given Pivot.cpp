// 2026/06/09 06:10:39
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> res;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] < pivot)
            res.push_back(nums[i]);
        else if (nums[i] == pivot)
            ++cnt;
    }
    res.insert(res.end(), cnt, pivot);

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > pivot)
            res.push_back(nums[i]);
    }
    return res;
}

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{9, 12, 5, 10, 14, 3, 10}, 10},
        {{-3, 4, 3, 2}, 2},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        vector<int> a = pivotArray(testSet[i].first, testSet[i].second);
        for (int x : a)
            cout << x << " ";
        cout << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
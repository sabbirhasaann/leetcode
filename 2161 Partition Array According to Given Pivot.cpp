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
vector<int> pivotArray1(vector<int> &nums, int pivot)
{
    vector<int> ans(nums.size());
    int i = 0, j = 0, k = 0, c = 0;
    while (i < nums.size())
    {
        if (nums[i] < pivot)
        {
            ans[k++] = nums[i];
        }
        else if (nums[i] == pivot)
        {
            c++;
        }
        i++;
    }
    for (int i = 0; i < c; i++)
    {
        ans[k++] = pivot;
    }
    while (j < nums.size())
    {
        if (nums[j] > pivot)
        {
            ans[k++] = nums[j];
        }
        j++;
    }
    return ans;
}
vector<int> pivotArray2(vector<int> &nums, int pivot)
{
    int n = nums.size();
    int countLess = 0;
    int countEqual = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < pivot)
        {
            countLess++;
        }
        else if (nums[i] == pivot)
        {
            countEqual++;
        }
    }

    int i = 0;
    int j = countLess;
    int k = countLess + countEqual;
    vector<int> res(n);

    for (int &num : nums)
    {
        if (num < pivot)
        {
            res[i] = num;
            i++;
        }
        else if (num > pivot)
        {
            res[k] = num;
            k++;
        }
        else
        {
            res[j] = num;
            j++;
        }
    }
    return res;
}

vector<int> pivotArray3(vector<int> &nums, int pivot)
{
    vector<int> result(nums.size(), 0);
    int left = 0, right = nums.size() - 1;

    for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j)
    {
        if (nums[i] < pivot)
        {
            result[left] = nums[i];
            left++;
        }

        if (nums[j] > pivot)
        {
            result[right] = nums[j];
            right--;
        }
    }

    while (left <= right)
    {
        result[left] = pivot;
        left++;
    }

    return result;
}
vector<int> pivotArray4(vector<int> &nums, int pivot)
{
    vector<int> result;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == pivot)
        {
            count++;
        }
        if (nums[i] < pivot)
        {
            result.push_back(nums[i]);
        }
    }

    for (int i = 0; i < count; i++)
    {
        result.push_back(pivot);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > pivot)
        {
            result.push_back(nums[i]);
        }
    }

    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}
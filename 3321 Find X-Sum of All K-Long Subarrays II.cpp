// 2025/11/05 09:54:28

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void printUmIntInt(unordered_map<int, int> mp)
{
    for (auto p : mp)
        cout << p.first << " " << p.second << endl;
    cout << endl;
}
void printPriorityQueIntInt(priority_queue<pair<int, int>, vector<pair<int, int>>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top().second << " " << pq.top().first << endl;
        pq.pop();
    }
    cout << endl;
}
vector<long long> findXSum(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    vector<long long> res;
    unordered_map<int, int> um;
    for (int i = 0; i < k; i++)
        um[nums[i]]++;

    for (int i = 0; i <= n - k; i++)
    {
        // cout << "Iteration " << i << " :\n";
        // printUmIntInt(um);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        int cnt = 0;
        long long sum = 0;
        for (auto p : um)
            pq.push({p.second, p.first});

        // printPriorityQueIntInt(pq);

        while (!pq.empty() && cnt < x)
        {
            sum += 1LL * pq.top().first * pq.top().second;
            pq.pop();
            cnt++;
            // cout << "sum :" << sum << endl;
        }
        // cout << endl;

        res.push_back(sum);

        if (i + k < n)
        {
            um[nums[i]]--;
            if (um[nums[i]] == 0)
                um.erase(nums[i]);
            um[nums[i + k]]++;
        }
        // cout << i << endl;
    }

    return res;
}
void printArray(vector<long long> &v)
{
    for (long long x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums;
    int k, x;
    vector<long long> xsum;
    // nums = {1, 1, 2, 2, 3, 4, 2, 3};
    // k = 6, x = 2;
    // vector<long long> xsum = findXSum(nums, k, x);
    // printArray(xsum);

    // nums = {3, 8, 7, 8, 7, 5};
    // k = 2, x = 2;
    // xsum = findXSum(nums, k, x);
    // printArray(xsum);

    nums = {5, 1};
    k = 1, x = 1;
    xsum = findXSum(nums, k, x);
    printArray(xsum);

    // for (int i = 0; i < 1e5; i++)
    //     nums.push_back(1e5);
    // k = 100, x = 50;
    // vector<long long> xsum = findXSum(nums, k, x);
    // printArray(xsum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
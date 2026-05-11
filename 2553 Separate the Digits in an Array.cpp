// 2026/05/11 23:22:00
// https://leetcode.com/problems/separate-the-digits-in-an-array/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

vector<int> separateDigits(vector<int> &nums)
{
    vector<int> res, temp;
    for (int x : nums)
    {
        while (x > 0)
        {
            int r = x % 10;
            temp.push_back(r);
            x /= 10;
        }
        reverse(temp.begin(), temp.end());
        for (int d : temp)
            res.push_back(d);
        temp.clear();
    }
    return res;
}

// Solution using stack data structure
vector<int> separateDigits1(vector<int> &nums)
{
    stack<int> st;
    vector<int> a;
    for (int i = 0; i < nums.size(); i++)
    {
        int r = 0, t = nums[i];
        while (t > 0)
        {
            r = t % 10;
            st.push(r);
            t = t / 10;
        }
        while (!st.empty())
        {
            a.push_back(st.top());
            st.pop();
        }
    }
    return a;
}

// solution using making int to string
vector<int> separateDigits2(vector<int> &nums)
{
    vector<int> a;
    for (int i = 0; i < nums.size(); i++)
    {
        string al = to_string(nums[i]);
        for (char j : al)
        {
            a.push_back(j - '0');
        }
    }
    return a;
}

// iterating from last
vector<int> separateDigits3(vector<int> &nums)
{
    vector<int> res;
    stack<int> st;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int num = nums[i];
        while (num != 0)
        {
            int dig = num % 10;
            st.push(dig);
            num /= 10;
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

// Most efficient
vector<int> separateDigits4(vector<int> &nums)
{
    vector<int> ans;

    for (auto &it : nums)
    {

        string tmp = to_string(it);

        for (auto &s : tmp)
            ans.push_back(s - '0');
    }

    return ans;
}

void soln()
{
    vector<vector<int>> testSet{
        {13, 25, 83, 77},
        {7, 1, 3, 9},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        vector<int> res = separateDigits(testSet[i]);
        for (int x : res)
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
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
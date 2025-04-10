#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums, int limit)
{
    int _left = 0, _right = 0;
    multiset<int> window;
    int _maxSize = 0;

    while (_right < nums.size())
    {
        window.insert(nums[_right]);
        while (*window.rbegin() - *window.begin() > limit)
        {
            window.erase(window.find(nums[_left]));
            _left++;
        }
        _maxSize = max(_maxSize, _right - _left + 1);
        _right++;
    }

    return _maxSize;
}
int main()
{
    int n;
    cin >> n;
    int limit;
    cin >> limit;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << longestSubarray(a, limit);
}

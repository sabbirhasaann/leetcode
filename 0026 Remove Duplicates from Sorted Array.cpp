// 2025/09/11 16:14:21

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int removeDuplicates2(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int i = 0; // last unique element index
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j]; // overwrite with unique element
        }
    }
    return i + 1; // total unique elements
}
int removeDuplicates(vector<int> &nums)
{
    int write = 0, read = 0;
    while (read < nums.size())
    {
        int val = nums[read];
        while (read < nums.size() && nums[read] == val)
            ++read;
        nums[write++] = val;
    }
    return write;
}
void soln()
{
    vector<int> arr = {1, 1, 2};
    // vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(arr) << endl;
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2026/01/02 21:26:43

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void sortColors(vector<int> &nums)
{
    vector<int> freq(3, 0);
    for (int x : nums)
        freq[x]++;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < freq[0])
            nums[i] = 0;
        else if (i >= freq[0] && i < (freq[0] + freq[1]))
            nums[i] = 1;
        else if (i >= freq[0] + freq[1])
            nums[i] = 2;
    }
}
void soln()
{
    vector<int> nums = {0, 1, 2, 0, 1, 2};
    sortColors(nums);
    printArray(nums);

    nums = {2, 0, 1};
    sortColors(nums);
    printArray(nums);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
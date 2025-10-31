// 2025/10/31 09:58:01

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> getSneakyNumbers2(vector<int> &nums)
{
    std::vector<int> res(nums.size() - 2);
    for (int num : nums)
    {
        res[num] += 1;
    }

    std::vector<int> return_vector;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == 2)
        {
            return_vector.push_back(i);
        }
    }
    return return_vector;
}
vector<int> getSneakyNumbers1(vector<int> &nums)
{

    int xorSum = 0;
    int totalSize = nums.size();
    int actualSize = nums.size() - 2;

    // XOR all elements of the array
    for (int i = 0; i < totalSize; i++)
    {
        xorSum ^= nums[i];
    }

    // XOR all numbers from 0 to n-1 (excluding the two sneaky numbers)
    for (int i = 0; i < actualSize; i++)
    {
        xorSum ^= i;
    }

    // Find the rightmost set bit in xorSum
    int rightmostSetBit = xorSum & ~(xorSum - 1);

    int firstSneakyNumber = 0;
    int secondSneakyNumber = 0;

    // Separate the numbers into two groups based on the rightmost set bit
    for (int i = 0; i < totalSize; i++)
    {
        if (nums[i] & rightmostSetBit)
        {
            firstSneakyNumber ^= nums[i];
        }
        else
        {
            secondSneakyNumber ^= nums[i];
        }
    }

    // XOR the range of numbers from 0 to n-1
    for (int i = 0; i < actualSize; i++)
    {
        if (i & rightmostSetBit)
        {
            firstSneakyNumber ^= i;
        }
        else
        {
            secondSneakyNumber ^= i;
        }
    }

    return {firstSneakyNumber, secondSneakyNumber};
}
vector<int> getSneakyNumbers(vector<int> &nums)
{
    vector<int> res;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            res.push_back(nums[i]);
            continue;
        }
        mp[nums[i]]++;
    }
    return res;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums;
    nums = {0, 1, 1, 0};
    printArray(getSneakyNumbers(nums));
    nums = {0, 3, 2, 1, 3, 2};
    printArray(getSneakyNumbers(nums));
    nums = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    printArray(getSneakyNumbers(nums));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
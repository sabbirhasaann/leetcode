// 2025/12/10 07:28:04

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void merge4(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int j = n - 1;
    int i = m - 1;
    int r = n + m - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[r] = nums1[i];
            i--;
        }
        else
        {
            nums1[r] = nums2[j];
            j--;
        }
        r--;
    }
}

void merge3(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}

void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] >= nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
            nums1[k--] = nums2[j--];
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> merged;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m)
    {
        merged.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        merged.push_back(nums2[j]);
        j++;
    }

    nums1 = merged;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);
    printArray(nums1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
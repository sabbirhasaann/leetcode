// 2025/12/18 00:55:59

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> productExceptSelf(vector<int> &nums)
{
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums = {1, 2, 3, 4};
    printArray(productExceptSelf(nums));

    nums = {-1, 1, 0, -3, 3};
    printArray(productExceptSelf(nums));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
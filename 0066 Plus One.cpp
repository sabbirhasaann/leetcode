// 2026/01/02 14:58:10

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> plusOne(vector<int> &digits)
{
    int carry = 0, n = digits.size();
    int x = digits[n - 1] + 1;

    digits[n - 1] = x % 10;
    carry = x / 10;

    while (carry && --n)
    {
        x = digits[n - 1] + carry;
        digits[n - 1] = x % 10;
        carry = x / 10;
    }

    if (carry)
        digits.insert(digits.begin(), carry);
    return digits;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> digits;

    digits = {1, 2, 3};
    printArray(plusOne(digits));

    digits = {4, 3, 2, 1};
    printArray(plusOne(digits));

    digits = {9};
    printArray(plusOne(digits));

    digits = {9, 9, 9};
    printArray(plusOne(digits));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
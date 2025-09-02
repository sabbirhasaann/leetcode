#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool hasEqualHalfSums(int number)
{
    string str = to_string(number);
    int len = str.length();

    int half = len / 2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < half; i++)
    {
        sum1 += str[i] - '0';
        sum2 += str[i + half] - '0';
    }
    return sum1 == sum2;
}

bool hasEvenDigits(int n)
{
    n = abs(n); // handle negative numbers
    int digitCount = 0;
    while (n > 0)
    {
        digitCount++;
        n /= 10;
    }
    return (digitCount % 2 == 0);
}

int countSymmetricIntegers(int low, int high)
{
    int ans = 0;
    for (int i = low; i <= high; i++)
    {
        if (hasEvenDigits(i))
            if (hasEqualHalfSums(i))
                ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int low, high;
    cin >> low >> high;
    cout << countSymmetricIntegers(low, high);

    return 0;
}
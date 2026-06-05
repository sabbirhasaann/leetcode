// 2026/06/05 07:49:43
// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int charToDigit(char c)
{
    return c - '0';
}

int totalWaviness(int num1, int num2)
{
    int waviness = 0;

    for (int i = num1; i <= num2; ++i)
    {
        string s = to_string(i);
        if (s.length() >= 3)
        {
            int prev = charToDigit(s[0]), curr = charToDigit(s[1]), next;

            for (int j = 1; j < s.length() - 1; ++j)
            {
                next = charToDigit(s[j + 1]);

                if ((curr > prev && curr > next) || (curr < prev && curr < next))
                    ++waviness;
                prev = curr;
                curr = next;
            }
        }
    }
    return waviness;
}

// we can directly compare characters - so no need to coversion
int totalWaviness1(int num1, int num2)
{
    int ans = 0;
    for (int i = num1; i <= num2; i++)
    {
        string s = to_string(i);
        for (int j = 1; j < s.size() - 1; j++)
        {
            if (s[j] > s[j - 1] && s[j] > s[j + 1])
            {
                ans++;
            }
            if (s[j] < s[j - 1] && s[j] < s[j + 1])
            {
                ans++;
            }
        }
    }
    return ans;
}

// manual string conversion producing better runtime
// string s;
// while (n > 0)
// {
//     int r = n % 10;
//     s += r + '0';
//     n /= 10;
// }
// reverse(s.begin(), s.end());

// dp base solution
bool check(int tmp)
{
    int right = tmp % 10;
    tmp /= 10;
    int mid = tmp % 10;
    tmp /= 10;
    int left = tmp % 10;
    return (mid > right && mid > left) || (mid < right && mid < left);
}
int totalWaviness2(int num1, int num2)
{
    if (num2 < 100)
    {
        return 0;
    }
    vector<int64_t> dp(num2 + 1, 0);
    for (int i = 100; i <= num2; ++i)
    {
        int tmp = i;
        int right = tmp % 10;
        tmp /= 10;
        int mid = tmp % 10;
        int left = (tmp % 100) / 10;
        int64_t ans = (mid > right && mid > left) || (mid < right && mid < left);
        ans += dp[tmp];
        dp[i] = ans;
    }
    for (int i = 1; i <= num2; i++)
    {
        dp[i] += dp[i - 1];
    }
    return dp[num2] - dp[num1 - 1];
}

// improved dp
int totalWaviness3(int num1, int num2)
{
    vector<int> dp(100, 0);
    for (int i = 100; i <= num2; i++)
    {
        int wave = 0;
        int n = i;
        int prev = n % 10;
        n /= 10;
        int cur = n % 10;
        int next = (n % 100) / 10;
        if ((prev < cur && next < cur) || (prev > cur && next > cur))
            wave++;
        wave += dp[n];
        dp.push_back(wave);
    }
    int ans = 0;
    for (int i = num1; i <= num2; i++)
        ans += dp[i];
    return ans;
}

int totalWaviness4(int num1, int num2)
{
    int ans = 0;
    vector<int> digits(10);
    for (int i = num1; i <= num2; i++)
    {
        int n = i;
        int sz = 0;
        while (n != 0)
        {
            digits[sz++] = (n % 10);
            n /= 10;
        }

        for (int i = 1; i < sz - 1; i++)
        {
            if (digits[i] > digits[i - 1] && digits[i] > digits[i + 1])
                ans++;
            else if (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])
                ans++;
        }
    }
    return ans;
}

// efficient solution
int wavy(int n)
{
    if (n < 101)
        return 0;
    int w = 0, a, b, c;

    c = n % 10, n /= 10;
    b = n % 10, n /= 10;

    while (n)
    {
        a = n % 10;
        if ((b > a && b > c) || (b < a && b < c))
            w++;
        c = b, b = a, n /= 10;
    }

    return w;
}
int totalWaviness5(int num1, int num2)
{
    int t = 0;
    for (int i = num1; i <= num2; i++)
    {
        t += wavy(i);
    }
    return t;
}

void soln()
{
    vector<pair<int, int>> testSet{
        {120, 130},
        {198, 202},
        {4848, 4848},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << totalWaviness(testSet[i].first, testSet[i].second) << endl;
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
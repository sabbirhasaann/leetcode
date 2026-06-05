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
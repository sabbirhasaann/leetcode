// 2026/06/22 09:32:23
// https://leetcode.com/problems/maximum-number-of-balloons/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int maxNumberOfBalloons(string text)
{
    unordered_map<char, int> um;
    for (int i = 0; i < text.length(); ++i)
        ++um[text[i]];
    string s = "balon";
    um['l'] /= 2;
    um['o'] /= 2;
    int cnt = INT_MAX;
    for (int i = 0; i < s.length(); ++i)
        cnt = min(cnt, um[s[i]]);
    return cnt;
}

void soln()
{
    vector<string> testSet{
        "nlaebolko",
        "loonbalxballpoon",
        "leetcode",
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << maxNumberOfBalloons(testSet[i]) << endl;
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
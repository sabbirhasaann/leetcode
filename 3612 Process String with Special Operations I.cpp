// 2026/06/17 18:24:14
// https://leetcode.com/problems/process-string-with-special-operations-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

string processStr(string s)
{
    string r;
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
            r += c;
        else if (c == '*' && !r.empty())
            r.pop_back();
        else if (c == '#')
            r += r;
        else
            reverse(r.begin(), r.end());
    }
    return r;
}

string processStr1(string s)
{
    string result = "";
    for (auto it : s)
    {
        if (it >= 'a' && it <= 'z')
            result += it;
        else if (it == '*')
            result = result.substr(0, result.size() - 1);
        else if (it == '#')
            result = result + result;
        else
            reverse(result.begin(), result.end());
    }
    return result;
}

void soln()
{
    vector<string> testSet{
        "a#b%*",
        "z*#",

    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << processStr(testSet[i]) << endl;
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
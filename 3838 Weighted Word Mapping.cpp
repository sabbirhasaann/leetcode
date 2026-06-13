// 2026/06/13 20:57:00
// https://leetcode.com/problems/weighted-word-mapping/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

string mapWordWeights(vector<string> &words, vector<int> &weights)
{
    string str;
    for (string s : words)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i)
            sum += weights[s[i] - 'a'];
        sum %= 26;
        str += (char)(25 - sum + 'a');
    }
    return str;
}

string mapWordWeights1(vector<string> &words, vector<int> &weights)
{
    int h = 0;
    string result = "";
    for (int i = 0; i < words.size(); i++)
    {
        int weight = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            weight += weights[words[i][j] - 'a'];
        }
        result += 'z' - (weight % 26);
    }
    return result;
}

void soln()
{
    vector<pair<vector<string>, vector<int>>> testSet{
        {{"abcd", "def", "xyz"}, {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2}},
        {{"a", "b", "c"}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {{"abcd"}, {7, 5, 3, 4, 3, 5, 4, 9, 4, 2, 2, 7, 10, 2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5}}};
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << mapWordWeights(testSet[i].first, testSet[i].second) << endl;
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
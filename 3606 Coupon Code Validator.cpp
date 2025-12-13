// 2025/12/13 10:03:33
// complexity - O(N∗Log(N))

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isAlphanumeric(string str)
{
    if (str == "")
        return false;

    return all_of(str.begin(), str.end(), [](char c)
                  { return (isalnum(static_cast<unsigned char>(c)) || c == '_'); });
}

vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    vector<string> res;
    map<string, int> bLine = {{"electronics", 1}, {"grocery", 2}, {"pharmacy", 3}, {"restaurant", 4}};
    map<string, vector<string>> code_bLine;
    int n = code.size();

    for (int i = 0; i < n; i++)
    {
        if (isActive[i] && isAlphanumeric(code[i]) && bLine.find(businessLine[i]) != bLine.end())
            code_bLine[businessLine[i]].push_back(code[i]);
    }

    for (pair<string, vector<string>> it : code_bLine)
    {
        sort(it.second.begin(), it.second.end());
        code_bLine[it.first] = it.second;
    }

    for (auto p : bLine)
    {
        cout << p.first << endl;
        vector<string> codes = code_bLine[p.first];
        for (string x : codes)
            res.push_back(x);
    }

    return res;
}
void printArray(vector<string> &v)
{
    for (string x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    vector<string> businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, true, true};
    vector<string> res = validateCoupons(code, businessLine, isActive);
    printArray(res);

    code = {"pBXoMqBU0_aMgc9F8dy6TaSzza3KjSJFjxZa_NuyMjzEBR7fJNwpGHh7lzuoZvQeEUeo6YumHmIOjjchXlzSVa4ItdyDOImQgm", "P8rIIUl35MW8yrqRbO0N_IITptYOxz9tOCbPL6d1aIF_hM2sapaDtUzNpmAZRmJQB1WgjLh8bdYADuSRSU21OzttUkq73qiA66", "aFWkYookQlHYMXzhVGxbnrXIl1810ws3qHtketHSECHqJoktWXVZGc6ZyeOuzA_VL9zFL9znpIHwbkwJF2bOPQqsz3_0PYgETJ"};
    businessLine = {"pharmacy", "invalid", "pharmacy"};
    isActive = {true, true, true};
    res = validateCoupons(code, businessLine, isActive);
    printArray(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
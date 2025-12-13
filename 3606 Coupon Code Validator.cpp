// 2025/12/13 10:03:33
// complexity - O(N∗Log(N))

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<string> validateCoupons1(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    int n = code.size();
    vector<string> ans;
    vector<string> categ = {"electronics", "grocery", "pharmacy", "restaurant"};
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        if (!isActive[i])
            continue;
        if (businessLine[i] != categ[0] && businessLine[i] != categ[1] && businessLine[i] != categ[2] && businessLine[i] != categ[3])
            continue;
        int f = 1;
        if (code[i].size() == 0)
            continue;
        for (int j = 0; j < code[i].size(); j++)
        {
            if (!((code[i][j] == '_') || (code[i][j] - 'a' < 26 && code[i][j] - 'a' >= 0) || (code[i][j] - 'A' < 26 && code[i][j] - 'A' >= 0) || (code[i][j] - '0' <= 9 && code[i][j] - '0' >= 0)))
            {
                f = -1;
                break;
            }
        }
        if (f == -1)
            continue;
        mp[businessLine[i]].push_back(code[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        auto it = mp.find(categ[i]);
        if (it == mp.end())
            continue;
        sort(it->second.begin(), it->second.end());
        for (int j = 0; j < it->second.size(); j++)
        {
            ans.push_back(it->second[j]);
        }
    }
    return ans;
}

vector<string> validateCoupons2(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    auto is_valid_code = [](const string &s) -> bool
    {
        if (s.empty())
            return false;
        for (auto c : s)
            if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && !(c == '_'))
                return false;
        return true;
    };
    auto is_valid_businessLine = [](const string &s) -> bool
    {
        return (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant");
    };
    int n = code.size();
    vector<int> ret;
    for (int i = 0; i < n; ++i)
    {
        if (is_valid_code(code[i]) && is_valid_businessLine(businessLine[i]) && isActive[i])
            ret.push_back(i);
    }
    sort(ret.begin(), ret.end(), [&](const int a, const int b)
         {
            if (businessLine[a] != businessLine[b])
                return businessLine[a] < businessLine[b];
            return code[a] < code[b]; });
    vector<string> ans;
    for (int i : ret)
        ans.push_back(code[i]);
    return ans;
}

vector<string> validateCoupons3(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    string lines[4] = {"electronics", "grocery", "pharmacy", "restaurant"};
    unordered_map<string, vector<string>> mp = {
        {"electronics", vector<string>()},
        {"grocery", vector<string>()},
        {"pharmacy", vector<string>()},
        {"restaurant", vector<string>()}};
    vector<string> ans;
    for (int i = 0; i < code.size(); i++)
    {
        if (!mp.count(businessLine[i]) || !isActive[i])
            continue;
        if (!code[i].empty() && all_of(code[i].begin(), code[i].end(), [&](char c)
                                       { return isalnum(c) || c == '_'; }))
        {
            mp[businessLine[i]].push_back(code[i]);
        }
    }
    for (auto &l : lines)
    {
        auto &coupons = mp[l];
        sort(coupons.begin(), coupons.end());
        ans.insert(ans.end(), coupons.begin(), coupons.end());
    }
    return ans;
}

vector<string> validateCoupons4(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    unordered_map<string, vector<string>> m;
    int n = code.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = isActive[i] && (businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") && code[i].size() > 0;
        if (flag)
        {
            for (auto &c : code[i])
                if (!(isalpha(c) || isdigit(c) || c == '_'))
                {
                    flag = false;
                    break;
                }
        }
        if (flag)
            m[businessLine[i]].push_back(code[i]);
    }
    vector<string> cats = {"electronics", "grocery", "pharmacy", "restaurant"};
    vector<string> ans;
    for (auto &cat : cats)
    {
        sort(m[cat].begin(), m[cat].end());
        for (auto &coupon : m[cat])
            ans.push_back(coupon);
    }
    return ans;
}

vector<string> validateCoupons5(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    int n = code.size();
    vector<string> res;
    vector<string> resE;
    vector<string> resG;
    vector<string> resP;
    vector<string> resR;
    for (int i = 0; i < n; i++)
    {
        string cd = code[i];
        string bL = businessLine[i];
        bool iA = isActive[i];
        // Validate code
        if (cd == "")
            continue;
        bool validCode = true;
        for (char c : cd)
        {
            if (!(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')) || (c == '_')))
                validCode = false;
        }
        if (!validCode)
            continue;
        // Validate isActive
        if (!iA)
            continue;
        // Validate businessLine
        if (bL == "restaurant")
            resR.push_back(cd);
        if (bL == "electronics")
            resE.push_back(cd);
        if (bL == "grocery")
            resG.push_back(cd);
        if (bL == "pharmacy")
            resP.push_back(cd);
    }

    sort(resR.begin(), resR.end());
    sort(resE.begin(), resE.end());
    sort(resG.begin(), resG.end());
    sort(resP.begin(), resP.end());

    res.insert(res.end(), resE.begin(), resE.end());
    res.insert(res.end(), resG.begin(), resG.end());
    res.insert(res.end(), resP.begin(), resP.end());
    res.insert(res.end(), resR.begin(), resR.end());

    return res;
}

bool isValid6(string s)
{
    if (s == "")
        return 0;
    for (auto c : s)
    {
        if ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9') or c == '_')
            continue;
        else
            return 0;
    }
    return 1;
}
bool check6(string s)
{
    if (s == "electronics" or s == "grocery" or s == "pharmacy" or s == "restaurant")
        return 1;
    else
        return 0;
}

vector<string> validateCoupons6(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    vector<vector<string>> a;
    int n = code.size();

    for (int i = 0; i < n; i++)
    {
        if (isActive[i])
        {
            if (isValid6(code[i]) and check6(businessLine[i]))
                a.push_back({businessLine[i], code[i]});
        }
    }
    sort(a.begin(), a.end());
    vector<string> ans;

    for (auto v : a)
        ans.push_back(v[1]);
    return ans;
}

bool v17(string s)
{
    if (s.empty())
        return false;
    for (char c : s)
    {
        if (!(isalnum(c) || c == '_'))
            return false;
    }
    return true;
}

vector<string> validateCoupons7(vector<string> &code, vector<string> &business, vector<bool> &active)
{
    unordered_map<string, int> priority = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}};

    int n = code.size();
    vector<pair<int, string>> valid;

    for (int i = 0; i < n; i++)
    {
        if (!active[i])
            continue;

        if (!priority.count(business[i]))
            continue;

        if (!v17(code[i]))
            continue;

        valid.push_back({priority[business[i]], code[i]});
    }

    sort(valid.begin(), valid.end(), [&](auto &a, auto &b)
         {
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second; });

    vector<string> ans;
    for (auto &p : valid)
    {
        ans.push_back(p.second);
    }

    return ans;
}

vector<string> validateCoupons8(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    vector<string> ans;
    vector<int> idx;
    for (int i = 0; i < code.size(); i++)
    {
        if (
            (businessLine[i] != "electronics" &&
             businessLine[i] != "grocery" &&
             businessLine[i] != "pharmacy" &&
             businessLine[i] != "restaurant") ||
            !isActive[i])
            continue;
        if (!code[i].empty() && all_of(code[i].begin(), code[i].end(), [&](char c)
                                       { return isalnum(c) || c == '_'; }))
        {
            cout << i << endl;
            idx.push_back(i);
        }
    }
    sort(idx.begin(), idx.end(), [&](int &a, int &b)
         { return (businessLine[a] < businessLine[b]) || (businessLine[a] == businessLine[b] && code[a] < code[b]); });
    for (auto &i : idx)
    {
        ans.push_back(code[i]);
    }
    return ans;
}

bool check9(string code, bool isActive)
{
    for (auto it : code)
    {
        if (it != '_' && !isalnum(it))
        {
            return false;
        }
    }
    return isActive;
}

vector<string> validateCoupons9(vector<string> &code,
                                vector<string> &businessLine,
                                vector<bool> &isActive)
{
    vector<string> groups[4];
    vector<string> ans;
    for (int i = 0; i < code.size(); i++)
    {
        if (code[i].size() && check9(code[i], isActive[i]))
        {
            if (businessLine[i] == "electronics")
            {
                groups[0].push_back(code[i]);
            }
            else if (businessLine[i] == "grocery")
            {
                groups[1].push_back(code[i]);
            }
            else if (businessLine[i] == "pharmacy")
            {
                groups[2].push_back(code[i]);
            }
            else if (businessLine[i] == "restaurant")
            {
                groups[3].push_back(code[i]);
            }
        }
    }
    for (auto &group : groups)
    {
        sort(group.begin(), group.end());
        ans.insert(ans.end(), group.begin(), group.end());
    }
    return ans;
}

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
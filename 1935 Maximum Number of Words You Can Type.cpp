// 2025/09/15 23:25:33

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int canBeTypedWords(string text, string brokenLetters)
{
    bool broken[26] = {};
    for (auto ch : brokenLetters)
        broken[ch - 'a'] = true;
    int res = 0, cnt = 0;
    for (auto ch : text)
        if (ch == ' ')
        {
            res += cnt == 0;
            cnt = 0;
        }
        else
            cnt += broken[ch - 'a'];
    return res + (cnt == 0);
}

int canBeTypedWords5(string text, string brokenLetters)
{
    int n = text.size();
    int m = brokenLetters.size();
    if (m == 26)
        return 0;
    if (m == 0)
    {
        int count = 1;
        int n = text.size();
        for (auto it : text)
        {
            if (it == ' ')
                count++;
        }
        return count;
    }
    int total_count = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        char c = text[i];
        if (c != ' ' && !flag)
        {
            for (int j = 0; j < m; j++)
            {
                if (c == brokenLetters[j])
                    flag = 1;
            }
        }
        else if (c == ' ')
        {
            if (!flag)
                total_count++;
            flag = 0;
        }
    }
    if (!flag)
        total_count++;
    return total_count;
}

int canBeTypedWords4(const std::string &t, const std::string &bl) const
{
    int blm = 0;
    for (const char c : bl)
        blm |= 1 << (c - 'a');
    int ans = 0;
    for (int i = 0, n = t.size(); i < n; ++i)
    {
        const char c = t[i];
        if (c == ' ')
        {
            ++ans;
            continue;
        }
        if ((1 << (c - 'a')) & blm)
        {
            while (i < n && t[i] != ' ')
                ++i;
            continue;
        }
        if (i == n - 1)
            ++ans;
    }
    return ans;
}

int canBeTypedWords3(string text, string brokenLetters)
{
    unordered_set<char> st;
    int cnt = 0;

    for (auto &it : brokenLetters)
    {
        st.insert(it);
    }

    stringstream ss(text);

    string word;
    vector<string> words;

    while (ss >> word)
    {
        words.push_back(word);
    }

    for (auto w : words)
    {
        for (char c : w)
        {
            if (st.find(c) != st.end())
            {
                cnt++;
                break;
            }
        }
    }

    return words.size() - cnt;
}

int canBeTypedWords2(string text, string brokenLetters)
{
    unordered_set<char> st;
    int cnt = 0;

    for (auto &it : brokenLetters)
    {
        st.insert(it);
    }

    stringstream ss(text);

    string word;
    vector<string> words;

    while (ss >> word)
    {
        words.push_back(word);
    }

    for (auto w : words)
    {
        for (char c : w)
        {
            if (st.find(c) != st.end())
            {
                cnt++;
                break;
            }
        }
    }

    return words.size() - cnt;
}

int canBeTypedWords(string text, string brokenLetters)
{
    string s;
    int cnt = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {

            int flag = 0;
            for (int j = 0; j < brokenLetters.size(); j++)
            {
                if (s.find(brokenLetters[j]) != string::npos)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag && !s.empty())
                cnt++;
            s = "";
            continue;
        }
        s += text[i];
    }
    if (!s.empty())
    {
        int flag = 0;
        for (int j = 0; j < brokenLetters.size(); j++)
        {
            if (s.find(brokenLetters[j]) != string::npos)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            cnt++;
    }
    return cnt;
}
void soln()
{
    cout << canBeTypedWords("hello world", "ad");
    cout << endl;
    cout << canBeTypedWords("leet code", "lt") << endl;
    cout << canBeTypedWords("leet code", "e") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
// 2025/11/03 15:09:43

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minCost7(const string &colors, const vector<int> &neededTime)
{
    if (colors.empty())
        return 0;
    int res = 0;

    int maxTime = neededTime[0];
    for (int i = 1; i < colors.length(); i++)
    {
        if (colors[i] == colors[i - 1])
        {
            res += min(maxTime, neededTime[i]);

            maxTime = max(maxTime, neededTime[i]);
        }
        else
        {
            maxTime = neededTime[i];
        }
    }

    return res;
}

int minCost6(string &colors, vector<int> &neededTime)
{
    const int n = colors.length();

    int leftBalloonIdx = 0;

    int time = 0;
    for (int i = 1; i < n; ++i)
    {
        if (colors[i] == colors[leftBalloonIdx])
        {
            if (neededTime[leftBalloonIdx] <= neededTime[i])
            {
                time += neededTime[leftBalloonIdx];
                leftBalloonIdx = i;
            }
            else
            {
                time += neededTime[i];
            }
        }
        else
            leftBalloonIdx = i;
    }

    return time;
}

int minCost5(const string &colors, const vector<int> &neededTime)
{
    const size_t n = colors.length();
    int min_time = 0;
    size_t i = 0;
    for (; i != n;)
    {
        size_t j = i;
        int total = 0;
        int max = std::numeric_limits<int>::min();
        for (; j != n and colors[j] == colors[i]; ++j)
        {
            total += neededTime[j];
            max = std::max<int>(max, neededTime[j]);
        }
        min_time += total - max;
        i = j;
    }
    return min_time;
}

int minCost4(string colors, vector<int> &neededTime)
{
    int currMax = 0;
    int currColorCost = 0;
    int totalCost = 0;

    char lastColor = '\0';
    int numCurrColor = 0;

    for (int i = 0; i < colors.size(); i++)
    {
        char c = colors[i];

        if (lastColor != c)
        {
            totalCost += numCurrColor <= 1 ? 0 : currColorCost - currMax;
            currColorCost = 0;
            numCurrColor = 0;
            currMax = 0;
        }

        lastColor = c;
        currMax = std::max(currMax, neededTime[i]);
        currColorCost += neededTime[i];
        numCurrColor++;
    }

    totalCost += numCurrColor <= 1 ? 0 : currColorCost - currMax;

    return totalCost;
}

int minCost3(string colors, vector<int> &neededTime)
{
    int n = neededTime.size();
    int i = 0;
    int j = 1;
    int ans = 0;

    while (j < n)
    {
        if (colors[i] == colors[j])
        {
            ans = ans + min(neededTime[i], neededTime[j]);

            neededTime[j] = max(neededTime[i], neededTime[j]);
        }
        i++;
        j++;
    }
    return ans;
}

int minCost2(const string &colors, const vector<int> &neededTime)
{
    if (colors.empty())
        return 0;
    int res = 0;

    int maxTime = neededTime[0];
    for (int i = 1; i < colors.length(); i++)
    {
        if (colors[i] == colors[i - 1])
        {
            res += min(maxTime, neededTime[i]);

            maxTime = max(maxTime, neededTime[i]);
        }
        else
        {
            maxTime = neededTime[i];
        }
    }

    return res;
}

int minCost1(string colors, vector<int> &neededTime)
{
    if (colors.size() == 1)
    {
        return 0;
    }
    int i = 0;
    int j = i + 1;
    int ans = 0;
    while (j < colors.size())
    {
        if (colors[i] == colors[j])
        {
            if (neededTime[i] <= neededTime[j])
            {
                ans += neededTime[i];
                i = j;
                j++;
            }
            else
            {
                ans += neededTime[j];
                j++;
            }
        }
        else
        {
            i = j;
            j++;
        }
    }
    return ans;
}

int minCost(string colors, vector<int> &neededTime)
{
    char ch = colors[0];
    int n = colors.size();
    vector<int> trackBallon = {neededTime[0]};
    int minTime = 0;

    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == ch)
            trackBallon.push_back(neededTime[i]);

        else
        {
            if (trackBallon.size() > 1)
            {
                sort(trackBallon.begin(), trackBallon.end());
                minTime += accumulate(trackBallon.begin(), trackBallon.begin() + (trackBallon.size() - 1), 0);
                // for (int j = 0; j < trackBallon.size() - 1; j++)
                //     // minTime += trackBallon[j];
                //     cout << trackBallon[j] << " ";
                // cout << endl;
            }
            trackBallon.clear();
            if (i == n)
                continue;
            ch = colors[i];
            trackBallon = {neededTime[i]};
        }
    }
    return minTime;
}
void soln()
{
    string colors;
    vector<int> neededTime;
    colors = "abaac";
    neededTime = {1, 2, 3, 4, 5};

    cout << minCost(colors, neededTime) << endl;

    colors = "abc", neededTime = {1, 2, 3};
    cout << minCost(colors, neededTime) << endl;

    colors = "aabaa", neededTime = {1, 2, 3, 4, 1};
    cout << minCost(colors, neededTime) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
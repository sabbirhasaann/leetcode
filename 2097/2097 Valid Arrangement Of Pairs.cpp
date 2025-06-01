#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
{
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> outDegree, inDegree;

    for (const auto &pair : pairs)
    {
        int start = pair[0], end = pair[1];
        graph[start].push_back(end);
        outDegree[start]++;
        inDegree[end]++;
    }

    int startNode = pairs[0][0];
    for (const auto &node : outDegree)
    {
        if (node.second - inDegree[node.first] == 1)
        {
            startNode = node.first;
            break;
        }
    }

    vector<int> path;
    stack<int> stk;

    stk.push(startNode);
    while (!stk.empty())
    {
        int node = stk.top();
        if (!graph[node].empty())
        {
            int nextNode = graph[node].back();
            graph[node].pop_back();
            stk.push(nextNode);
        }
        else
        {
            path.push_back(node);
            stk.pop();
        }
    }
    reverse(path.begin(), path.end());
    vector<vector<int>> result;
    for (int i = 0; i < path.size() - 1; ++i)
        result.push_back({path[i], path[i + 1]});
    return result;
}
int main()
{
    vector<vector<int>> pairs = {{1, 3}, {3, 2}, {2, 1}};
    vector<vector<int>> result = validArrangement(pairs);

    for (const auto &pair : result)
        cout << "[" << pair[0] << ", " << pair[1] << "]";
    cout << endl;
}
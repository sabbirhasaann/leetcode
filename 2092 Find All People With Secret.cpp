// 2025/12/19 22:37:07

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
{
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> visited(n);
    vector<int> people;
    queue<int> q;

    adj[0].push_back({firstPerson, 0});

    for (int i = 0; i < meetings.size(); i++)
        adj[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        people.push_back(u);

        for (pair<int, int> v : adj[u])
            if (!visited[v.first])
            {
                visited[v.first] = true;
                q.push(v.first);
            }
    }

    return people;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    int n, firstPerson;
    vector<vector<int>> meetings;
    n = 6, meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}}, firstPerson = 1;
    printArray(findAllPeople(n, meetings, firstPerson));

    n = 4, meetings = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}}, firstPerson = 3;
    printArray(findAllPeople(n, meetings, firstPerson));

    n = 5, meetings = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}}, firstPerson = 1;
    printArray(findAllPeople(n, meetings, firstPerson));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
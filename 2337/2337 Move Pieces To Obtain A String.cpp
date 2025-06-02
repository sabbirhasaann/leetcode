#include <bits/stdc++.h>
using namespace std;
bool canChange(string start, string target)
{
    int n = start.size();

    if (count(start.begin(), start.end(), 'L') != count(target.begin(), target.end(), 'L') ||
        count(start.begin(), start.end(), 'R') != count(target.begin(), target.end(), 'R') ||
        count(start.begin(), start.end(), '_') != count(target.begin(), target.end(), '_'))
        return false;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        while (i < n && start[i] == '_')
            i++;
        while (j < n && target[j] == '_')
            j++;

        if (i == n && j == n)
            return true;
        if (i == n || j == n)
            return false;

        if (start[i] != target[j])
            return false;
        if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
            return false;

        i++;
        j++;
    }
    return true;
}
int main()
{
    string start, target;
    cin >> start >> target;

    cout << (canChange(start, target) ? "true" : "false") << endl;
}
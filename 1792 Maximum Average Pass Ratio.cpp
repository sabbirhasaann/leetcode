// 2025/09/02 21:41:47

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    int n = classes.size();
    double avg = numeric_limits<double>::max();
    double average;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        double first = round(((double)classes[i][0] / classes[i][1]) * 10000.0) / 10000.0;
        average += first;
        cout << setw(6) << first << endl;
        if (avg > first)
        {
            avg = first;
            idx = i;
        }
    }
    average = average - avg + round(((double)classes[idx][0] + extraStudents) / ((double)classes[idx][1] + extraStudents));
    return average / 4;
}
vector<vector<int>> input_matrix(int n, int m)
{
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    return arr;
}
void soln()
{
    int n, extraStudents;
    cin >> n >> extraStudents;
    vector<vector<int>> classes = input_matrix(n, 2);
    cout << maxAverageRatio(classes, extraStudents);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
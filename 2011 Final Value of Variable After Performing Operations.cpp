// 2025/10/20 23:18:00

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (string op : operations)
    {
        if (op[0] == '+')
            ++x;
        else if (op[0] == '-')
            --x;
        else if (op[2] == '+')
            x++;
        else
            x--;
    }
    return x;
}
void soln()
{
    vector<string> operations;
    operations = {"--X", "X++", "X++"};
    cout << finalValueAfterOperations(operations) << endl;
    operations = {"X++", "++X", "--X", "X--"};
    cout << finalValueAfterOperations(operations) << endl;
    operations = {"++X", "++X", "X++"};
    cout << finalValueAfterOperations(operations) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
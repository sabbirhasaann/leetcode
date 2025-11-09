// 2025/11/09 20:02:19

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int countOperations1(int num1, int num2)
{
    int cnt = 0, a = max(num1, num2), b = min(num1, num2);
    while (a && b)
    {
        cnt += a / b;
        a %= b;
        swap(a, b);
    }
    return cnt;
}

int countOperations(int num1, int num2)
{
    int cnt = 0;
    while (num1 != 0 && num2 != 0)
    {
        if (num1 > num2)
        {
            cnt += num1 / num2;
            num1 %= num2;
        }
        else
        {
            cnt += num2 / num1;
            num2 %= num1;
        }
    }
    return cnt;
}
void soln()
{
    cout << countOperations(2,3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
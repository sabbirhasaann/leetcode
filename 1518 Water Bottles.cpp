// 2025/10/01 23:47:45

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int numWaterBottles(int numBottles, int numExchange)
{
    double res = 0;
    res += numBottles;
    while (numBottles >= numExchange)
    {
        int val = numBottles / numExchange;
        int rem = numBottles % numExchange;
        res += val;
        numBottles = val + rem;
    }
    return res;
}
void soln()
{
    cout << numWaterBottles(9, 3) << endl;
    cout << numWaterBottles(15, 4) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
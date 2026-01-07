// 2025/11/26 19:35:05

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int smallestRepunitDivByK(int k) {
        vector<pair<long long, int>> nums = {
            {1,1},
            {11,2},
            {111,3},
            {1111,4},
            {11111,5},
            {111111,6},
            {1111111,7},
            {11111111,8},
            {111111111,9},
            {1111111111,10},
            {11111111111,11},
            {111111111111,12},
            {1111111111111,13},
            {11111111111111,14},
            {111111111111111,15},
            {1111111111111111,16},
            {11111111111111111,17},
            {111111111111111111,18},

        };

        for(auto x: nums){
            if(x.first % k ==0)
                return x.second;
        }
        return -1;
    }
void soln()
{
    cout << smallestRepunitDivByK(5) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}

// 37/70 test case passed
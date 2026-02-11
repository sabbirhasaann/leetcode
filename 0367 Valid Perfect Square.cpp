// 2026/02/11 22:19:45
// https://leetcode.com/problems/valid-perfect-square/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isPerfectSquare(int num) {
    if(num == 1)
        return true;
    int l = 1, r = num/2;
    while(l<=r){
        int mid = (l + r) / 2;
        if((long long) mid * mid == num)
            return true;
        else if((long long) mid * mid < num)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

bool isPerfectSquare1(int num) {
    long long left = 1, right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sq = mid * mid;

        if (sq == num)
            return true;
        else if (sq < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
void soln()
{
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
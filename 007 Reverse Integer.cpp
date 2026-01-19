// 2026/01/19 19:01:42

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int reverse(int x) {
    
    long long rev = 0;
    while (x != 0) {
        int digit = x % 10;
        rev = rev * 10 + digit;
        x /= 10;
    }
    if (rev < INT_MIN || rev > INT_MAX) {
        return 0;
    }

    return rev;        
}

int reverse1(int x) {
    int rev = 0;
    
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
            return 0;

        rev = rev * 10 + digit;
    }

    return rev;
}

void soln()
{
    
    int x;
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
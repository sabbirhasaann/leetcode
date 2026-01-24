// 2025/12/18 00:54:55

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isPalindrome(int x)
{

    if(x < 0)
        return false;

    long long rev=0;
    int n = x;

    while(n){
        if(rev * 10 + n % 10 >= INT_MAX)
            return false;
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    if(rev != x)
        return false;

    return true;
}
void soln()
{
    int x = 121;
    cout << isPalindrome(x) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(10) << endl;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}
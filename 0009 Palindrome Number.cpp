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

bool isPalindrome1(int x) {
    // Negative numbers or numbers ending with 0 (except 0) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversedHalf = 0;

    // Reverse only half of the number
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // For even digits: x == reversedHalf
    // For odd digits: x == reversedHalf / 10
    return (x == reversedHalf || x == reversedHalf / 10);
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
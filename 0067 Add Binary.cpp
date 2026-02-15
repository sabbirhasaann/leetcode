#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
        string s;
        int n = a.size();
        int m = b.size();

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        
        int carry = 0,i=0,j=0;
        while(i<n && j<m)
        {
            int b1 = a[i] - '0';
            int b2 = b[j] - '0';
            s += (b1 ^ b2 ^ carry) + '0';
            carry = (b1 & b2) | (( b1 ^ b2 ) & carry); // just change
            ++i;
            ++j;
        }

        while(i<n){
            int b1 = a[i] - '0';
            s += (b1 ^ carry) + '0';
            carry = b1 & carry;
            ++i;
        }

        while(j<m){
            int b1 = b[j] - '0';
            s += (b1 ^ carry) + '0';
            carry = b1 & carry;
            ++j;
        }

        if(carry)
            s+= (carry + '0');
        
        reverse(s.begin(), s.end());
        return s;
}

string addBinaryEff(string a, string b) {
        string s;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i>=0 || j>=0 || carry)
        {
            int sum = carry;
            if(i>=0){
                sum += a[i] - '0';
                --i;
            }
            if(j>=0)
            {
                sum += b[j] - '0';
                --j;
            }

            s += (sum%2) + '0';
            carry = sum/2;
        }

        
        reverse(s.begin(), s.end());
        return s;
}

string addBinary1(string a, string b) {
    string res;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) carry += a[i--] - '0';
        if (j >= 0) carry += b[j--] - '0';

        res += carry % 2 + '0';
        carry /= 2;
    }

    reverse(begin(res), end(res));
    return res;        
}

int main(){

    // cout << addBinary("11", "1") << endl;
    // cout << addBinary("1010", "1011") << endl;

    cout << addBinary("110010", "10111") << endl;


}
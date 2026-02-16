// 2026/02/16 08:44:07
// https://leetcode.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int reverseBits(int n){
    int rev = 0;
    for (int i = 0; i < 32; i++) {
        rev <<= 1;
        if (n & 1) {
            rev |= 1;
        }
        n >>= 1;
    }
    return rev;
}

int convert_back(vector<int>bits){
    int num=bits[31];
    for(int i=0;i<31;i++){
        num=num+bits[i]*pow(2,31-i);
    }
    return num;
}
int reverseBits1(int n) {
    vector<int>bits(32,0);
    int num=n,i=0;
    while(num!=0){
        int rem=num%2;
        bits[i]=rem;
        num=num/2;
        i++;
    }
    return convert_back(bits);
}

uint32_t reverseBits2(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        int bit = n & 1;       // Extract the least significant bit
        result = (result << 1) | bit; // Append the bit to the result
        n = n >> 1;           // Right-shift n to process the next bit
    }
    return result;
}
int reverseBitsNaive(int n) {

    int rev = 0;
    string s;
    for(int i=0;i<32;++i){
        if(n & (1<<i))
            s += '1';
        else
            s += '0';       
    }

    for(int i=0;i<32;i++)
        if(s[i]=='1')
            rev += (1<<(31-i));

    return rev;
}

void soln()
{
    int n = 2147483644;
    cout << reverseBits(n) << endl;
    n = 43261596;
    cout << reverseBits(n) << endl;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}